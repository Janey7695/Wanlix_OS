#include "wlx_core_c.h"


U8 gaucRootTaskStack[ROOTTASKSTACK];

W_TCB* gpstrCurTcb;                   /* ��ǰ���������TCBָ�� */

W_TCB* gpstrRootTaskTcb;



S32 main(void)
{
	gpstrRootTaskTcb = WLX_TaskCreate(WLX_RootTask,gaucRootTaskStack,ROOTTASKSTACK);
	
	WLX_TaskStart(gpstrRootTaskTcb);
	
	return 0;
}

/***********************************************************************************
��������: ��ʼ������ջ����, ����������������ǰ��ջ״̬.
��ڲ���: pstrTcb: �����TCBָ��.
          vfFuncPointer: �������еĺ���.
�� �� ֵ: none.
***********************************************************************************/
static void WLX_TaskStackInit(W_TCB* pstrTcb, VFUNC vfFuncPointer)
{
    STACKREG* pstrStackReg;

    /* �Ĵ������ַ */
    pstrStackReg = &pstrTcb->strStackReg;

    /* ��TCB�еļĴ������ʼ�� */
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
��������: ��ʼ������TCB, ����������������ǰTCB��״̬.
��ڲ���: vfFuncPointer: �������еĺ���.
          pucTaskStack: ������ʹ�õ�ջ��ַ.
          uiStackSize: ջ��С, ��λ: �ֽ�.
�� �� ֵ: ����TCB��ָ��.
***********************************************************************************/
static W_TCB* WLX_TaskTcbInit(VFUNC vfFuncPointer, U8* pucTaskStack, U32 uiStackSize)
{
    W_TCB* pstrTcb;
    U8* pucStackBy4;

    /* ��������ʱ��ջ����ַ�����TCB, ��Ҫ4�ֽڶ��� */
    pucStackBy4 = (U8*)(((U32)pucTaskStack + uiStackSize) & ALIGN4MASK);

    /* TCB��ַ������ʱʹ�õ�ջ��ʼ��ַ, cortex�ں�ʹ��8�ֽڶ��� */
    pstrTcb = (W_TCB*)(((U32)pucStackBy4 - sizeof(W_TCB)) & ALIGN8MASK);

    /* ��ʼ������ջ */
    WLX_TaskStackInit(pstrTcb, vfFuncPointer);

    return pstrTcb;
}

/*************************���񴴽�����*******************************
*
*   ��������: ����������������ǰ��״̬.
*	��ڲ���: vfFuncPointer: �������еĺ���ָ��.
*         pucTaskStack: ����ʹ�õ�ջ�������ʼ��ַ.
*			uiStackSize:ջ��С����λ���ֽ�
*	�� �� ֵ: �����������TCBָ��.
*			NULl:��������ʧ��
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



/*************************������������*******************************
*
*   ��������: ��ʼ���е�һ������
*	��ڲ���: none
*	�� �� ֵ: none
**********************************************************************/
void WLX_TaskStart(W_TCB* pstrTcb)
{
    STACKREG* pstrNextTaskStackRegAddr;

    /* ������������Ĵ�����ĵ�ַ */
    pstrNextTaskStackRegAddr = &pstrTcb->strStackReg;

	gpstrCurTcb = pstrTcb;
	
    /* �л�������״̬ */
    WLX_SwitchToTask(pstrNextTaskStackRegAddr);
}

/*************************�����л�����*******************************
*
*   ��������: �����л�
*	��ڲ���: pstrTcb:�������е������TCbָ��
*	�� �� ֵ: none
**********************************************************************/
void WLX_TaskSwitch(W_TCB* pstrTcb)
{
    STACKREG* pstrCurTaskStackRegAddr;
    STACKREG* pstrNextTaskStackRegAddr;
	
	//ָ��ǰ���е�����ļĴ������ַ
    pstrCurTaskStackRegAddr=&gpstrCurTcb->strStackReg;
	//ָ�򼴽����е�����ļĴ����ĵ�ַ
	pstrNextTaskStackRegAddr=&pstrTcb->strStackReg;
	//����ǰ��������ָ���л�ָ��Ϊ��һ�������TCB
	gpstrCurTcb=pstrTcb;

    /* �л����� */
    WLX_ContextSwitch(pstrCurTaskStackRegAddr, pstrNextTaskStackRegAddr);
}

U8* WLX_GetWanlixVersion(void)
{
	return SOFTWARE_VER;
}

