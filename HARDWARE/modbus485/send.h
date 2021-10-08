#ifndef __SEND_H
#define __SEND_H
#include "G_USART.h"
#include "G_Switch.h"
void USART_SendBytes(const u8 * pstr,u16 len ,u8 UARTx);
#endif
