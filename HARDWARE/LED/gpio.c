#include "gpio.h"

/***************************************************************
Copyright  HUE of information and electrical engineering All rights reserved.
文件名		: gpio.c
作者	  	: 张博钊
版本	   	: V1.0
描述	   	: GPIO初始化
其他	   	: 无
网站 	   	: 无
日志	   	: 初版V1.0 2020/5/12 张博钊创建
***************************************************************/

void gpio_Init(void)
{
 
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);	 //使能PA PB端口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD, ENABLE);	 //使能PC PD端口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	 //使能PE 端口时钟	

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz


	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 // 蜂鸣器  端口配置
	GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIOC.5
	GPIO_ResetBits(GPIOC,GPIO_Pin_5);						 //PC.5 输出低

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;				 //LoRa EN  端口配置
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.11
	GPIO_ResetBits(GPIOB,GPIO_Pin_11);						 //PA.11 输出低
	
	//继电器gpio初始化 顺序1-20
	
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
 
