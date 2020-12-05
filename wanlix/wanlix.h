#ifndef _WANLIX_H
#define _WANLIX_H

/* ����������� */
typedef unsigned char       U8;     /* ��������char��Ϊ�޷����� */
typedef unsigned short      U16;
typedef unsigned int        U32;
typedef signed char         S8;
typedef short               S16;
typedef int                 S32;
typedef void                (*VFUNC)(void);


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


extern W_TCB* WLX_TaskInit(VFUNC vfFuncPointer, U32* puiTaskStack);
extern void WLX_TaskSwitch(void);
extern void WLX_TaskStart(void);

#endif


