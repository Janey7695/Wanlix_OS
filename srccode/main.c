#include "global.h"


//extern void TEST_TestTask1(void);
//extern void TEST_TestTask2(void);
//extern U32* TEST_GetTaskInitSp(U8 ucTask);

U32 gauiTask1Stack[TASKSTACK];      /* 任务1的栈 */
U32 gauiTask2Stack[TASKSTACK];      /* 任务2的栈 */

void TEST_TestTask1(void);
void TEST_TestTask2(void);
U32* TEST_GetTaskInitSp(U8 ucTask);


S32 main(void)
{				 
	SystemInit();
	LED_Init();
	gpstrTask1Tcb=WLX_TaskInit(TEST_TestTask1,TEST_GetTaskInitSp(1));
	gpstrTask2Tcb=WLX_TaskInit(TEST_TestTask2,TEST_GetTaskInitSp(2));

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
        return (gauiTask1Stack + TASKSTACK);
    }
    else //if(2 == ucTask)
    {
        return (gauiTask2Stack + TASKSTACK);
    }
}

