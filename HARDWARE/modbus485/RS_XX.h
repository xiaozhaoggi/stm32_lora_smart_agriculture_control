#ifndef RS_XX_H_
#define RS_XX_H_
#include "send.h"
#include "delay.h"

#define  MULOR  0xA001       //CRC异或多项式


// Lora 接收缓冲区
typedef struct
{
#define  ADDR  0x01	;	//本主控板节点地址
#define  FUNC  0x06  ; //写寄存器的功能码 
	u8  reg_start;	  
	u8  reg_end;      
	u8  cmd_start;   
	u8  cmd_end;     
	u16 crc_check;//crc校验
	u8  flag;     //表示数据包是否就绪
}LORA_GET_BUFF;

// Lora 发送缓冲区
typedef struct
{
#define NODE_ADDR  0x01		//本主控板节点地址
#define FUNC 0x06 //写寄存器的功能码  
	u8  data[4];//数据区
	u16 crc_check;//crc校验
}LORA_SEND_BUFF;

//控制设备地址及状态值
#define	DKC_REG					0X1A	//顶开窗
#define	DKC_open				0x01  //顶开窗开窗 
#define	DKC_25					0x02	//顶开窗 25
#define	DKC_50					0x03	//顶开窗 50
#define	DKC_75					0x04	//顶开窗 75
#define	DKC_auto				0x05	//顶开窗自动模式
#define	DKC_close				0x00	//顶开窗停止工作

#define WZY_REG					0X1B	//外遮阳
#define WZY_open				0x01
#define WZY_25					0x02
#define WZY_50					0x03
#define WZY_75					0x04
#define WZY_auto				0x05
#define WZY_close				0x00

#define NZY_REG					0X1C	//内遮阳
#define NZY_open				0x01
#define NZY_25					0x02
#define NZY_50					0x03
#define NZY_75					0x04
#define NZY_auto				0x05
#define NZY_close    		0x00

#define NBW_REG					0X1D	//内保温
#define NBW_open				0x01
#define NBW_25					0x02
#define NBW_50					0x03
#define NBW_75					0x04
#define NBW_auto				0x05
#define NBW_close				0x00

#define WFC_REG					0X1E	//外翻窗
#define WFC_open				0x01
#define WFC_25					0x02
#define WFC_50					0x03
#define WFC_75					0x04
#define WFC_auto				0x05
#define WFC_close				0x00

#define WIND1_REG				0X1F	//一级风机
#define WIND1_open 			0x01
#define WIND1_auto 			0x02
#define WIND1_hand			0x03
#define WIND1_close  		0x00

#define WIND2_REG 			0x20	//二级风机
#define WIND2_open			0x01
#define WIND2_auto			0x02
#define WIND2_hand			0x03	
#define WIND2_close			0x00

#define WINDROUND_REG		0X21	//环流风机
#define WINDROUND_open	0x01
#define WINDROUND_auto	0x02
#define WINDROUND_hand	0x03
#define WINDROUND_close 0x00

#define WATER_REG				0X22	//湿帘水泵
#define WATER_open			0x01
#define WATER_auto			0x02
#define WATER_hand			0x03
#define WATER_close			0x00

#define LIGHT1_REG			0X23	//照明1
#define LIGHT1_open			0x01
#define LIGHT1_close		0x00

#define LIGHT2_REG			0X24	//照明2
#define LIGHT2_open			0x01
#define LIGHT2_close		0x00

#define CLOSEALL_REG    0X00 // 全关
#define CLOSEALL				0X00

static u16  CRC_Check(const u8 *buff,u16 length);
void lora_get(void);
void lora_send(void);
void relay_control(u8 relay_reg, u8 cmd);
void controlling(void);

#endif
