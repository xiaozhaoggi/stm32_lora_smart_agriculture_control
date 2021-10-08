#ifndef RS_XX_H_
#define RS_XX_H_
#include "send.h"
#include "delay.h"

#define  MULOR  0xA001       //CRC������ʽ


// Lora ���ջ�����
typedef struct
{
#define  ADDR  0x01	;	//�����ذ�ڵ��ַ
#define  FUNC  0x06  ; //д�Ĵ����Ĺ����� 
	u8  reg_start;	  
	u8  reg_end;      
	u8  cmd_start;   
	u8  cmd_end;     
	u16 crc_check;//crcУ��
	u8  flag;     //��ʾ���ݰ��Ƿ����
}LORA_GET_BUFF;

// Lora ���ͻ�����
typedef struct
{
#define NODE_ADDR  0x01		//�����ذ�ڵ��ַ
#define FUNC 0x06 //д�Ĵ����Ĺ�����  
	u8  data[4];//������
	u16 crc_check;//crcУ��
}LORA_SEND_BUFF;

//�����豸��ַ��״ֵ̬
#define	DKC_REG					0X1A	//������
#define	DKC_open				0x01  //���������� 
#define	DKC_25					0x02	//������ 25
#define	DKC_50					0x03	//������ 50
#define	DKC_75					0x04	//������ 75
#define	DKC_auto				0x05	//�������Զ�ģʽ
#define	DKC_close				0x00	//������ֹͣ����

#define WZY_REG					0X1B	//������
#define WZY_open				0x01
#define WZY_25					0x02
#define WZY_50					0x03
#define WZY_75					0x04
#define WZY_auto				0x05
#define WZY_close				0x00

#define NZY_REG					0X1C	//������
#define NZY_open				0x01
#define NZY_25					0x02
#define NZY_50					0x03
#define NZY_75					0x04
#define NZY_auto				0x05
#define NZY_close    		0x00

#define NBW_REG					0X1D	//�ڱ���
#define NBW_open				0x01
#define NBW_25					0x02
#define NBW_50					0x03
#define NBW_75					0x04
#define NBW_auto				0x05
#define NBW_close				0x00

#define WFC_REG					0X1E	//�ⷭ��
#define WFC_open				0x01
#define WFC_25					0x02
#define WFC_50					0x03
#define WFC_75					0x04
#define WFC_auto				0x05
#define WFC_close				0x00

#define WIND1_REG				0X1F	//һ�����
#define WIND1_open 			0x01
#define WIND1_auto 			0x02
#define WIND1_hand			0x03
#define WIND1_close  		0x00

#define WIND2_REG 			0x20	//�������
#define WIND2_open			0x01
#define WIND2_auto			0x02
#define WIND2_hand			0x03	
#define WIND2_close			0x00

#define WINDROUND_REG		0X21	//�������
#define WINDROUND_open	0x01
#define WINDROUND_auto	0x02
#define WINDROUND_hand	0x03
#define WINDROUND_close 0x00

#define WATER_REG				0X22	//ʪ��ˮ��
#define WATER_open			0x01
#define WATER_auto			0x02
#define WATER_hand			0x03
#define WATER_close			0x00

#define LIGHT1_REG			0X23	//����1
#define LIGHT1_open			0x01
#define LIGHT1_close		0x00

#define LIGHT2_REG			0X24	//����2
#define LIGHT2_open			0x01
#define LIGHT2_close		0x00

#define CLOSEALL_REG    0X00 // ȫ��
#define CLOSEALL				0X00

static u16  CRC_Check(const u8 *buff,u16 length);
void lora_get(void);
void lora_send(void);
void relay_control(u8 relay_reg, u8 cmd);
void controlling(void);

#endif
