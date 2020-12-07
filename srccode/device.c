#include "global.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIOInitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIOInitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOInitStruct.GPIO_Pin=LED_Pin;
	GPIOInitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(LED_GPIO,&GPIOInitStruct);
	
	GPIO_SetBits(LED_GPIO,LED_Pin);
}


void DEV_DelayMs(U32 uiMs)
{
    U32 i;
    U32 j;

    j = 5540 * uiMs;

    for(i = 0; ; i++)
    {
        if(i == j)
        {
            break;
        }
    }
}

