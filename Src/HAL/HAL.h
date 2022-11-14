


#ifndef	__HAL_H__
#define __HAL_H__

#include "stdint.h"

#define		Led_On			1
#define		Led_Off			0

#define		LedRunnig		1
#define		LedStoped		2
#define		LedShutDown	3



typedef enum{
	LedRed 		= 1,
	LedBlue		= 2,
	LedGreen	=	3
}LedColorType;



typedef struct {
	uint16_t count       ;
	uint16_t status 				:4;
	uint16_t currentLed 		:2;
	uint16_t LedOnOffStatus :1 ;
}LedDevice;


void LedBlinkStart();
void LedBlinkStop();
void LedBlinkShutdown();

void LedInit(LedColorType Led,uint32_t OnTime,uint32_t OffTime);

extern	LedDevice			Led;
#endif