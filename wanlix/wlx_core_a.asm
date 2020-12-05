
	INCLUDE wlx_core_a.h
	


	;栈8字节对齐
	PRESERVE8
			
	AREA	WLX_CORE_A, CODE, READONLY
	THUMB
		

WLX_ContextSwitch

    ;保存当前任务的栈信息
    STMIA  R0!, {R4 - R12}  ;保存R4-R12寄存器
    STMIA  R0!, {R13}       ;保存SP寄存器
    STMIA  R0!, {R14}       ;保存LR寄存器
    MRS    R2, XPSR         ;获取XPSR寄存器数值
    STMIA  R0, {R2}         ;保存到寄存器组中的XPSR

    ;恢复将要运行任务的栈信息并运行新任务
    LDMIA  R1!, {R4 - R12}  ;恢复R4-R12寄存器
    LDMIA  R1, {R13}        ;恢复SP寄存器
    ADD    R1, #8           ;R1指向寄存器组中的XPSR
    LDMIA  R1, {R0}         ;获取寄存器组中的XPSR数值
    MSR    XPSR, R0         ;恢复XPSR寄存器
    SUB    R1, #4           ;R1指向寄存器组中的LR
    LDMIA  R1, {PC}         ;切换任务

		


WLX_SwitchToTask

	LDMIA 	R0!, {R4 - R12}			;将任务的R4-R12填入寄存器中（前面的R0接受入口参数，是一个指向TCb结构的头指针，因此R0->uiR4，以此类推）
	LDMIA 	R0, {R13}				;回复SP寄存器
	ADD 	R0, #8					;使R0指向XPSR
	LDMIA 	R0,{R1}					;获取寄存器组中的XPSR数值
	MSR 	XPSR, R1				;恢复XPSR寄存器
	SUB 	R0, #4					;R0指向寄存器组中的LR
	LDMIA 	R0, {PC}				;运行首个任务
	
	ALIGN
		
	END
