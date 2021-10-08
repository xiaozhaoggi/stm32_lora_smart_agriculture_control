#include "send.h"
#include "delay.h"

/***************************************************************
Copyright  HUE of information and electrical engineering All rights reserved.
�ļ���		: send.c
����	  	: �Ų���
�汾	   	: V1.0
����	   	: ���ڷ�������
����	   	: ��
��վ 	   	: ��
��־	   	: ����V1.0 2020/5/12 �Ų��ȴ���
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


