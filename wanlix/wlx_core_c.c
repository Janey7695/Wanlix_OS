#include "wlx_core_c.h"

U32 guiCurTask;                         /* ��ǰ���е����� */

W_TCB* gpstrTask1Tcb;                   /* ����1��TCBָ�� */
W_TCB* gpstrTask2Tcb;                   /* ����2��TCBָ�� */


/*************************�����ʼ������*******************************
*
*   ��������: ����������������ǰ��״̬.
*	��ڲ���: vfFuncPointer: �������еĺ���ָ��.
*         puiTaskStack: ����ʹ�õ�ջ��ַ.
*	�� �� ֵ: �����TCBָ��.
**********************************************************************/
W_TCB* WLX_TaskInit(VFUNC vfuncPointer,U32* puiTaskStack)
{
	W_TCB* pstrTcb;
	STACKREG* pstrStackReg;
	//���ڵݼ�ջ��TCbҪ����ջ������˶���һ�����飨ջ������Ҫ����ĩ��ַ��Ȼ����ĩ��ַ�Ļ����ϼ�ȥTCB�Ĵ�С����TCB��ŵ�λ��
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



/*************************������������*******************************
*
*   ��������: ��ʼ���е�һ������
*	��ڲ���: none
*	�� �� ֵ: none
**********************************************************************/
void WLX_TaskStart(void)
{
    STACKREG* pstrNextTaskStackRegAddr;

    /* ������������Ĵ�����ĵ�ַ */
    pstrNextTaskStackRegAddr = &gpstrTask1Tcb->strStackReg;

    /* �����´ε��ȵ����� */
    guiCurTask = 1;

    /* �л�������״̬ */
    WLX_SwitchToTask(pstrNextTaskStackRegAddr);
}

/*************************�����л�����*******************************
*
*   ��������: �����л�
*	��ڲ���: none
*	�� �� ֵ: none
**********************************************************************/
void WLX_TaskSwitch(void)
{
    STACKREG* pstrCurTaskStackRegAddr;
    STACKREG* pstrNextTaskStackRegAddr;

    if(1 == guiCurTask)
    {
        /* ��ǰ����Ĵ�����ĵ�ַ */
        pstrCurTaskStackRegAddr = &gpstrTask1Tcb->strStackReg;

        /* ������������Ĵ�����ĵ�ַ */
        pstrNextTaskStackRegAddr = &gpstrTask2Tcb->strStackReg;

        /* �����´����е����� */
        guiCurTask = 2;
    }
    else //if(2 == guiCurTask)
    {
        pstrCurTaskStackRegAddr = &gpstrTask2Tcb->strStackReg;
        pstrNextTaskStackRegAddr = &gpstrTask1Tcb->strStackReg;

        guiCurTask = 1;
    }

    /* �л����� */
    WLX_ContextSwitch(pstrCurTaskStackRegAddr, pstrNextTaskStackRegAddr);
}

