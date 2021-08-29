#ifndef __Z_COLOR_H__
#define __Z_COLOR_H__

#include "stm32f10x_conf.h"

/******************************************************************************/
#define TCS_SDA_PIN_NUM       0
#define TCS_SCL_PIN 		GPIO_Pin_7
#define TCS_SDA_PIN 		GPIO_Pin_5
#define TCS_SDA_GPIO		GPIOA
#define TCS_SCL_GPIO		GPIOA
#define TCS_GPIO			GPIOA



#define TCS34725_ADDRESS          (0x29)
 
#define TCS34725_COMMAND_BIT      (0x80)
 
#define TCS34725_ENABLE           (0x00)
#define TCS34725_ENABLE_AIEN      (0x10)    /* RGBC Interrupt Enable */
#define TCS34725_ENABLE_WEN       (0x08)    /* Wait enable - Writing 1 activates the wait timer */
#define TCS34725_ENABLE_AEN       (0x02)    /* RGBC Enable - Writing 1 actives the ADC, 0 disables it */
#define TCS34725_ENABLE_PON       (0x01)    /* Power on - Writing 1 activates the internal oscillator, 0 disables it */
#define TCS34725_ATIME            (0x01)    /* Integration time */
#define TCS34725_WTIME            (0x03)    /* Wait time (if TCS34725_ENABLE_WEN is asserted) */
#define TCS34725_WTIME_2_4MS      (0xFF)    /* WLONG0 = 2.4ms   WLONG1 = 0.029s */
#define TCS34725_WTIME_204MS      (0xAB)    /* WLONG0 = 204ms   WLONG1 = 2.45s  */
#define TCS34725_WTIME_614MS      (0x00)    /* WLONG0 = 614ms   WLONG1 = 7.4s   */
#define TCS34725_AILTL            (0x04)    /* Clear channel lower interrupt threshold */
#define TCS34725_AILTH            (0x05)
#define TCS34725_AIHTL            (0x06)    /* Clear channel upper interrupt threshold */
#define TCS34725_AIHTH            (0x07)
#define TCS34725_PERS             (0x0C)    /* Persistence register - basic SW filtering mechanism for interrupts */
#define TCS34725_PERS_NONE        (0b0000)  /* Every RGBC cycle generates an interrupt                                */
#define TCS34725_PERS_1_CYCLE     (0b0001)  /* 1 clean channel value outside threshold range generates an interrupt   */
#define TCS34725_PERS_2_CYCLE     (0b0010)  /* 2 clean channel values outside threshold range generates an interrupt  */
#define TCS34725_PERS_3_CYCLE     (0b0011)  /* 3 clean channel values outside threshold range generates an interrupt  */
#define TCS34725_PERS_5_CYCLE     (0b0100)  /* 5 clean channel values outside threshold range generates an interrupt  */
#define TCS34725_PERS_10_CYCLE    (0b0101)  /* 10 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_15_CYCLE    (0b0110)  /* 15 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_20_CYCLE    (0b0111)  /* 20 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_25_CYCLE    (0b1000)  /* 25 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_30_CYCLE    (0b1001)  /* 30 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_35_CYCLE    (0b1010)  /* 35 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_40_CYCLE    (0b1011)  /* 40 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_45_CYCLE    (0b1100)  /* 45 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_50_CYCLE    (0b1101)  /* 50 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_55_CYCLE    (0b1110)  /* 55 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_60_CYCLE    (0b1111)  /* 60 clean channel values outside threshold range generates an interrupt */
#define TCS34725_CONFIG           (0x0D)
#define TCS34725_CONFIG_WLONG     (0x02)    /* Choose between short and long (12x) wait times via TCS34725_WTIME */
#define TCS34725_CONTROL          (0x0F)    /* Set the gain level for the sensor */
#define TCS34725_ID               (0x12)    /* 0x44 = TCS34721/TCS34725, 0x4D = TCS34723/TCS34727 */
#define TCS34725_STATUS           (0x13)
#define TCS34725_STATUS_AINT      (0x10)    /* RGBC Clean channel interrupt */
#define TCS34725_STATUS_AVALID    (0x01)    /* Indicates that the RGBC channels have completed an integration cycle */
#define TCS34725_CDATAL           (0x14)    /* Clear channel data */
#define TCS34725_CDATAH           (0x15)
#define TCS34725_RDATAL           (0x16)    /* Red channel data */
#define TCS34725_RDATAH           (0x17)
#define TCS34725_GDATAL           (0x18)    /* Green channel data */
#define TCS34725_GDATAH           (0x19)
#define TCS34725_BDATAL           (0x1A)    /* Blue channel data */
#define TCS34725_BDATAH           (0x1B)
 
#define TCS34725_INTEGRATIONTIME_2_4MS   0xFF   /**<  2.4ms - 1 cycle    - Max Count: 1024  */
#define TCS34725_INTEGRATIONTIME_24MS    0xF6   /**<  24ms  - 10 cycles  - Max Count: 10240 */
#define TCS34725_INTEGRATIONTIME_50MS    0xEB   /**<  50ms  - 20 cycles  - Max Count: 20480 */
#define TCS34725_INTEGRATIONTIME_101MS   0xD5   /**<  101ms - 42 cycles  - Max Count: 43008 */
#define TCS34725_INTEGRATIONTIME_154MS   0xC0   /**<  154ms - 64 cycles  - Max Count: 65535 */
#define TCS34725_INTEGRATIONTIME_240MS   0x9C   /**<  240ms - 100 cycles - Max Count: 65535 */
#define TCS34725_INTEGRATIONTIME_700MS   0x00   /**<  700ms - 256 cycles - Max Count: 65535 */
 
#define TCS34725_GAIN_1X                 0x00   /**<  No gain  */
#define TCS34725_GAIN_4X                 0x01   /**<  4x gain  */
#define TCS34725_GAIN_16X                0x02   /**<  16x gain */
#define TCS34725_GAIN_60X                0x03   /**<  60x gain */
/******************************************************************************/
#define TCS_SDA_IN()  {TCS_SDA_GPIO->CRL&=0xFF0FFFFF;TCS_SDA_GPIO->CRL|=8<<20;}
//#define TCS_SDA_IN() {TCS_SDA_GPIO->MODER&=~(3<<(TCS_SDA_PIN_NUM*2));TCS_SDA_GPIO>MODER|=0<<TCS_SDA_PIN_NUM*2;}
#define TCS_SDA_OUT() {TCS_SDA_GPIO->CRL&=0xFF0FFFFF;TCS_SDA_GPIO->CRL|=3<<20;}
//#define TCS_SDA_OUT() {TCS_SDA_GPIO->MODER&=~(3<<(TCS_SDA_PIN_NUM*2));TCS_SDA_GPIO>MODER|=1<<TCS_SDA_PIN_NUM*2;}


#define TCS_SDA_READ   TCS_GPIO->IDR&(TCS_SDA_PIN)
 
#define TCS_SCL_H     GPIO_SetBits(TCS_GPIO,TCS_SCL_PIN)
#define TCS_SCL_L     GPIO_ResetBits(TCS_GPIO,TCS_SCL_PIN)
#define TCS_SDA_H     GPIO_SetBits(TCS_GPIO,TCS_SDA_PIN)
#define TCS_SDA_L     GPIO_ResetBits(TCS_GPIO,TCS_SDA_PIN)
/******************************************************************************/
#define max3v(v1, v2, v3)   ((v1)<(v2)? ((v2)<(v3)?(v3):(v2)):((v1)<(v3)?(v3):(v1)))
#define min3v(v1, v2, v3)   ((v1)>(v2)? ((v2)>(v3)?(v3):(v2)):((v1)>(v3)?(v3):(v1)))
 
typedef struct{
	unsigned short  c;      //[0-65536]
	unsigned short  r;
	unsigned short  g;
	unsigned short  b;
}COLOR_RGBC;//RGBC
 
typedef struct{
	unsigned short h;       //[0,360]
	unsigned char  s;       //[0,100]
	unsigned char  l;       //[0,100]
}COLOR_HSL;//HSL
 

u8 TCS34725_Init(u8 time);
u8 TCS34725_GetRawData(COLOR_RGBC *rgbc);
void TCS34725_LedON(u8 enable);


void RGBtoHSL(COLOR_RGBC *Rgb, COLOR_HSL *Hsl);
u16 TCS34725_GetR(void);
u16 TCS34725_GetG(void);
u16 TCS34725_GetB(void);
u16 TCS34725_GetC(void);

#endif

