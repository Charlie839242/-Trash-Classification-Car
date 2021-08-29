/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-08-26     张JASON       the first version
 */
#include <pid.h>

extern int x_middle;
extern int speed_set;
typedef struct
{
    float A0;          /**< The derived gain, A0 = Kp + Ki + Kd . */
    float A1;          /**< The derived gain, A1 = -Kp - 2Kd. */
    float A2;          /**< The derived gain, A2 = Kd . */
    float state[3];    /**< The state array of length 3. */
    float Kp;               /**< The proportional gain. */
    float Ki;               /**< The integral gain. */
    float Kd;               /**< The derivative gain. */
} arm_pid_instance_f32;


float arm_pid_f32(arm_pid_instance_f32 *S,float in)
{
    float out;

    /* y[n] = y[n-1] + A0 * x[n] + A1 * x[n-1] + A2 * x[n-2]  */
    out = (S->A0 * in) +
      (S->A1 * S->state[0]) + (S->A2 * S->state[1]) + (S->state[2]);

    /* Update state */
    S->state[1] = S->state[0];
    S->state[0] = in;
    S->state[2] = out;

    /* return to application */
    return (out);
}


typedef struct
{
    arm_pid_instance_f32 S;
    float out;
}PidCtrTypedef;
PidCtrTypedef pidCtrl_sp;


void PidInit(void)
{
    pidCtrl_sp.S.Kp=10;
    pidCtrl_sp.S.Ki=0;
    pidCtrl_sp.S.Kd=0;
    pidCtrl_sp.out=0;
}

void Pid_Execu_sp(int x_middle,int speed_set)
{
    static float pid_err;
    pid_err=160-x_middle;
    pidCtrl_sp.out=arm_pid_f32(&pidCtrl_sp.S,pid_err);
    speed_set=pidCtrl_sp.out+speed_set;
}
