/************************************************************************************
* Function List:
* 1. void I2C_Configuration(void) -- 配置CPU的硬件I2C
* 2. void I2C_WriteByte(uint8_t addr,uint8_t data) -- 向寄存器地址写一个byte的数据
* 3. void WriteCmd(unsigned char I2C_Command) -- 写命令
* 4. void WriteDat(unsigned char I2C_Data) -- 写数据
* 5. void OLED_Init(void) -- OLED屏初始化
* 6. void OLED_SetPos(unsigned char x, unsigned char y) -- 设置起始点坐标
* 7. void OLED_Fill(unsigned char fill_Data) -- 全屏填充
* 8. void OLED_CLS(void) -- 清屏
* 9. void OLED_ON(void) -- 唤醒
* 10. void OLED_OFF(void) -- 睡眠
* 11. void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize) -- 显示字符串(字体大小有6*8和8*16两种)
* 12. void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N) -- 显示中文(中文需要先取模，然后放到codetab.h中)
* 13. void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]) -- BMP图片
*
* History: none;
*
*************************************************************************************/
#include "z_oled_i2c.h"
#include "z_delay.h"
#include "z_codetab.h"

void I2C_Configuration(void)
{
	I2C_InitTypeDef  I2C_InitStructure;
	GPIO_InitTypeDef  GPIO_InitStructure; 

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

	/*STM32F103C8T6芯片的硬件I2C: PB6 -- SCL; PB7 -- SDA */
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;//I2C必须开漏输出
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	I2C_DeInit(I2C1);//使用I2C1
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	I2C_InitStructure.I2C_OwnAddress1 = 0x30;//主机的I2C地址,随便写的
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	I2C_InitStructure.I2C_ClockSpeed = 400000;//400K

	I2C_Cmd(I2C1, ENABLE);
	I2C_Init(I2C1, &I2C_InitStructure);
}

u8 I2C_WriteByte(uint8_t addr,uint8_t data)
{
//	#define state_timeout 100000
//	u32 state = 0;
//	
//	state = 0;
//	while(I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY) && (state++ < state_timeout));
//	
//	state = 0;
//	I2C_GenerateSTART(I2C1, ENABLE);//开启I2C1
//	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT) && (state++ < state_timeout));/*EV5,主模式*/

//	state = 0;
//	I2C_Send7bitAddress(I2C1, OLED_ADDRESS, I2C_Direction_Transmitter);//器件地址 -- 默认0x78
//	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) && (state++ < state_timeout));

//	state = 0;
//	I2C_SendData(I2C1, addr);//寄存器地址
//	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED) && (state++ < state_timeout));

//	state = 0;
//	I2C_SendData(I2C1, data);//发送数据
//	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED) && (state++ < state_timeout));
//	
//	I2C_GenerateSTOP(I2C1, ENABLE);//关闭I2C1总线
//	
//	if(state > state_timeout)return 1;
//	
//	return 0;

	u8 i, max_ack_times = 100;
	I2C_GenerateSTART(I2C1,ENABLE);
	
	i=0;
	while(i++<max_ack_times && !I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_MODE_SELECT));
	if(i>=max_ack_times) return 1;

	I2C_Send7bitAddress(I2C1,OLED_ADDRESS,I2C_Direction_Transmitter);
	
	i=0;
	while(i++<max_ack_times && !I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	if(i>=max_ack_times) return 2;

	I2C_SendData(I2C1,addr);
	
	i=0;
	while(i++<max_ack_times && !I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	if(i>=max_ack_times) return 3;

	I2C_SendData(I2C1,data);
	
	i=0;
	while(i++<max_ack_times && !I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	if(i>=max_ack_times) return 4;

	I2C_GenerateSTOP(I2C1,ENABLE);
	return 0;
}

u8 WriteCmd(unsigned char I2C_Command)//写命令
{
	return I2C_WriteByte(0x00, I2C_Command);
}

u8 WriteDat(unsigned char I2C_Data)//写数据
{
	return I2C_WriteByte(0x40, I2C_Data);
}

u8 OLED_Init(void)
{
	u8 state = 0;
	mdelay(100); //这里的延时很重要
	I2C_Configuration();
	
	state |= WriteCmd(0xAE); //display off
	state |= WriteCmd(0x20);	//Set Memory Addressing Mode	
	state |= WriteCmd(0x10);	//00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	state |= WriteCmd(0xb0);	//Set Page Start Address for Page Addressing Mode,0-7
	state |= WriteCmd(0xc8);	//Set COM Output Scan Direction
	state |= WriteCmd(0x00); //---set low column address
	state |= WriteCmd(0x10); //---set high column address
	state |= WriteCmd(0x40); //--set start line address
	state |= WriteCmd(0x81); //--set contrast control register
	state |= WriteCmd(0xff); //亮度调节 0x00~0xff
	state |= WriteCmd(0xa1); //--set segment re-map 0 to 127
	state |= WriteCmd(0xa6); //--set normal display
	state |= WriteCmd(0xa8); //--set multiplex ratio(1 to 64)
	state |= WriteCmd(0x3F); //
	state |= WriteCmd(0xa4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	state |= WriteCmd(0xd3); //-set display offset
	state |= WriteCmd(0x00); //-not offset
	state |= WriteCmd(0xd5); //--set display clock divide ratio/oscillator frequency
	state |= WriteCmd(0xf0); //--set divide ratio
	state |= WriteCmd(0xd9); //--set pre-charge period
	state |= WriteCmd(0x22); //
	state |= WriteCmd(0xda); //--set com pins hardware configuration
	state |= WriteCmd(0x12);
	state |= WriteCmd(0xdb); //--set vcomh
	state |= WriteCmd(0x20); //0x20,0.77xVcc
	state |= WriteCmd(0x8d); //--set DC-DC enable
	state |= WriteCmd(0x14); //
	state |= WriteCmd(0xaf); //--turn on oled panel
	
	OLED_CLS();
	
	return state;
}

void OLED_SetPos(unsigned char x, unsigned char y) //设置起始点坐标
{ 
	WriteCmd(0xb0+y);
	WriteCmd(((x&0xf0)>>4)|0x10);
	WriteCmd((x&0x0f)|0x01);
}

void OLED_Fill(unsigned char fill_Data)//全屏填充
{
	unsigned char m,n;
	for(m=0;m<8;m++)
	{
		WriteCmd(0xb0+m);		//page0-page1
		WriteCmd(0x00);		//low column start address
		WriteCmd(0x10);		//high column start address
		for(n=0;n<128;n++)
			{
				WriteDat(fill_Data);
			}
	}
}

void OLED_CLS(void)//清屏
{
	OLED_Fill(0x00);
}

//--------------------------------------------------------------
// Prototype      : void OLED_ON(void)
// Calls          : 
// Parameters     : none
// Description    : 将OLED从休眠中唤醒
//--------------------------------------------------------------
void OLED_ON(void)
{
	WriteCmd(0X8D);  //设置电荷泵
	WriteCmd(0X14);  //开启电荷泵
	WriteCmd(0XAF);  //OLED唤醒
}

//--------------------------------------------------------------
// Prototype      : void OLED_OFF(void)
// Calls          : 
// Parameters     : none
// Description    : 让OLED休眠 -- 休眠模式下,OLED功耗不到10uA
//--------------------------------------------------------------
void OLED_OFF(void)
{
	WriteCmd(0X8D);  //设置电荷泵
	WriteCmd(0X10);  //关闭电荷泵
	WriteCmd(0XAE);  //OLED休眠
}

//--------------------------------------------------------------
// Prototype      : void OLED_ShowChar(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize)
// Calls          : 
// Parameters     : x,y -- 起始点坐标(x:0~127, y:0~7); ch[] -- 要显示的字符串; TextSize -- 字符大小(1:6*8 ; 2:8*16)
// Description    : 显示codetab.h中的ASCII字符,有6*8和8*16可选择
//--------------------------------------------------------------
void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize)
{
	unsigned char c = 0,i = 0,j = 0;
	switch(TextSize)
	{
		case 1:
		{
			while(ch[j] != '\0')
			{
				c = ch[j] - 32;
				if(x > 126)
				{
					x = 0;
					y++;
				}
				OLED_SetPos(x,y);
				for(i=0;i<6;i++)
					WriteDat(F6x8[c][i]);
				x += 6;
				j++;
			}
		}break;
		case 2:
		{
			while(ch[j] != '\0')
			{
				c = ch[j] - 32;
				if(x > 120)
				{
					x = 0;
					y++;
				}
				OLED_SetPos(x,y);
				for(i=0;i<8;i++)
					WriteDat(F8X16[c*16+i]);
				OLED_SetPos(x,y+1);
				for(i=0;i<8;i++)
					WriteDat(F8X16[c*16+i+8]);
				x += 8;
				j++;
			}
		}break;
	}
}

//--------------------------------------------------------------
// Prototype      : void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N)
// Calls          : 
// Parameters     : x,y -- 起始点坐标(x:0~127, y:0~7); N:汉字在codetab.h中的索引
// Description    : 显示codetab.h中的汉字,16*16点阵
//--------------------------------------------------------------
void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N)
{
	unsigned char wm=0;
	unsigned int  adder=32*N;
	OLED_SetPos(x , y);
	for(wm = 0;wm < 16;wm++)
	{
		WriteDat(F16x16[adder]);
		adder += 1;
	}
	OLED_SetPos(x,y + 1);
	for(wm = 0;wm < 16;wm++)
	{
		WriteDat(F16x16[adder]);
		adder += 1;
	}
}

//--------------------------------------------------------------
// Prototype      : void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);
// Calls          : 
// Parameters     : x0,y0 -- 起始点坐标(x0:0~127, y0:0~7); x1,y1 -- 起点对角线(结束点)的坐标(x1:1~128,y1:1~8)
// Description    : 显示BMP位图
//--------------------------------------------------------------
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[])
{
	unsigned int j=0;
	unsigned char x,y;

  if(y1%8==0)
		y = y1/8;
  else
		y = y1/8 + 1;
	for(y=y0;y<y1;y++)
	{
		OLED_SetPos(x0,y);
		for(x=x0;x<x1;x++)
		{
			WriteDat(BMP[j++]);
		}
	}
}




