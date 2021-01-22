#include "global.h"

U8 Task1Stack[TASKSTACK];      /* ����1��ջ */
U8 Task2Stack[TASKSTACK];      /* ����2��ջ */
U8 Task3Stack[TASKSTACK];      /* ����3��ջ */

W_TCB* Task1Tcb;				//����1��TCBָ��
W_TCB* Task2Tcb;				//����2��TCBָ��
W_TCB* Task3Tcb;				//����3��TCBָ��

void TEST_TestTask1(void)
{
	while(1)
	{
		GPIO_ResetBits(LED_GPIO,LED_Pin);
		#if OS_OLED_EN
		OLED_ShowString(0,3,"Task 1 Run",8);
		#endif
		#if OS_USART_EN
		printf(">> TASK 1 Running\n\r");
		#endif
		DEV_DelayMs(1000);
		
		WLX_TaskSwitch(Task2Tcb);
	}
}

void TEST_TestTask2(void)
{
	while(1)
	{
		GPIO_SetBits(LED_GPIO,LED_Pin);
		#if OS_OLED_EN
		OLED_ShowString(0,3,"Task 2 Run",8);
		#endif
		#if OS_USART_EN
		printf(">> TASK 2 Running\n\r");
		#endif
		DEV_DelayMs(2000);
		WLX_TaskSwitch(Task3Tcb);
	}
}
void TEST_TestTask3(void)
{
	while(1)
	{
		GPIO_ResetBits(LED_GPIO,LED_Pin);
		#if OS_OLED_EN
		OLED_ShowString(0,3,"Task 3 Run",8);
		#endif
		#if OS_USART_EN
		printf(">> TASK 3 Running\n\r");
		#endif
		DEV_DelayMs(3000);
		WLX_TaskSwitch(Task1Tcb);
	}
}


