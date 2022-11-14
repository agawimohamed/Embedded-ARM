
#include "GPIO_Lcfg.h"
#include "stdint.h"

#define PortNumbConf			3			// the maximum array length og ports to be configured intially

#define	GPIO_ALL_UNLOCK		1			// UNCOMMENT TO UNLOCK THE CR OF THE INITIAL CONFIGURATIONS ARRAY DURING DEVICE INTIALIZATION



GPIO_ConfigType GPIO_Config[PortNumbConf];   //array of interrupts to be configured initially


/////////////////////////////////////////////////////////////////
// this function will be called during device intalization to intially configure an array 
// (GPIO_Config[]) of length (PortNumbConf) defined by user in this file
// GPIO_ConfigType contaim GPIO,clockEnable,Direction,DigitalEnable  AND CAN CONTAIN OTHER DATA
///////////////////////////////////////////////////////////////////////////////////////////////
void InitGPIO_Config(){
	
	GPIO_Config[0].GPIO = GPIOA;
	GPIO_Config[0].clockEnable = 1;
	GPIO_Config[0].Direction = 0XFF ; //(1<<P0)|(1<<P1)|(1<<P2);			// MAKE PINS 0,1,2 OUT
	GPIO_Config[0].DigitalEnable = 0XFF;										// all pins enable
	
	GPIO_Config[1].GPIO = GPIOC;
	GPIO_Config[1].clockEnable = 1;
	GPIO_Config[1].Direction = 0XFF;//(1<<P0)|(1<<P3)|(1<<P4);			// MAKE PINS 0,1,2 OUT
	GPIO_Config[1].DigitalEnable = 0XFF;	
	
	GPIO_Config[2].GPIO = GPIOE;
	GPIO_Config[2].clockEnable = 1;
	GPIO_Config[2].Direction = 0XFF ; //(1<<P0)|(1<<P1)|(1<<P2);			// MAKE PINS 0,1,2 OUT
	GPIO_Config[2].DigitalEnable = 0XFF;	
	
	///////////////////////////////////////////////////////////////////
	//loop through the array to configure the driver
	
	uint8_t a;
	for(a=0;a<= PortNumbConf-1;a++ ){
		if(GPIO_Config[a].clockEnable){
			GPIOClockEnable(GPIO_Config[a].GPIO);			// enable the clock to specific gpio
			//uint8_t GPIOVAL= (uint8_t)GPIO_Config[a].GPIO;
			
			if(GPIO_Config[a].GPIO == GPIOA){
					GPIOA_APB->GPIODIR = GPIO_Config[a].Direction;
					GPIOA_APB->GPIODEN = GPIO_Config[a].DigitalEnable;}
			else if (GPIO_Config[a].GPIO == GPIOB){
					GPIOB_APB->GPIODIR = GPIO_Config[a].Direction;
					#ifdef  GPIO_ALL_UNLOCK
					GPIOB_APB->GPIOLOCK = GPIO_LOCK;
					GPIOB_APB->GPIOCR		= 0XFF;
					GPIOB_APB->GPIODEN = GPIO_Config[a].DigitalEnable;
					#endif
			}
			else if(GPIO_Config[a].GPIO == GPIOC){
					GPIOC_APB->GPIODIR = GPIO_Config[a].Direction;
					#ifdef  GPIO_ALL_UNLOCK
					GPIOC_APB->GPIOLOCK = GPIO_LOCK;
					GPIOC_APB->GPIOCR		= 0XFF;
					GPIOC_APB->GPIODEN = GPIO_Config[a].DigitalEnable;
					#endif
			}
			else if (GPIO_Config[a].GPIO == GPIOD){
					GPIOD_APB->GPIODIR = GPIO_Config[a].Direction;
					#ifdef  GPIO_ALL_UNLOCK
					GPIOD_APB->GPIOLOCK = GPIO_LOCK;
					GPIOD_APB->GPIOCR		= 0XFF;
					GPIOD_APB->GPIODEN = GPIO_Config[a].DigitalEnable;
					#endif
			}
			else	if(GPIO_Config[a].GPIO == GPIOE){
					GPIOE_APB->GPIODIR = GPIO_Config[a].Direction;
					#ifdef  GPIO_ALL_UNLOCK
					GPIOE_APB->GPIOLOCK = GPIO_LOCK;
					GPIOE_APB->GPIOCR		= 0XFF;
					GPIOE_APB->GPIODEN = GPIO_Config[a].DigitalEnable;
					#endif
			}
			else if (GPIO_Config[a].GPIO == GPIOF){
					GPIOF_APB->GPIODIR = GPIO_Config[a].Direction;
					#ifdef  GPIO_ALL_UNLOCK
					GPIOF_APB->GPIOLOCK = GPIO_LOCK;
					GPIOF_APB->GPIOCR		= 0XFF;
					GPIOF_APB->GPIODEN = GPIO_Config[a].DigitalEnable;
					#endif
			}
		} else GPIOClockDisable(GPIO_Config[a].GPIO);	
	}
}

