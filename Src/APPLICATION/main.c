#include   "Device.h"
#include   "CORE.h"
#include   "intctrl.h"
#include		"timerdriver.h"
#include    "Systick_Lcfg.h"
#include		"SystickTimerDriver.h"
#include		"GPIODriver.h"
#include		"GPIO_Lcfg.h"
#include		"HAL.H"





int main() {
			

	IntCtrl_init();

	InitGPIO_Config();
	
	//WriteToGPIO_BitMasking(GPIOA,0B11000111,0B0111101);
	
	LedInit(LedRed,3000,200);
	LedBlinkStart();
	
	
	
	
	
	while(1){
		if(Led.count>=0x5){
			LedBlinkStop();
			if(Led.status == LedStoped) LedBlinkShutdown();};
	};

	
	
}
