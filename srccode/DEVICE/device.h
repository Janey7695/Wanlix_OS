#ifndef _DEVICE_H
#define _DEVICE_H

#include "stm32f10x.h"

/* ���蹦������ */
#define OS_OLED_EN				0
#define OS_USART_EN				0


#if OS_OLED_EN
#include "oled.h"
#include "draw_api.h"
#endif

#if OS_USART_EN
#include "usart.h"
#endif


/*********����˿��ض���********/


//LED -> PB5
#define LED_GPIO GPIOB
#define LED_Pin GPIO_Pin_5



void DEV_Init(void);
void DEV_DelayMs(unsigned int uiMs);


#endif




