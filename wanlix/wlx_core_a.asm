
	INCLUDE wlx_core_a.h
	


	;ջ8�ֽڶ���
	PRESERVE8
			
	AREA	WLX_CORE_A, CODE, READONLY
	THUMB
		

WLX_ContextSwitch

    ;���浱ǰ�����ջ��Ϣ
    STMIA  R0!, {R4 - R12}  ;����R4-R12�Ĵ���
    STMIA  R0!, {R13}       ;����SP�Ĵ���
    STMIA  R0!, {R14}       ;����LR�Ĵ���
    MRS    R2, XPSR         ;��ȡXPSR�Ĵ�����ֵ
    STMIA  R0, {R2}         ;���浽�Ĵ������е�XPSR

    ;�ָ���Ҫ���������ջ��Ϣ������������
    LDMIA  R1!, {R4 - R12}  ;�ָ�R4-R12�Ĵ���
    LDMIA  R1, {R13}        ;�ָ�SP�Ĵ���
    ADD    R1, #8           ;R1ָ��Ĵ������е�XPSR
    LDMIA  R1, {R0}         ;��ȡ�Ĵ������е�XPSR��ֵ
    MSR    XPSR, R0         ;�ָ�XPSR�Ĵ���
    SUB    R1, #4           ;R1ָ��Ĵ������е�LR
    LDMIA  R1, {PC}         ;�л�����

		


WLX_SwitchToTask

	LDMIA 	R0!, {R4 - R12}			;�������R4-R12����Ĵ����У�ǰ���R0������ڲ�������һ��ָ��TCb�ṹ��ͷָ�룬���R0->uiR4���Դ����ƣ�
	LDMIA 	R0, {R13}				;�ظ�SP�Ĵ���
	ADD 	R0, #8					;ʹR0ָ��XPSR
	LDMIA 	R0,{R1}					;��ȡ�Ĵ������е�XPSR��ֵ
	MSR 	XPSR, R1				;�ָ�XPSR�Ĵ���
	SUB 	R0, #4					;R0ָ��Ĵ������е�LR
	LDMIA 	R0, {PC}				;�����׸�����
	
	ALIGN
		
	END
