/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-08-26     ’≈JASON       the first version
 */
#ifndef APPLICATIONS_UART2F4_2_H_
#define APPLICATIONS_UART2F4_2_H_
#include <rtthread.h>
#include "rtconfig.h"
#include <rtdevice.h>
#include "drv_common.h"

int uart_init(void);
void uart_send(void);
#endif /* APPLICATIONS_UART2F4_2_H_ */
