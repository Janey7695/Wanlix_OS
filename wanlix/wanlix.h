#ifndef _WANLIX_H
#define _WANLIX_H

/* ����������� */
typedef unsigned char       U8;
typedef unsigned short      U16;
typedef unsigned int        U32;
typedef signed char         S8;
typedef short               S16;
typedef int                 S32;
typedef void                (*VFUNC)(void);

#define ROOTTASKSTACK 512

#ifndef NULL
 #define NULL               ((void*)0)
#endif
/* ע�⣺Cortex-m3�����ݼ�ջģʽ��*/
/* TCB�б��ݼĴ�����Ľṹ��, ������ʱ��������ǰ���ļĴ��� */
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

/* TCB�ṹ�� */
/* TCB����������ļĴ���״̬����˿�����TCb��Ϊһ�������Ψһ��ʶ */
typedef struct w_tcb
{
	STACKREG strStackReg;//���ݼĴ�����
}W_TCB;

/****************** �ⲿ�������� *********************/
extern W_TCB* gpstrTask1Tcb;
extern W_TCB* gpstrTask2Tcb;

/******************* �ⲿ�������� *********************/
extern W_TCB* WLX_TaskCreate(VFUNC vfuncPointer,U8* pucTaskStack,U32 uiStackSize);
extern void WLX_TaskSwitch(W_TCB* pstrTcb);
extern void WLX_TaskStart(W_TCB* pstrTcb);
extern U8* WLX_GetWanlixVersion(void);
extern void WLX_RootTask(void);

#endif


