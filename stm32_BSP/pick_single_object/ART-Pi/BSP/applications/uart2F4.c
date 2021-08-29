/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-08-22     张JASON       the first version
 */

#include "uart2F4.h"
#include "stdio.h"
#define THREAD_PRIORITY         2
#define THREAD_STACK_SIZE       1024
#define THREAD_TIMESLICE        5

extern int sign;
extern int _x1;
extern int _y1;
extern int _x2;
extern int _y2;
int x_middle;



#define SAMPLE_UART_NAME       "uart5"    /* 串口设备名称 */
static rt_device_t serial;                /* 串口设备句柄 */
struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT;  /* 初始化配置参数 */

char str[40] ={};
char str_temp[40] ={};
/* 线程 的入口函数 */


int uart_init(void)
{
    /* 查找系统中的串口设备 */
    serial = rt_device_find(SAMPLE_UART_NAME);
    if (!serial)
    {
        rt_kprintf("find %s failed!\n", SAMPLE_UART_NAME);
        return RT_ERROR;
    }
    /* step2：修改串口配置参数 */
    config.baud_rate = BAUD_RATE_115200;        //修改波特率为 115200
    config.data_bits = DATA_BITS_8;           //数据位 8
    config.stop_bits = STOP_BITS_1;           //停止位 1
    config.bufsz     = 512;                   //修改缓冲区 buff size 为 128
    config.parity    = PARITY_NONE;           //无奇偶校验位

    /* step3：控制串口设备。通过控制接口传入命令控制字，与控制参数 */
    rt_device_control(serial, RT_DEVICE_CTRL_CONFIG, &config);

    return 0;
}

void uart_send(void)
{

        /* step4：打开串口设备。以中断接收及轮询发送模式打开串口设备 */
        rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);
//        rt_thread_mdelay(800);
        /* 发送字符串 */
        x_middle=(_x1+_x2)*0.5;//注意这里有个0.5被忽略掉了
        sprintf(str_temp, "#%d*\n", x_middle);
        rt_device_write(serial, 0, str_temp, (sizeof(str_temp) - 1));
        rt_kprintf(str_temp);
        rt_device_close(serial);//关闭设备
}

