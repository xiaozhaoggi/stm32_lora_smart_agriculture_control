#include "RS_XX.h"
#include "send.h"
#include "gpio.h"

/***************************************************************
Copyright  HUE of information and electrical engineering All rights reserved.
文件名		: RS_XX.c
作者	  	: 张博钊
版本	   	: V1.0
描述	   	: 设备控制及数据处理、中断
其他	   	: 无
网站 	   	: 无
日志	   	: 初版V1.0 2020/5/12 张博钊创建
***************************************************************/

u8 readAddrNow;//当前读取的设备地址码
u8 checkCrcBuff[260];
LORA_SEND_BUFF send; 
LORA_GET_BUFF get;
u8 get_sent_flag;       //接收网关请求数据标志位
u8 set_mode;


u8 dkc_status = DKC_close, wzy_status = WZY_close, nzy_status = NZY_close, 
	 nbw_status = NBW_close, wfc_status = WFC_close, wind1_status = WIND1_close,
	 wind2_status = WIND2_close, windround_status = WINDROUND_close, water_status = WATER_close,
	 light1_status = 0,light2_status = 0; //寄存器值初始化
	 
extern u16 base_num;
extern u16 lora_id;

void relay_control(u8 relay_reg, u8 cmd)
{	
	switch (relay_reg) {
	
		case DKC_REG:
			if(cmd == DKC_open)
				dkc_status = DKC_open;
			if(cmd == DKC_close)
				dkc_status = DKC_close;
			break;
		case WZY_REG:                  
			if(cmd == WZY_open)
				wzy_status = WZY_open;
			if(cmd == WZY_close)
				wzy_status = WZY_close;
			break;
		case NZY_REG:
			if(cmd == NZY_open)
				nzy_status = NZY_open;
			if(cmd == NZY_close)
				nzy_status = NZY_close;
			break;
		case NBW_REG:
			if(cmd == NBW_open)
				nbw_status = NBW_open;
			if(cmd == NBW_close)
				nbw_status = NBW_close;
			break;
		case WFC_REG:
			if(cmd == WFC_open)
				wfc_status = WFC_open;
			if(cmd == WFC_close)
				wfc_status = WFC_close;
			break;
		case WIND1_REG:
			if(cmd == WIND1_open)
				wind1_status = WIND1_open;
			if(cmd == WIND1_close)
				wind1_status = WIND1_close;
			break;
		case WIND2_REG:
			if(cmd == WIND2_open)
				wind2_status = WIND2_open;
			if(cmd == WIND2_close)
				wind2_status = WIND2_close;
			break;
		case WINDROUND_REG:
			if(cmd == WINDROUND_open)
				windround_status = WINDROUND_open;
			if(cmd == WINDROUND_close)
				windround_status = WINDROUND_close;
			break;
		case WATER_REG:
			if(cmd == WATER_open)
				water_status = WATER_open;
			if(cmd == WATER_close)
				water_status = WATER_close;
			break;
		case LIGHT1_REG:
			if(cmd == LIGHT1_open)
				light1_status = LIGHT1_open;
			if(cmd == 0)
				light1_status = 0;
			break;
		case LIGHT2_REG:
			if(cmd == LIGHT2_open)
				light2_status = LIGHT2_open;
			if(cmd == 0)
				light2_status = 0;
			break;
		case CLOSEALL_REG:
			if(cmd == CLOSEALL)
			{
				CMD1 = 0;
				CMD2 = 0;
				CMD3 = 0;
				CMD4 = 0;
				CMD5 = 0;
				CMD6 = 0;
				CMD7 = 0;
				CMD8 = 0;
				CMD9 = 0;
				CMD10 = 0;
				CMD11 = 0;
				CMD12 = 0;
				CMD13 = 0;
				CMD14 = 0;
				CMD15 = 0;
				CMD16 = 0;
				CMD17 = 0;
				CMD18 = 0;
				CMD19 = 0;
				CMD20 = 0;
			}
		default:
			break;
	
	}
	

}




void controlling(void)
{
			if(dkc_status == DKC_open)
				CMD1 = 1;
			if(dkc_status == DKC_close)
				CMD1 = 0;
			
			if(wzy_status == WZY_open)
				CMD2 = 1;
			if(wzy_status == WZY_close)
				CMD2 = 0;

			if(nzy_status == NZY_open)
				CMD3 = 1;
			if(nzy_status == NZY_close)
				CMD3 = 0;

			if(nbw_status == NBW_open)
				CMD4 = 1;
			if(nbw_status == NBW_close)
				CMD4 = 0;

			if(wfc_status == WFC_open)
				CMD5 = 1;
			if(wfc_status == WFC_close)
				CMD5 = 0;

			if(wind1_status == WIND1_open)
				CMD6 = 1;
			if(wind1_status == WIND1_close)
				CMD6 = 0;

			if(wind2_status == WIND2_open)
				CMD7 = 1;
			if(wind2_status == WIND2_close)
				CMD7 = 0;

			if(windround_status == WINDROUND_open)
				CMD8 = 1;
			if(windround_status == WINDROUND_close)
				CMD8 = 0;

			if(water_status == WATER_open)
				CMD9 = 1;
			if(water_status == WATER_close)
				CMD9 = 0;

			if(light1_status == LIGHT1_open)
				CMD10 = 1;
			if(light1_status == 0)
				CMD10 = 0;

			if(light2_status == LIGHT2_open)
				CMD11 = 1;
			if(light2_status == 0)
				CMD11 = 0;
	

}


////////////////////////////////////////////* modbus slave*////////////////////////////////////////////
//lora接收中断函数
void lora_get(void)
{
	static u8  					receiveIndex= 0;
	static u8  					reg_start  = 0;
	static u8  					reg_end   = 0;
  static u8    	      cmd_start = 0;
	static u8    	      cmd_end  = 0;
	static u16 					hight8_crc  = 0;//crc校验高8位
	static LORA_GET_BUFF * pget = 0;
	u8 Res;
	
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //
	{
//		USART_ClearITPendingBit(USART_RS_XX,USART_IT_RXNE);
		Res =USART_ReceiveData(USART1);//(USART_RS_XX->DR);	//读取接收到的数据
		//USART_SendByte(Res,USART1);
		if(Res == 0xaa && receiveIndex == 0)
			set_mode = 1;
		if(set_mode == 1)
			flash_485_write(Res);
		
		if(set_mode == 0)
		{
		switch(receiveIndex)
		{
			case 0://地址码
						if(Res == lora_id)
						{
						pget = &get;//获取对应的缓冲区地址
						readAddrNow = Res;
						receiveIndex++;
						}else
						{					
						receiveIndex= 0;
						reg_end   = 0;
				  	reg_start = 0;
					  cmd_start = 0;
					  cmd_end   = 0;
						hight8_crc = 0;
						pget = 0;
						}
				
				break;
						
			 case 1://功能码
				 if(Res == 0x06)
				 {
					 checkCrcBuff[0]   = lora_id;
					 checkCrcBuff[1]   = Res;
					 receiveIndex++;
				 }else
				 {
						receiveIndex= 0;
						reg_end   = 0;
				  	reg_start = 0;
					  cmd_start = 0;
					  cmd_end   = 0;
						hight8_crc = 0;
						pget = 0;
				 }
					break;
			 case 2://reg_start
				 reg_start = Res;
			   pget->reg_start = reg_start;
			   checkCrcBuff[2] = reg_start;
				 receiveIndex++;
				 break;
			 case 3: //reg_end
				 reg_end = Res;
			   pget->reg_end = reg_end;
			   checkCrcBuff[3] = reg_end;
				 receiveIndex++;
				 break;
			 case 4: //cmd_start
				 cmd_start = Res;
			   pget->cmd_start = cmd_start;
			   checkCrcBuff[4] = cmd_start;
				 receiveIndex++;
				 break;
			 case 5: // cmd_end
				 cmd_end = Res;
			   pget->cmd_end = cmd_end;
			   checkCrcBuff[5] = cmd_end;
				 receiveIndex++;
				 break;
			 case 6: // crc高八位获取
				 	hight8_crc = Res;
			    receiveIndex++;
			   break;
			 case 7: //crc判断
				 	pget->crc_check = (hight8_crc<<8) | Res;
			 
			    if(pget->crc_check == CRC_Check(checkCrcBuff,6))
					{
						pget->flag = 1;
						get_sent_flag = 1;    //如果校验成功，发送标志位置1
					}
						receiveIndex= 0;
						reg_end   = 0;
				  	reg_start = 0;
					  cmd_start = 0;
					  cmd_end   = 0;
						hight8_crc = 0;
						pget = 0;
			 default:
				 break;
			}

		}
	}
}



//lora发送数据函数   Uart 1 
 u8 buf1[100]={0};
void lora_send(void)
{
	 static LORA_SEND_BUFF * psend = 0;
	 u8 dataCount=0;
   u16 crc;
	 psend=&send;  
	buf1[0] = lora_id;  //本采集板地址
	buf1[1] = FUNC;				//功能码
    	 while(dataCount < 4)//接收有效返回字节
				 {  
 				 	 buf1[2+dataCount] = psend->data[dataCount];
					 dataCount++;
				 }
	crc    = CRC_Check(buf1,6);
	buf1[6] = crc>>8;
	buf1[7] = crc&0xff;
	USART_SendBytes(buf1,8,1); 


}

//CRC校验计算
u16 CRC_Check(const u8 *buff,u16 length)
{
	u16 n;
	u16 tmp=0xffff;
	u16 ret;
	u8 i;
	for(n = 0; n < length; n++)
	{
        tmp = buff[n] ^ tmp;
        for(i = 0;i < 8;i++)
				{
            if(tmp & 0x01){
                tmp = tmp >> 1;
                tmp = tmp ^ MULOR;
            }   
            else{
                tmp = tmp >> 1;
            }   
        }   
    }   
    ret = tmp >> 8;
    ret = ret | (tmp << 8);
		return ret;
}
