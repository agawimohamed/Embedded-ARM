

#ifndef  __IntCtrl_Lcfg_H__
#define		__IntCtrl_Lcfg_H__

#include "IntCtrl.h"
#include "stdint.h"


#define			PRIO_XXX			//GROUP PRIORITIES 	8
//#define				PRIO_XXY			//GROUP PRIORITIES 	4		SUBGROUP	2								
//#define				PRIO_XYY			//GROUP PRIORITIES 	2		SUBGROUP	4
//#define				PRIO_YYY			//SUBGROUP					8

#define INT_COUNT		0x3			// numver of interrupts to config



typedef struct {
	uint8_t	EN						:1;			// Enable or disable
	uint8_t	PRI_Group 		:3;			// priority group
	uint8_t PRI_Subgroup	:3;			// subgroup priority
	uint8_t reserved 			:1;
	VecTableNames	InterruptName;	// name of interrupts defined in VecTableNames which have same offset in NVIC table
}
interruptConfigType;

extern volatile interruptConfigType Interrupts[];			// to be axcessible from outside c file

void interruptConfigSet();
#endif