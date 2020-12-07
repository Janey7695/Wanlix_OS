#ifndef _WLX_CORE_C_H
#define _WLX_CORE_C_H

#include "global.h"


/* THUMBָ�USR����ģʽ���� */
#define    MODE_USR     0x01000000

/* �ֽڶ������� */
#define ALIGN4MASK          0xFFFFFFFC  /* 4�ֽڶ��� */
#define ALIGN8MASK          0xFFFFFFF8  /* 8�ֽڶ��� */

extern U32 guiCurTask;



extern void WLX_SwitchToTask(STACKREG* pstrNextTaskStackRegAddr);
extern void WLX_ContextSwitch(STACKREG* pstrCurTaskStackRegAddr,
                              STACKREG* pstrNextTaskStackRegAddr);
#endif

