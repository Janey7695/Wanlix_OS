#ifndef _WANLIX_H
#define _WANLIX_H

/* 定义变量类型 */
typedef unsigned char       U8;     /* 本编译器char型为无符号型 */
typedef unsigned short      U16;
typedef unsigned int        U32;
typedef signed char         S8;
typedef short               S16;
typedef int                 S32;
typedef void                (*VFUNC)(void);


#ifndef NULL
 #define NULL               ((void*)0)
#endif
/* 注意：Cortex-m3是满递减栈模式！*/
/* TCB中备份寄存器组的结构体, 用来临时保存任务前换的寄存器 */
typedef struct stackreg
{
	U32 uiR4;
	U32 uiR5;
	U32 uiR6;
	U32 uiR7;	
	U32 uiR8;
	U32 uiR9;
	U32 uiR10;
	U32 uiR11;
	U32 uiR12;
	U32 uiR13;
	U32 uiR14;
	U32 uiXpsr;
	
}STACKREG;

/* TCB结构体 */
/* TCB管理着任务的寄存器状态，因此可以用TCb作为一个任务的唯一标识 */
typedef struct w_tcb
{
	STACKREG strStackReg;//备份寄存器组
}W_TCB;


extern W_TCB* WLX_TaskInit(VFUNC vfFuncPointer, U32* puiTaskStack);
extern void WLX_TaskSwitch(void);
extern void WLX_TaskStart(void);

#endif


