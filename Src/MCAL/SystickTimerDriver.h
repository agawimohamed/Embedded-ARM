

#ifndef		__SystickTimerDriver_H__
#define		__SystickTimerDriver_H__

#include "Device.h"
#include "stdint.h"
#include "systick_lcfg.h"

////////////////////////////////////////////////////////////////////
#define XTAL_Freq		16000000		// definition of clock speed
#define	MS_Devision	1000					// the devisor to obtain time delay in milliseconde
#define	US_Devision	1000					// the devisor to obtain time delay in microseconds

#define US_OPTION 	0
#define MS_OPTION 	1
/////////////////////////////////////////////////////////////////////

typedef struct {
	
	uint32_t PendingTask				:8 ;
	uint32_t AllTasks						:8 ;
	uint32_t Mode								:3 ;
	
}SystickSW_CtlReg;
/////////////////////////////////////////////////////////////






void StopSystickTimer();
void StartSystickTimer();

void SystickInit();

#endif