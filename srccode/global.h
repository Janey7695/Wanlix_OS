#ifndef  GLOBAL_H
#define  GLOBAL_H

#include "stm32f10x.h"
#include "wanlix.h"
#include "device.h"

#define SOFTWARE_VER			"001.003.002.005"  /*ϵͳ�汾�� {Major}.{Minor}.{Revision}.{Build}*/
/********
Major:���汾�ţ�������ϵͳ���ܻ�ṹ�����ش�ı�ʱ���޸ģ��������Ҫ���ܻ�����ܹ��ع�
Minor:�Ӱ汾�ţ�����ԭ�й��ܡ��ṹ���ӡ��޸�һЩ����ʱ�޸Ĵ˰汾��
Revision:�޸İ汾�ţ��޸�bug������С����ʱ�͸�������汾��
Build:����汾�ţ�ÿ����ʽ����ʱ��һ��һ�������ڲ��޸ģ������⹫��
********/


/*   ϵͳ����   */
#define TASKSTACK				512     /* ��������ջ��С, ��λ: �ֽ� */

/*	 ȫ�ֱ��� ����ʹ�õĶ�ջ��TCB   */
extern U8 Task1Stack[TASKSTACK];
extern U8 Task2Stack[TASKSTACK];
extern U8 Task3Stack[TASKSTACK];
extern W_TCB* Task1Tcb;
extern W_TCB* Task2Tcb;
extern W_TCB* Task3Tcb;

/*	  ������     */
extern void TEST_TestTask1(void);
extern void TEST_TestTask2(void);
extern void TEST_TestTask3(void);


#endif


