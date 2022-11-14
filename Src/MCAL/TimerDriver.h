


#ifndef	__TimerDriver_h__
#define __TimerDriver_h__

#include "stdint.h"

//////////////////////////////////////////////////////////////////////
//  CONFIGURATION HASH DEFINED
#define GPT_PREDEF_100US_32BIT
#define GPT_PREDEF_1US_16BIT
#define GPT_PREDEF_1US_24BIT
#define GPT_PREDEF_1US_32BIT

#define MAX_TCKS_Value		0xFFFFFFFF
/////////////////////////////////////////
// gpt type number

typedef enum {
	TMR0=0,			// 16/32 TIMER
	TMR1=1,
	TMR2=2,
	TMR3=3,
	TMR4=4,
	TMR5=5,
	TMRW0=6,		//W = WIDE 32/64 TIMER
	TMRW1=7,
	TMRW2=8,
	TMRW3=9,
	TMRW4=10,
	TMRW5=11,
}TimerModule;
///////////////////////////////////////////////
typedef enum {
	TMRA0=0,			// 16/32 TIMER
	TMRB0=1,
	TMRA1=2,
	TMRB1=3,
	TMRA2=4,
	TMRB2=5,
	TMRA3=6,
	TMRB3=7,
	TMRA4=8,
	TMRB4=9,
	TMRA5=10,
	TMRB5=11,
	
	TMRWA0=12,			//W = WIDE 32/64 TIMER
	TMRWB0=13,
	TMRWA1=14,
	TMRWB1=15,
	TMRWA2=16,
	TMRWB2=17,
	TMRWA3=18,
	TMRWB3=19,
	TMRWA4=20,
	TMRWB4=21,
	TMRWA5=22,
	TMRWB5=23,
	
}TimerInterruptModule;


//////////////////////////////////////////////

typedef enum {
	_GPT_PREDEF_100US_32BIT,
	_GPT_PREDEF_1US_16BIT,
	_GPT_PREDEF_1US_24BIT,
	_GPT_PREDEF_1US_32BIT,
}Gpt_PredefTimerType;

typedef enum {
	Gpt_Mode_Normal,
	Gpt_Mode_Sleep
} Gpt_ModeType;

typedef enum {
	Gpt_Ch_Mode_Periodic,
	Gpt_Ch_Mode_OneShot
}Gpt_ChannelMode;
////////////////////////////////////////
/// CONFIGURATION TYPE
typedef struct {
	TimerModule	TMR;
	uint32_t maxTickValue;
	uint32_t TickFrequency;
	Gpt_ChannelMode ChMode;
	Gpt_ModeType	GptMode;
	Gpt_PredefTimerType	PredefTimer[4];
}Gpt_ConfigType;
//////////////////////////////////////////////////////////////////////





///////////////////////////////////  in GPTM Timer A Mode (GPTMTAMR) and GPTM Timer B Mode (GPTMTBMR)
#define One_Shot_mode		0x1 //One-Shot Timer mode
#define Periodic_mode		0x2 //Periodic Timer mode
#define Capture_mode		0x3 //Capture mode

/////////////////////////////////////////////////////////////



void enableTimerModuleClock(TimerModule TMR);

void TimerRegWrite(TimerModule TMR,uint32_t word);

void setTimerInterruptFunctionCall(TimerInterruptModule TMRnInt,void(*func)());

#endif