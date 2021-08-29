#include "z_rcc.h"
#include "stm32f10x_rcc.h"


void tb_rcc_init(void) {
//--------------------------- CLK INIT, HSE PLL ----------------------------
	ErrorStatus HSEStartUpStatus;
	//RCC reset
	RCC_DeInit();
	//开启外部时钟 并执行初始化
	RCC_HSEConfig(RCC_HSE_ON); 
	//等待外部时钟准备好
	HSEStartUpStatus = RCC_WaitForHSEStartUp();
	//启动失败 在这里等待
	while(HSEStartUpStatus == ERROR);
	//设置内部总线时钟
	RCC_HCLKConfig(RCC_SYSCLK_Div1);//SYSCLK
	RCC_PCLK1Config(RCC_HCLK_Div2);//APB1  MAX = 36M
	RCC_PCLK2Config(RCC_HCLK_Div1);//APB2  MAX = 72M
	//外部时钟为8M 这里倍频到72M
	RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);
	RCC_PLLCmd(ENABLE); 
	while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
	while(RCC_GetSYSCLKSource() != 0x08);

	//----------------------------- CLOSE HSI ---------------------------
	//关闭内部时钟HSI
	//RCC_HSICmd(DISABLE);
	//关闭内部始终LSI
	//RCC_LSICmd(DISABLE);
	
	//配置IO口时钟
	//开PA口时钟
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	//开PB口时钟
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	



	return;
}




