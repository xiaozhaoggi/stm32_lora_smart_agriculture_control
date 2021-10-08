#ifndef __GPIO_H
#define __GPIO_H 
#include "sys.h"


void gpio_Init(void);//初始化


#define BEEP 		PCout(5)

//定义CMD管脚
#define	CMD1		PEout(7)
#define	CMD2		PEout(8)
#define	CMD3		PEout(9)
#define	CMD4		PEout(10)
#define	CMD5		PEout(11)
#define	CMD6		PEout(12)
#define	CMD7		PEout(13)
#define	CMD8		PEout(14)
#define	CMD9		PEout(15)
#define	CMD10		PBout(10)
#define	CMD11		PCout(10)
#define	CMD12		PCout(11) 	
#define	CMD13		PCout(12)
#define	CMD14		PDout(0)
#define	CMD15		PDout(1)
#define	CMD16		PDout(2)
#define	CMD17		PDout(3)
#define	CMD18		PDout(4)
#define	CMD19		PDout(5)
#define	CMD20		PDout(6)

		 				    
#endif
