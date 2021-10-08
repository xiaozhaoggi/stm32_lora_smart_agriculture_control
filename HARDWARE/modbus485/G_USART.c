#include "G_USART.h"
#include "G_EC20.h"
#include "RS_XX.h"

/***************************************************************
Copyright  HUE of information and electrical engineering All rights reserved.
�ļ���		: G_USART.c
����	  	: �Ų���
�汾	   	: V1.0
����	   	: ���ڳ�ʼ��
����	   	: ��
��վ 	   	: ��
��־	   	: ����V1.0 2020/5/12 �Ų��ȴ���
***************************************************************/

u8 g_HaveUSARTConfigured[6] = {0};
u8 g_USART1_ReceivedBuf 		= 0;

static USART_TypeDef *USART_Print;

void uart_init(u32 bound){
  //GPIO�˿�����
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//ʹ��GPIOAʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE); //ʹ��USART1ʱ��
  
	//USART1_TX   GPIOA.9
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
  GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.9
   
  //USART1_RX	  GPIOA.10��ʼ��
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
  GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.10  

  //Usart1 NVIC ����
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1 ;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		//�����ȼ�2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
	
	
   //USART ��ʼ������

	USART_InitStructure.USART_BaudRate = bound;//���ڲ�����
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ

  USART_Init(USART1, &USART_InitStructure); //��ʼ������1
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//�������ڽ����ж�
  USART_Cmd(USART1, ENABLE);                    //ʹ�ܴ���1 
	
}

void USART_SendByte(u8 byte,USART_TypeDef *USARTx)
{	
	if	(((USARTx == USART1) && g_HaveUSARTConfigured[0])
		 ||((USARTx == USART2) &&	g_HaveUSARTConfigured[1])
		 ||((USARTx == USART3) &&	g_HaveUSARTConfigured[2])
		 ||((USARTx == UART4)  &&	g_HaveUSARTConfigured[3])
		 ||((USARTx == UART5)  &&	g_HaveUSARTConfigured[4])
       )
	{
	while(!USART_GetFlagStatus(USARTx,USART_FLAG_TC))
   USART_SendData(USARTx,byte);
	}
}

void protocolSend_BoChuang(USART_TypeDef *USARTx,BoChuang_Protocol* protocol)
{
	u16 i = 0;
	USART_SendByte(0x55,USARTx);
	USART_SendByte(0xaa,USARTx);
	USART_SendByte(protocol->ID,USARTx);
	USART_SendByte(protocol->length,USARTx);
	USART_SendByte(protocol->cmd,USARTx);
	protocol->sum = 0x55 + 0xaa + protocol->ID + protocol->length + protocol->cmd;
	for(i=0; i<protocol->length; i++)
	{
		USART_SendByte(protocol->data[i],USARTx);
		protocol->sum += protocol->data[i];
	}
	for(i=0; i<4; i++)
	{
		USART_SendByte(protocol->sum>>((3-i)*8)&0xff,USARTx);
	}

}


void USART_PrintfInit(USART_TypeDef* USARTx)
{
	USART_Print = USARTx;
}

//�ض���printf
int fputc(int ch,FILE * stream)
{
	USART_SendByte((u8)ch,USART_Print);
	return ch;
}

void USART1_IRQHandler(void)
{
	lora_get();
}

