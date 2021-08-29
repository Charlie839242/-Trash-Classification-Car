/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-08-21     张JASON       the first version
 */
#include <rtthread.h>
#include <pid.h>
#include <car_uart.h>
int speed_set=0;

char right_corner[]="{#012P1800T0400!#013P1800T0400!#014P1800T0400!#015P1800T0400!}";
char left_corner[]="{#012P1200T0400!#013P1200T0400!#014P1200T0400!#015P1200T0400!}";

char right_corner_slower[]="{#012P16500T0400!#013P1650T0400!#014P1650T0400!#015P1650T0400!}";
char left_corner_slower[]="{#012P1350T0400!#013P1370T0400!#014P1350T0400!#015P1350T0400!}";

char stop_com[]="{#012P1500T200!#013P1500T200!#014P1500T200!#015P1500T200!}";
char temp[70]={};
char stop_bit[]="*";
char restart_bit[]="+";
int change_flag=0;//意思是在转动的过程中不接收信息;为0的时候接收,为1的时候不接收


extern int continue_flag;
#define SAMPLE_UART_NAME       "uart2"       /* 需要操作的设备 */
static rt_device_t serial;                   /* 设备句柄 */

extern _Bool turn_flag;
extern int x_middle;
int stop_flag=1;
int receive_times=0;//此变量表示没有收到数据的次数
extern int class_name;




char class1_com[]="A";//表示第一类发送命令A
char class2_com[]="B";//表示第二类发送命令B


int state=1;

int turn_state=1;//默认是旋转状态
int turn_corner(int angle);
int uart_init(void)
{
    turn_state=1;
    /* 查找系统中的串口设备 */
    serial = rt_device_find(SAMPLE_UART_NAME);
    if (!serial)
    {
        rt_kprintf("find %s failed!\n", SAMPLE_UART_NAME);
        return RT_ERROR;
    }
    return 0;
}

int uart_sample(void)
{
    if(turn_state==1)
    {
        receive_times++;
        stop_flag=0;
        if(receive_times>5)
        {
            x_middle=0;
            continue_flag=0;

            if(receive_times==6||receive_times==7)//让F1知道很久没有收到消息了
            {
                rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);
                rt_device_write(serial, 0, restart_bit, (sizeof(restart_bit) - 1));//停止左右转，开始前后运动
                rt_thread_mdelay(200);
                rt_device_close(serial);//关闭设备
            }
        }
    }
    else {
        receive_times=0;//直行态清零
    }

    if(continue_flag==0)
    {
        rt_kprintf("abc\r\n");
    //    char word_temp[15];
        if(x_middle>=180||x_middle<=140)//180以外或者140以下
        {
            turn_flag=1;
        }
        else {
            rt_kprintf("point5\r\n");
            if(turn_state==1){
                rt_kprintf("point6\r\n");
                turn_flag=0;
                rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);
                if(stop_flag==0)
                {
                    rt_device_write(serial, 0, stop_com, (sizeof(stop_com) - 1));//停止左右转，开始前后运动
                    stop_flag=1;
                }
                rt_thread_mdelay(120);
                rt_device_write(serial, 0, stop_bit, (sizeof(stop_bit) - 1));//停止左右转，开始前后运动
                rt_thread_mdelay(200);

                /***发送类别***/
                if(class_name==1)//第一类
                {
                    rt_device_write(serial, 0, class1_com, (sizeof(class1_com) - 1));//检测到的是第一类
                }
                if(class_name==2)//第二类
                {
                    rt_device_write(serial, 0, class2_com, (sizeof(class2_com) - 1));//检测到的是第二类
                }

                turn_state=0;//退出旋转状态
                rt_device_close(serial);//关闭设备
            }
        }
        if(turn_flag==1&&(turn_state==1))
        {
            rt_kprintf("point7\r\n");
            /* 以中断接收及轮询发送模式打开串口设备 */
            stop_flag=0;
             rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);
            /* 发送字符串 */
            if(x_middle>180)//物体在屏幕中心的右侧
            /*右转*/
            {
                if(x_middle>310)
                {
                    turn_corner(350);
                }
                else
                {
                    turn_corner(120+(x_middle-160)*1);

                }

                rt_thread_mdelay(20);
            }
            else if(x_middle<140)//物体在屏幕中心的左侧
            {
            /*左转*/
                if(x_middle<10){

                  turn_corner(-350);
                }
                else {
                    turn_corner(-120+(x_middle-160)*1);
                }

                rt_thread_mdelay(20);

            }
            //rt_kprintf("serial device test successful\r\n");
            rt_device_close(serial);//关闭设备
        }
    }


    else if(continue_flag==1)
    {
        rt_kprintf("point1\r\n");
        if(x_middle>=170||x_middle<=150)//165以外或者155以下
         {
            rt_kprintf("pointa\r\n");
             turn_flag=1;
         }
         else {
             if(turn_state==1){
                 turn_flag=0;
                 rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);
                 if(stop_flag==0)
                 {
                     rt_kprintf("point2\r\n");
                     rt_device_write(serial, 0, stop_com, (sizeof(stop_com) - 1));//停止左右转，开始前后运动
                     stop_flag=1;
                 }
                 rt_kprintf("point3\r\n");
                 rt_thread_mdelay(120);
                 rt_device_write(serial, 0, stop_bit, (sizeof(stop_bit) - 1));//停止左右转，开始前后运动
                 rt_thread_mdelay(200);
                 turn_state=0;//退出旋转状态
                /***发送类别***/
                 if(class_name==1)//第一类
                 {
                     rt_device_write(serial, 0, class1_com, (sizeof(class1_com) - 1));//检测到的是第一类
                 }
                 if(class_name==2)//第二类
                 {
                     rt_device_write(serial, 0, class2_com, (sizeof(class2_com) - 1));//检测到的是第二类
                 }

                 rt_device_close(serial);//关闭设备
             }
         }
         if(turn_flag==1&&(turn_state==1))
         {
             rt_kprintf("point4\r\n");
             /* 以中断接收及轮询发送模式打开串口设备 */
             stop_flag=0;
              rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);
             /* 发送字符串 */
             if(x_middle>170)//物体在屏幕中心的右侧
             /*右转*/
             {
                 if(x_middle>310)
                 {
                     turn_corner(350);
                 }
                 else
                 {
                     turn_corner(120+(x_middle-160)*1);

                 }

                 rt_thread_mdelay(20);
             }
             else if(x_middle<150)//物体在屏幕中心的左侧
             {
             /*左转*/
                 if(x_middle<10){

                   turn_corner(-350);
                 }
                 else {
                     turn_corner(-120+(x_middle-160)*1);
                 }

                 rt_thread_mdelay(20);

             }
             //rt_kprintf("serial device test successful\r\n");
             rt_device_close(serial);//关闭设备
         }
    }


    change_flag=1;//表示正在变换，所以不接收信息
//    rt_thread_mdelay(400);//延迟1500ms
    change_flag=0;//表示变换结束，开始接收
    return RT_EOK;
}


int turn_corner(int angle)//为正数代表右转,范围为-1000到1000
{
    int static left_speed,right_speed;
    /* 以中断接收及轮询发送模式打开串口设备 */
    rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);
    left_speed=angle+1500;
    right_speed=1500+angle;
    sprintf(temp,"{#012P%dT0400!#013P%dT0400!#014P%dT0400!#015P%dT0400!}",left_speed,right_speed,left_speed,right_speed);

    /*发送*/
    rt_device_write(serial, 0, temp, (sizeof(temp) - 1));
    rt_device_close(serial);//关闭设备


    return RT_EOK;
}

///* 导出到 msh 命令列表中 */
//MSH_CMD_EXPORT(uart_sample, uart device sample);

