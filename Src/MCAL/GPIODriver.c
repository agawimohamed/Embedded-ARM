

#include <GPIODriver.h>
#include <Device.h>
#include "stdint.h"



 uint32_t GPIO_Offset_Array[]={0x40004000,0x40005000,0x40006000,0x40007000,0x40024000,0x40025000
,0x40058000,0x40059000,0x4005A000,0x4005B000,0x4005C000,0x4005D000};



///////////////////////////////////////////////////////////////////////////
void GPIOClockEnable(GPIO_Name GPIO){
	
	#ifdef use_extended_RCGC2
		switch (GPIO){
			case GPIOA:
				RCGC2 |= (1 << 0);
				break;
			case GPIOB:
				RCGC2 |= (1 << 1);
				break;
			case GPIOC:
				RCGC2 |= (1 << 2);
				break;
			case GPIOD:
				RCGC2 |= (1 << 3);
				break;
			case GPIOE:
				RCGC2 |= (1 << 4);
				break;
			case GPIOF:
				RCGC2 |= (1 << 5);
				break;
		}
	#else
	RCGC2 |= (1UL << GPIO);
	#endif
	
	}

void GPIOClockDisable(GPIO_Name GPIO){
	
	#ifdef use_extended_RCG2
		switch (GPIO){
			case GPIOA:
				RCGC2 &= ~(1UL << 0);
				break;
			case GPIOB:
				RCGC2 &= ~(1UL << 1);
				break;
			case GPIOC:
				RCGC2 &= ~(1UL << 2);
				break;
			case GPIOD:
				RCGC2 &= ~(1UL << 3);
				break;
			case GPIOE:
				RCGC2 &= ~(1UL << 4);
				break;
			case GPIOF:
				RCGC2 &= ~(1UL << 5);
				break;
		}
	#else
	RCGC2 &= ~(1UL << GPIO);
	#endif
	
	}

	
	

	
/////////////////////////////////////////////////////////////////////////
//   function to write directly to specific GPIO using BIT Masking so as not to use read modify write
//		it takes GPIO name defined by enum type GPIO_Name  like "GPIOA,GPIOB........"
//		It takes also the mask to be used and the word which is the byte to be written through the mask	
/////////////////////////////////////////////////////////////////////////////	
	
	void WriteToGPIO_BitMasking(GPIO_Name GPIO,uint32_t Mask , uint32_t word ){
			* (volatile uint32_t*)(GPIO_Offset_Array[GPIO]  +( Mask <<2) ) = word;
	}


	//////////////////////////////////////////////////////////////////////////
	// function to set a specific bit directly to specific GPIO using BIT Banding so as not to use read modify write
	// it takes GPIO name defined by enum type GPIO_Name  like "GPIOA,GPIOB........"
	// bit the is the bit postion (from 0-7)
	void SetBitGPIO_BitBanding(GPIO_Name GPIO,uint8_t bit){
		*(volatile uint32_t*)(0x42000000 + (((GPIO_Offset_Array[GPIO]&0xfffffUL)+0X3FC)*32) + (bit*4))= 1;
	}
	/////////////////////////////////////////////////////////////////////////////
	//  clear bit using bit banding
	///////////////////////////////////////////////////////////////////
		void ClearBitGPIO_BitBanding(GPIO_Name GPIO,uint8_t bit){
		*(volatile uint32_t*)(0x42000000 + (((GPIO_Offset_Array[GPIO]&0xfffffUL)+0X3FC)*32) + (bit*4))= 0;
	}
		
	//////////////////////////////////////////////////////////////////////////
	// function to return current value in DATA register of specific GPIO
	// it takes GPIO name defined by enum type GPIO_Name  like "GPIOA,GPIOB........"
	//////////////////////////////////////////////////////////////
	uint32_t GPIO_Read(GPIO_Name GPIO){
		return (GPIO_Offset_Array[GPIO]&0XFF);		
	}
	
	////////////////////////////////////////////////////////////////////////////
	// function to change a pin direction in specific GPIO to be output
	// IT TAKES THE NUMBER OF PIN (0-8)
	////////////////////////////////////////////////////////////////////
	void changeGPIO_BitDirection_Output(GPIO_Name GPIO,uint8_t bit ){
		*(volatile uint32_t*) (GPIO_Offset_Array[GPIO] +GPIODIR_offset) |= (1<<bit);

	}
	void changeGPIO_BitDirection_Input(GPIO_Name GPIO,uint8_t bit ){
		*(volatile uint32_t*) (GPIO_Offset_Array[GPIO] +GPIODIR_offset) &= ~(1<<bit);

	}

	////////////////////////////////////////////////////////////////////
	// FUNCTION TO DIGITAL ENABLE A PIN
	void changeGPIO_BitDigitalEnable(GPIO_Name GPIO,uint8_t bit ){
		*(volatile uint32_t*) (GPIO_Offset_Array[GPIO] +GPIODEN_offset) |= (1<<bit);
		
	}
	
	void changeGPIO_BitDigitalDisable(GPIO_Name GPIO,uint8_t bit ){
		*(volatile uint32_t*) (GPIO_Offset_Array[GPIO] +GPIODEN_offset) &= ~(1<<bit);
	}
	
	//////////////////////////////////////////////////////////////////////
	//  DIRECT WRITE A BYTE TO GPIO THROUGH OFFSET 0X3FC WHICH IS IN BIT MASKING REGION = (0XFF<<2)
	void DirectWriteGPIO(GPIO_Name GPIO,uint8_t word){
		*(volatile uint32_t*) (GPIO_Offset_Array[GPIO] +0x3FC) = word;
	}