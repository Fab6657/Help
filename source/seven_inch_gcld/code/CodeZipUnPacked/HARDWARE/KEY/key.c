#include "key.h"

void KEY_Init(void)
{
	/*
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;	
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOB, &GPIO_InitStructure); 
	*/
	
	GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOE, ENABLE);//ʹ��GPIOA,GPIOEʱ��

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4; //KEY0 KEY1 KEY2��Ӧ����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
    GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��GPIOE2,3,4


    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//WK_UP��Ӧ����PA0
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN ;//����
    GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA0
}


unsigned char Scan_Key(void)
{
	static unsigned char key_up=1;//�������ɿ���־
	if(key_up&&(KEY1==0||KEY2==0))
	{
		delay_ms(10);//ȥ���� 
		key_up=0;
		if(KEY1==0)							return KEY1_PRES;
		else if(KEY2==0)				return KEY2_PRES;
	}
	else if(KEY1==1&&KEY2==1)
	{
		key_up=1; 	    
	}
	
 	return 0;// �ް�������
}


void Waiting_Key(void)
{
	unsigned char key = 0;
	do
	{
		__NOP();
		key = Scan_Key();
	}
	while(key == 0);
}


void WaitKey(void)
{
	delay_ms(200);
	while(KEY1==1);//�ȴ�KEY1���� KEY0  KEY2   WK_UP������
	delay_ms(200);	
}


unsigned char Scan_Key_delay(unsigned int t)
{
	unsigned char key = 0;
	unsigned int i = 0;
	for(i = 0 ; i < t ; i++)
	{
		delay_ms(1);
		key = Scan_Key();
		if(key == KEY1_PRES)	return 1;
		if(key == KEY2_PRES)	return 1;
	}
	return 0;
}




unsigned char Scan_FunctionKey(void)
{
	unsigned char key = 0;
	unsigned char state1 = 0;
	unsigned char state2 = 0;
	unsigned int key1_count = 0;
	unsigned int key2_count = 0;
	
	while(1)
	{
		delay_ms(1);
		key = Scan_Key();
		
		if((state1==0)&&(state2==0))
		{
			if((key == KEY1_PRES)||(key == KEY2_PRES))
			{
				if(key == KEY1_PRES)			state1 = 1;
				else if(key == KEY2_PRES)	state2 = 1;
			}
		}
		
		if(state1 == 1)
		{
			if(KEY1 == 0)
			{
				key1_count++;
			}
			else
			{
				break;
			}
		}
		else if(state2 == 1)
		{
			if(KEY2 == 0)
			{
				key2_count++;
			}
			else
			{
				break;
			}
		}
	}
	
	if(key1_count >= 500)												return 3;
	else if((key1_count>0) && (key1_count<500))	return 1;
	
	if(key2_count >= 500)												return 3;
	else if((key2_count>0) && (key2_count<500))	return 2;
	
	return 0;
}







