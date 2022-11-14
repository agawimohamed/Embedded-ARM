

#ifndef __GPIODriver_h__
#define __GPIODriver_h__

#include "stdint.h"

#define GPIO_LOCK		0x4C4F434B


//#define		use_extended_RCGCGPIO    /* remove this definition to use the short cut GPIOClockEnable function*/
typedef enum {
	GPIOA	=	0,
	GPIOB	=	1,
	GPIOC	=	2,
	GPIOD	=	3,
	GPIOE	=	4,
	GPIOF	=	5
}GPIO_Name;




void WriteToGPIO_BitMasking(GPIO_Name GPIO,uint32_t Mask , uint32_t word );
void SetBitGPIO_BitBanding(GPIO_Name GPIO,uint8_t bit);
void ClearBitGPIO_BitBanding(GPIO_Name GPIO,uint8_t bit);

uint32_t GPIO_Read(GPIO_Name GPIO);



void GPIOClockEnable(GPIO_Name GPIO);
void GPIOClockDisable(GPIO_Name GPIO);
unsigned char GPIOConfig(void);



extern uint32_t GPIO_Offset_Array[];

void changeGPIO_BitDirection_Output(GPIO_Name GPIO,uint8_t bit );
void changeGPIO_BitDirection_Input(GPIO_Name GPIO,uint8_t bit );
void changeGPIO_BitDigitalEnable(GPIO_Name GPIO,uint8_t bit );
void changeGPIO_BitDigitalDisable(GPIO_Name GPIO,uint8_t bit );
void DirectWriteGPIO(GPIO_Name GPIO,uint8_t word);

#endif