/*
							   主控板V1.0
					RS_XX.c/h   modbus 从机配置 程序主体
					G_USART.c/h 串口及串口中断配置
					gpio.c/h		继电器gpio配置
					
					工作方式：lora接收到网关讯息后，解析modbus协议帧，再经过函数处理，实现继电器开关，
									  再通过lora向网关返回modbus协议帧。
										
					          open 为开    
										shutdown 为关
*/


#include "gpio.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "RS_XX.h"
#include "stmflash.h"

/***************************************************************
Copyright  HUE of information and electrical engineering All rights reserved.
文件名		: main.c
作者	  	: 张博钊
版本	   	: V1.0
描述	   	: 主函数
其他	   	: 无
网站 	   	: 无
日志	   	: 初版V1.0 2020/5/12张博钊创建
***************************************************************/

extern LORA_GET_BUFF get;
extern LORA_SEND_BUFF send;
extern u8 get_sent_flag;       			 //接收网关请求数据标志位
 int main(void)
 {	
	u16  relay_reg = 0;
	u16  cmd;
	delay_init();	    	 //延时函数初始化	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2
	gpio_Init();		  	 //初始化与LED连接的硬件接口 
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



