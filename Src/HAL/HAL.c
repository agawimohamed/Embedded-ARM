#include   "Device.h"
#include   "CORE.h"
#include   "intctrl.h"
#include		"timerdriver.h"
#include    "Systick_Lcfg.h"
#include		"SystickTimerDriver.h"
#include		"GPIODriver.h"
#include		"GPIO_Lcfg.h"


#include "HAL.H"


LedColorType _Led;
LedDevice			Led;


void LedOn();
void LedOff();

void LedInit(LedColorType LedColor,uint32_t OnTime,uint32_t OffTime){
	_Led = LedColor;
	Led.count = 0; 									//zeroing the led counter
	
	void (*FuncArray[TASK_ALL])();
	FuncArray [0] = LedOn;
	FuncArray [1] = LedOff;
	ticksTimeStampType timeStampVal;
	timeStampVal.TimeBaseOption = MS_OPTION;			//choose in ms time base
	timeStampVal.TimeStamp[0] = OffTime;
	timeStampVal.TimeStamp[1] = OnTime;
	
	systickConfig(&timeStampVal,FuncArray);
	
	GPIOClockEnable(GPIOF);
	changeGPIO_BitDirection_Output(GPIOF,LedColor);
	changeGPIO_BitDigitalEnable(GPIOF,LedColor);
}

void LedBlinkStart(){
	StartSystickTimer();
}


///////////////////////////////////////////////////////
// this will stop led blinking and turn of the led
void LedBlinkStop(){
	StopSystickTimer();
	LedOff();
	
	Led.status = 	LedStoped;
	Led.currentLed = 		_Led;
}

void LedBlinkShutdown(){
	

//////////////////////////////////////////////////////
// earasing the time stamp array and pointers to function call back	
	void (*FuncArray[TASK_ALL])();
	FuncArray [0] = 0;
	FuncArray [1] = 0;
	ticksTimeStampType timeStampVal;
	timeStampVal.TimeBaseOption = MS_OPTION;			//choose in ms time base
	timeStampVal.TimeStamp[0] = 0;
	timeStampVal.TimeStamp[1] = 0;
	
	systickConfig(&timeStampVal,FuncArray);
	
	LedBlinkStop();
	
	Led.count = 0; 									//zeroing the led counter
	Led.status = 	LedShutDown;			// change the status
	Led.currentLed = 		0;					//no led selected
}

void LedOn(){
	SetBitGPIO_BitBanding(GPIOF,_Led);
	Led.count++;
	Led.status = LedRunnig;
	Led.LedOnOffStatus = Led_On;
}

void LedOff(){
	ClearBitGPIO_BitBanding(GPIOF,_Led);
	
	Led.status = 					LedRunnig;
	Led.LedOnOffStatus = Led_Off;
}	