#ifndef  GLOBAL_H
#define  GLOBAL_H

#include "stm32f10x.h"
#include "wanlix.h"
#include "device.h"

#define SOFTWARE_VER			"001.003.002.005"  /*系统版本号 {Major}.{Minor}.{Revision}.{Build}*/
/********
Major:主版本号，当操作系统功能或结构发生重大改变时才修改，如添加重要功能或整体架构重构
Minor:子版本号，基于原有功能、结构增加、修改一些功能时修改此版本号
Revision:修改版本号，修改bug，完善小功能时就更改这个版本号
Build:编译版本号，每次正式编译时加一，一般限于内部修改，不对外公布
********/


/*   系统设置   */
#define TASKSTACK				512     /* 单个任务栈大小, 单位: 字节 */

/*	 全局变量 任务使用的堆栈和TCB   */
extern U8 Task1Stack[TASKSTACK];
extern U8 Task2Stack[TASKSTACK];
extern U8 Task3Stack[TASKSTACK];
extern W_TCB* Task1Tcb;
extern W_TCB* Task2Tcb;
extern W_TCB* Task3Tcb;

/*	  任务函数     */
extern void TEST_TestTask1(void);
extern void TEST_TestTask2(void);
extern void TEST_TestTask3(void);


#endif


