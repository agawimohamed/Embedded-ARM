


#ifndef __GPIO_Lcfg_H__
#define __GPIO_Lcfg_H__


#include "stdint.h"
#include "gpiodriver.h"
#include "device.h"


#define	PIN_OUTPUT				1
#define	PIN_NTPUT					0

#define DIGITAL_Enable		1
#define DIGITAL_Disable		0


typedef enum {
	P0,P1,P2,P3,P4,P5,P6,P7
}PintType;

typedef struct {
	uint32_t	clockEnable 	:1;				//GPIO Clock enanble or disable
	uint8_t		Direction	;							//either PIN_OUTPUT  or PIN_NTPUT
	uint8_t  DigitalEnable;						// either DIGITAL_Enable or DIGITAL_Disable
	GPIO_Name	GPIO;										// name of GPIO defined in enum of GPIO_Name like "GPIOA,GPIOB ......"
} GPIO_ConfigType;


void InitGPIO_Config();

void SetupGPIO_ConfigArray(GPIO_ConfigType* GPIO_Config[]);



#endif