/********************* COPYRIGHT  **********************
* File Name        : if_port.h
* Author           : Levetop Electronics
* Version          : V1.0
* Date             : 2017-9-11
* Description      : ѡ��ͬ�������ӿ�
********************************************************/

#ifndef _if_port_h
#define _if_port_h
#include "sys.h"      // STM32��ͷ�ļ�

/*

//-------- ֻ�ܿ���һ������ ----------
#define STM32_FSMC_8  0     // ʹ��STM32������FSMC����LT768(STM32Ӳ��ģ��8080����(8λ))
#define STM32_FSMC_16 0     // ʹ��STM32������FSMC����LT768(STM32Ӳ��ģ��8080����(16λ))
#define STM32_SPI     1     // ʹ��STM32��SPI����LT768
#define STM32_IIC     0     // ʹ��STM32��IIC����LT768

*/
//#define STM32_SPI     1




#if 0 //3wire SPI

#define SDA_IN()  {GPIOF->MODER&=~(3<<(2*12));GPIOF->MODER|=0<<2*12;} //PF12����ģʽ
#define SDA_OUT() {GPIOF->MODER&=~(3<<(2*12));GPIOF->MODER|=1<<2*12;} //PF12���ģʽ

#define CS  		PGout(12) 
#define SCL  		PDout(5)
#define SDA  		PFout(12)
#define READ_SDA    PFin(12)
#define RESET  		PDout(4)

#endif 



#if 1 //4wire SPI

#define SDA_IN()  {GPIOB->MODER&=~(3<<(2*15));GPIOB->MODER|=0<<2*15;}//PB15����ģʽ
//#define SDA_OUT() {GPIOF->MODER&=~(3<<(2*12));GPIOF->MODER|=1<<2*12;}//PF12���ģʽ


#define CS  		PGout(12) 
#define SCL  		PDout(5)
//#define SDI  		PFin(11)
#define SDI  		PBin(15)
#define SDO    		PFout(12)
#define RESET  		PDout(4)


#endif








void Parallel_Init(void);
void SPI_IO_Init(void);

void LCD_CmdWrite(u8 cmd);
void LCD_DataWrite(u8 data);
void LCD_DataWrite_Pixel(u16 data);
u8 LCD_StatusRead(void);
u16 LCD_DataRead(void);
	 
void Delay_us(u16 time); //��ʱ����us��
void Delay_ms(u16 time); //��ʱ����ms��

void test_SPIIO(void);



#endif
