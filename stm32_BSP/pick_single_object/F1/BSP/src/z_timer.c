#include "z_timer.h"
#include "z_gpio.h"
#include "stm32f10x_conf.h"
#include "z_global.h"
#include "z_usart.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "z_delay.h"
#include "z_sensor.h"

// systick register
#define SYSTICK_TENMS    (*((volatile unsigned long *)0xE000E01C))  
#define SYSTICK_CURRENT  (*((volatile unsigned long *)0xE000E018))  
#define SYSTICK_RELOAD   (*((volatile unsigned long *)0xE000E014))  
#define SYSTICK_CSR       (*((volatile unsigned long *)0xE000E010)) 

u32 systick_ms = 0;

u8 ir_start=0,ir_start_flag=0;
u8 ir_repeat=0,ir_repeat_flag=0;
u8 ir_end_flag=0,ir_time_flag=0;
u8 ir_data_count=0;

//初始化函数
float _abs(float temp) {
	if(temp>0)return temp;
	else {
		return (-temp);
	}
}

void SysTick_Int_Init(void) {
	SYSTICK_CURRENT = 0;
	SYSTICK_RELOAD = 72000;
	SYSTICK_CSR|=0x07;
}
void SysTick_Handler(void) {   
	SYSTICK_CURRENT=0;  
	systick_ms++;
}

u32 millis(void) {
	return systick_ms;
}

void TIM1_Int_Init(u16 arr,u16 psc) {
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;  
	NVIC_InitTypeDef NVIC_InitStructure;  

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); //时钟使能  

	TIM_TimeBaseStructure.TIM_Period = arr; //设置自动重装载寄存器周期值  
	TIM_TimeBaseStructure.TIM_Prescaler =(psc-1);//设置预分频值  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割  
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//向上计数模式  
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;//重复计数设置  
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //参数初始化  
	TIM_ClearFlag(TIM1, TIM_FLAG_Update);//清中断标志位  

	TIM_ITConfig(      //使能或者失能指定的TIM中断  
	TIM1,            //TIM1  
	TIM_IT_Update  | //TIM 更新中断源  
	TIM_IT_Trigger,  //TIM 触发中断源   
	ENABLE           //使能  
	);  
	  
	//设置优先级  
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;    
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//先占优先级0级  
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;       //从优先级0级  
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  
	NVIC_Init(&NVIC_InitStructure);   

	TIM_Cmd(TIM1, ENABLE);  //使能TIMx外设 
}


void TIM2_Int_Init(u16 arr,u16 psc) {
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //①时钟 TIM2 使能	
	//定时器 TIM2 初始化
	TIM_TimeBaseStructure.TIM_Period = arr; //设置自动重装载寄存器周期的值
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM 向上计数
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);  //②初始化 TIM2
	TIM_ARRPreloadConfig(TIM2, DISABLE);
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE );  //③允许更新中断
	
	//中断优先级 NVIC 设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //TIM2 中断
	//NVIC_SetVectorTable(NVIC_VectTab_FLASH,0x0000);
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; //先占优先级 0 级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  //从优先级 2 级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  //IRQ 通道被使能
	NVIC_Init(&NVIC_InitStructure);  //④初始化 NVIC 寄存器
	TIM_Cmd(TIM2, ENABLE);  //⑤使能 TIM2
}

void TIM3_Int_Init(u16 arr,u16 psc) {
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //①时钟 TIM3 使能	
	//定时器 TIM3 初始化
	TIM_TimeBaseStructure.TIM_Period = arr; //设置自动重装载寄存器周期的值
	TIM_TimeBaseStructure.TIM_Prescaler = psc; //设置时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM 向上计数
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);  //②初始化 TIM3
	TIM_ARRPreloadConfig(TIM3, DISABLE);
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE );  //③允许更新中断
	
	//中断优先级 NVIC 设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3 中断
	//NVIC_SetVectorTable(NVIC_VectTab_FLASH,0x0000);
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3; //先占优先级 0 级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  //从优先级 3 级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  //IRQ 通道被使能
	NVIC_Init(&NVIC_InitStructure);  //④初始化 NVIC 寄存器
	TIM_Cmd(TIM3, ENABLE);  //⑤使能 TIM3
}


void TIM3_Pwm_Init(u16 arr,u16 psc)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;   //对应CH3通道PB0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure); 
	
	TIM_TimeBaseStructure.TIM_Period = arr;  
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); 

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;  
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  
	TIM_OCInitStructure.TIM_Pulse=500; 
	
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);        
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);

	TIM_OC4Init(TIM3, &TIM_OCInitStructure);        
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable); 

	TIM_Cmd(TIM3, ENABLE);  

}

void TIM4_Pwm_Init(u16 arr,u16 psc) {  
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;   //对应CH3通道PB0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure); 
	
	TIM_TimeBaseStructure.TIM_Period = arr;  
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); 

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;  
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  
	TIM_OCInitStructure.TIM_Pulse=500; 
	
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);        
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_OC4Init(TIM4, &TIM_OCInitStructure);        
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable); 

	TIM_Cmd(TIM4, ENABLE);  
}

//void TIM1_UP_IRQHandler(void) {
//	if (TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET) //检查 TIM1 更新中断发生与否
//	{
//		TIM_ClearITPendingBit(TIM1, TIM_IT_Update); //清除 TIM1 更新中断标志
//		//systick_ms++;
//	}
//}

float abs_float(float value) {
	if(value>0) {
		return value;
	}
	return (-value);
}

void duoji_inc_handle(u8 index) {	
	int aim_temp;
	
	if(duoji_doing[index].inc != 0) {
		
		aim_temp = duoji_doing[index].aim;
		
		if(aim_temp > 2490){
			aim_temp = 2490;
		} else if(aim_temp < 500) {
			aim_temp = 500;
		}
	
		if(abs_float(aim_temp - duoji_doing[index].cur) <= abs_float(duoji_doing[index].inc + duoji_doing[index].inc)) {
			duoji_doing[index].cur = aim_temp;
			duoji_doing[index].inc = 0;
		} else {
			duoji_doing[index].cur += duoji_doing[index].inc;
		}
	}
}

void TIM2_IRQHandler(void) {
	static u8 flag = 0;
	static u8 duoji_index1 = 0;
	int temp;
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) //检查 TIM2 更新中断发生与否
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update ); //清除 TIM2 更新中断标志
		
		if(duoji_index1 == 8) {
			duoji_index1 = 0;
		}
		
		if(flag == 0) {
			TIM2->ARR = ((unsigned int)(duoji_doing[duoji_index1].cur));
			dj_io_set(duoji_index1, 1);	
			duoji_inc_handle(duoji_index1);
		} else {
			temp = 2500 - (unsigned int)(duoji_doing[duoji_index1].cur);
			TIM2->ARR = temp;
			dj_io_set(duoji_index1, 0);
			duoji_index1 ++;
		}
		flag = !flag;
	}
} 

void TIM3_IRQHandler(void) {
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) //检查 TIM3 更新中断发生与否
	{
		TIM_ClearITPendingBit(TIM3 , TIM_IT_Update);
	}
}



/***********************************************
	函数名称：timer1_ir_init(arr,psc) 
	功能介绍：初始化定时器1
	函数参数：arr：计数值 psc：分频值
	返回值：	无
 ***********************************************/
void timer1_ir_init(u16 arr,u16 psc)		
{
	TIM_ICInitTypeDef  TIM_ICInitStructure;
	TIM_TimeBaseInitTypeDef	TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_TIM1, ENABLE );

	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel        				= TIM1_CC_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority 	= 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority       	= 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd               	= ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel        				= TIM1_UP_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority 	= 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority       	= 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd               	= ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_TimeBaseInitStructure.TIM_Period        = arr; 
	TIM_TimeBaseInitStructure.TIM_Prescaler     = psc; 
	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseInitStructure.TIM_CounterMode   = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);

	TIM_ICInitStructure.TIM_Channel     = TIM_Channel_1;
	TIM_ICInitStructure.TIM_ICPolarity  = TIM_ICPolarity_Falling;
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInitStructure.TIM_ICFilter    = 0x0;
	TIM_ICInit(TIM1, &TIM_ICInitStructure);
	
	TIM_ClearFlag(TIM1, TIM_FLAG_Update);
	TIM_ClearFlag(TIM1, TIM_FLAG_CC1);
	TIM_ITConfig(TIM1, TIM_IT_CC1,ENABLE);

	TIM_Cmd(TIM1, ENABLE);
}

/***********************************************
	函数名称：	TIM1_UP_IRQHandler() 
	功能介绍：	定时器1溢出中断 判断是否再无重复码
	函数参数：	无
	返回值：		无
 ***********************************************/
void TIM1_UP_IRQHandler(void) {
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET) {
		TIM_ClearFlag(TIM1, TIM_FLAG_Update);
		if(ir_time_flag<2)  
			ir_time_flag++;
		else {
			if(ir_data_count>31){
				ir_start=0;
				ir_start_flag=0;
				ir_repeat=0;
				ir_repeat_flag=0;
				ir_end_flag=0;
				ir_time_flag=0;
				ir_data_count=0;
				Timeout_OFF();
			}
		}
	}
}

/***********************************************
	函数名称：	TIM1_CC_IRQHandler() 
	功能介绍：	定时器1捕获中断 接收红外遥控器数据
	函数参数：	无
	返回值：		无
 ***********************************************/
void TIM1_CC_IRQHandler(void) {
	static u32 ir_data_buf=0;
	static u16 ir_low_time=0,ir_high_time=0,ir_period_time=0;
	if (TIM_GetITStatus(TIM1, TIM_IT_CC1) == SET ) {
		TIM_ClearFlag(TIM1, TIM_FLAG_CC1);
		if(ir_start_flag==0) {
			if(ir_start==0) {
				TIM_SetCounter(TIM1,0);
				CCP_Rising();
				ir_start=1;
			}
			else if(ir_start==1) {
				ir_low_time = TIM_GetCapture1(TIM1);
				TIM_SetCounter(TIM1,0);
				CCP_Falling();
				if(ir_low_time>8000&&ir_low_time<10000)
					ir_start=2;
				else
					ir_start=0;
			}
			else if(ir_start==2) {
				ir_high_time = TIM_GetCapture1(TIM1);
				TIM_SetCounter(TIM1,0);
				if(ir_high_time>3500&&ir_high_time<5500)
					ir_start_flag=1;
				else
					ir_start=0;
			}
		}		
		else {
			if(ir_data_count<32) {
				ir_period_time = TIM_GetCapture1(TIM1);
				TIM_SetCounter(TIM1,0);
				if (ir_period_time<1000&&ir_period_time>2400) {
					ir_start=0;
					ir_start_flag=0;
					ir_data_count=0;
				}
				else {
					ir_data_buf <<= 1;
					if (ir_period_time>1700)
						ir_data_buf |= 0x01;
					ir_data_count++;
					if(ir_data_count==32) {
						ir_data[0] = (ir_data_buf>>24) &0xff;
						ir_data[1] = (ir_data_buf>>16) &0xff;
						ir_data[2] = (ir_data_buf>>8)  &0xff;
						ir_data[3] = ir_data_buf 	   &0xff;
						if(ir_data[2]+ir_data[3]!=0xff) {
							ir_start=0;
							ir_start_flag=0;
							ir_data_count=0;
						}
					}
				}
			}
			else {
				if(ir_repeat==0) {
					ir_low_time = TIM_GetCapture1(TIM1);
					TIM_SetCounter(TIM1,0);
					CCP_Rising();
					ir_flag=1;
					ir_time_flag=0;
					ir_repeat=1;
				}
				else if(ir_repeat==1) {
					ir_low_time = TIM_GetCapture1(TIM1);
					TIM_SetCounter(TIM1,0);
					CCP_Falling();
					if(ir_low_time>8000&&ir_low_time<10000)
						ir_repeat=2;
					else {
						ir_repeat=0;
						ir_end_flag=1;
					}
				}
				else if(ir_repeat==2) {
					ir_high_time = TIM_GetCapture1(TIM1);
					TIM_SetCounter(TIM1,0);
					if(ir_high_time>1700&&ir_high_time<2400) {
						CCP_Rising();
						ir_repeat=3;
					}
					else {
						ir_repeat=0;
						ir_end_flag=1;
					}
				}
				else if(ir_repeat==3) {
					ir_low_time = TIM_GetCapture1(TIM1);
					TIM_SetCounter(TIM1,0);
					CCP_Falling();
					if(ir_low_time>500&&ir_low_time<650) {
						ir_repeat_flag=1;
					} else {
						ir_end_flag=1;
					}
					ir_repeat=0;
				}
				if(ir_repeat_flag) {
					ir_repeat_flag=0;
					ir_time_flag=0;
					Timeout_ON();
				}
				if(ir_end_flag) {
					ir_start=0;
					ir_start_flag=0;
					ir_repeat=0;
					ir_repeat_flag=0;
					ir_end_flag=0;
					ir_time_flag=0;
					ir_data_count=0;
				}
			}			
		}
	}
}
