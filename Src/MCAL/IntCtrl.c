



#include "IntCtrl.h"
#include "IntCtrl_Lcfg.h"
#include "Device.h"
#include "core.h"


unsigned char IntCtrl_Init(void){
	
	return 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////
//will enable or disable the the interrupts inside vector table from interrupt no 0
// (option) either (Enable=1) (Disable=0)
void interruptEnableDisable(VecTableNames InterruptName,unsigned char option){
	InterruptName -= interruptsNameOffest;
	volatile uint8_t registerNumber = InterruptName/32;
	volatile uint8_t devisionRemainder = InterruptName%32;
	if(option == Enable) {*((volatile uint32_t*)(NVIC_Base + EN0_Offset+(registerNumber*4))) |= (1<<devisionRemainder);}
	else if (option == Disable){*((volatile uint32_t*)(NVIC_Base + DIS0_Offset+(registerNumber*4))) |= (1<<devisionRemainder);}
}
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
//  will clear PEND0 .....
void interruptPendSetClear(VecTableNames InterruptName,unsigned char option){
	InterruptName -= interruptsNameOffest;
	volatile uint8_t registerNumber = InterruptName/32;
	volatile uint8_t devisionRemainder = InterruptName%32;
	if(option == SetPend) {*((volatile uint32_t*)(NVIC_Base + PEND0_Offset+(registerNumber*4))) |= (1<<devisionRemainder);}
	else if (option == ClearPend){*((volatile uint32_t*)(NVIC_Base + UNPEND0_Offset+(registerNumber*4))) |= (1<<devisionRemainder);}
}

//////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
void APINT_Write(uint32_t word){
	word &= 0xFFFF;															// ZERO TO VECTKEY
	word |= ((uint32_t)APINT_VECTKEY <<16);			// THEN WRITING THE KEY 0x05FA AT VECTKEY REGION
	APINT_R = word; 														// WRITING TO APINT REGISTER
}


//////////////////////////////////////////////////////////////
// function to change the periority of specific interrupt
// InterruptName = name defined in enum by VecTableNames it have the same offset number in vector table
// InterruptName like "GPIOA_ISR, PWM0Generator1" plz refer to VecTableNames
//  priority three bit resolution (0-7) it may group or sub group according to the type of priority
void interruptPrioritySet(VecTableNames InterruptName,unsigned char priority){
	priority &= 0x7;										// not more than 0b111
	InterruptName -= interruptsNameOffest;						//TO get the correct interrupt number by substraction 16 from its number in vector table
	volatile uint8_t registerNumber = InterruptName/4;				//clac
	volatile uint8_t devisionRemainder = InterruptName%4;			//clac
	*((volatile uint32_t*)(NVIC_Base + PRI0_Offset+((registerNumber)*4))) &= ~((uint32_t)PRIORITY_MASK<<((devisionRemainder*8)+5)); // nice clac
	*((volatile uint32_t*)(NVIC_Base + PRI0_Offset+(registerNumber*4))) |= ((uint32_t) priority <<((devisionRemainder*8)+5));				
}



///////////////////////////////////////////////////////////////
// change peririty (XXX OR XXY OR XYY OR YYY)
// PRIORITY = PRIO_CONFIG_XXX OR PRIO_CONFIG_XXY ..OR................
void changePriorityType(priorityType PRIORITY){
	uint32_t TEMP = APINT_R & ((uint32_t)0B111 << 8);
	TEMP |= (uint32_t) PRIORITY << 8;
	APINT_Write(TEMP);}

////////////////////////////////////////////////////////////////	
void	APINT_Reset(){
	APINT_Write(((uint32_t) 0x1 << SYSRESREQ));
}

///////////////////////////////////////////////////////////////

uint32_t GetPSR_val(){
	return readSpecialRegister(PSR);
}


/////////////////////////////////////////////////////////////////
unsigned char IntCtrl_init (){
	//volatile interruptConfigType* interrupts_p =  GetInterruptsArray();
	interruptConfigSet();
	
	unsigned char perioritConfigSet = 0;
	
	for(unsigned char a=0 ;a <INT_COUNT;a++){
			unsigned char periorityTemp = 0;
			
			
			#ifdef	PRIO_XXX														// IF WE SELECT THE TYPE OF PERIRITY TO BE ALL BITS FOR GROUP AND NO SUBGROUP
			if(perioritConfigSet==0) {
				changePriorityType(PRIO_CONFIG_XXX);
				perioritConfigSet = 1;}											// SO AS NOT TO EXCUTE changePriorityType() EVERY TIME DURING LOOP OPERATION
			periorityTemp = Interrupts[a].PRI_Group;
			#endif
	
			#ifdef	PRIO_XXY
			if(perioritConfigSet==0) {
				changePriorityType(PRIO_CONFIG_XXX);
				perioritConfigSet = 1;}
			if(Interrupts[a].PRI_Group>3 || Interrupts[a].PRI_Subgroup>1)return 0;
			periorityTemp = (Interrupts[a].PRI_Group << 1) |Interrupts[a].PRI_Subgroup ;
			#endif

	
			#ifdef	PRIO_XYY
			if(perioritConfigSet==0) {
				changePriorityType(PRIO_CONFIG_XYY);
				perioritConfigSet = 1;}
			if(Interrupts[a].PRI_Group>1 || Interrupts[a].PRI_Subgroup>3)return 0;
			periorityTemp = (Interrupts[a].PRI_Group << 2) |Interrupts[a].PRI_Subgroup ;
			#endif
	
			#ifdef	PRIO_YYY
			if(!perioritConfigSet==0) {
				changePriorityType(PRIO_CONFIG_YYY);
				perioritConfigSet = 1;}
			periorityTemp = Interrupts[a].PRI_Subgroup;
			#endif
		
			interruptPrioritySet(Interrupts[a].InterruptName,periorityTemp);
			if(Interrupts[a].EN){interruptEnableDisable(Interrupts[a].InterruptName,Enable); }
			else interruptEnableDisable(Interrupts[a].InterruptName,Disable);
	}
	
		enablePRIMASK();
		enableFAULTMASK();
		
		return 1;
	}	

	
	

