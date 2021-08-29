/***************************************************************
	@笔者：tacbo
	@日期：2017年11月08日
	@所属：杭州众灵科技有限公司
	@功能：实现舵机控制器功能
	功能列表：
	1、单个舵机控制（支持PWM舵机和总线舵机）
	2、多个舵机控制（支持PWM舵机和总线舵机）
	3、手柄控制舵机
	4、串口控制舵机
	5、OLED显示舵机的执行情况
	6、USB一键下载
	7、可支持总线MP3 总线WIFI等设备
	8、上位机图形化编程
	9、控制6自由度机械臂	

	20180621 智能版本增加功能
	所需硬件
	循迹模块 2个
	超声波模块 1个
	颜色识别模块 1个
	声音模块 1个
	木块红、蓝、绿各一个
	
	IO口分布
	循迹左 PB11
	循迹右 PA1
	超声波/颜色/声音 PA0
	
	智能识别功能（手柄绿灯模式 左边 上下左右 和 右边 上下左右）
	
	功能0 循迹模式
	功能1 声控夹取
	功能2 自由避障
	功能3 颜色识别
	功能4 定距夹取
	功能5 跟随功能
	功能6 循迹避障
	功能7 循迹识别
	功能8 循迹定距
	
	手动遥控功能
	1、手柄遥控
	2、APP遥控
	3、WIFI遥控
	
	图形化编程功能
	
	功能切换：绿灯模式下通过左边上下左右键切换功能，通过蜂鸣器的声音的响声播报功能
	
	
	修正：
	循迹左 PB6
	循迹右 PB11
	超声波 PB7 PA0
	
	超声波/颜色/声音 PA0
	
***************************************************************/

#include "z_rcc.h"			//配置时钟文件
#include "z_gpio.h"		//配置IO口文件
#include "z_global.h"	//存放全局变量
#include "z_delay.h"		//存放延时函数
#include "tb_type.h"		//存放类型定义
#include "tb_usart.h"		//存放串口功能文件
#include "tb_timer.h"		//存放定时器功能文件
				
#include "ADC.h"			  //存放ADC的
#include "PS2_SONY.h"		//存放索尼手柄
#include "w25q64.h"			//存储芯片的操作

#include <stdio.h>			//标准库文件
#include <string.h>		  //标准库文件
#include <math.h>			  //标准库文件

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

#define COLOR_RED 215	//红色基准色
#define COLOR_GRN 310	//蓝色基准色
#define COLOR_BLU 283	//绿色基准色
#define W25Q64_INFO_ADDR_SAVE_STR			(((8<<10)-2)<<10)  //(8*1024-1)*1024		//eeprom_info结构体存储的位置

/*
	初始化函数声明
*/

void setup_rcc(void);     //初始化时钟
void setup_global(void);	//初始化全局变量		
void setup_gpio(void);    //初始化IO口			
void setup_nled(void);    //初始化工作指示灯
void setup_beep(void);	  //初始化蜂鸣器		
void setup_djio(void);	  //初始化舵机IO口
void setup_sensor(void);  //初始化传感器IO口
void setup_w25q64(void);	//初始化存储器W25Q64
void setup_adc(void);	    //初始化ADC采集
void setup_ps2(void);     //初始化PS2手柄
void setup_dj_timer(void);//初始化定时器2 处理舵机PWM输出
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
void loop_nled(void);	          //循环执行工作指示灯，500ms跳动一次	
void loop_uart(void);	          //串口数据接收处理
void loop_action(void);	        //动作组批量执行
void loop_bt_once(void);	      //蓝牙修改波特率和名称	
void loop_ps2_data(void);	      //循环读取PS2手柄数据
void loop_ps2_button(void);	    //处理手柄上的按钮
void loop_ps2_car_pwm(void);    //处理小车电机摇杆控制
void loop_save_something(void); //定时保存一些变量
void loop_vol_warning(void);    //处理低压报警
void loop_smart_sensor(void);	  //处理智能传感器功能
/*
	主循环函数声明 - 子函数
*/
void smart_xunji(void); 				//循迹功能
void smart_soundjiaqu(void);	 	//静态声音识别夹取
void smart_yssbjiaqu(void);		  //静态颜色识别夹取
void smart_xunjiyanse(void);		//循迹颜色夹取
void smart_csbjiaqu(void);			//静态超声波夹取
void smart_xunjibizhang(void);	//循迹超声波避障
void smart_gensui(void);			  //超声波跟随功能
void smart_ziyoubizhang(void);	//超声波自由避障
void smart_xunjicsbjiaqu(void);	//循迹超声波夹取
void soft_reset(void);					               //软件复位
void car_pwm_set(int car_left, int car_right); //电机控制函数
void parse_psx_buf(U8 *buf, U8 mode);     	   //手柄按键解析子函数
void parse_cmd(u8 *cmd);			            	   //命令解析
void action_save(u8 *str);			             	 //动作保存函数
int get_action_index(u8 *str);			           //获取动作组序号
void print_group(int start, int end);	         //打印动作组
void int_exchange(int *int1, int *int2);	     //两个int互换
void do_group_once(int group_num); 		         //执行动作组1次
u8 check_dj_state(void);				               //获取舵机的状态
void do_action(u8 *uart_receive_buf);			     //执行动作
void replace_char(u8*str, u8 ch1, u8 ch2);		 //字符串字母替换
void rewrite_eeprom(void);						         //写入eeprom_info结构体
int abs_int(int int1);							           //取绝对值

/*
	全局变量定义
*/
int i;								    //常用的一个临时变量
u8 car_dw = 1;						//摇杆档位控制 总共3档 1档最快 3档最慢
u8 group_do_ok = 1;				//动作执行完成标志
int do_start_index;				//动作组执行 起始序号
int do_time;						  //动作组执行 执行次数
int group_num_start;			//动作组执行 起始序号
int group_num_end;				//动作组执行 终止序号
int group_num_times;			//动作组执行 起始变量
u32 dj_record_time = 1000;//学习时间默认1000

float vol_adc;						  //电池电压
u8 djBiasSaveFlag = 0;		  //偏差保存标志
u32 bias_systick_ms_bak = 0;//偏差保存标志时间
u8 smart_mode = 255;				//模式变量

u8 psx_buf[9]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}; //存储手柄的数据 	

const char *pre_cmd_set_red[PSX_BUTTON_NUM] = {//红灯模式下按键的配置			
	"<PS2_RED01:#005P0600T2000!^$DST!>",	//L2						  
	"<PS2_RED02:#005P2400T2000!^$DST!>",	//R2						  
	"<PS2_RED03:#004P0600T2000!^$DST!>",	//L1						  
	"<PS2_RED04:#004P2400T2000!^$DST!>",	//R1			
	"<PS2_RED05:#002P2400T2000!^$DST!>",	//RU						  
	"<PS2_RED06:#003P2400T2000!^$DST!>",	//RR						  
	"<PS2_RED07:#002P0600T2000!^$DST!>",	//RD						  
	"<PS2_RED08:#003P0600T2000!^$DST!>",	//RL				
	"<PS2_RED09:$DJ_RECORD_DO:1!>",			  //SE  执行1次					  
	"<PS2_RED10:$DJ_RECORD_CLEAR!>",		  //AL	清除					  
	"<PS2_RED11:$DJ_RECORD!>",				    //AR	学习					  
	"<PS2_RED12:$DJR!>",					        //ST			
	"<PS2_RED13:#001P0600T2000!^$DST!>",	//LU						  
	"<PS2_RED14:#000P0600T2000!^$DST!>",	//LR								  
	"<PS2_RED15:#001P2400T2000!^$DST!>",	//LD						  
	"<PS2_RED16:#000P2400T2000!^$DST!>",	//LL						
};

const char *pre_cmd_set_grn[PSX_BUTTON_NUM] = {//绿灯模式下按键的配置			
	"<PS2_GRN01:$!>",	                    //L2						  
	"<PS2_GRN02:$!>",	                    //R2						  
	"<PS2_GRN03:$!>",	                    //L1						  
	"<PS2_GRN04:$!>",	                    //R1			
	"<PS2_GRN05:$SMODE5!>",             	//RU						  
	"<PS2_GRN06:$SMODE8!>",	              	//RR						  
	"<PS2_GRN07:$SMODE6!>",	              	//RD						  
	"<PS2_GRN08:$SMODE7!>",	              	//RL				
	"<PS2_GRN09:$SMODE0!>>",				//SE    				  
	"<PS2_GRN10:$!>",						//AL					  
	"<PS2_GRN11:$!>",						//AR						  
	"<PS2_GRN12:$DJR!>",					//ST			
	"<PS2_GRN13:$SMODE1!>",	                //LU						  
	"<PS2_GRN14:$SMODE4!>",	                //LR								  
	"<PS2_GRN15:$SMODE2!>",	                //LD						  
	"<PS2_GRN16:$SMODE3!>",	                //LL					  
};

u8 dbt_flag = 0;

const char *action_pre_group[] = {//把上位机生成的动作组放置到单片机内部rom当中
    //动作生成数据为(可直接全选复制粘贴到程序中)：
    //偏差调节组
    "{G0000#000P1500T1000!#001P1500T1000!#002P1500T1000!#003P1500T1000!#004P1500T1000!#005P1500T1000!}",
    //直立
    "{G0001#000P1500T1500!#001P1500T1500!#002P1500T1500!#003P1500T1500!#004P1500T1500!#005P1500T0000!}",
    //蜷缩
    "{G0002#000P1500T1500!#001P2100T1500!#002P2400T1500!#003P1900T1500!#004P1500T1500!#005P1500T1500!}",
    //大前抓右放 K0001(3-11)
    "{G0003#000P1500T1000!#001P1500T1000!#002P1500T1000!#003P1500T1000!#004P1500T1000!#005P1000T1000!}",
    "{G0004#000P1500T1000!#001P1100T1000!#002P1600T1000!#003P2100T1000!#004P1500T1000!#005P1000T0000!}",
    "{G0005#000P1500T1500!#001P1100T1500!#002P1600T1000!#003P2100T1000!#004P1500T1000!#005P1900T1000!}",
    "{G0006#000P1500T1500!#001P1800T1500!#002P1800T1000!#003P2100T1000!#004P1500T1000!#005P2000T0000!}",
    "{G0007#000P0800T1500!#001P1800T1500!#002P1800T1000!#003P2100T1000!#004P1500T1000!#005P2000T0000!}",
    "{G0008#000P0800T1000!#001P1200T1000!#002P1800T1000!#003P2100T1000!#004P1500T1000!#005P2000T0000!}",
    "{G0009#000P0800T1000!#001P1200T1000!#002P1800T1000!#003P2100T1000!#004P1500T1000!#005P1000T1000!}",
    "{G0010#000P0800T1000!#001P1600T1500!#002P1800T1000!#003P2100T1000!#004P1500T1000!#005P1000T0000!}",
    "{G0011#000P1500T1500!#001P2100T1500!#002P2400T1500!#003P1900T1500!#004P1500T1500!#005P1500T1500!}",
    //前爪前放 K0002(12-18)
    "{G0012#000P1500T1000!#001P1500T1000!#002P1500T1000!#003P1500T1000!#004P1500T1000!#005P1500T1000!}",
    "{G0013#000P1500T1000!#001P1100T2000!#002P1860T1500!#003P2110T1500!#004P1500T1500!#005P1000T1500!}",
    "{G0014#000P1500T1000!#001P1100T2000!#002P1850T1000!#003P2110T1000!#004P1500T1000!#005P2000T1000!}",
    "{G0015#000P1520T1000!#001P1800T2000!#002P2000T1000!#003P2000T1000!#004P1500T1000!#005P2000T1000!}",
    "{G0016#000P1520T1000!#001P1100T2000!#002P1800T1000!#003P2000T1000!#004P1500T1000!#005P2000T1000!}",
    "{G0017#000P1520T1000!#001P1100T2000!#002P1800T1000!#003P2000T1000!#004P1500T1000!#005P1000T1000!}",
    "{G0018#000P1500T1500!#001P2100T1500!#002P2400T1500!#003P1900T1500!#004P1500T1500!#005P1500T1500!}",
    //前爪左放 K0003(19-27)
    "{G0019#000P1500T1000!#001P1500T1000!#002P1500T1000!#003P1500T1000!#004P1500T1000!#005P1500T1000!}",
    "{G0020#000P1520T1000!#001P1100T2000!#002P1860T1000!#003P2110T1500!#004P1500T1500!#005P1000T1500!}",
    "{G0021#000P1520T1000!#001P1100T2000!#002P1850T1000!#003P2110T1000!#004P1500T1000!#005P2000T1000!}",
    "{G0022#000P1520T1000!#001P1800T2000!#002P2000T1000!#003P2000T1000!#004P1500T1000!#005P2000T1000!}",
    "{G0023#000P2200T1000!#001P1800T2000!#002P2000T1000!#003P2000T1000!#004P1500T1000!#005P2000T1000!}",
    "{G0024#000P2200T1000!#001P1200T2000!#002P2000T1000!#003P2000T1000!#004P1500T1000!#005P2000T1000!}",
    "{G0025#000P2200T1000!#001P1200T2000!#002P2000T1000!#003P2000T1000!#004P1500T1000!#005P1000T1000!}",
    "{G0026#000P2200T1000!#001P1800T2000!#002P2000T1000!#003P2000T1000!#004P1500T1000!#005P1000T1000!}",
    "{G0027#000P1500T1500!#001P2100T1500!#002P2400T1500!#003P1900T1500!#004P1500T1500!#005P1500T1500!}",
    //前爪右放 K0004(28-36)
    "{G0028#000P1500T1000!#001P1500T1000!#002P1500T1000!#003P1500T1000!#004P1500T1000!#005P1500T1000!}",
    "{G0029#000P1520T1000!#001P1100T2000!#002P1860T1000!#003P2110T1500!#004P1500T1500!#005P1000T1000!}",
    "{G0030#000P1520T1000!#001P1100T2000!#002P1850T1000!#003P2110T1000!#004P1500T1000!#005P2000T1000!}",
    "{G0031#000P1520T1000!#001P1800T2000!#002P2000T1000!#003P2000T1000!#004P1500T1000!#005P2000T1000!}",
    "{G0032#000P0800T1000!#001P1800T2000!#002P2000T1000!#003P2000T1000!#004P1500T1000!#005P2000T1000!}",
    "{G0033#000P0800T1000!#001P1200T2000!#002P2000T1000!#003P2000T1000!#004P1500T1000!#005P2000T1000!}",
    "{G0034#000P0800T1000!#001P1200T2000!#002P2000T1000!#003P2000T1000!#004P1500T1000!#005P1000T1000!}",
    "{G0035#000P0800T1000!#001P1800T2000!#002P2000T1000!#003P2000T1000!#004P1500T1000!#005P1000T1000!}",
    "{G0036#000P1500T1500!#001P2100T1500!#002P2400T1500!#003P1900T1500!#004P1500T1500!#005P1500T1500!}",
};


/*-------------------------------------------------------------------------------------------------------
*  程序从这里执行				
*  这个启动代码 完成时钟配置 使用外部晶振作为STM32的运行时钟 并倍频到72M最快的执行速率
-------------------------------------------------------------------------------------------------------*/
int main(void) {	
		setup_rcc();			//初始化时钟
		setup_global();		//初始化全局变量
		setup_gpio();			//初始化IO口
		setup_nled();			//初始化工作指示灯
		setup_beep();			//初始化定时器
		setup_djio();			//初始化舵机IO口
		setup_sensor();		//初始化传感器IO口
		setup_w25q64();		//初始化存储器W25Q64
		setup_adc();			//初始化ADC采集
		setup_ps2();			//初始化PS2手柄
		setup_car_pwm();	//初始化电机PWM定时
		setup_uart1();		//初始化串口1
		setup_uart2();		//初始化串口2
		setup_uart3();		//初始化串口3
		setup_systick();	//初始化滴答时钟，1S增加一次systick_ms的值
		setup_others();		//初始化其他
		setup_dj_timer();	//初始化定时器2 处理舵机PWM输出
		setup_interrupt();//初始化总中断	
		setup_start();		//初始化启动信号
	while(1) {
		loop_nled();		       //循环执行工作指示灯，500ms跳动一次
		loop_uart();		       //串口数据接收处理
		loop_action();	       //动作组批量执行
		loop_bt_once();	       //蓝牙修改波特率和名称
		loop_ps2_data();		   //循环读取PS2手柄数据
		loop_ps2_button();		 //处理手柄上的按钮
		loop_ps2_car_pwm();		 //处理小车电机摇杆控制
		loop_save_something(); //定时保存一些变量
		//loop_vol_warning();	 //处理低压报警
		loop_smart_sensor();	 //处理智能传感器功能
		//单个测试功能的时候可以用下面这些函数，功能总控函数为 loop_smart_sensor
		//smart_xunji();			  //循迹功能
		//smart_xunjibizhang();	//循迹避障
		//smart_gensui();			  //跟随功能
		//smart_ziyoubizhang();	//自由避障
		//smart_csbjiaqu();		  //超声波夹取
		//smart_yssbjiaqu();		//颜色识别夹取
		//smart_soundjiaqu();		//声音夹取
		//smart_xunjicsbjiaqu();//循迹超声波
		//smart_xunjiyanse();		//循迹颜色
	}
}

//--------------------------------------------------------------------------------
/*
	初始化函数实现
*/

void setup_rcc(void) {   //初始化时钟
	tb_rcc_init();	  	   //时钟初始化
}

void setup_global(void) {//初始化全局变量
	tb_global_init();	
}

void setup_gpio(void) { //初始化IO口
	tb_gpio_init();		    
}

void setup_nled(void) { //初始化工作指示灯
	nled_init();		
	nled_off();		        //工作指示灯关闭
}

void setup_beep(void) { //初始化定时器蜂鸣器
	beep_init();		
	beep_off();			      //关闭蜂鸣器
}			

void setup_djio(void) { //初始化舵机IO口
	dj_io_init();		
}	

void setup_sensor(void) {//初始化传感器IO口
	sensor_init();		
}

void setup_w25q64(void) { //初始化存储器W25Q64
	W25Q_Init();				    //动作组存储芯片初始化
	if(W25Q_TYPE != W25Q64){//判断是否是W25Q64芯片
		while(1)beep_on();		//如果不是则长鸣，说明芯片有问题，无法通信
	}
	W25Q_Read((u8 *)(&eeprom_info), W25Q64_INFO_ADDR_SAVE_STR, sizeof(eeprom_info));//读取全局变量
	if(eeprom_info.version != VERSION) {//判断版本是否是当前版本
		eeprom_info.version = VERSION;		//复制当前版本
		eeprom_info.dj_record_num = 0;		//学习动作组变量赋值0
		rewrite_eeprom();					        //写入到存储器
	}
	
	if(eeprom_info.dj_bias_pwm[DJ_NUM] != FLAG_VERIFY) {
		for(i=0;i<DJ_NUM;i++) {
			eeprom_info.dj_bias_pwm[i] = 0;
		}
		eeprom_info.dj_bias_pwm[DJ_NUM] = FLAG_VERIFY;
	}
	
	for(i=0;i<DJ_NUM;i++) {
		duoji_doing[i].aim = 1500 + eeprom_info.dj_bias_pwm[i];
		duoji_doing[i].cur = 1500 + eeprom_info.dj_bias_pwm[i];
		duoji_doing[i].inc = 0;
	}
}	

void setup_adc(void) {//初始化ADC采集
	ADC_init();	
}

void setup_ps2(void) {//初始化PS2手柄
	PSX_init();	
}

void setup_dj_timer(void) {//初始化定时器2 处理舵机PWM输出
	TIM2_Int_Init(20000, 71);	
}

//初始化电机PWM定时
void setup_car_pwm(void) {
	//小车 pwm 初始化
	TIM3_Pwm_Init(1000, 239);
	TIM4_Pwm_Init(1000, 239);
	car_pwm_set(0,0);	//设置小车的左右轮速度为0
}


void setup_uart1(void) {
  //串口1初始化
	tb_usart1_init(115200);
	//串口1打开
	uart1_open();
	//串口发送测试字符
	uart1_send_str((u8 *)"uart1 check ok!");
}
//初始化串口2
void setup_uart2(void) {
	//串口2初始化
	tb_usart2_init(115200);
	//串口2打开
	uart2_open();
	//串口发送测试字符
	uart2_send_str((u8 *)"uart2 check ok!");
}	
//初始化串口3
void setup_uart3(void) {
	//串口3初始化
	tb_usart3_init(115200);
	//串口3打开
	uart3_open();
	//串口发送测试字符
	uart3_send_str((u8 *)"uart3 check ok!");
	
	//总线输出 复位总线舵机 串口3即为总线串口
	zx_uart_send_str((u8 *)"#255P1500T2000!");
}	
//初始化滴答时钟，1S增加一次systick_ms的值
void setup_systick(void) {
	//系统滴答时钟初始化	
	SysTick_Int_Init();
}	

//初始化启动信号
void setup_start(void) {
	//蜂鸣器LED 名叫闪烁 示意系统启动
	beep_on();nled_on();tb_delay_ms(100);beep_off();nled_off();tb_delay_ms(100);
	beep_on();nled_on();tb_delay_ms(100);beep_off();nled_off();tb_delay_ms(100);
	beep_on();nled_on();tb_delay_ms(100);beep_off();nled_off();tb_delay_ms(100);
}	
//初始化其他
void setup_others(void) {
	
	//机械臂蜷缩 G0002组
	memset(uart_receive_buf, 0, sizeof(uart_receive_buf));
	if(ACTION_USE_ROM) {
		//使用存储在单片机内部rom中的动作组
		strcpy((char *)uart_receive_buf, action_pre_group[2]);
	} else {
		//从存储芯片中读取第group_num个动作组
		w25x_read(uart_receive_buf, 2*ACTION_SIZE, ACTION_SIZE);	
	}
	//把读取出来的动作组传递到do_action执行
	for(i=16;i<strlen((char *)uart_receive_buf);i+=15) {
		uart_receive_buf[i] = '0';
		uart_receive_buf[i+1] = '0';
		uart_receive_buf[i+2] = '0';
		uart_receive_buf[i+3] = '0';
	}
	do_action(uart_receive_buf);
	
	//执行预存命令 {G0000#000P1500T1000!#000P1500T1000!}
	if(eeprom_info.pre_cmd[PRE_CMD_SIZE] == FLAG_VERIFY) {
		if(eeprom_info.pre_cmd[0] == '$') {
			strcpy((char *)uart_receive_buf, (char *)eeprom_info.pre_cmd);
			for(i=16;i<strlen((char *)uart_receive_buf);i+=15) {
				uart_receive_buf[i] = '0';
				uart_receive_buf[i+1] = '0';
				uart_receive_buf[i+2] = '0';
				uart_receive_buf[i+3] = '0';
			}
			do_action(uart_receive_buf);
			
		}
	}

}
//初始化总中断
void setup_interrupt(void) {
	//总中断打开
	tb_interrupt_open();
}	
//--------------------------------------------------------------------------------




//--------------------------------------------------------------------------------
/*
	主循环函数实现
*/
//循环执行工作指示灯，500ms跳动一次
void loop_nled(void) {
	static u32 time_count=0;
	static u8 flag = 0;
	if(systick_ms-time_count > 1000)  {
		time_count = systick_ms;
		if(flag) {
			nled_on();
		} else {
			nled_off();
		}
		flag= ~flag;
	}
}		
//串口数据接收处理
void loop_uart(void) {
	if(uart1_get_ok) {
		if(uart1_mode == 1) {					//命令模式
			//uart1_send_str("cmd:");
			//uart1_send_str(uart_receive_buf);
			parse_cmd(uart_receive_buf);			
		} else if(uart1_mode == 2) {			//单个舵机调试
			//uart1_send_str("sig:");
			//uart1_send_str(uart_receive_buf);
			do_action(uart_receive_buf);
		} else if(uart1_mode == 3) {		//多路舵机调试
			//uart1_send_str("group:");
			//uart1_send_str(uart_receive_buf);
			do_action(uart_receive_buf);
		} else if(uart1_mode == 4) {		//存储模式
			//uart1_send_str("save:");
			//uart1_send_str(uart_receive_buf);
			action_save(uart_receive_buf);
		} 
		uart1_mode = 0;
		uart1_get_ok = 0;
		uart1_open();
	}
	return;
}	

//动作组批量执行
void loop_action(void) {
//通过判断舵机是否全部执行完毕 并且是执行动作组group_do_ok尚未结束的情况下进入处理
	if((check_dj_state() == 0) && (group_do_ok == 0)) {
		//调用do_start_index个动作
		do_group_once(do_start_index);
		
		if(group_num_start<group_num_end) {
			if(do_start_index == group_num_end) {
				do_start_index = group_num_start;
				if(group_num_times != 0) {
					do_time--;
					if(do_time == 0) {
						group_do_ok = 1;
						uart1_send_str((u8*)"@GroupDone!");
					}
				}
				return;
			}
			do_start_index++;
		} else {
			if(do_start_index == group_num_end) {
				do_start_index = group_num_start;
				if(group_num_times != 0) {
					do_time--;
					if(do_time == 0) {
						group_do_ok = 1;
						uart1_send_str((u8*)"@GroupDone!");
					}
				}
				return;
			}
			do_start_index--;
		}
	}
}
//蓝牙修改波特率和名称
void loop_bt_once(void) {
static u8 first_change = 1, step = 0;
	static u32 systick_ms_bak = 0;
	if(first_change) {
		if((systick_ms - systick_ms_bak > 500) && (step == 0)) {
			systick_ms_bak = systick_ms;
			tb_usart2_init(9600);
			uart2_open();
			uart2_send_str((u8 *)"AT+BAUD8\r\n");
			step++;
		} else if((systick_ms - systick_ms_bak > 500) && (step == 1)){
			systick_ms_bak = systick_ms;		
			tb_usart2_init(115200);
			step++;
		}  else if((systick_ms - systick_ms_bak > 500) && (step == 2)){
			systick_ms_bak = systick_ms;		
			uart2_send_str((u8 *)"AT+SPPNAMEZL-BT2.0\r\n");
			step++;
		} else if((systick_ms - systick_ms_bak > 500) && (step == 3)){
			systick_ms_bak = systick_ms;
			uart2_send_str((u8 *)"AT+LENAMEZL-BT4.0\r\n");
			step++;
		} else if((systick_ms - systick_ms_bak > 500) && (step == 4)){
			systick_ms_bak = systick_ms;
			uart2_send_str((u8 *)"AT+NAMEZL-BT2.0\r\n");
			step++;
			first_change = 0;
		} 
	}
}		
//循环读取PS2手柄数据
void loop_ps2_data(void) {
	static u32 systick_ms_bak = 0;
	//每20ms处理1次
	if(systick_ms - systick_ms_bak < 20) {
		return;
	}
	systick_ms_bak = systick_ms;
	//读写手柄数据
	psx_write_read(psx_buf);
	
#if 0
	//测试手柄数据，1为打开 0为关闭
	sprintf((char *)cmd_return, "0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x\r\n", 
	(int)psx_buf[0], (int)psx_buf[1], (int)psx_buf[2], (int)psx_buf[3],
	(int)psx_buf[4], (int)psx_buf[5], (int)psx_buf[6], (int)psx_buf[7], (int)psx_buf[8]);
	uart1_send_str(cmd_return);
#endif 	
	
	return;
}	
//处理手柄上的按钮
void loop_ps2_button(void) {
	static unsigned char psx_button_bak[2] = {0};
	static unsigned char mode_bak;

	//处理智能模式 红灯模式下 智能模式取消，此时为遥控模式
	if(mode_bak != psx_buf[1]) {
		mode_bak = psx_buf[1];
		if(PS2_LED_RED == psx_buf[1]) {
			smart_mode = 255;
		}
		car_pwm_set(0,0);
		beep_on_times(1, 500);
	}
		
	//对比两次获取的按键值是否相同 ，相同就不处理，不相同则处理
	if((psx_button_bak[0] == psx_buf[3])
	&& (psx_button_bak[1] == psx_buf[4])) {				
	} else {		
		//处理buf3和buf4两个字节，这两个字节存储这手柄16个按键的状态
		parse_psx_buf(psx_buf+3, psx_buf[1]);
		psx_button_bak[0] = psx_buf[3];
		psx_button_bak[1] = psx_buf[4];
	}
	return;
}	
//处理小车电机摇杆控制
void loop_ps2_car_pwm(void) {
	static int car_left, car_right, car_left_bak, car_right_bak;
	
	if(psx_buf[1] != PS2_LED_RED)return;
	
	if(abs_int(127 - psx_buf[8]) < 5 )psx_buf[8] = 127;
	if(abs_int(127 - psx_buf[6]) < 5 )psx_buf[6] = 127;
	
	car_left = (127 - psx_buf[8]) * 8;
	car_right = (127 - psx_buf[6]) * 8;
		
	if(car_left != car_left_bak || car_right != car_right_bak) {
		car_pwm_set(car_left, car_right);
		car_left_bak = car_left;
		car_right_bak = car_right;
	}
}
//定时保存一些变量
void loop_save_something(void) {
	static u32 saveTime = 3000;
	if((djBiasSaveFlag == 1) && (systick_ms - bias_systick_ms_bak > saveTime)) {
		djBiasSaveFlag = 0;
		bias_systick_ms_bak = systick_ms;
		rewrite_eeprom();
	}	
	return;
}	
//处理低压报警
void loop_vol_warning(void) {
	static u32 systick_ms_bak = 0;
	if(systick_ms - systick_ms_bak < 1000)return;
	systick_ms_bak = systick_ms;
	//经过一个肖特基 有0.3V的压降
	vol_adc = ADC_ConvertedValue[0]/4096.0 * 3.3 * 4 + 0.3;
	if((vol_adc > 4.8) && (vol_adc < 7.4)) {
		beep_on();
		mdelay(100);
		beep_off();
	}
	//sprintf((char *)cmd_return, "vol:%.1f \r\n", vol_adc);
	//uart1_send_str(cmd_return);
}
//处理智能传感器功能
void loop_smart_sensor(void) {
	if(smart_mode == 0) {
		smart_xunji();				//循迹模式
	} else if(smart_mode == 1) {
		smart_soundjiaqu();	//声控夹取
	} else if(smart_mode == 2) {
		smart_ziyoubizhang();	//自由避障
	} else if(smart_mode == 3) {
		smart_yssbjiaqu();		//颜色识别
	} else if(smart_mode == 4) {
		smart_csbjiaqu();		//定距夹取
	} else if(smart_mode == 5) {
		smart_gensui();		//跟随功能
	} else if(smart_mode == 6) {
		smart_xunjibizhang();	//循迹避障
	} else if(smart_mode == 7) {
		smart_xunjiyanse();	//循迹识别
	} else if(smart_mode == 8) {
		smart_xunjicsbjiaqu();	//循迹定距
	} else if(smart_mode == 9) {
		//parse_cmd((u8 *)"$DJR!");
	}	
}

//--------------------------------------------------------------------------------

//软件复位函数，调用后单片机自动复位
void soft_reset(void) {
	__set_FAULTMASK(1);     
	NVIC_SystemReset();
}

//小车控制函数
//参数 左轮速度和右轮速度 范围 -1000 到 1000
void car_pwm_set(int car_left, int car_right) {
	
	if(car_left >= CYCLE)car_left = CYCLE-1;
	else if(car_left <= -CYCLE)car_left = -CYCLE+1;
	else if(car_left == 0)car_left = 1;
	
	if(car_right >= CYCLE)car_right = CYCLE-1;
	else if(car_right <= -CYCLE)car_right = -CYCLE+1;
	else if(car_right == 0)car_right = 1;
	
	car_left = -car_left;
	car_right = -car_right;
	
	car_left = car_left/car_dw;
	car_right = car_right/car_dw;
	
	if(car_right>0) {
		TIM_SetCompare4(TIM4,1);
		TIM_SetCompare3(TIM4,car_right);
	} else if(car_right<0){
		TIM_SetCompare4(TIM4,-car_right);
		TIM_SetCompare3(TIM4,1);
	} else {
		TIM_SetCompare4(TIM4,CYCLE - 1);
		TIM_SetCompare3(TIM4,CYCLE - 1);
	}

	if(car_left>0) {
		TIM_SetCompare4(TIM3,1);
		TIM_SetCompare3(TIM3,car_left);
	} else if(car_left<0){
		TIM_SetCompare4(TIM3,-car_left);
		TIM_SetCompare3(TIM3,1);
	} else {
		TIM_SetCompare4(TIM3,CYCLE - 1);
		TIM_SetCompare3(TIM3,CYCLE - 1);
	}	
	return;
}


//处理手柄按键字符，buf为字符数组，mode是指模式 主要是红灯和绿灯模式
void parse_psx_buf(unsigned char *buf, unsigned char mode) {
	u8 i, pos = 0;
	static u16 bak=0xffff, temp, temp2;
	temp = (buf[0]<<8) + buf[1];
	
	if(bak != temp) {
		temp2 = temp;
		temp &= bak;
		for(i=0;i<16;i++) {//16个按键一次轮询
			if((1<<i) & temp) {
			} else {
				if((1<<i) & bak) {	//press 表示按键按下了
															
					memset(uart_receive_buf, 0, sizeof(uart_receive_buf));					
					if(mode == PS2_LED_RED) {
						memcpy((char *)uart_receive_buf, (char *)pre_cmd_set_red[i], strlen(pre_cmd_set_red[i]));
					} else if(mode == PS2_LED_GRN) {
						memcpy((char *)uart_receive_buf, (char *)pre_cmd_set_grn[i], strlen(pre_cmd_set_grn[i]));
					} else continue;
					
					pos = str_contain_str(uart_receive_buf, (u8 *)"^");
					if(pos) uart_receive_buf[pos-1] = '\0';
					if(str_contain_str(uart_receive_buf, (u8 *)"$")) {
						uart1_close();
						uart1_get_ok = 0;
						strcpy((char *)cmd_return, (char *)uart_receive_buf+11);
						strcpy((char *)uart_receive_buf, (char *)cmd_return);
						uart1_get_ok = 1;
						uart1_open();
						uart1_mode = 1;
					} else if(str_contain_str(uart_receive_buf, (u8 *)"#")) {
						uart1_close();
						uart1_get_ok = 0;
						strcpy((char *)cmd_return, (char *)uart_receive_buf+11);
						strcpy((char *)uart_receive_buf,(char *) cmd_return);
						uart1_get_ok = 1;
						uart1_open();
						uart1_mode = 2;
					}
					bak = 0xffff;
				} else {//release 表示按键松开了
										
					memset(uart_receive_buf, 0, sizeof(uart_receive_buf));					
					if(mode == PS2_LED_RED) {
						memcpy((char *)uart_receive_buf, (char *)pre_cmd_set_red[i], strlen(pre_cmd_set_red[i]));
					} else if(mode == PS2_LED_GRN) {
						memcpy((char *)uart_receive_buf, (char *)pre_cmd_set_grn[i], strlen(pre_cmd_set_grn[i]));
					} else continue;	
					
					pos = str_contain_str(uart_receive_buf, (u8 *)"^");
					if(pos) {
						if(str_contain_str(uart_receive_buf+pos, (u8 *)"$")) {
							//uart1_close();
							//uart1_get_ok = 0;
							strcpy((char *)cmd_return, (char *)uart_receive_buf+pos);
							cmd_return[strlen((char *)cmd_return) - 1] = '\0';
							strcpy((char *)uart_receive_buf, (char *)cmd_return);
							parse_cmd(uart_receive_buf);
							//uart1_get_ok = 1;
							//uart1_mode = 1;
						} else if(str_contain_str(uart_receive_buf+pos, (u8 *)"#")) {
							//uart1_close();
							//uart1_get_ok = 0;
							strcpy((char *)cmd_return, (char *)uart_receive_buf+pos);
							cmd_return[strlen((char *)cmd_return) - 1] = '\0';
							strcpy((char *)uart_receive_buf, (char *)cmd_return);
							do_action(uart_receive_buf);
							//uart1_get_ok = 1;
							//uart1_mode = 2;
						}
						//uart1_send_str(uart_receive_buf);
					}	
				}

			}
		}
		bak = temp2;
		beep_on();mdelay(10);beep_off();
	}	
	return;
}

//int型 取绝对值函数
int abs_int(int int1) {
	if(int1 > 0)return int1;
	return (-int1);
}

/*
	所有舵机停止命令：$DST!
	第x个舵机停止命令：$DST:x!
	单片机重启命令：$RST!
	检查动作组x到y组命令：$CGP:x-y!
	执行第x个动作：$DGS:x!
	执行第x到y组动作z次：$DGT:x-y,z!
	小车左轮x速度，右轮y速度：$DCR:x,y!
	所有舵机复位命令：$DJR!
	获取应答信号：$GETA!
*/
//命令解析函数
void parse_cmd(u8 *cmd) {
	static u8 djrFlag = 0;
	int pos, i, index, int1, int2;
	u8 temp_buf[160];
	u32 long1;
	
	//uart1_send_str(cmd);
	
	if(pos = str_contain_str(cmd, (u8 *)"$DST!"), pos) {
		group_do_ok  = 1;
		dbt_flag = 0;
		for(i=0;i<DJ_NUM;i++) {
			duoji_doing[i].inc = 0;	
			duoji_doing[i].aim = duoji_doing[i].cur;
		}
		zx_uart_send_str((u8 *)"#255PDST!");
	} else if(pos = str_contain_str(cmd, (u8 *)"$DST:"), pos) {
		if(sscanf((char *)cmd, "$DST:%d!", &index)) {
			duoji_doing[index].inc = 0;	
			duoji_doing[index].aim = duoji_doing[index].cur;
			sprintf((char *)cmd_return, "#%03dPDST!\r\n", (int)index);
			zx_uart_send_str(cmd_return);
			memset(cmd_return, 0, sizeof(cmd_return));
		}
	} else if(pos = str_contain_str(cmd, (u8 *)"$RST!"), pos) {		
		soft_reset();
	} else if(pos = str_contain_str(cmd, (u8 *)"$CGP:"), pos) {		
		if(sscanf((char *)cmd, "$CGP:%d-%d!", &int1, &int2)) {
			print_group(int1, int2);
		}
	} else if(pos = str_contain_str(cmd, (u8 *)"$DGS:"), pos) {		
		if(sscanf((char *)cmd, "$DGS:%d!", &int1)) {
			do_group_once(int1);
			group_do_ok = 1;
		}
	} else if(pos = str_contain_str(cmd, (u8 *)"$DGT:"), pos) {		
		if(sscanf((char *)cmd, "$DGT:%d-%d,%d!", &group_num_start, &group_num_end, &group_num_times)) {		
			if(group_num_start != group_num_end) {
				do_start_index = group_num_start;
				do_time = group_num_times;
				group_do_ok = 0;
			} else {
				do_group_once(group_num_start);
			}
		}
	} else if(pos = str_contain_str(cmd, (u8 *)"$DCR:"), pos) {		
		if(sscanf((char *)cmd, "$DCR:%d,%d!", &int1, &int2)) {
			car_pwm_set(int1, int2);	
		}
	} else if(pos = str_contain_str(cmd, (u8 *)"$DWA!"), pos) {		
		car_dw--;
		if(car_dw == 0)car_dw = 1;
		beep_on();mdelay(100);beep_off();
	} else if(pos = str_contain_str(cmd, (u8 *)"$DWD!"), pos) {		
		car_dw++;
		if(car_dw == 4)car_dw = 3;
		beep_on();mdelay(100);beep_off();
	} else if(pos = str_contain_str(cmd, (u8 *)"$CAR_FARWARD!"), pos) {		
		car_pwm_set(1000, 1000);
	} else if(pos = str_contain_str(cmd, (u8 *)"$CAR_BACKWARD!"), pos) {		
		car_pwm_set(-1000, -1000);
	} else if(pos = str_contain_str(cmd, (u8 *)"$CAR_LEFT!"), pos) {		
		car_pwm_set(1000, -1000);
	} else if(pos = str_contain_str(cmd, (u8 *)"$CAR_RIGHT!"), pos) {		
		car_pwm_set(-1000, 1000);
	} else if(pos = str_contain_str(cmd, (u8 *)"$DJR!"), pos) {	
		zx_uart_send_str((u8 *)"#255P1500T2000!\r\n");
		for(i=0;i<DJ_NUM;i++) {
			duoji_doing[i].aim = 1500;
			duoji_doing[i].time = 2000;
			duoji_doing[i].inc = (duoji_doing[i].aim -  duoji_doing[i].cur) / (duoji_doing[i].time/20.000);
		}
		
		if(djrFlag) {
			do_group_once(1);
		} else {
			do_group_once(2);
		}
		djrFlag = !djrFlag;
		
		
	} else if(pos = str_contain_str(cmd, (u8 *)"$STOP!"), pos) {	
		group_do_ok  = 1;
		dbt_flag = 0;
		for(i=0;i<DJ_NUM;i++) {
			duoji_doing[i].inc = 0;	
			duoji_doing[i].aim = duoji_doing[i].cur;
		}
		zx_uart_send_str((u8 *)"#255PDST!");//舵机停
		car_pwm_set(0,0);	//车停
	} else if (pos = str_contain_str(cmd, (u8*)"$DJ_RECORD!"), pos) {
		sprintf((char *)temp_buf, "<G%04d", eeprom_info.dj_record_num);
		for(i=0;i<6;i++) {
			sprintf((char *)cmd_return, "#%03dP%04dT%04d!", (int)i, (int)duoji_doing[i].cur, dj_record_time);
			strcat((char *)temp_buf, (char *)cmd_return);
		}		
		strcat((char *)temp_buf, "B000!>");
		eeprom_info.dj_record_num ++;
		rewrite_eeprom();
		uart1_send_str(temp_buf);
		action_save(temp_buf);
		uart1_send_str((u8 *)"$DJ_RECORD OK!");
		beep_times(100,1);
	}else if (pos = str_contain_str(cmd, (u8*)"$DJ_RECORD_CLEAR!"), pos) {
		eeprom_info.dj_record_num  = 0;;
		rewrite_eeprom();
		//uart1_send_str(temp_buf);
		action_save(temp_buf);
		uart1_send_str((u8 *)"$DJ_RECORD_CLEAR OK!");
		beep_times(100,1);
	} else if (pos = str_contain_str(cmd, (u8*)"$DJ_RECORD_DO:"), pos) {
		if(sscanf((char *)uart_receive_buf, "$DJ_RECORD_DO:%u!", &long1)) {
			if(eeprom_info.dj_record_num==0)return;	

			group_num_start = 0;
			group_num_end = eeprom_info.dj_record_num-1;
			group_num_times = long1;			

			if(group_num_start != group_num_end) {
				do_start_index = group_num_start;
			} else {
				do_group_once(group_num_start);
			}
			do_time = group_num_times;
			group_do_ok = 0;	
		}
	} else if(pos = str_contain_str(cmd, (u8 *)"$GETA!"), pos) {		
		uart1_send_str((u8 *)"AAA");
	} else if(pos = str_contain_str(cmd, (u8 *)"$DBT:"), pos) {		
		if(sscanf((char *)uart_receive_buf, "$DBT:%d,%d!", &int1, &int2)) {
			if(int1 == 1) {
				group_num_start = 1;
				group_num_end = 10;
				group_num_times = int2;
			} else if(int1 == 2) {
				group_num_start = 11;
				group_num_end = 20;
				group_num_times = int2;
			} else if(int1 == 3) {
				group_num_start = 21;
				group_num_end = 30;
				group_num_times = int2;
			} else if(int1 == 4) {
				group_num_start = 31;
				group_num_end = 40;
				group_num_times = int2;
			} else {
				group_num_start = 0;
				group_num_end = 0;
			}
			
			if(group_num_start != group_num_end) {
				do_start_index = group_num_start;
				do_time = group_num_times;
				group_do_ok = 0;
				dbt_flag = 1;
			} else {
				do_group_once(group_num_start);
			}
			
		}
	} else if(pos = str_contain_str(cmd, (u8 *)"$SMODE"), pos) {		
		if(sscanf((char *)cmd, "$SMODE%d!", &int1)) {
			if(int1 < 10) {
				smart_mode = int1;
				beep_on_times(1, 100);
				car_pwm_set(0,0);
				uart1_send_str(cmd);
			}
		}
	} 
}


//动作组保存函数
//只有用<>包含的字符串才能在此函数中进行解析
void action_save(u8 *str) {
	int action_index = 0;
	//获取动作的组号
	action_index = get_action_index(str);
	
	//预存命令处理
	if(str[1] == '$' && str[2] == '!') {
		eeprom_info.pre_cmd[PRE_CMD_SIZE] = 0;
		rewrite_eeprom();
		uart1_send_str((u8 *)"@CLEAR PRE_CMD OK!");
		return;
	} else if(str[1] == '$') {
		memset(eeprom_info.pre_cmd, 0, sizeof(eeprom_info.pre_cmd));
		strcpy((char *)eeprom_info.pre_cmd, (char *)str+1);
		eeprom_info.pre_cmd[strlen((char *)str) - 2] = '\0';
		eeprom_info.pre_cmd[PRE_CMD_SIZE] = FLAG_VERIFY;
		rewrite_eeprom();
		uart1_send_str((u8 *)"@SET PRE_CMD OK!");
		return;
	}
	//获取动作的组号如果不正确，或是第6个字符不是#则认为字符串错误
	//<G0000#000P1500T1000!>
	if((action_index == -1) || str[6] != '#'){
		uart1_send_str((u8 *)"E");
		return;
	}
	//把尖括号替换成大括号直接存储到存储芯片里面去，则在执行动作组的时候直接拿出来解析就可以了
	replace_char(str, '<', '{');
	replace_char(str, '>', '}');
	w25x_write(str, action_index*ACTION_SIZE, strlen((char *)str) + 1);
	//反馈一个A告诉上位机我已经接收到了
	uart1_send_str((u8 *)"A");
	return;	
}

//获取动作组的组号，字符串中有组号返回组号，否则返回-1
int get_action_index(u8 *str) {
	u16 index = 0;
	//uart_send_str(str);
	while(*str) {
		if(*str == 'G') {
			str++;
			while((*str != '#') && (*str != '$')) {
				index = index*10 + *str-'0';
				str++;	
			}
			return index;
		} else {
			str++;
		}
	}
	return -1;
}


//打印存储在芯片里的动作组，从串口1中发送出来 $CGP:x-y!这个命令调用
void print_group(int start, int end) {
	if(start > end) {
		int_exchange(&start, &end);
	}
	for(;start<=end;start++) {
		memset(uart_receive_buf, 0, sizeof(uart_receive_buf));
		w25x_read(uart_receive_buf, start*ACTION_SIZE, ACTION_SIZE);
		uart1_send_str(uart_receive_buf);
		uart1_send_str((u8 *)"\r\n");
	}
}

//两个int变量交换
void int_exchange(int *int1, int *int2) {
	int int_temp;
	int_temp = *int1;
	*int1 = *int2;
	*int2 = int_temp;
}

//执行动作组1次
//参数是动作组序号
void do_group_once(int group_num) {
	memset(uart_receive_buf, 0, sizeof(uart_receive_buf));
	if(ACTION_USE_ROM) {
	//使用存储在单片机内部rom中的动作组
		strcpy((char *)uart_receive_buf, action_pre_group[group_num]);
	} else {
	//从存储芯片中读取第group_num个动作组
		w25x_read(uart_receive_buf, group_num*ACTION_SIZE, ACTION_SIZE);	
	}
	//把读取出来的动作组传递到do_action执行
	do_action(uart_receive_buf);
	sprintf((char *)cmd_return, "@DoGroup %d OK!\r\n", group_num);
	uart1_send_str(cmd_return);
}


//检查舵机状态，把每个舵机的增量变量想加，只要不等于0就说明舵机在执行中
u8 check_dj_state(void) {
	int i;
	float	inc = 0;
	for(i=0;i<DJ_NUM;i++) {
		inc += duoji_doing[i].inc;
		if(inc)return 1;
	}
	return 0;
}

//处理 #000P1500T1000! 类似的字符串
void do_action(u8 *uart_receive_buf) {
	u16 index,  time, i = 0;
	int bias;
	float pwm;
	float aim_temp;
	zx_uart_send_str(uart_receive_buf);
	
	if(uart_receive_buf[0] == '#' && uart_receive_buf[4] == 'P' && uart_receive_buf[5] == 'S' && uart_receive_buf[6] == 'C' && uart_receive_buf[7] == 'K' && uart_receive_buf[12] == '!') {
		index = (uart_receive_buf[1] - '0')*100 + (uart_receive_buf[2] - '0')*10 + (uart_receive_buf[3] - '0');
		bias = (uart_receive_buf[9] - '0')*100 + (uart_receive_buf[10] - '0')*10 + (uart_receive_buf[11] - '0');
		if((bias >= -500) && (bias <= 500) && (index < DJ_NUM)) {
			if(uart_receive_buf[8] == '+') {
			} else if(uart_receive_buf[8] == '-') {
				bias = -bias;
			}
			aim_temp = duoji_doing[index].cur + 0.043198 - eeprom_info.dj_bias_pwm[index] + bias;
			eeprom_info.dj_bias_pwm[index] = bias;			
			if(aim_temp > 2497){
				aim_temp = 2497;
			} else if(aim_temp < 500) {
				aim_temp = 500;
			}
			
			duoji_doing[index].aim = aim_temp;
			duoji_doing[index].cur = aim_temp;
			duoji_doing[index].inc = 0;
			bias_systick_ms_bak = systick_ms;
			djBiasSaveFlag = 1;
		}
		return;
	} else if(uart_receive_buf[0] == '#' && uart_receive_buf[4] == 'P' && uart_receive_buf[5] == 'D' && uart_receive_buf[6] == 'S' && uart_receive_buf[7] == 'T' && uart_receive_buf[8] == '!') {
		index = (uart_receive_buf[1] - '0')*100 + (uart_receive_buf[2] - '0')*10 + (uart_receive_buf[3] - '0');
		duoji_doing[index].inc = 0;	
		duoji_doing[index].aim = (int)duoji_doing[index].cur;
		memset(cmd_return, 0, sizeof(cmd_return));
		return;
	}
	
	while(uart_receive_buf[i]) {
		if(uart_receive_buf[i] == '#') {
			index = 0;i++;
			while(uart_receive_buf[i] && uart_receive_buf[i] != 'P') {
				index = index*10 + uart_receive_buf[i]-'0';i++;
			}
		} else if(uart_receive_buf[i] == 'P') {
			pwm = 0;i++;
			while(uart_receive_buf[i] && uart_receive_buf[i] != 'T') {
				pwm = pwm*10 + uart_receive_buf[i]-'0';i++;
			}
		} else if(uart_receive_buf[i] == 'T') {
			time = 0;i++;
			while(uart_receive_buf[i] && uart_receive_buf[i] != '!') {
				time = time*10 + uart_receive_buf[i]-'0';i++;
			}
			
			if(index < DJ_NUM && (pwm<=2500)&& (pwm>=500) && (time<=10000)) {
				//duoji_doing[index].inc = 0;
				if(duoji_doing[index].cur == pwm) {
					duoji_doing[index].cur -= 0.135;
				}
				pwm += eeprom_info.dj_bias_pwm[index];
				
				if(pwm>2497)pwm=2497;
				if(pwm<500)pwm=500;
				
				if(time < 20) {
					duoji_doing[index].aim = pwm;
					duoji_doing[index].cur = pwm;
					duoji_doing[index].inc = 0;
				} else {
					duoji_doing[index].aim = pwm;
					duoji_doing[index].time = time;
					duoji_doing[index].inc = (duoji_doing[index].aim -  duoji_doing[index].cur) / (duoji_doing[index].time/20.000);
				}

				//sprintf(cmd_return, "#%03dP%04dT%04d! %f \r\n", index, pwm, time, duoji_doing[index].inc);
				//uart1_send_str(cmd_return);
			}
		} else {
			i++;
		}
	}	
}

//字符串中的字符替代函数 把str字符串中所有的ch1换成ch2
void replace_char(u8*str, u8 ch1, u8 ch2) {
	while(*str) {
		if(*str == ch1) {
			*str = ch2;
		} 
		str++;
	}
	return;
}

//把eeprom_info写入到W25Q64_INFO_ADDR_SAVE_STR位置
void rewrite_eeprom(void) {
	W25Q_Write((u8 *)(&eeprom_info), W25Q64_INFO_ADDR_SAVE_STR, sizeof(eeprom_info));
}



/*
	智能功能代码
*/

void selection_sort(int *a, int len) {//选择排序，从小到大排列
    int i,j,mi,t;
    for(i=0;i<len-1;i++) {                          
        mi = i;
        for(j=i+1;j<len;j++) {
            if(a[mi] > a[j]) {                        
                mi = j;    
            }    
        }    
        if(mi != i) {
            t = a[mi];
            a[mi] = a[i];
            a[i] = t;    
        }
    }
}

int get_adc_a0_middle() {//读取AD值，排序，并返回中间值
	u8 i;
	static int ad_value[5] = {0},  ad_index = 0, myvalue;//ad_value_bak[5] = {0},
	for(i=0;i<5;i++)ad_value[ad_index] = ADC_ConvertedValue[1];
	//ad_value[ad_index] = ADC_ConvertedValue[1];
	//ad_value_bak[ad_index] = ADC_ConvertedValue[1];
	ad_index ++ ;
	if(ad_index == 5)ad_index = 0;
	selection_sort(ad_value, 5);
	myvalue = ad_value[2];
	//for(i=0;i<5;i++)ad_value[i] = ad_value_bak[i];
	return myvalue;  
}

void smart_xunji(void) {//两路循迹功能
	int speed = 600;
	if((sensor_pb11() == 0) && (sensor_pa1() == 1)) {
		car_pwm_set(speed+200, 0);
	} else if((sensor_pb11() == 1) && (sensor_pa1() == 1)) {
		car_pwm_set(speed, speed);
	} else if((sensor_pb11() == 1) && (sensor_pa1() == 0)) {
		car_pwm_set(0, speed+200);
	} 	
}

void smart_xunjibizhang(void) {//在一定距离内，发现有障碍物，停在当前，否则继续循迹
	static u32 systick_ms_bak = 0;
	int adc_a0;
	if(systick_ms - systick_ms_bak > 50) {
		systick_ms_bak = systick_ms;
		//避障处理
		adc_a0 = get_adc_a0_middle()/4;//获取a0的ad值，计算出距离
		//adc_a0 = ADC_ConvertedValue[1]/4;
		//sprintf((char *)uart_receive_buf, "adc0 = %d\r\n", adc_a0);
		//uart1_send_str(uart_receive_buf);
		if(adc_a0 < 250) {//距离低于250mm就停止
			car_pwm_set(0, 0);
			//uart1_send_str("---");
		} else {
			//car_pwm_set(500, 500);
			//uart1_send_str("+++");
			//循迹处理
			smart_xunji();
		}
	}
}


void smart_gensui(void) {//在一定距离内跟随着物体移动，超出一定范围则停止
	static u32 systick_ms_bak = 0;
	int speed = 500, adc_a0;
	if(systick_ms - systick_ms_bak > 20) {
		systick_ms_bak = systick_ms;
		adc_a0 = get_adc_a0_middle()/4;//获取a0的ad值，计算出距离
		if((adc_a0 > 400) && (adc_a0 < 1000)  ) {//距离400~1000mm前进
			car_pwm_set(speed, speed);
		} else if(adc_a0 < 300) {//距离低于300mm就后退
			car_pwm_set(-speed, -speed);
		} else {//其他情况停止
			car_pwm_set(0, 0);
		}
	}
}

void smart_ziyoubizhang(void) {//障碍物距离小于一定距离就右转
	static u32 systick_ms_bak = 0;
	int speed = 600, adc_a0;
	if(systick_ms - systick_ms_bak > 100) {
		systick_ms_bak = systick_ms;
		adc_a0 = get_adc_a0_middle()/4;//获取a0的ad值，计算出距离
//		sprintf((char *)uart_receive_buf, "adc0 = %d\r\n", adc_a0);
//		uart1_send_str(uart_receive_buf);
		if(adc_a0 < 500) {//距离低于500mm就右转
			car_pwm_set(1000, -1000);
		} else {
			car_pwm_set(speed, speed);
		}
	}
}

void smart_csbjiaqu(void) {//超声波在一定范围内夹取物品
	static u32 systick_ms_bak = 0, nextStepTime = 100;
	int adc_a0;
	adc_a0 = get_adc_a0_middle()/4;//获取a0的ad值，计算出距离
	if(systick_ms - systick_ms_bak > nextStepTime) {
		systick_ms_bak = systick_ms;
		//sprintf((char *)uart_receive_buf, "adc0 = %d\r\n", adc_a0);
		//uart1_send_str(uart_receive_buf);
		if((adc_a0 > 150-15) && (adc_a0 < 150+15)) {//距离150mm左右就夹取
			nextStepTime = 11000;
			parse_cmd((u8 *)"$DGT:3-11,1!");
		} else {
			nextStepTime = 100;
			//car_pwm_set(speed, speed);
		}
	}	
}

void smart_yssbjiaqu(void) {//静态颜色识别夹取
	//static u8  getCountOk = 0;
	static u32 systick_ms_bak = 0,  nextStepTime = 100;
	static int adc_a0;

	if((systick_ms - systick_ms_bak) > nextStepTime) {
		systick_ms_bak = systick_ms;
		adc_a0 = get_adc_a0_middle()/4;
		if((adc_a0>COLOR_RED-10) && (adc_a0<COLOR_RED+10)) {
				nextStepTime = 12000;
				//uart1_send_str("RED");
				parse_cmd((u8 *)"$DGT:12-18,1!");
		} else if((adc_a0>COLOR_GRN-10) && (adc_a0<COLOR_GRN+10)) {
				nextStepTime = 12000;
				//uart1_send_str("GRN");
				parse_cmd((u8 *)"$DGT:19-27,1!");
		} else if((adc_a0>COLOR_BLU-10) && (adc_a0<COLOR_BLU+10)) {
				nextStepTime = 12000;
				//uart1_send_str("BLU");
				parse_cmd((u8 *)"$DGT:28-36,1!");
		} else {
			nextStepTime = 100;
		} 
		
	}	
}

void smart_soundjiaqu(void) {//判断声音响的次数夹取
	
	static u8 initOnce = 0, justDo = 0;
	static u32 systick_ms_bak = 0, systick_ms_bak2 = 0, nextStepTime = 1000;
	static int soundCount = 0;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	if(!initOnce) {//引脚设为输入
		initOnce = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);  
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;   //PA0
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   
		GPIO_Init(GPIOA, &GPIO_InitStructure); 
	}
	
	if((justDo == 0) && (systick_ms - systick_ms_bak > 5)) {
		systick_ms_bak = systick_ms;
		if(sensor_pa0() == 0) {
			soundCount ++;
			if(soundCount == 1)systick_ms_bak2 = systick_ms;
		}
	}
	
	if(systick_ms - systick_ms_bak2 > nextStepTime) {
		systick_ms_bak2 = systick_ms;
		if(nextStepTime > 2000)beep_on_times(1, 300);
		
		if(soundCount>1) {			//右放
			nextStepTime = 13000;
			parse_cmd((u8 *)"$DGT:28-36,1!");
			justDo = 1;
			beep_on_times(2, 100);
		} else if(soundCount>0){	//左放
			nextStepTime = 13000;
			parse_cmd((u8 *)"$DGT:19-27,1!");
			justDo = 1;
			beep_on_times(1, 100);
		} else {
			nextStepTime = 1000;
			justDo = 0;
		}
		soundCount = 0;	
	}
}

void smart_xunjicsbjiaqu() {//循迹的过程中超声波测过范围内遇到物体夹取
	static u32 systick_ms_bak = 0, nextStepTime = 50;
	int adc_a0;	
	adc_a0 = get_adc_a0_middle()/4;//获取a0的ad值，计算出距离
	if(systick_ms - systick_ms_bak > nextStepTime) {
		systick_ms_bak = systick_ms;
		if(nextStepTime > 2000)beep_on_times(1, 300);
		if((adc_a0 > 100-15) && (adc_a0 < 100+15)) {//距离100mm左右就夹取
			car_pwm_set(0, 0);
			nextStepTime = 10000;
			parse_cmd((u8 *)"$DGT:3-11,1!");
		} else {
			smart_xunji();
			nextStepTime = 50;
		}
	}
}

void smart_xunjiyanse() {//循迹颜色识别夹取
	static u8 shibieOK = 0;
	static u32 systick_ms_bak = 0, systick_ms_bak3 = 0, nextStepTime = 100;//systick_ms_bak2 = 0,
	static int adc_a0;
	
	adc_a0 = get_adc_a0_middle()/4;
	if((systick_ms - systick_ms_bak) > nextStepTime) {
		systick_ms_bak = systick_ms;
		//获取a0的ad值，缩小4倍
//		sprintf((char *)uart_receive_buf, "adc0 = %d\r\n", adc_a0);
//		uart1_send_str(uart_receive_buf);
		
		if(nextStepTime > 2000)beep_on_times(1, 300);
		
		if((adc_a0>COLOR_RED-10) && (adc_a0<COLOR_RED+10)) {
			//RED
			car_pwm_set(0, 0);
			for(i=0;i<5;i++) {
				adc_a0 = get_adc_a0_middle()/4;
				mdelay(20);
			}
			if((adc_a0>COLOR_RED-10) && (adc_a0<COLOR_RED+10)) {
				shibieOK = 1;
				nextStepTime = 12000;
				uart1_send_str("RED");
				//parse_cmd((u8 *)"$DGT:12-18,1!");
				parse_cmd((u8 *)"$DGT:19-27,1!");
			}

		} else if((adc_a0>COLOR_BLU-10) && (adc_a0<COLOR_BLU+10)) {
			//BLU
			car_pwm_set(0, 0);
			for(i=0;i<5;i++) {
				adc_a0 = get_adc_a0_middle()/4;
				mdelay(20);
			}
			if((adc_a0>COLOR_BLU-10) && (adc_a0<COLOR_BLU+10)) {
				shibieOK = 1;
				nextStepTime = 12000;
				uart1_send_str("BLU");
				parse_cmd((u8 *)"$DGT:28-36,1!");
			}
		} else {
			shibieOK = 0;
			nextStepTime = 100;
		} 
		
	}

	if(shibieOK == 0) {
		if(systick_ms - systick_ms_bak3 > 50) {
			systick_ms_bak3 = systick_ms;
			smart_xunji();
		}
	}
}
