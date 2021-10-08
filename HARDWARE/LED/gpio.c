#include "gpio.h"

/***************************************************************
Copyright  HUE of information and electrical engineering All rights reserved.
�ļ���		: gpio.c
����	  	: �Ų���
�汾	   	: V1.0
����	   	: GPIO��ʼ��
����	   	: ��
��վ 	   	: ��
��־	   	: ����V1.0 2020/5/12 �Ų��ȴ���
***************************************************************/

void gpio_Init(void)
{
 
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��PA PB�˿�ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD, ENABLE);	 //ʹ��PC PD�˿�ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	 //ʹ��PE �˿�ʱ��	

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz


	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 // ������  �˿�����
	GPIO_Init(GPIOC, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOC.5
	GPIO_ResetBits(GPIOC,GPIO_Pin_5);						 //PC.5 �����

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;				 //LoRa EN  �˿�����
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.11
	GPIO_ResetBits(GPIOB,GPIO_Pin_11);						 //PA.11 �����
	
	//�̵���gpio��ʼ�� ˳��1-20
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;				
	GPIO_Init(GPIOE, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOE,GPIO_Pin_7); //PE7 1    

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				
	GPIO_Init(GPIOE, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOE,GPIO_Pin_8); //PE8 2

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				
	GPIO_Init(GPIOE, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOE,GPIO_Pin_9); //PE9 3

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;				
	GPIO_Init(GPIOE, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOE,GPIO_Pin_10); //PE10 4
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;				
	GPIO_Init(GPIOE, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOE,GPIO_Pin_11); //PE11 5		

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;				
	GPIO_Init(GPIOE, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOE,GPIO_Pin_12); //PE12 6

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;				
	GPIO_Init(GPIOE, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOE,GPIO_Pin_13); //PE13 7
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;				
	GPIO_Init(GPIOE, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOE,GPIO_Pin_14); //PE14 8
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;				
	GPIO_Init(GPIOE, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOE,GPIO_Pin_15); //PE15 9
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;				
	GPIO_Init(GPIOB, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOB,GPIO_Pin_10); //PB10 10
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;				
	GPIO_Init(GPIOC, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOC,GPIO_Pin_10); //PC10 11
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;				
	GPIO_Init(GPIOC, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOC,GPIO_Pin_11); //PC11 12
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;				
	GPIO_Init(GPIOC, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOC,GPIO_Pin_12); //PC12 13
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				
	GPIO_Init(GPIOD, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOD,GPIO_Pin_0); //PD0 14
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				
	GPIO_Init(GPIOD, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOD,GPIO_Pin_1); //PD1 15
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				
	GPIO_Init(GPIOD, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOD,GPIO_Pin_2); //PD2 16
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;				
	GPIO_Init(GPIOD, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOD,GPIO_Pin_3); //PD3 17
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;				
	GPIO_Init(GPIOD, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOD,GPIO_Pin_4); //PD4 18

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				
	GPIO_Init(GPIOD, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOD,GPIO_Pin_5); //PD5 19
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;				
	GPIO_Init(GPIOD, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOD,GPIO_Pin_6); //PD6 20
	
	

 
 
}
 
