
#include "Systick_Lcfg.h"
#include "SystickTimerDriver.h"


ticksTimeStampType* TimeStamp_p;

func_ptr* TaskFuncCallBack[TASK_ALL];

/////////////////////////////////////////////////////////////////////////////////
//  this function will pass the array of pointers to call back functions 
//  and array of TimeStampP which is a structure of ticksTimeStampType 	(uint32_t TimeBaseOption; uint32_t TimeStamp[TASK_ALL] ;)
//	containing time fram for each function which will be excuted 
//  in serial manner, passing them to SystickTimerDriver.c 
//  arguments pointer of ticksTimeStampType and pinter if TaskFunArray
//////////////////////////////////////////////////////////////////////////////////////////
void systickConfig(ticksTimeStampType* TimeStampP,void (*TaskFunArray[])(void)){
	
	
	TimeStamp_p = TimeStampP;
	
	passingTaskFuncCallBack(TaskFunArray);
	SystickInit();
	//StartSystickTimer();
	
	
}

///////////////////////////////////////////////////////////////////////
// just passing the previuos arguments
//////////////////////////////////////////////
void passingTaskFuncCallBack(func_ptr* FUNC[]){
	unsigned char a;
	for( a =0;a <TASK_ALL;a++){
		TaskFuncCallBack[a] = FUNC[a];
	}
}