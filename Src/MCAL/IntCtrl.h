


#ifndef __IntCtrl_h__
#define	__IntCtrl_h__

#include "stdint.h"

#define interruptsNameOffest			16

#define Enable		1
#define	Disable		0

#define SetPend		1
#define ClearPend	0

#define APINT_VECTKEY 		0x05FA			// THIS 2 BYTES MUS BE WRITTEN TO CHANGE APINT
//#define PRIO_CONFIG_XXX		0X0
//#define PRIO_CONFIG_XXY		0X5
//#define PRIO_CONFIG_XYY		0x6
//#define PRIO_CONFIG_YYY		0x7
#define  SYSRESREQ		0x2					//APINT reset pin

#define	PRIORITY_MASK				0X7

typedef enum {
	PRIO_CONFIG_XXX = 0x0 ,
	PRIO_CONFIG_XXY = 0x5,
	PRIO_CONFIG_XYY = 0x6,
	PRIO_CONFIG_YYY = 0x7
}priorityType;


typedef enum{
	SP = 0,
	Reset,
	NMI,
	HardFault,
	MemoryManagement,
	BusFault,
	UsageFault = 6,
	non0,
	non1,
	non2,
	non3,
	SVCall = 11,
	DebugMonitor,
	non4,
	PendSV = 14,
	SysTick,
	GPIOA_ISR = 16,
	GPIOB_ISR,
	GPIOC_ISR,
	GPIOD_ISR,
	GPIOE_ISR,
	UART0,
	UART1,
	SSI0,
	I2C0,
	PWM0Fault,
	PWM0Generator0,
	PWM0Generator1,
	PWM0Generator2,
	QEI0,
	ADC0Sequence0,
	ADC0Sequence1,
	ADC0Sequence2,
	ADC0Sequence3,
	WatchdogTimers0and1,
	_16_32_Timer0A,
	_16_32_Timer0B,
	_16_32_Timer1A,
	_16_32_Timer1B,
	_16_32_Timer2A,
	_16_32_Timer2B,
	AnalogComparator0,
	AnalogComparator1,
	Reserved,
	SystemControl = 44,
	Flash_Memory_Control_and_EEPROM_Control,
	GPIOF_ISR,
	Reserved1,
	Reserved2,
	UART2 = 49,
	SSI1,
	_16_32_Timer3A,
	_16_32_Timer3B,
	I2C1,
	QEI1,
	CAN0,
	CAN1,
	Reserved3,
	Reserved4,
	HibernationModule = 59,
	USB,
	PWMGenerator3,
	uDMASoftware,
	uDMAError,
	ADC1Sequence0,
	ADC1Sequence1,
	ADC1Sequence2,
	ADC1Sequence3,
	Reserved5,
	Reserved6,
	Reserved7,
	Reserved8,
	Reserved9,
	SSI2 = 73,
	SSI3,
	UART3,
	UART4,
	UART5,
	UART6,
	UART7,
	Reserved10,
	Reserved11,
	Reserved12,
	Reserved13,
	I2C2 = 84,
	I2C3,
	Timer4A,
	Timer4B,
	Reserved14,
	Reserved15,
	Reserved16,
	Reserved17,
	Reserved18,
	Reserved19,
	Reserved20,
	Reserved21,
	Reserved22,
	Reserved23,
	Reserved24,
	Reserved25,
	Reserved26,
	Reserved27,
	Reserved28,
	Reserved29,
	Reserved30,
	Reserved31,
	Reserved32,
	Reserved33,
	_16_32_Timer5A = 108,
	_16_32_Timer5B,
	_32_64Timer0A,
	_32_64Timer0B,
	_32_64Timer1A,
	_32_64Timer1B,
	_32_64Timer2A,
	_32_64Timer2B,
	_32_64Timer3A,
	_32_64Timer3B,
	_32_64Timer4A,
	_32_64Timer4B,
	_32_64Timer5A,
	_32_64Timer5B,
	SystemException,
	Reserved34,
	Reserved35,
	Reserved36,
	Reserved37,
	Reserved38,
	Reserved39,
	Reserved40,
	Reserved41,
	Reserved42,
	Reserved43,
	Reserved44,
	Reserved45,
	Reserved46,
	Reserved47,
	Reserved48,
	Reserved49,
	Reserved50,
	Reserved51,
	Reserved52,
	Reserved53,
	Reserved54,
	Reserved55,
	Reserved56,
	Reserved57,
	Reserved58,
	Reserved59,
	Reserved60,
	PWM1Generator0 = 	150,
	PWM1Generator1,
	PWM1Generator2,
	PWM1Generator3,
	PWM1Fault
}VecTableNames;


unsigned char IntCtrl_Init(void);

void interruptEnableDisable(VecTableNames InterruptName,unsigned char option );

void interruptPendSetClear(VecTableNames InterruptName,unsigned char option );

void changePriorityType(priorityType PRIORITY);

void interruptPrioritySet(VecTableNames InterruptName,unsigned char priority);

void	APINT_Reset();
uint32_t GetPSR_val();

unsigned char IntCtrl_init ();
#endif