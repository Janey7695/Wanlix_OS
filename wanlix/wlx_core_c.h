#ifndef _WLX_CORE_C_H
#define _WLX_CORE_C_H

#include "wanlix.h"

#define    MODE_USR     0x01000000


extern U32 guiCurTask;

//extern W_TCB* gpstrTask1Tcb;                   /* 任务1的TCB指针 */
//extern W_TCB* gpstrTask2Tcb;                   /* 任务2的TCB指针 */


extern void WLX_SwitchToTask(STACKREG* pstrNextTaskStackRegAddr);
extern void WLX_ContextSwitch(STACKREG* pstrCurTaskStackRegAddr,
                              STACKREG* pstrNextTaskStackRegAddr);
#endif

