
#include "timerdriver.h"
#include "device.h"
#include "stdint.h"



void	(*TMRA0_Int_Func)(void);
void	(*TMRB0_Int_Func)(void);
void	(*TMRA1_Int_Func)(void);
void	(*TMRB1_Int_Func)(void);
void	(*TMRA2_Int_Func)(void);
void	(*TMRB2_Int_Func)(void);
void	(*TMRA3_Int_Func)(void);
void	(*TMRB3_Int_Func)(void);
void	(*TMRA4_Int_Func)(void);
void	(*TMRB4_Int_Func)(void);
void	(*TMRA5_Int_Func)(void);
void	(*TMRB5_Int_Func)(void);

void	(*TMRWA0_Int_Func)(void);
void	(*TMRWB0_Int_Func)(void);
void	(*TMRWA1_Int_Func)(void);
void	(*TMRWB1_Int_Func)(void);
void	(*TMRWA2_Int_Func)(void);
void	(*TMRWB2_Int_Func)(void);
void	(*TMRWA3_Int_Func)(void);
void	(*TMRWB3_Int_Func)(void);
void	(*TMRWA4_Int_Func)(void);
void	(*TMRWB4_Int_Func)(void);
void	(*TMRWA5_Int_Func)(void);
void	(*TMRWB5_Int_Func)(void);


/////////////////////////////////////////////////////////////////////////////
// setTimerInterruptFunctionCall
// THIS FUNCTION WILL PASS A POINTER TO A FUNCTION TO BE EXCUTED WHEN THE CORRESPONDING TIMER HAVE INTERRUPT ROUTIN
// it takes arguments TMRA0 - 	TMRB5  16/32 TIMER    TMRWA0 - TMRWB5		W = WIDE 32/64 TIMER  from enum defined by
// TimerInterruptModule 
// the second arument is the pointer to function to be excuted

void setTimerInterruptFunctionCall(TimerInterruptModule TMRnInt,void(*func)()){
	switch(TMRnInt){
		case TMRA0:
			TMRA0_Int_Func = func;
			break;
		case TMRB0:
			TMRB0_Int_Func = func;
			break;
		case TMRA1:
			TMRA1_Int_Func = func;
			break;
		case TMRB1:
			TMRB1_Int_Func = func;
			break;
		case TMRA2:
			TMRA2_Int_Func = func;
			break;
		case TMRB2:
			TMRB2_Int_Func = func;
			break;
		case TMRA3:
			TMRA3_Int_Func = func;
			break;	
		case TMRB3:
			TMRB3_Int_Func = func;
			break;
		case TMRA4:
			TMRA4_Int_Func = func;
			break;
		case TMRB4:
			TMRB4_Int_Func = func;
			break;
		case TMRA5:
			TMRA5_Int_Func = func;
			break;
		case TMRB5:
			TMRB5_Int_Func = func;
			break;
		
		case TMRWA0:
			TMRWA0_Int_Func = func;
			break;
		case TMRWB0:
			TMRWB0_Int_Func = func;
			break;
		case TMRWA1:
			TMRWA1_Int_Func = func;
			break;
		case TMRWB1:
			TMRWB1_Int_Func = func;
			break;
		case TMRWA2:
			TMRWA2_Int_Func = func;
			break;
		case TMRWB2:
			TMRWB2_Int_Func = func;
			break;
		case TMRWA3:
			TMRWA3_Int_Func = func;
			break;	
		case TMRWB3:
			TMRWB3_Int_Func = func;
			break;
		case TMRWA4:
			TMRWA4_Int_Func = func;
			break;
		case TMRWB4:
			TMRWB4_Int_Func = func;
			break;
		case TMRWA5:
			TMRWA5_Int_Func = func;
			break;
		case TMRWB5:
			TMRWB5_Int_Func = func;
			break;

	}
}


//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// this array contains the offset of each timer indexed
///////////////////////////////////////////////////////////////////
const uint32_t TimerTable[] = {0x40030000,0x40031000,0x40032000,
												0x40033000,0x40034000,0x40035000,
												0x40036000,0x40037000,0x4004c000,
												0x4004d000,0x4004E000,0x4004F000};


//////////////////////////////////////////////////////////////
//	enable Timer clock user must enable clock before writing to specific timer registers
// it take arguemnts defined by enum type (TimerModule) like TMR0-TMR5 and TMRW0-TMRW5
/////////////////////////////////////////////////////////////////////////////												
void enableTimerModuleClock(TimerModule TMR){
		if (TMR<=5)RCGCTIMER 	|= (1<<TMR);				//16/32 timers
		else RCGCWTIMER 			|= (1<<(TMR-6));		//32/64 timers
	
	
}

//////////////////////////////////////////////////////////////
//	disable Timer clock user must enable clock before writing to specific timer registers
// it take arguemnts defined by enum type (TimerModule) like TMR0-TMR5 and TMRW0-TMRW5
/////////////////////////////////////////////////////////////////////////////	
void disableTimerModuleClock(TimerModule TMR){
		if (TMR<=5)RCGCTIMER 	&= ~(1<<TMR);				//16/32 timers
		else RCGCWTIMER 			&= ~(1<<(TMR-6));		//32/64 timers
	
	
}

///////////////////////////////////////////////////////////////////////////

void TimerRegWrite(TimerModule TMR,uint32_t word){
	volatile TimerRegisters* timer = (volatile TimerRegisters*) TimerTable[TMR] ;
	timer->GPTMCTL = word;				//0XC
	timer->GPTMPP = word;					//0XFC0
	timer->GPTMRTCPD = word	;			//0X58
	timer->GPTMIMR = word;				//0X18
	
}


////////////////////////////////////////////////////////////////////////////////////////////
// interrupt handlers of GPTM
void TIMER0A_Handler (void){ TIMER0_16_32->GPTMICR =0X1;	TMRA0_Int_Func();}
void TIMER0B_Handler (void){	TMRB0_Int_Func();}
void TIMER1A_Handler (void){ 	TMRA1_Int_Func();}
void TIMER1B_Handler (void){	TMRB1_Int_Func();}
void TIMER2A_Handler (void){	TMRA2_Int_Func();}
void TIMER2B_Handler (void){	TMRB2_Int_Func();}
void TIMER3A_Handler (void){	TMRA3_Int_Func();}
void TIMER3B_Handler (void){	TMRB3_Int_Func();}
void TIMER4A_Handler (void){	TMRA4_Int_Func();}
void TIMER4B_Handler (void){	TMRB4_Int_Func();}
void TIMER5A_Handler (void){	TMRA5_Int_Func();}
void TIMER5B_Handler (void){	TMRB5_Int_Func();}


void WTIMER0A_Handler (void){		TMRWA0_Int_Func();}
void WTIMER0B_Handler (void){		TMRWB0_Int_Func();}
void WTIMER1A_Handler (void){		TMRWA1_Int_Func();}
void WTIMER1B_Handler (void){		TMRWB1_Int_Func();}
void WTIMER2A_Handler (void){		TMRWA2_Int_Func();}
void WTIMER2B_Handler (void){		TMRWB2_Int_Func();}
void WTIMER3A_Handler (void){		TMRWA3_Int_Func();}
void WTIMER3B_Handler (void){		TMRWB3_Int_Func();}
void WTIMER4A_Handler (void){		TMRWA4_Int_Func();}
void WTIMER4B_Handler (void){		TMRWB4_Int_Func();}
void WTIMER5A_Handler (void){		TMRWA5_Int_Func();}
void WTIMER5B_Handler (void){		TMRWB5_Int_Func();}
///////////////////////////////////////////////////////////////////////////////////////
	
