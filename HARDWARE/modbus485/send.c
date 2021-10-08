#include "send.h"
#include "delay.h"

/***************************************************************
Copyright  HUE of information and electrical engineering All rights reserved.
文件名		: send.c
作者	  	: 张博钊
版本	   	: V1.0
描述	   	: 串口发送数据
其他	   	: 无
网站 	   	: 无
日志	   	: 初版V1.0 2020/5/12 张博钊创建
***************************************************************/


void USART_SendBytes(const u8 * pstr,u16 len ,u8 UARTx)
{
	int i=0;

	if(UARTx == 1)
 {
	for(i=0;i<len;i++)
	{ while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);	  
		USART_SendData(USART1,pstr[i]);
	}
 }

}


