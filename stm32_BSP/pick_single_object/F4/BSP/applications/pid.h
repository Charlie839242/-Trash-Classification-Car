/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-08-26     张JASON       the first version
 */
#ifndef APPLICATIONS_PID_H_
#define APPLICATIONS_PID_H_


void PidInit(void);
void Pid_Execu_sp(int x_middle,int voltage_set);

#endif /* APPLICATIONS_PID_H_ */
