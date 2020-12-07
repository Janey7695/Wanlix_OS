#include "global.h"


U8 Task1Stack[TASKSTACK];      /* 任务1的栈 */
U8 Task2Stack[TASKSTACK];      /* 任务2的栈 */
U8 Task3Stack[TASKSTACK];      /* 任务3的栈 */

W_TCB* Task1Tcb;				//任务1的TCB指针
W_TCB* Task2Tcb;				//任务2的TCB指针
W_TCB* Task3Tcb;				//任务3的TCB指针

/*********** 任务声明 *************/
void TEST_TestTask1(void);
void TEST_TestTask2(void);
void TEST_TestTask3(void);

S32 main(void)
{				 
	SystemInit();
	DEV_Init();
	#if OS_OLED_EN
	OLED_ShowString(0,0,"Wanlix_OS",16);
	OLED_ShowString(0,2,"Task Init...",8);
	#endif
	/*****初始化任务的TCB*****/
	Task1Tcb = WLX_TaskCreate(TEST_TestTask1,Task1Stack,TASKSTACK);
	Task2Tcb = WLX_TaskCreate(TEST_TestTask2,Task2Stack,TASKSTACK);
	Task3Tcb = WLX_TaskCreate(TEST_TestTask3,Task3Stack,TASKSTACK);
	#if OS_OLED_EN
	OLED_ShowString(0,2,"Task Init OK",8);
	OLED_ShowString(0,5,"Version:",8);
	OLED_ShowString(0,6,WLX_GetWanlixVersion(),8);
	#endif
	//启动任务，OS启动
	WLX_TaskStart(Task1Tcb);
	
	return 0;
}

void TEST_TestTask1(void)
{
	while(1)
	{
		GPIO_ResetBits(LED_GPIO,LED_Pin);
		#if OS_OLED_EN
		OLED_ShowString(0,3,"Task 1 Run",8);
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
		DEV_DelayMs(2000);
		WLX_TaskSwitch(Task3Tcb);
	}
}
void TEST_TestTask3(void)
{
	while(1)
	{
		GPIO_SetBits(LED_GPIO,LED_Pin);
		#if OS_OLED_EN
		OLED_ShowString(0,3,"Task 3 Run",8);
		#endif
		DEV_DelayMs(3000);
		WLX_TaskSwitch(Task1Tcb);
	}
}


