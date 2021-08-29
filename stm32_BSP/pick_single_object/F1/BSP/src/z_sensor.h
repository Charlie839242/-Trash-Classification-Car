#ifndef __SENSOR_H__
#define __SENSOR_H__

#include "stm32f10x_conf.h"
#include "z_color.h"	//颜色拾取传感器


#define XJ_ON 0
#define XJ_OFF 1
#define xj0() GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)
#define xj1() GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)

#define Trig(x) gpioB_pin_set(0, x);
#define Echo() GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2)

#define sound() GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)

#define ADC_YSSB	0	//A5 数组所在位置是0 
#define COLOR_RED 215	//红色基准色
#define COLOR_GRN 310	//蓝色基准色
#define COLOR_BLU 283	//绿色基准色
#define YSSB_LED(x) TCS34725_LedON(x); //颜色识别的LED灯

#define COLOR_VERIFY   0x42
#define COLOR_RED_BASE 119 //红色基准色
#define COLOR_GRN_BASE 135 //绿色基准色
#define COLOR_BLU_BASE 141 //蓝色基准色
/*******红外遥控器映射表*******/
#define IR	GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8)

/*******红外遥控器键码表*******/
#define IR_POWER		0xa2
#define IR_MENU			0x62
#define IR_MUTE			0xe2
#define IR_MODE			0x22
#define IR_ADD			0x02
#define IR_BACK			0xc2
#define IR_FORWARD			0xe0
#define IR_SUSPEND			0xa8
#define IR_BACKWARD 		0x90
#define IR_0 				0x68
#define IR_SUBTRACT 		0x98
#define IR_OK				0xb0
#define IR_1 				0x30
#define IR_2 				0x18
#define IR_3 				0x7a
#define IR_4 				0x10
#define IR_5 				0x38
#define IR_6 				0x5a
#define IR_7 				0x42
#define IR_8 				0x4a
#define IR_9 				0x52
extern u8 ir_data[4],ir_flag;

//红外遥控器定义
void setup_ir(void);
void loop_ir(void);

//处理智能传感器功能
void setup_sensor(void);	//初始化所有传感器
void loop_sensor(void);		//传感器大循环

void AI_xunji_moshi(void); 			//循迹功能
void AI_shengkong_jiaqu(void);		//静态声音识别夹取
void AI_yanse_shibie(void);			//静态颜色识别夹取
void AI_xunji_shibie(void);			//循迹颜色夹取
void AI_dingju_jiaqu(void);			//静态超声波夹取
void AI_xunji_bizhang(void);		//循迹超声波避障
void AI_gensui_moshi(void);			//超声波跟随功能
void AI_ziyou_bizhang(void);		//超声波自由避障
void AI_xunji_dingju(void);			//循迹超声波夹取
void AI_shengkong_xunji(void);		//声控循迹

#endif


