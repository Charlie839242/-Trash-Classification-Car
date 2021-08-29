/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-08-21     张JASON       the first version
 */
#include <semaphore.h>
#include <drv_common.h>
#include <string.h>
#include <stdio.h>
#define SAMPLE_UART3_NAME       "uart3"       /* 需要操作的设备 */
static struct rt_semaphore      rx_sem3;      /* 信号量 */
static rt_device_t              serial3;      /* 设备句柄 */

int i=0;
char str[30];
int bai,shi,ge;
int x_middle;
int sum_temp;
_Bool turn_flag=0;
extern int change_flag;//意思是在转动的过程中不接收信息;为0的时候接收,为1的时候不接收
extern int receive_times;
int class_name=1;//取值是1或者2

/* 接收数据回调函数 */
static rt_err_t uart3_rx_ind(rt_device_t dev, rt_size_t size)
{
    /* 串口接收到数据后产生中断，调用此回调函数，然后发送接收信号量 */
    if (size > 0)
    {
        rt_sem_release(&rx_sem3);
    }
    return RT_EOK;
}

static char uart_ZIGBEE_get_char(void)
{
    char ch;
    static uint8_t rv_flag = 1;

    while (rt_device_read(serial3, 0, &ch, 1) == 0)
    {
        rt_sem_control(&rx_sem3, RT_IPC_CMD_RESET, RT_NULL);
        if(rv_flag)
            rt_sem_take(&rx_sem3, RT_WAITING_FOREVER);
        else if(-RT_ETIMEOUT == rt_sem_take(&rx_sem3, 100))//超时100ms未获得串口数据  100是根据时钟节拍来定 节拍单位是1/RT_TICK_PER_SECOND 秒
        {
            rv_flag = 1; //收完一帧
            ch = '\n'; //也可以用别的当伪帧尾
            return ch;
        }
    }
    rv_flag = 0; //正常获取一个字节
    return ch;
}

/* 数据解析线程 */
static void ZIGBEE_data_parsing(void)
{
    char rx_temp = 0, rx_len = 0;
    char data_buf[30] = {0};

    while (1)
    {
//        if(change_flag==0)//表示变换已经结束，开始接收信息
//        {
            rx_temp = uart_ZIGBEE_get_char();
            if(rx_temp != '\n')
            {
                data_buf[(rx_len++) % 30] = rx_temp;//防止数组越界
            }
            else //开始处理一帧数据
            {
                rx_len = 0;
                rt_kprintf("uart3 received data is %s\r\n", data_buf);
                /* 帧数据处理，即清零，如果不清零，先输入一个多的，再输入一个少，就会出现错误*/

                if(data_buf[0]=='#')
                {
                    receive_times=0;//收到数据清零
                    i=1;
                    x_middle=0;
                    while(data_buf[i]!='*'&&i<20)
                    {
                        x_middle=10*x_middle;
                        sum_temp=data_buf[i]-'0';
                        x_middle+=sum_temp;
                        i++;
                    }
                    while(data_buf[i]!='&'&&i<20)
                    {
                        class_name=data_buf[i]-'0';
                        i++;
                    }
                    sprintf(str, "x_middle=%d\r\n", x_middle);
                    rt_kprintf(str);
//                    turn_flag=1;

                }
                memset(data_buf, 0, sizeof(data_buf));
            }

//        }
    }
}

static int uart3_ZIGBEE(void)
{
    rt_err_t ret = RT_EOK;
    /* 查找系统中的串口设备 */
    serial3 = rt_device_find(SAMPLE_UART3_NAME);
    if (!serial3)
    {
        rt_kprintf("find %s failed!\n", SAMPLE_UART3_NAME);
        return RT_ERROR;
    }
    /* 初始化信号量 */
    rt_sem_init(&rx_sem3, "rx_sem3", 0, RT_IPC_FLAG_FIFO);
    /* 以中断接收及轮询发送模式打开串口设备 */
    rt_device_open(serial3, RT_DEVICE_FLAG_INT_RX);
    /* 设置接收回调函数 */
    rt_device_set_rx_indicate(serial3, uart3_rx_ind);

    /* 创建 serial 线程 */
    rt_thread_t thread = rt_thread_create("ZIG_th", (void (*)(void *parameter))ZIGBEE_data_parsing,
                                           RT_NULL, 1024, RT_THREAD_PRIORITY_MAX-10, 10);
    /* 创建成功则启动线程 */
    if (thread != RT_NULL)
    {
        rt_thread_startup(thread);
    }
    else
    {
        ret = RT_ERROR;
    }

    return ret;
}

INIT_APP_EXPORT(uart3_ZIGBEE);

