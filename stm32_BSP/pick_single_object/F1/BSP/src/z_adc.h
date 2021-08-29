
#ifndef __ADC_H__
#define __ADC_H__

#include "z_main.h"
#include "z_type.h"
#include "stm32f10x_conf.h"

#define ADC_NUM 1


void ADC_init(void);
void ADC1_GPIO_Configuration(void);
void ADC1_Configuration(void);
void DMA_Configuration(void);

extern u16 ADC_ConvertedValue[ADC_NUM];

#endif
