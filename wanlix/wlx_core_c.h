#ifndef _WLX_CORE_C_H
#define _WLX_CORE_C_H

#include "global.h"


/* THUMB指令集USR工作模式掩码 */
#define    MODE_USR     0x01000000

/* 字节对齐掩码 */
#define ALIGN4MASK          0xFFFFFFFC  /* 4字节对齐 */
#define ALIGN8MASK          0xFFFFFFF8  /* 8字节对齐 */

//extern U32 guiCurTask;

extern U8 gaucRootTaskStack[ROOTTASKSTACK];
extern W_TCB* gpstrCurTcb;
extern W_TCB* gpstrRootTaskTcb;


extern void WLX_SwitchToTask(STACKREG* pstrNextTaskStackRegAddr);
extern void WLX_ContextSwitch(STACKREG* pstrCurTaskStackRegAddr,
                              STACKREG* pstrNextTaskStackRegAddr);


#endif

