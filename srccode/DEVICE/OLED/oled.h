#ifndef __OLED_H
#define __OLED_H			  	 
#include "stm32f10x.h"
#include "stdlib.h"	  


//����OLED����
#define OLED_PORTA GPIOA
#define OLED_PORTB GPIOB
#define OLED_D0_SCLK GPIO_Pin_5   //PA5
#define OLED_D1_SDIN GPIO_Pin_7   //PA7
#define OLED_DC GPIO_Pin_1   //PB1
#define OLED_CS GPIO_Pin_4   //PA4
#define OLED_RES GPIO_Pin_0   //PB0

//OLEDģʽ����
//0:4�ߴ���ģʽ
//1:����8080ģʽ
#define OLED_MODE 0
#define SIZE 8
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	    

//-----------------OLED�˿ڶ���----------------  					   


#define OLED_SCLK_Clr() GPIO_ResetBits(OLED_PORTA,OLED_D0_SCLK)//CLK
#define OLED_SCLK_Set() GPIO_SetBits(OLED_PORTA,OLED_D0_SCLK)

#define OLED_SDIN_Clr() GPIO_ResetBits(GPIOA,OLED_D1_SDIN)//DIN
#define OLED_SDIN_Set() GPIO_SetBits(GPIOA,OLED_D1_SDIN)

#define OLED_RST_Clr() GPIO_ResetBits(GPIOB,OLED_RES)//RES
#define OLED_RST_Set() GPIO_SetBits(GPIOB,OLED_RES)

#define OLED_DC_Clr() GPIO_ResetBits(GPIOB,OLED_DC)//DC
#define OLED_DC_Set() GPIO_SetBits(GPIOB,OLED_DC)
 		     
#define OLED_CS_Clr()  GPIO_ResetBits(GPIOA,OLED_CS)//CS
#define OLED_CS_Set()  GPIO_SetBits(GPIOA,OLED_CS)

#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����


//OLED�����ú���
void OLED_WR_Byte(u8 dat,u8 cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);	   							   		    
void OLED_Init(void);
void OLED_Clear(void);

void OLED_ShowChar(u8 x,u8 y,u8 chr);
void OLED_ShowString_Reverse(u8 x,u8 y,u8 *chr,u8 font);

void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 font);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_ShowCHinese(u8 x,u8 y,u8 no);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,const unsigned char BMP[]);
#endif 

