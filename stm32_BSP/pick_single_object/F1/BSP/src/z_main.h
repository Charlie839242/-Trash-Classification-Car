#ifndef __MAIN_H__
#define __MAIN_H__

#include "stm32f10x_conf.h"
#include "z_kinematics.h"	//逆运动学算法


/*
	宏定义数据
*/
#define VERSION				  20180705	//版本定义
#define ACTION_USE_ROM	0			//1:动作组使用内部数组动作组	0:动作组使用上位机下载动作组
#define CYCLE 				  1000		//PWM模块周期
#define PS2_LED_RED  		0x73		//PS2手柄红灯模式
#define PS2_LED_GRN  		0x41		//PS2手柄绿灯模式
#define PSX_BUTTON_NUM 	16			//手柄按键数目
#define PS2_MAX_LEN 		64			//手柄命令最大字节数
#define FLAG_VERIFY 		0x25		//校验标志
#define ACTION_SIZE 		0x80		//一个动作的存储大小


#define W25Q64_INFO_ADDR_SAVE_STR			(((8<<10)-2)<<10)  //(8*1024-1)*1024		//eeprom_info结构体存储的位置

/*
	初始化函数声明
*/

void setup_rcc(void);     //初始化时钟
void setup_global(void);  //初始化全局变量		
void setup_gpio(void);    //初始化IO口			
void setup_nled(void);    //初始化工作指示灯
void setup_beep(void);	  //初始化蜂鸣器		
void setup_djio(void);	  //初始化舵机IO口
void setup_w25q64(void);	//初始化存储器W25Q64
void setup_ps2(void);      //初始化PS2手柄
void setup_dj_timer(void); //初始化定时器2 处理舵机PWM输出
void setup_car_pwm(void);	//初始化电机PWM定时
void setup_uart1(void);	  //初始化串口1
void setup_uart2(void);	  //初始化串口2
void setup_uart3(void);	  //初始化串口3
void setup_systick(void);	//初始化滴答时钟，1S增加一次systick_ms的值
void setup_start(void);		//初始化启动信号
void setup_others(void);  //初始化其他
void setup_interrupt(void);//初始化总中断
/*
	主循环函数声明
*/
void loop_nled(void);	        //循环执行工作指示灯，500ms跳动一次	
void loop_uart(void);	        //串口数据接收处理
void loop_action(void);	        //动作组批量执行
void loop_bt_once(void);	    //蓝牙修改波特率和名称	
void loop_ps2_data(void);	    //循环读取PS2手柄数据
void loop_ps2_button(void);	    //处理手柄上的按钮
void loop_ps2_car(void);    //处理小车电机摇杆控制
void loop_monitor(void); 		//定时保存一些变量
void loop_vol_warning(void);    //处理低压报警
void loop_inc(void);			//循环处理增量


void soft_reset(void);					               //软件复位
void car_set(int car_left, int car_right); //电机控制函数
void parse_psx_buf(u8 *buf, u8 mode);     	   //手柄按键解析子函数
void parse_cmd(u8 *cmd);			            	   //命令解析
void save_action(u8 *str);			             	 //动作保存函数
int  get_action_index(u8 *str);			           //获取动作组序号
void print_group(int start, int end);	         //打印动作组
void int_exchange(int *int1, int *int2);	     //两个int互换
void do_group_once(int group_num); 		         //执行动作组1次
void parse_action(u8 *uart_receive_buf);			     //执行动作
void replace_char(u8*str, u8 ch1, u8 ch2);		 //字符串字母替换
void rewrite_eeprom(void);						         //写入eeprom_info结构体
void duoji_inc_handle(u8 index);					//处理舵机增量
int getMaxTime(u8 *str);
void set_servo(int index, int pwm, int time);	//设置舵机角度
int kinematics_move(float x, float y, float z, int time);//逆运动学转动


#endif

