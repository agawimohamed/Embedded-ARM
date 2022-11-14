

#include "SystickTimerDriver.h"
#include "Systick_Lcfg.h"
#include "stdint.h"
#include "Device.h"




uint32_t Counter;
uint32_t TimeBase;

SystickSW_CtlReg SysTickCtrl;


/////////////////////////////////////////////////
// this function will pass a pinter of functins array from user to the systick handler
// arguemnts void (*func[])() pinter of array of function
//




void StartSystickTimer(){
	STCTRL->BF.ENABLE = 1;			// enable the time and start count down
}

void StopSystickTimer(){
	STCTRL->BF.ENABLE = 0;			// enable the time and start count down
}


/////////////////////////////////////////////////////
void SystickInit(){

	STCTRL->BF.ENABLE = 0;			// stop systick befor initialization
	STCTRL->BF.INTEN	= 1;			// INTERRUPT ENABLE
	STCTRL->BF.CLK_SRC= 1;			// CLOCK SOURCE IS SYSTEM CLOCK

	STCURRENT = 0X0;						// clear systick current value and COUNT falg
	
	Counter =  TimeStamp_p->TimeStamp[0];		//loading counter with first task time stamp
	SysTickCtrl.AllTasks = TASK_ALL;
	SysTickCtrl.PendingTask = 0;
	
	if(TimeStamp_p->TimeBaseOption == MS_OPTION)	
		TimeBase = (XTAL_Freq/MS_Devision)-1 ;
	else if (TimeStamp_p->TimeBaseOption == US_OPTION) 
		TimeBase = (XTAL_Freq/US_Devision)-1 ;
	
	STRELOAD = TimeBase;
}










void SysTick_Handler (void){
	

	
	if(Counter==0){
		TaskFuncCallBack[SysTickCtrl.PendingTask]();
		SysTickCtrl.PendingTask++;
		if(SysTickCtrl.PendingTask > (SysTickCtrl.AllTasks -1)){SysTickCtrl.PendingTask = 0; }
		Counter = TimeStamp_p->TimeStamp[SysTickCtrl.PendingTask];
		
	}else Counter--;

	
}