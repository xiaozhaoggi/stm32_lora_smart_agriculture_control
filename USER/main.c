/*
							   ���ذ�V1.0
					RS_XX.c/h   modbus �ӻ����� ��������
					G_USART.c/h ���ڼ������ж�����
					gpio.c/h		�̵���gpio����
					
					������ʽ��lora���յ�����ѶϢ�󣬽���modbusЭ��֡���پ�����������ʵ�̵ּ������أ�
									  ��ͨ��lora�����ط���modbusЭ��֡��
										
					          open Ϊ��    
										shutdown Ϊ��
*/


#include "gpio.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "RS_XX.h"
#include "stmflash.h"

/***************************************************************
Copyright  HUE of information and electrical engineering All rights reserved.
�ļ���		: main.c
����	  	: �Ų���
�汾	   	: V1.0
����	   	: ������
����	   	: ��
��վ 	   	: ��
��־	   	: ����V1.0 2020/5/12�Ų��ȴ���
***************************************************************/

extern LORA_GET_BUFF get;
extern LORA_SEND_BUFF send;
extern u8 get_sent_flag;       			 //���������������ݱ�־λ
 int main(void)
 {	
	u16  relay_reg = 0;
	u16  cmd;
	delay_init();	    	 //��ʱ������ʼ��	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2
	gpio_Init();		  	 //��ʼ����LED���ӵ�Ӳ���ӿ� 
	flash_init();
	uart_init(9600);

	while(1)
{ 
	
					
		        
	if(get_sent_flag == 1)
	{	
		get.reg_start = get.reg_start << 4;
		relay_reg = get.reg_start | get.reg_end;
		
		get.cmd_start = get.cmd_start << 4;
		cmd = get.cmd_start | get.cmd_end;
		
		relay_control(relay_reg, cmd);
		controlling();
		
		send.data[0] = get.reg_start;
		send.data[1] = get.reg_end;
		send.data[2] = get.cmd_start;
		send.data[3] = get.cmd_end;
		
		lora_send();
		get_sent_flag = 0 ;
	}
					
					
}	 

 
}



