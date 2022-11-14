

#include "stdint.h"
#include "IntCtrl.h"
#include "IntCtrl_Lcfg.h"



//interruptConfigType Interrupts[3];

//	_______________________________________________________________________________________________________
//  |	interrupt name (VecTableNames)|reserved bit|sub periotity(3bits) | group periority(3bits)|ENABLE BIT|
//	-------------------------------------------------------------------------------------------------------
volatile interruptConfigType Interrupts[INT_COUNT];


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  user must call this function to set the interrupts configurations required 
// the container is ARRAY OF structure defined by (interruptConfigType) called Interrupts[] which contains
// InterruptName = name of interrupt comes drom enum defined by (VecTableNames)in IntCtrl.h file like "_16_32_Timer1A" "PWM0Generator1" ...
//, EN = Enable bit required ,PRI_Group = periority group (0-7),PRI_Subgroup = periority sub group
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void interruptConfigSet(){
	
	
	Interrupts[0].InterruptName = _16_32_Timer0A;
	Interrupts[0].EN = 1;
	Interrupts[0].PRI_Group = 5;
	Interrupts[0].PRI_Subgroup = 0;
	
	Interrupts[1].InterruptName = PWM0Generator1;
	Interrupts[1].EN = 1;
	Interrupts[1].PRI_Group = 3;
	Interrupts[1].PRI_Subgroup = 0;
	
	Interrupts[2].InterruptName = AnalogComparator0;
	Interrupts[2].EN = 1;
	Interrupts[2].PRI_Group = 2;
	Interrupts[2].PRI_Subgroup = 0;
	
}


