#include "wlx_core_c.h"


U8 gaucRootTaskStack[ROOTTASKSTACK];

W_TCB* gpstrCurTcb;                   /* 当前运行任务的TCB指针 */

W_TCB* gpstrRootTaskTcb;



S32 main(void)
{
	gpstrRootTaskTcb = WLX_TaskCreate(WLX_RootTask,gaucRootTaskStack,ROOTTASKSTACK);
	
	WLX_TaskStart(gpstrRootTaskTcb);
	
	return 0;
}

/***********************************************************************************
函数功能: 初始化任务栈函数, 用来创建任务运行前的栈状态.
入口参数: pstrTcb: 任务的TCB指针.
          vfFuncPointer: 任务运行的函数.
返 回 值: none.
***********************************************************************************/
static void WLX_TaskStackInit(W_TCB* pstrTcb, VFUNC vfFuncPointer)
{
    STACKREG* pstrStackReg;

    /* 寄存器组地址 */
    pstrStackReg = &pstrTcb->strStackReg;

    /* 对TCB中的寄存器组初始化 */
    pstrStackReg->uiR4 = 0;                     /* R4 */
    pstrStackReg->uiR5 = 0;                     /* R5 */
    pstrStackReg->uiR6 = 0;                     /* R6 */
    pstrStackReg->uiR7 = 0;                     /* R7 */
    pstrStackReg->uiR8 = 0;                     /* R8 */
    pstrStackReg->uiR9 = 0;                     /* R9 */
    pstrStackReg->uiR10 = 0;                    /* R10 */
    pstrStackReg->uiR11 = 0;                    /* R11 */
    pstrStackReg->uiR12 = 0;                    /* R12 */
    pstrStackReg->uiR13 = (U32)pstrTcb;         /* R13 */
    pstrStackReg->uiR14 = (U32)vfFuncPointer;   /* R14 */
    pstrStackReg->uiXpsr = MODE_USR;            /* XPSR */
}

/***********************************************************************************
函数功能: 初始化任务TCB, 用来创建任务运行前TCB的状态.
入口参数: vfFuncPointer: 任务运行的函数.
          pucTaskStack: 任务所使用的栈地址.
          uiStackSize: 栈大小, 单位: 字节.
返 回 值: 任务TCB的指针.
***********************************************************************************/
static W_TCB* WLX_TaskTcbInit(VFUNC vfFuncPointer, U8* pucTaskStack, U32 uiStackSize)
{
    W_TCB* pstrTcb;
    U8* pucStackBy4;

    /* 创建任务时的栈满地址处存放TCB, 需要4字节对齐 */
    pucStackBy4 = (U8*)(((U32)pucTaskStack + uiStackSize) & ALIGN4MASK);

    /* TCB地址即运行时使用的栈开始地址, cortex内核使用8字节对齐 */
    pstrTcb = (W_TCB*)(((U32)pucStackBy4 - sizeof(W_TCB)) & ALIGN8MASK);

    /* 初始化任务栈 */
    WLX_TaskStackInit(pstrTcb, vfFuncPointer);

    return pstrTcb;
}

/*************************任务创建函数*******************************
*
*   函数功能: 创建单个任务运行前的状态.
*	入口参数: vfFuncPointer: 任务运行的函数指针.
*         pucTaskStack: 任务使用的栈的最低起始地址.
*			uiStackSize:栈大小，单位：字节
*	返 回 值: 其它：任务的TCB指针.
*			NULl:创建任务失败
**********************************************************************/
W_TCB* WLX_TaskCreate(VFUNC vfuncPointer,U8* pucTaskStack,U32 uiStackSize)
{
	W_TCB* pstrTcb;
	
	if(vfuncPointer == NULL)
	{
		return (W_TCB*)NULL;
	}
	if(pucTaskStack == NULL)
	{
		return (W_TCB*)NULL;
	}
	
	pstrTcb=WLX_TaskTcbInit(vfuncPointer, pucTaskStack, uiStackSize);
	
	return pstrTcb;
	
}



/*************************任务启动函数*******************************
*
*   函数功能: 开始运行第一个任务
*	入口参数: none
*	返 回 值: none
**********************************************************************/
void WLX_TaskStart(W_TCB* pstrTcb)
{
    STACKREG* pstrNextTaskStackRegAddr;

    /* 即将运行任务寄存器组的地址 */
    pstrNextTaskStackRegAddr = &pstrTcb->strStackReg;

	gpstrCurTcb = pstrTcb;
	
    /* 切换到任务状态 */
    WLX_SwitchToTask(pstrNextTaskStackRegAddr);
}

/*************************任务切换函数*******************************
*
*   函数功能: 任务切换
*	入口参数: pstrTcb:即将运行的任务的TCb指针
*	返 回 值: none
**********************************************************************/
void WLX_TaskSwitch(W_TCB* pstrTcb)
{
    STACKREG* pstrCurTaskStackRegAddr;
    STACKREG* pstrNextTaskStackRegAddr;
	
	//指向当前运行的任务的寄存器组地址
    pstrCurTaskStackRegAddr=&gpstrCurTcb->strStackReg;
	//指向即将运行的任务的寄存器的地址
	pstrNextTaskStackRegAddr=&pstrTcb->strStackReg;
	//将当前运行任务指针切换指向为下一个任务的TCB
	gpstrCurTcb=pstrTcb;

    /* 切换任务 */
    WLX_ContextSwitch(pstrCurTaskStackRegAddr, pstrNextTaskStackRegAddr);
}

U8* WLX_GetWanlixVersion(void)
{
	return SOFTWARE_VER;
}

