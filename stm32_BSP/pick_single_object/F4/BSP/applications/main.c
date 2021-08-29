/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-08-21     RT-Thread    first version
 */

#include <rtthread.h>
#include <car_uart.h>
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include <pid.h>
extern int x_middle;
extern int speed_set;
extern int turn_state;
extern _Bool turn_flag;
extern int continue_flag;
int main(void)
{
    char str_tem[30];
    int count = 1;
    uart_init();
//    PidInit();
//    x_middle=100;
//    speed_set=130;
//    rt_kprintf("adf");
    while (count++)
    {
        uart_sample();
        rt_thread_mdelay(1100);
        sprintf(str_tem,"turn_state=%d,turn_flag=%d,continue_flag=%d\r\n",turn_state,turn_flag,continue_flag);
        rt_kprintf(str_tem);
    }

    return RT_EOK;
}
