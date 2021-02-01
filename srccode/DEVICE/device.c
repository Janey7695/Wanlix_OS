#include "global.h"
//初始化设备
void DEV_Init(void)
{
	GPIO_InitTypeDef GPIOInitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIOInitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOInitStruct.GPIO_Pin=LED_Pin;
	GPIOInitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(LED_GPIO,&GPIOInitStruct);
	GPIO_SetBits(LED_GPIO,LED_Pin);
	
	#if OS_OLED_EN
	OLED_Init();
	OLED_Clear();
	#endif
	
	#if OS_USART_EN
	Usart_Init(115200);
	#endif
}

//软件延时函数
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






