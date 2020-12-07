#include "global.h"


U32 gauiTask1Stack[TASKSTACK];      /* 任务1的栈 */
U32 gauiTask2Stack[TASKSTACK];      /* 任务2的栈 */

/*********** 任务声明 *************/
void TEST_TestTask1(void);
void TEST_TestTask2(void);
U32* TEST_GetTaskInitSp(U8 ucTask);


S32 main(void)
{				 
	SystemInit();
	LED_Init();
	/*****初始化任务的TCB*****/
	gpstrTask1Tcb=WLX_TaskInit(TEST_TestTask1,TEST_GetTaskInitSp(1));
	gpstrTask2Tcb=WLX_TaskInit(TEST_TestTask2,TEST_GetTaskInitSp(2));
	
	//启动任务，OS启动
	WLX_TaskStart();
	
	return 0;
}

void TEST_TestTask1(void)
{
	while(1)
	{
	GPIO_ResetBits(LED_GPIO,LED_Pin);
	DEV_DelayMs(1000);
	WLX_TaskSwitch();
	}
}

void TEST_TestTask2(void)
{
	while(1)
	{
	GPIO_SetBits(LED_GPIO,LED_Pin);
	DEV_DelayMs(2000);
	WLX_TaskSwitch();
	}
}

U32* TEST_GetTaskInitSp(U8 ucTask)
{
    if(1 == ucTask)
    {
        return (gauiTask1Stack + TASKSTACK);//找到数组的末地址（满递减）
    }
    else //if(2 == ucTask)
    {
        return (gauiTask2Stack + TASKSTACK);
    }
}

