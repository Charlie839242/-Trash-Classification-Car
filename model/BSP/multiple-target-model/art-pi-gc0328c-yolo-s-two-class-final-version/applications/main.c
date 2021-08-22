/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-09-02     RT-Thread    first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#include "drv_spi_ili9488.h"  // spi lcd driver 
#include <lcd_spi_port.h>  // lcd ports
#include <rt_ai_person_yolo_model.h>
#include <rt_ai.h>
#include <backend_cubeai.h>
#include <yolo_layer.h>
#include <stdio.h>
#define LED_PIN GET_PIN(I, 8)

struct rt_event ov2640_event;
rt_uint8_t *input_gray;
rt_uint8_t *input_gray_160;
float *input_buf;                   // input of the model
rt_uint8_t ai_flag = 0;
float obj[125];                     // store the objectness*class_score of 125 boxes
int class;                          // This is the class prediction of the model

extern void DCMI_Start();
extern int rt_gc0328c_init();
static inline void _itof(float *dst,rt_uint8_t *src, uint32_t size, float div);
void rgb2gray(unsigned char *src,unsigned char *dst, int width,int height);
void bilinera_interpolation(rt_uint8_t* in_array, short height, short width, 
                            rt_uint8_t* out_array, short out_height, short out_width);

yolo_region_layer r1;
void ai_camera();

int main(void)
{
    char temp[80];
    rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);

    input_gray = rt_malloc(320*240);
    input_gray_160 = rt_malloc(160*160);
    input_buf = rt_malloc(160*160*sizeof(float));
    
    /* init spi data notify event */
    rt_event_init(&ov2640_event, "ov2640", RT_IPC_FLAG_FIFO);
    struct drv_lcd_device *lcd;
    lcd = (struct drv_lcd_device *)rt_device_find("lcd");
    struct rt_device_rect_info rect_info = {0, 0, LCD_WIDTH, 240};
    lcd->parent.control(&lcd->parent, RTGRAPHIC_CTRL_RECT_UPDATE, &rect_info);

    // find ai model handle
    rt_ai_t person_d = NULL;
    person_d = rt_ai_find(RT_AI_PERSON_YOLO_MODEL_NAME);
    if(!person_d) {rt_kprintf("ai find err\n"); return -1;}
    // alloc calculate mem
    rt_ai_buffer_t *work_buf = rt_malloc(RT_AI_PERSON_YOLO_WORK_BUFFER_BYTES);
    if(!work_buf) {rt_kprintf("malloc err\n");return -1;}
    // ai out
    rt_ai_buffer_t *_out = rt_malloc(RT_AI_PERSON_YOLO_OUT_1_SIZE_BYTES);
    if(!_out) {rt_kprintf("malloc err\n"); return -1;}
    
    // connect the work buffer, input buffer and output buffer to the model
    if(rt_ai_init(person_d,work_buf) != 0){rt_kprintf("ai init err\n"); return -1;}
    rt_ai_config(person_d,CFG_INPUT_0_ADDR,(rt_ai_buffer_t*)input_buf);
    rt_ai_config(person_d,CFG_OUTPUT_0_ADDR,_out);
    
    // yolo_box
    yolo_box *boxs = NULL;
    yolo_box *p  = NULL;                        // two bbox
    yolo_region_layer_init(&r1, 0.5, 125, 0.2, 5);    // init nms rules
    int _x1 = 0;
    int _y1 = 0;
    int _x2 = 0;
    int _y2 = 0;                                // location of the predicted bbox
    
    ai_camera();
    while(1){
        rt_pin_write(LED_PIN, PIN_LOW);
        rt_event_recv(&ov2640_event,
                        1,
                        RT_EVENT_FLAG_AND | RT_EVENT_FLAG_CLEAR,
                        RT_WAITING_FOREVER,
                        RT_NULL);
        rt_pin_write(LED_PIN, PIN_HIGH);
        lcd->parent.control(&lcd->parent, RTGRAPHIC_CTRL_RECT_UPDATE, &rect_info);
        if(ai_flag > 0)
        {
            rgb2gray(lcd->lcd_info.framebuffer ,input_gray, 320,240);  // change the taken img to gray in 'input_gray'
            bilinera_interpolation(input_gray, 240, 320, input_gray_160, 160, 160); // change the size of 'input_gray' in 'input_gray_160'
            _itof(input_buf,input_gray_160, 160*160, 255.0); // normalize the 'input_gray_160' in input_buf
            rt_ai_run(person_d, NULL, NULL);
            boxs = (yolo_box *)rt_ai_output(person_d,0); // 'boxes' is a ''yolo_box' pointer' to the start of the output region
            // output shape is 1*5*5*30, since every box has 6 params, the number of output boxes is 125
            yolo_decode((float*) boxs); // decode the 125 boxes
            // do_nms_sort(&r1,boxs);
            p = boxs;
            for(int i=0;i<125;i++)
            {
                p = &boxs[i];
                float p0 = p->class_score0 * p->objectness;
                float p1 = p->class_score1 * p->objectness;
                float max = p0>p1 ? p0:p1;
                obj[i] = max;
            }
            int number = find_max(obj);
            yolo_box best_box = boxs[number];
            float box0 = best_box.class_score0 * best_box.objectness;
            float box1 = best_box.class_score1 * best_box.objectness;
            if((box0>r1.threshold)||(box1>r1.threshold))
            {
                rt_kprintf("detected! \n");
                _x1 = (int)(best_box.x*320 - (best_box.w*320*0.5));  _x1 = _x1>0 ? _x1:1; _x1 = _x1<320 ? _x1:319;
                _y1 = (int)(best_box.y*240 - (best_box.h*160*1.5*0.5)); _y1 = _y1>0 ? _y1:1; _y1 = _y1 < 240 ? _y1:239;
                _x2 = (int)(best_box.x*320 + (best_box.w*320*0.5)); _x2 = _x2>0 ? _x2:1; _x2 = _x2<320 ? _x2:319;
                _y2 = (int)(best_box.y*240 + (best_box.h*160*1.5*0.5)); _y2 = _y2>0 ? _y2:1; _y2 = _y2 < 240 ? _y2:239;
                lcd_draw_rectangle(_x1, _y1, _x2, _y2);
                if(box0>0.4)
                {
                    rt_kprintf("class 0! \n");
                    class = 0;
                }
                else
                {
                    rt_kprintf("class 1! \n");
                    class = 1;
                }
            }
            else
                rt_kprintf("not detected! \n");
        DCMI_Start();
        }  
    }
    
    return RT_EOK;
}

#include "stm32h7xx.h"
static int vtor_config(void)
{
   /* Vector Table Relocation in Internal QSPI_FLASH */
   SCB->VTOR = QSPI_BASE;
   return 0;
}
INIT_BOARD_EXPORT(vtor_config);

void ai_camera()
{
    rt_gc0328c_init();
    ai_flag = 1;
    DCMI_Start();
}
// MSH_CMD_EXPORT(ai_camera, Start the AI camera to recognize person);

static inline void _itof(float *dst,rt_uint8_t *src, uint32_t size, float div){
    if (div == 0){
        return ;
    }else{
        int i = 0;
        for(i = 0; i < size; i++){
            dst[i] = (float)src[i] / div;
        }
    }
}

// img covnert to gray: Gray = 0.2989*R + 0.5870*G + 0.1140*B
// better: 4898*R + 9618*G + 1868*B >> 14
// int8: 76*R + 150*G + 30*B >> 8
void rgb2gray(unsigned char *src, unsigned char *dst, int width, int height)
{
    int r, g, b;
    for (int i=0; i<width*height; ++i)
    {
        r = *src++; // load red
        g = *src++; // load green
        b = *src++; // load blue
        // build weighted average:
        *dst++ = (r * 76 + g * 150 + b * 30) >> 8;
    }
}

int is_in_array(short x, short y, short height, short width)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
        return 1;
    else
        return 0;
}

void bilinera_interpolation(rt_uint8_t* in_array, short height, short width, 
                            rt_uint8_t* out_array, short out_height, short out_width)
{
    double h_times = (double)out_height / (double)height,
           w_times = (double)out_width / (double)width;
    short  x1, y1, x2, y2, f11, f12, f21, f22;
    double x, y;

    for (int i = 0; i < out_height; i++){
        for (int j = 0; j < out_width; j++){
            x = j / w_times;
            y = i / h_times;
          
            x1 = (short)(x - 1);
            x2 = (short)(x + 1);
            y1 = (short)(y + 1);
            y2 = (short)(y - 1);
            f11 = is_in_array(x1, y1, height, width) ? in_array[y1*width+x1] : 0;
            f12 = is_in_array(x1, y2, height, width) ? in_array[y2*width+x1] : 0;
            f21 = is_in_array(x2, y1, height, width) ? in_array[y1*width+x2] : 0;
            f22 = is_in_array(x2, y2, height, width) ? in_array[y2*width+x2] : 0;
            out_array[i*out_width+j] = (rt_uint8_t)(((f11 * (x2 - x) * (y2 - y)) +
                                       (f21 * (x - x1) * (y2 - y)) +
                                       (f12 * (x2 - x) * (y - y1)) +
                                       (f22 * (x - x1) * (y - y1))) / ((x2 - x1) * (y2 - y1)));
        }
    }
}
