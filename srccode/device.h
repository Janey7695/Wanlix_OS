#ifndef _DEVICE_H
#define _DEVICE_H

#include "stm32f10x.h"

#define LED_GPIO GPIOB
#define LED_Pin GPIO_Pin_5


void LED_Init(void);
void DEV_DelayMs(unsigned int uiMs);
#endif




