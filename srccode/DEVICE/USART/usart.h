#ifndef _USART_H
#define _USART_H

#include "stm32f10x.h"
#include "stdio.h"


#define TxD_Pin GPIO_Pin_9
#define RxD_Pin GPIO_Pin_10


void Usart_Init(unsigned int baudRate);

#endif

