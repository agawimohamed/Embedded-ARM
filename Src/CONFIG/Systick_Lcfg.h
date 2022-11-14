

#ifndef __Systick_Lcfg_H__
#define __Systick_Lcfg_H__

#include "SystickTimerDriver.h"


#define TASK_ALL 2		//this define the all tasks call back functions will be implimented



typedef struct {
	uint32_t TimeBaseOption;
	uint32_t TimeStamp[TASK_ALL] ;
}ticksTimeStampType;

extern ticksTimeStampType* TimeStamp_p;


typedef void (func_ptr)();

extern func_ptr* TaskFuncCallBack[TASK_ALL];

void passingTaskFuncCallBack(func_ptr* FUNC[]);

void systickConfig(ticksTimeStampType* TimeStamp,void (*TaskFunArray[])(void));

#endif