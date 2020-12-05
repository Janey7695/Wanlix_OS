#include "wlx_core_c.h"

U32 guiCurTask;                         /* 当前运行的任务 */

W_TCB* gpstrTask1Tcb;                   /* 任务1的TCB指针 */
W_TCB* gpstrTask2Tcb;                   /* 任务2的TCB指针 */


/*************************任务初始化函数*******************************
*
*   函数功能: 创建单个任务运行前的状态.
*	入口参数: vfFuncPointer: 任务运行的函数指针.
*         puiTaskStack: 任务使用的栈地址.
*	返 回 值: 任务的TCB指针.
**********************************************************************/
W_TCB* WLX_TaskInit(VFUNC vfuncPointer,U32* puiTaskStack)
{
	W_TCB* pstrTcb;
	STACKREG* pstrStackReg;
	//对于递减栈，TCb要放在栈顶，因此对于一个数组（栈），需要求其末地址，然后在末地址的基础上减去TCB的大小才是TCB存放的位置
	pstrTcb = (W_TCB*)((U32)puiTaskStack-sizeof(W_TCB));
	pstrStackReg = &pstrTcb->strStackReg;
	pstrStackReg->uiR4 = 0;
	pstrStackReg->uiR5 = 0;
	pstrStackReg->uiR6 = 0;
	pstrStackReg->uiR7 = 0;
	pstrStackReg->uiR8 = 0;
	pstrStackReg->uiR9 = 0;
	pstrStackReg->uiR10 = 0;
	pstrStackReg->uiR11 = 0;
	pstrStackReg->uiR12 = 0;
	pstrStackReg->uiR13 = (U32)pstrTcb;
	pstrStackReg->uiR14 = (U32)vfuncPointer;
	pstrStackReg->uiXpsr = MODE_USR;
	
	return pstrTcb;
	
}



/*************************任务启动函数*******************************
*
*   函数功能: 开始运行第一个任务
*	入口参数: none
*	返 回 值: none
**********************************************************************/
void WLX_TaskStart(void)
{
    STACKREG* pstrNextTaskStackRegAddr;

    /* 即将运行任务寄存器组的地址 */
    pstrNextTaskStackRegAddr = &gpstrTask1Tcb->strStackReg;

    /* 更新下次调度的任务 */
    guiCurTask = 1;

    /* 切换到任务状态 */
    WLX_SwitchToTask(pstrNextTaskStackRegAddr);
}

/*************************任务切换函数*******************************
*
*   函数功能: 任务切换
*	入口参数: none
*	返 回 值: none
**********************************************************************/
void WLX_TaskSwitch(void)
{
    STACKREG* pstrCurTaskStackRegAddr;
    STACKREG* pstrNextTaskStackRegAddr;

    if(1 == guiCurTask)
    {
        /* 当前任务寄存器组的地址 */
        pstrCurTaskStackRegAddr = &gpstrTask1Tcb->strStackReg;

        /* 即将运行任务寄存器组的地址 */
        pstrNextTaskStackRegAddr = &gpstrTask2Tcb->strStackReg;

        /* 更新下次运行的任务 */
        guiCurTask = 2;
    }
    else //if(2 == guiCurTask)
    {
        pstrCurTaskStackRegAddr = &gpstrTask2Tcb->strStackReg;
        pstrNextTaskStackRegAddr = &gpstrTask1Tcb->strStackReg;

        guiCurTask = 1;
    }

    /* 切换任务 */
    WLX_ContextSwitch(pstrCurTaskStackRegAddr, pstrNextTaskStackRegAddr);
}

