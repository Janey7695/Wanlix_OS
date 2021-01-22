#include "global.h"


void WLX_RootTask(void)
{
	DEV_Init();
	#if OS_OLED_EN
	OLED_ShowString(0,0,"Wanlix_OS",16);
	OLED_ShowString(0,2,"Task Init...",8);
	#endif
	
	#if OS_USART_EN
	printf("\n\r************ Wanlix OS ************\n\r");
	printf("\n\r*    Version:");
	printf("%s",WLX_GetWanlixVersion());
	printf("        *\n\r");
	printf("\n\r*---------------------------------*\n\r");
	#endif
	
	/*****初始化任务的TCB*****/
	Task1Tcb = WLX_TaskCreate(TEST_TestTask1,Task1Stack,TASKSTACK);
	Task2Tcb = WLX_TaskCreate(TEST_TestTask2,Task2Stack,TASKSTACK);
	Task3Tcb = WLX_TaskCreate(TEST_TestTask3,Task3Stack,TASKSTACK);
	
	
	#if OS_OLED_EN
	OLED_ShowString(0,2,"Task Init OK",8);
	OLED_ShowString(0,5,"Version:",8);
	OLED_ShowString(0,6,WLX_GetWanlixVersion(),8);
	OLED_ShowString(0,3,"Task 1 Run",8);
	#endif
	
	#if OS_USART_EN
	printf("\n\r>> OS Run\n\r");
	#endif
	
	WLX_TaskSwitch(Task1Tcb);
}


