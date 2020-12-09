# Wanlix_OS
## About The Project 简介
`Wanlix`是一个基于学习《嵌入式操作系统内核调度》仿制的嵌入式微型操作系统，其含有最简单的任务调度内核，是一个不可抢占内核

## Getting Started 开始
1. 获取源码  
git clone https://github.com/Janey7695/Wanlix_OS.git
2. 进入`project`目录，打开keil工程`Wanlix_OS.uvprojx`并编译
3. 通过ST-LINK或其它仿真器下载程序到stm32f103上

## VERSION 版本迭代
* 001.001.002   
—— “增加led灯验证2个任务切换的有效性”-__2020/12/7 11:00__
* 001.002.001  
—— “添加OLED显示模块”  
—— “从2个任务切换变成多个任务切换（不可抢占）”-__2020/12/7 21:00__
* 001.002.002  
—— “修正bug 使oled正常使用”-__2020/12/7 21:50__

## OS_API 重要操作系统API
### 1. `W_TCB* WLX_TaskCreate(VFUNC vfuncPointer,U8* pucTaskStack,U32 uiStackSize)`
> Function 功能</br>

创建函数，其内完成对任务控制块(TCB)、堆栈的初始化
> Parameter 参数</br>

* `VFUNC vfuncPointer` 需要创建的任务的函数指针，指向任务的函数入口(一般输入函数名，函数名即为函数头指针)</br>
* `U8* pucTaskStack` 为这个任务创建的堆栈的指针(即数组首地址)
* `U32 uiStackSize` 堆栈大小，单位：字节

> Return 返回值

* `W_TCB* pstrTcb` 返回初始化完毕的任务控制块的指针

### 2. `void WLX_TaskStart(W_TCB* pstrTcb)` 
> Function 功能</br>

开始运行入口参数提供的任务控制块关联的任务
> Parameter 参数</br>

* `W_TCB* pstrTcb` 准备开始执行的任务的控制块指针</br>

> Return 返回值

* `void` 无返回值

### 3. `void WLX_TaskSwitch(W_TCB* pstrTcb)`
> Function 功能</br>

切换到入口参数提供的任务控制块关联的任务，函数内部完成对当前运行任务的现场保存以及即将运行任务的现场恢复
> Parameter 参数</br>

* `W_TCB* pstrTcb` 欲切换到的任务的控制块指针</br>

> Return 返回值

* `void` 无返回值

### 4. `U8* WLX_GetWanlixVersion(void)`
> Function 功能</br>

获取当前版本号
> Parameter 参数</br>

* `void` 无</br>

> Return 返回值

* `U8* SOFTWARE_VER` 返回由字符串构成的版本号的字符串首地址
