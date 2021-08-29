#include <stdio.h>
#include <string.h>
#include "z_adc.h"
#include "z_global.h"
#include "z_gpio.h"
#include "z_timer.h"
#include "z_usart.h"
#include "z_main.h"
#include "z_delay.h"
#include "z_sensor.h"



/*自定义变量*/
extern _Bool go_stright_flag;
extern int state;
char class_name='A';


int color_red_base, color_grn_base, color_blu_base;
static u8 flagSoundStart=0;
COLOR_RGBC color_rgbc;
COLOR_HSL color_hsl;

u8 ir_data[4],ir_flag;

_Bool zhixing_flag;

/*car_zhixing_set车直行设置*/
//2->8,3->9,4->10,5->11
char forward_com[]="{#012P1150T1000!#013P1850T1000!#014P1150T1000!#015P1950T1000!}";
char backward_com[]="{#012P1300T0200!#013P1700T0200!#014P1700T0200!#015P1300T0200!}";
char stop_com[]="{#012P1500T0500!#013P1500T0500!#014P1500T0500!#015P1500T0500!}";





/*
	智能功能代码
*/

 // 循迹 左 A0 右 A1  
void setup_xunji(void) {
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
}

//
void setup_csb() {
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE);  
	
	//初始化超声波IO口 Trig PB0  Echo PA2
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	GPIO_Init(GPIOB, &GPIO_InitStructure); 	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;   
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  
	GPIO_Init(GPIOA, &GPIO_InitStructure); 	
	
	//初始化超声波定时器
	TIM3_Int_Init(30000, 71);
}

//声音PB14  - TODO
void setup_sound() {
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);  
	
	//sound
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;   
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   
	GPIO_Init(GPIOB, &GPIO_InitStructure); 
}

//灰度传感器 PA1 AD
void setup_yssb() {
	TCS34725_Init(TCS34725_INTEGRATIONTIME_24MS);
}


/***********************************************
	函数名称：	setup_ir() 
	功能介绍：	初始化红外遥控器
	函数参数：	无
	返回值：		无
 ***********************************************/
void setup_ir(void) {
	timer1_ir_init(65535,71);
}

//初始化传感器IO口
void setup_sensor(void) {
//	setup_xunji();	//初始化循迹
//	setup_sound();	//初始化声音
	setup_csb();	//初始化超声波
//	setup_yssb();	//初始化颜色识别
//	setup_ir();		//初始化红外遥控器
}

/***********************************************
	函数名称：	loop_ir() 
	功能介绍：	红外遥控器按键功能函数
	函数参数：	无
	返回值：	无
 ***********************************************/
void loop_ir(void)
{
	if(ir_flag) {
		switch(ir_data[2]) {
			case IR_POWER : 
				uart1_send_str((u8 *)"IR_POWER is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_MENU : 
				uart1_send_str((u8 *)"IR_MENU is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_MUTE : 
				uart1_send_str((u8 *)"IR_MUTE is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_ADD : 
				uart1_send_str((u8 *)"IR_ADD is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_SUBTRACT : 
				uart1_send_str((u8 *)"IR_SUBTRACT is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_FORWARD : 
				uart1_send_str((u8 *)"IR_FORWARD is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_BACKWARD : 
				uart1_send_str((u8 *)"IR_BACKWARD is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_SUSPEND : 
				uart1_send_str((u8 *)"IR_SUSPEND is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_MODE : 
				uart1_send_str((u8 *)"IR_MODE is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_BACK : 
				uart1_send_str((u8 *)"IR_BACK is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_OK : 
				uart1_send_str((u8 *)"IR_OK is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_0 : 
				uart1_send_str((u8 *)"IR_0 is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_1 : 
				uart1_send_str((u8 *)"IR_1 is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_2 : 
				uart1_send_str((u8 *)"IR_2 is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_3 : 
				uart1_send_str((u8 *)"IR_3 is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_4 : 
				uart1_send_str((u8 *)"IR_4 is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_5 : 
				uart1_send_str((u8 *)"IR_5 is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_6 : 
				uart1_send_str((u8 *)"IR_6 is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_7 : 
				uart1_send_str((u8 *)"IR_7 is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_8 : 
				uart1_send_str((u8 *)"IR_8 is pressed!\r\n");beep_on_times(1,100);
				break;
			case IR_9 : 
				uart1_send_str((u8 *)"IR_9 is pressed!\r\n");beep_on_times(1,100);
				break;
		}
		ir_flag=0;
		memset(ir_data, 0, sizeof(ir_data));	
	}
}

//处理智能传感器功能
void loop_sensor(void) {
	static u8 AI_mode_bak;
	
	if(AI_mode == 0) {
		AI_xunji_moshi();				//循迹模式
	} else if(AI_mode == 1) {
		AI_shengkong_jiaqu();			//声控夹取
	} else if(AI_mode == 2) {
		AI_ziyou_bizhang();				//自由避障
	} else if(AI_mode == 3) {
		AI_yanse_shibie();				//颜色识别
	} else if(AI_mode == 4) {
		AI_dingju_jiaqu();				//定距夹取
	} else if(AI_mode == 5) {
		AI_gensui_moshi();				//跟随功能
	} else if(AI_mode == 6) {
		AI_xunji_bizhang();				//循迹避障
	} else if(AI_mode == 7) {
		AI_xunji_shibie();				//循迹识别
	} else if(AI_mode == 8) {
		AI_xunji_dingju();				//循迹定距
	} else if(AI_mode == 9) {	
		AI_shengkong_xunji();			//声控循迹
	} else if(AI_mode == 10) {
		AI_mode = 255;
	}
	
	if(AI_mode_bak != AI_mode) {
		car_set(0, 0);
		AI_mode_bak = AI_mode;
		flagSoundStart=0;
		group_do_ok = 1;
	}

	loop_ir();	
}


/*************************************************************
函数名称：get_adc_yssb_middle()
功能介绍：获取灰度传感器采集到的值并返回
函数参数：无
返回值：  采集的数据  
*************************************************************/
int get_adc_yssb_middle() {//读取AD值，排序，并返回中间值
	TCS34725_GetRawData(&color_rgbc);
	sprintf((char *)cmd_return, "R=%d G=%d B=%d C=%d\r\n",color_rgbc.r,color_rgbc.g,color_rgbc.b,color_rgbc.c);
	uart1_send_str(cmd_return);

	RGBtoHSL(&color_rgbc,&color_hsl);
	sprintf((char *)cmd_return, "H=%d S=%d L=%d\r\n",color_hsl.h,color_hsl.s,color_hsl.l);
	uart1_send_str(cmd_return);
	
	return 0;
}

void csb_Delay_Us(uint16_t time)  //延时函数
{ 
	uint16_t i,j;
	for(i=0;i<time;i++)
  		for(j=0;j<9;j++);
}
/*************************************************************
函数名称：get_csb_value()
功能介绍：采集超声波数据
函数参数：无
返回值：  采集的数据  
*************************************************************/
u16 get_csb_value(void) {
	u16 csb_t;
	Trig(1);
	csb_Delay_Us(20);
	Trig(0);
	while(Echo() == 0);      //等待接收口高电平输出
	TIM_SetCounter(TIM3,0);//清除计数
	TIM_Cmd(TIM3, ENABLE);  //使能TIMx外设
	while(Echo() == 1);
	TIM_Cmd(TIM3, DISABLE);  //使能TIMx外设      
	csb_t = TIM_GetCounter(TIM3);//获取时间,分辨率为1US
	//340m/s = 0.017cm/us
	if(csb_t < 25000) {
//		sprintf((char *)cmd_return, "csb_time=%d\r\n", (int)(csb_t*0.17));
//		uart1_send_str(cmd_return);
		csb_t = csb_t*0.017;
		return csb_t;
	}
	return 0;
}
/*************************************************************
函数名称：get_adc_csb_middle()
功能介绍：处理超声波采集到的数据，取采集到的中间值
函数参数：无
返回值：  处理后的超声波数据  
*************************************************************/
int get_adc_csb_middle() {
	u8 i;
	static int ad_value[5] = {0}, myvalue;// ad_value_bak[5] = {0}, 
	for(i=0;i<5;i++)ad_value[i] = get_csb_value();
	selection_sort(ad_value, 5);
	myvalue = ad_value[2];
// 	for(i=0;i<5;i++)ad_value[i] = ad_value_bak[i];
	return myvalue;  
}

/*************************************************************
函数名称：AI_xunji_moshi()
功能介绍：实现循迹功能
函数参数：无
返回值：  无  
*************************************************************/
void AI_xunji_moshi(void) {
	static u32 systick_ms_bak = 0;
	int speed = 500;
	
	if(millis() - systick_ms_bak < 100) return;
	systick_ms_bak = millis();
	
	if((xj0() == XJ_OFF) && (xj1() == XJ_ON)) {
		car_set(0, speed+200);
	} else if((xj0() == XJ_ON) && (xj1() == XJ_ON)) {
		car_set(speed, speed);
	} else if((xj0() == XJ_ON) && (xj1() == XJ_OFF)) {
		
		car_set(speed+200, 0);
	} 
}
/*************************************************************
函数名称：AI_xunji_bizhang()
功能介绍：在循迹的过程中，检测有障碍物，则停止，否则继续循迹
函数参数：无
返回值：  无  
*************************************************************/
void AI_xunji_bizhang(void) {
	static u32 systick_ms_bak = 0;
	int adc_csb;
	
	if(millis() - systick_ms_bak > 100) {
		systick_ms_bak = millis();
		//避障处理
		adc_csb = get_adc_csb_middle();//获取a0的ad值，计算出距离
		//sprintf((char *)uart_receive_buf, "adc_csb = %d\r\n", adc_csb);
		//uart1_send_str(uart_receive_buf);
		if(adc_csb < 30) {//距离低于30mm就停止
			car_set(0, 0);
		} else {
			//循迹处理
			AI_xunji_moshi();
		}
	}
}

/*************************************************************
函数名称：AI_gensui_moshi()
功能介绍：检测物体距离，在一定距离内实现跟随功能
函数参数：无
返回值：  无  
*************************************************************/
void AI_gensui_moshi(void) {
	static u32 systick_ms_bak = 0;
	int speed = 450, adc_csb;
	if(millis() - systick_ms_bak > 100) {
		systick_ms_bak = millis();
		adc_csb = get_adc_csb_middle();//获取a0的ad值，计算出距离
		//sprintf((char *)uart_receive_buf, "adc_csb = %d\r\n", adc_csb);
		//uart1_send_str(uart_receive_buf);
		if((adc_csb > 30) && (adc_csb < 50)) {//距离30~50cm前进
			car_set(speed, speed);
		} else if(adc_csb < 20) {//距离低于20cm就后退
			car_set(-speed, -speed);
		} else {//其他情况停止
			car_set(0, 0);
		}
	}
}
/*************************************************************
函数名称：AI_ziyou_bizhang()
功能介绍：识别物体距离从而避开物体前进
函数参数：无
返回值：  无  
*************************************************************/
void AI_ziyou_bizhang(void) {
	static u32 systick_ms_bak = 0;
	int speed = 500, adc_csb;
	if(millis() - systick_ms_bak > 100) {
		systick_ms_bak = millis();
		adc_csb = get_adc_csb_middle();//获取a0的ad值，计算出距离
		//sprintf((char *)uart_receive_buf, "adc_csb = %d\r\n", adc_csb);
		//uart1_send_str(uart_receive_buf);
		if(adc_csb < 30) {//距离低于50cm就右转
			car_set(speed+200, -speed-200);
		} else {
			car_set(speed, speed);
		}
	}
}
/*************************************************************
函数名称：AI_dingju_jiaqu()
功能介绍：识别物体距离夹取物体
函数参数：无
返回值：  无  
*************************************************************/
void AI_dingju_jiaqu(void) {
	static u32 systick_ms_bak = 0;
	static u8 str[20];
	int adc_csb;
	if(group_do_ok == 0)return;

	//每20ms计算一次
	if(millis() - systick_ms_bak > 100) {
		systick_ms_bak = millis();
		adc_csb = get_adc_csb_middle();//获取a0的ad值，计算出距离
		zx_uart_send_str((u8 *)"\r\nsensor_read:");

		sprintf((char *)str, "%d\r\n", adc_csb);
		zx_uart_send_str(str);

		uart1_send_str((u8*)str);
		if(adc_csb>70&&state==2)
		{
			zx_uart_send_str((u8*)forward_com);
		}
		else if(adc_csb<=70&&adc_csb>60&&state==2)
		{
			state=3;
			uart1_send_str((u8 *)"Con!C*");
			uart3_send_str((u8 *)"Con!C*");
			beep_on();mdelay(50);beep_off();
		}
		else if(adc_csb<=60&&state==2)
		{
			state=4;
		}
		if(state==4&&adc_csb>20)
			{
				zx_uart_send_str((u8*)forward_com);
			}
		else if(state==4&&adc_csb<=20)
		{
			zx_uart_send_str((u8*)stop_com);
			beep_on_times(1, 100);
			zx_uart_send_str((u8 *)"\r\nsensor_read:");
			sprintf((char *)str, "%d\r\n", adc_csb);
			zx_uart_send_str(str);
//			if(class_name=='A')
//			{
//				parse_cmd((u8 *)"$DGT:0-10,1!");//执行录入的第一个动作，放入右边框
//			}
//		  if(class_name=='B')
//			{
//				parse_cmd((u8 *)"$DGT:0-10,1!");//执行录入的第二个动作，放入左边框
//			}
			parse_cmd((u8 *)"$DGT:0-10,1!");//执行录入的第一个动作，放入右边框
			state=5;
		} 
	}
}
void AI_shengkong_jiaqu(void) {
	static u8 placeLeft = 0;
	
	if(group_do_ok == 0)return;//有动作执行，直接返回
	if(sound() == 0) {
		while(sound() == 0);
		if(placeLeft){
			parse_cmd((u8 *)"$DGT:19-27,1!");
			beep_on_times(1, 100);
		} else {
			parse_cmd((u8 *)"$DGT:28-36,1!");
			beep_on_times(2, 100);
		}
		placeLeft = !placeLeft;
	}
	
}
/*************************************************************
函数名称：AI_yanse_shibie()
功能介绍：识别木块颜色，夹取分别放到不同位置
函数参数：无
返回值：  无  
******************************************************** *****/
void AI_yanse_shibie() {
	static u32 systick_ms_yanse = 0;
  
  if (group_do_ok && millis() - systick_ms_yanse > 20) {
      systick_ms_yanse = millis();
		  TCS34725_GetRawData(&color_rgbc);//获取RGB
    	YSSB_LED(0);//关闭LED
    if (color_rgbc.c < 1) {
			sprintf((char *)cmd_return, "R=%d G=%d B=%d C=%d\r\n",color_rgbc.r,color_rgbc.g,color_rgbc.b,color_rgbc.c);
	    uart1_send_str(cmd_return);
			  car_set(0,0);
      	YSSB_LED(1);//打开LED
        tb_delay_ms(800);
        TCS34725_GetRawData(&color_rgbc);//获取RGB			
      if (color_rgbc.r > color_rgbc.g && color_rgbc.r  > color_rgbc.b ) {
        	car_set(0,0);
        	parse_cmd("$DGT:12-18,1!"); //执行脱机存储动作组

      } else if (color_rgbc.g > color_rgbc.r && color_rgbc.g  > color_rgbc.b) {
        	car_set(0,0);
        	parse_cmd("$DGT:19-27,1!"); //执行脱机存储动作组
				
      } else if (color_rgbc.b > color_rgbc.g && color_rgbc.b  > color_rgbc.r) {
        	car_set(0,0);
        	parse_cmd("$DGT:28-36,1!"); //执行脱机存储动作组
      }

    }

  }
}
/*void AI_yanse_shibie(void) {
	static u8 i;
	static u32 systick_ms_bak = 0, systick_ms_bak2 = 0;
	static int adc_yssb;
	
	//配合打印测试
	if((millis() - systick_ms_bak2 < 100) ) return;
	systick_ms_bak2 = millis();
	
	YSSB_LED(0);//关闭LED
	TCS34725_GetRawData(&color_rgbc);//获取RGB
	//RGBtoHSL(&color_rgbc,&color_hsl);//转化HSL
	
	//打印测试                                                                                                                                     
	sprintf((char *)cmd_return, "R=%d G=%d B=%d C=%d\r\n",color_rgbc.r,color_rgbc.g,color_rgbc.b,color_rgbc.c);
	uart1_send_str(cmd_return);
	sprintf((char *)cmd_return, "H=%d S=%d L=%d\r\n",color_hsl.h,color_hsl.s,color_hsl.l);
	uart1_send_str(cmd_return);
	
	//每100ms识别一次
	if((millis() - systick_ms_bak > 100) && group_do_ok && color_rgbc.c < 3) {
		systick_ms_bak = millis();
		
		YSSB_LED(1);//打开LED
		mdelay(1000);
		TCS34725_GetRawData(&color_rgbc);//获取RGB
		RGBtoHSL(&color_rgbc,&color_hsl);//转化HSL
		
		//打印测试
		sprintf((char *)cmd_return, "R=%d G=%d B=%d C=%d\r\n",color_rgbc.r,color_rgbc.g,color_rgbc.b,color_rgbc.c);
		uart1_send_str(cmd_return);
		sprintf((char *)cmd_return, "H=%d S=%d L=%d\r\n",color_hsl.h,color_hsl.s,color_hsl.l);
		uart1_send_str(cmd_return);
		
		return;
		
		//策略判断
		if((adc_yssb>color_red_base-10) && (adc_yssb<color_red_base+10)) {
			//RED
				//uart1_send_str("RED");
				car_set(0,0);
				beep_on_times(1, 100);
				parse_cmd((u8 *)"$DGT:12-18,1!");

		} else if((adc_yssb>color_grn_base-10) && (adc_yssb<color_grn_base+10)) {
			//GRN
			for(i=0;i<5;i++) {
				adc_yssb = get_adc_yssb_middle();
				mdelay(20);
			}
			if((adc_yssb>color_grn_base-10) && (adc_yssb<color_grn_base+10)) {
				//uart1_send_str("GRN");
				car_set(0,0);
				beep_on_times(1, 100);
				parse_cmd((u8 *)"$DGT:19-27,1!");
			}
		} else if((adc_yssb>color_blu_base-10) && (adc_yssb<color_blu_base+10)) {
			//BLU
			for(i=0;i<5;i++) {
				adc_yssb = get_adc_yssb_middle();
				mdelay(20);
			}
			if((adc_yssb>color_blu_base-10) && (adc_yssb<color_blu_base+10)) {
				//uart1_send_str("BLU");
				car_set(0,0);
				beep_on_times(1, 100);
				parse_cmd((u8 *)"$DGT:28-36,1!");
			}
		}  
	}	
}
*/
/*************************************************************
函数名称：AI_xunji_dingju()
功能介绍：在循迹的过程中实现定距夹取功能
函数参数：无
返回值：  无  
*************************************************************/
void AI_xunji_dingju() {
	if(group_do_ok == 1) {
		AI_xunji_moshi();
	}
	AI_dingju_jiaqu();
}
/*************************************************************
函数名称：AI_xunji_shibie()
功能介绍：在循迹的过程中实现颜色识别功能，并将颜色模块移开
函数参数：无
返回值：  无  
*************************************************************/
void AI_xunji_shibie(void) {	
	if(group_do_ok == 1) {
		AI_xunji_moshi();
	}
	AI_yanse_shibie();
}

/*************************************************************
函数名称：AI_shengkong_xunji()
功能介绍：声控循迹函数
函数参数：无
返回值：  无  
*************************************************************/
void AI_shengkong_xunji(void) {
	
	if(sound() == 0) {
		while(sound() == 0);
		flagSoundStart=1;
	}
	
	if(flagSoundStart) {
		AI_xunji_moshi();
	}
}

