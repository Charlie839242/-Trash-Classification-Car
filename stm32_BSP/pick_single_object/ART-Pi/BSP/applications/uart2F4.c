/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-08-22     ��JASON       the first version
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



#define SAMPLE_UART_NAME       "uart5"    /* �����豸���� */
static rt_device_t serial;                /* �����豸��� */
struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT;  /* ��ʼ�����ò��� */

char str[40] ={};
char str_temp[40] ={};
/* �߳� ����ں��� */


int uart_init(void)
{
    /* ����ϵͳ�еĴ����豸 */
    serial = rt_device_find(SAMPLE_UART_NAME);
    if (!serial)
    {
        rt_kprintf("find %s failed!\n", SAMPLE_UART_NAME);
        return RT_ERROR;
    }
    /* step2���޸Ĵ������ò��� */
    config.baud_rate = BAUD_RATE_115200;        //�޸Ĳ�����Ϊ 115200
    config.data_bits = DATA_BITS_8;           //����λ 8
    config.stop_bits = STOP_BITS_1;           //ֹͣλ 1
    config.bufsz     = 512;                   //�޸Ļ����� buff size Ϊ 128
    config.parity    = PARITY_NONE;           //����żУ��λ

    /* step3�����ƴ����豸��ͨ�����ƽӿڴ�����������֣�����Ʋ��� */
    rt_device_control(serial, RT_DEVICE_CTRL_CONFIG, &config);

    return 0;
}

void uart_send(void)
{

        /* step4���򿪴����豸�����жϽ��ռ���ѯ����ģʽ�򿪴����豸 */
        rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);
//        rt_thread_mdelay(800);
        /* �����ַ��� */
        x_middle=(_x1+_x2)*0.5;//ע�������и�0.5�����Ե���
        sprintf(str_temp, "#%d*\n", x_middle);
        rt_device_write(serial, 0, str_temp, (sizeof(str_temp) - 1));
        rt_kprintf(str_temp);
        rt_device_close(serial);//�ر��豸
}

