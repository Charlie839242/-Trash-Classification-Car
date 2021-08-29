/*
	通道对照表：
	ch0-PA0
	ch1-PA1
	ch2-PA2
	ch3-PA3
	ch4-PA4
	ch5-PA5
	ch6-PA6
	ch7-PA7
	ch8-PB0
	ch9-PB1
	ch10-PC0
	ch11-PC1
	ch12-PC2
	ch13-PC3
	ch14-PC4
	ch15-PC5
	
	ch16-温度传感器
	ch17-内部参照电压
	
	需要修改的数据 
	1、ADC_NUM 通道数量
	2、ADC1_Configuration 中的通道配置，和ADC_NUM数量保持一致
	3、数据直接获取数组 ADC_ConvertedValue
	
*/

#include "z_adc.h"

#define ADC1_DR_Address ((u32)0x40012400+0x4c)
u16 ADC_ConvertedValue[ADC_NUM] = {0};

void ADC_init(void) {
	ADC1_GPIO_Configuration();
	DMA_Configuration();
	ADC1_Configuration();
}

void ADC1_GPIO_Configuration(void) {
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOA, ENABLE); 

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_5; 
	
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_AIN; 
	GPIO_Init(GPIOA,&GPIO_InitStructure); 	
}


void ADC1_Configuration(void) {
	ADC_InitTypeDef ADC_InitStructure;

	ADC_DeInit(ADC1); //将外设 ADC1 的全部寄存器重设为缺省值
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent; //ADC工作模式:ADC1和ADC2工作在独立模式
	ADC_InitStructure.ADC_ScanConvMode =ENABLE; //模数转换工作在扫描模式
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE; //模数转换工作在连续转换模式 不停的转换
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; //外部触发转换关闭
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right; //ADC数据右对齐
	ADC_InitStructure.ADC_NbrOfChannel = ADC_NUM; //顺序进行规则转换的ADC通道的数目
	ADC_Init(ADC1, &ADC_InitStructure); //根据ADC_InitStruct中指定的参数初始化外设ADCx的寄存器

	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	//设置指定ADC的规则组通道，设置它们的转化顺序和采样时间
	//ADC1,ADC通道x,规则采样顺序值为y,采样时间为239.5周期
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_239Cycles5 );
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 2, ADC_SampleTime_239Cycles5 );
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 3, ADC_SampleTime_239Cycles5 );
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 1, ADC_SampleTime_239Cycles5 );
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 1, ADC_SampleTime_239Cycles5 );
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 2, ADC_SampleTime_239Cycles5 );
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 3, ADC_SampleTime_239Cycles5 );
	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 1, ADC_SampleTime_239Cycles5 );
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 7, ADC_SampleTime_239Cycles5 );
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 8, ADC_SampleTime_239Cycles5 );
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_239Cycles5 );
	
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_239Cycles5 );
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 2, ADC_SampleTime_239Cycles5 );
	
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 9, ADC_SampleTime_239Cycles5 );
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 10, ADC_SampleTime_239Cycles5 );
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_14, 11, ADC_SampleTime_239Cycles5 );
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_15, 12, ADC_SampleTime_239Cycles5 );

	// 开启ADC的DMA支持（要实现DMA功能，还需独立配置DMA通道等参数）
	ADC_DMACmd(ADC1, ENABLE);

	ADC_Cmd(ADC1, ENABLE); //使能指定的ADC1

	ADC_ResetCalibration(ADC1); //复位指定的ADC1的校准寄存器

	while(ADC_GetResetCalibrationStatus(ADC1)); //获取ADC1复位校准寄存器的状态,设置状态则等待

	ADC_StartCalibration(ADC1); //开始指定ADC1的校准状态

	while(ADC_GetCalibrationStatus(ADC1)); //获取指定ADC1的校准程序,设置状态则等待          
	
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);

}



void DMA_Configuration(void)
{
	DMA_InitTypeDef DMA_InitStructure;
	DMA_DeInit(DMA1_Channel1); //将DMA的通道1寄存器重设为缺省值
	DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address; //DMA外设ADC基地址*****
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)ADC_ConvertedValue; //DMA内存基地址*****
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC; //内存作为数据传输的目的地
	DMA_InitStructure.DMA_BufferSize = ADC_NUM; //DMA通道的DMA缓存的大小*****
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; //外设地址寄存器不变
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable; //内存地址寄存器递增
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord; //数据宽度为16位
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord; //数据宽度为16位
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular; //工作在循环缓存模式
	DMA_InitStructure.DMA_Priority = DMA_Priority_High; //DMA通道 x拥有高优先级
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable; //DMA通道x没有设置为内存到内存传输
	DMA_Init(DMA1_Channel1, &DMA_InitStructure); //根据DMA_InitStruct中指定的参数初始化DMA的通道
	DMA_Cmd(DMA1_Channel1, ENABLE);
	
}

