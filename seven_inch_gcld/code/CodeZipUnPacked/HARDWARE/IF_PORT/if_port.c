/********************* COPYRIGHT  **********************
* File Name        : if_port.c
* Author           : Levetop Electronics
* Version          : V1.0
* Date             : 2017-9-11
* Description      : ��ͬ�������ӿ�
********************************************************/


#include "usart.h" 
#include "if_port.h"

// ------------------------------------------------------------ SPI���� --------------------------------------------------------------------

void Delay_us(u16 time)
{    
   u16 i=0;  
   while(time--)
   {
      i=12;        //�Լ����� 12
      while(i--);    
   }
}

void Delay_ms(u16 time)
{    
   u16 i=0;  
   while(time--)
   {
      i=12000;    //�Լ�����
      while(i--);    
   }
}



void SPI_IO_Init(void)
{
	
	#if 0 //3wire SPI
	
   	GPIO_InitTypeDef  GPIO_InitStructure;	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD|RCC_AHB1Periph_GPIOF|RCC_AHB1Periph_GPIOG|RCC_AHB1Periph_GPIOB, ENABLE);//ʹ��GPIOB,D,F,Gʱ��

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5;//PD4,PD5����Ϊ�������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);//��ʼ��
	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;//PB15����Ϊ����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;//PG12����Ϊ�������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOG, &GPIO_InitStructure);//��ʼ��	

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;//PF12�����������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ��
	
	#endif 
	
	#if 1//4wire SPI

	GPIO_InitTypeDef  GPIO_InitStructure;	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD|RCC_AHB1Periph_GPIOF|RCC_AHB1Periph_GPIOG|RCC_AHB1Periph_GPIOB, ENABLE);//ʹ��GPIOB,D,F,Gʱ��

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5;//PD4,PD5����Ϊ�������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);//��ʼ��
	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;//PF11����Ϊ����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;//PG12����Ϊ�������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOG, &GPIO_InitStructure);//��ʼ��	

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;//PF12�����������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ��
	
	
	#endif
	
	
	

	
	
	
}

/*

void SDA_IN(void)
{
	
	GPIO_InitTypeDef  GPIO_InitStructure;	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//ʹ��GPIOFʱ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;//PF12
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//����ģʽ
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ��	
	
	
}


void SDA_OUT(void)
{
	
	GPIO_InitTypeDef  GPIO_InitStructure;	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//ʹ��GPIOFʱ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;//PF12
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ��	
	
	
}

*/



#if 1   //4wire SPI

void SPI_SendByte(u8 buf)
{
	u8 count = 0;
	//SDA_OUT();
	for(count = 0 ; count < 8 ; count++)
	{
		SCL=0;
		if(buf&0x80)	SDO=1;
		else            SDO=0;
		SCL=1;
		buf<<=1;
	}
	SCL=0;
	SDO=0;
}

u8 SPI_ReadByte(void)
{
	u8 count = 0;
	u8 val = 0;
	SDA_IN();
	for(count = 0 ; count < 8 ; count++)
	{
		val<<=1;
		SCL=0;
		__nop();
		__nop();
		//__nop();
		if(SDI == 1)	    val|=1;
		else		    	val&=0xfe;
		//Delay_us(1);
		SCL=1;
	}
	SCL=0;
	return val;
}

#endif



#if 0   //3wire SPI


void SPI_SendByte(u8 buf)
{
	u8 count = 0;
	SDA_OUT();
	for(count = 0 ; count < 8 ; count++)
	{
		SCL=0;
		if(buf&0x80)	SDA=1;
		else            SDA=0;
		SCL=1;
		buf<<=1;
	}
	SCL=0;
	SDA=0;
}

u8 SPI_ReadByte(void)
{
	u8 count = 0;
	u8 val = 0;
	SDA_IN();
	for(count = 0 ; count < 8 ; count++)
	{
		val<<=1;
		SCL=0;
		__nop();
		__nop();
		if(READ_SDA == 1)	val|=1;
		else		    	val&=0xfe;
		SCL=1;
	}
	SCL=0;
	return val;
}




#endif






void SPI_CmdWrite(u8 cmd)
{
	CS=0; 	      
	SPI_SendByte(0x00);
	SPI_SendByte(cmd);
	CS=1;
}

void SPI_DataWrite(u8 data)
{
	CS=0; 	      
	SPI_SendByte(0x80);
	SPI_SendByte(data);
	CS=1;
}


void SPI_DataWrite_Pixel(u16 data)
{
	CS=0; 	      
	SPI_SendByte(0x80);
	SPI_SendByte(data);
	CS=1;
	
	CS=0;
	SPI_SendByte(0x80);
	SPI_SendByte(data>>8);
	CS=1;
}


u8 SPI_StatusRead(void)
{
	u8 temp = 0;
	CS=0; 	      
	SPI_SendByte(0x40);
	temp = SPI_ReadByte();
	CS=1;
	return temp;
}

u16 SPI_DataRead(void)
{
	u8 temp = 0;
	CS=0; 	      
	SPI_SendByte(0xC0);
	temp = SPI_ReadByte();
	CS=1;
	return temp;
}





//-----------------------------------------------------------------------------------------------------------------------------------

void LCD_CmdWrite(u8 cmd)
{

	SPI_CmdWrite(cmd);

}

void LCD_DataWrite(u8 data)
{

	SPI_DataWrite(data);

}

void LCD_DataWrite_Pixel(u16 data)
{

	SPI_DataWrite_Pixel(data);

}


u8 LCD_StatusRead(void)
{
	u8 temp = 0;
	
	temp = SPI_StatusRead();
	
	return temp;
}

u16 LCD_DataRead(void)
{
	u16 temp = 0;
	
	temp = SPI_DataRead();
	
	return temp;
}
	  
	 


void Parallel_Init(void)
{

		SPI_IO_Init();

}



void test_SPIIO(void)
	
{  
  	
  u8 temp1,temp2;
  temp1=LCD_StatusRead();
  printf("Status:0x%X\r\n",temp1);//0x50


  LCD_CmdWrite(0x01);
  temp2 =LCD_DataRead();
  printf("R01h:0x%X\r\n",temp2);//0xC8
	
	
	
}












