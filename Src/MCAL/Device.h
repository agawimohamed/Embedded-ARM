

#ifndef __Device_h__
#define	__Device_h__

#include <stdint.h>



///////////////////////////////////////////////////////////////////////////////////
// TIMERS DEFINITIONS
#define Timer_Base						0x400FE000UL
#define RCGCTIMER_Offset			0x604		
#define	RCGCTIMER							*((volatile uint32_t *)(Timer_Base+RCGCTIMER_Offset))			//16/32-Bit General-Purpose Timer Run Mode Clock Gating Control

#define RCGCWTIMER_Offset			0x65C
#define RCGCWTIMER						*((volatile uint32_t *)(Timer_Base+RCGCWTIMER_Offset))    //32/64-Bit Wide General-Purpose Timer Run Mode Clock Gating Control 

#define	_16_32_bitTimer_0_base 0x40030000
#define	_16_32_bitTimer_1_base 0x40031000
#define	_16_32_bitTimer_2_base 0x40032000
#define	_16_32_bitTimer_3_base 0x40033000
#define	_16_32_bitTimer_4_base 0x40034000
#define	_16_32_bitTimer_5_base 0x40035000

#define	_32_64_bitTimer_0_base 0x40036000
#define	_32_64_bitTimer_1_base 0x40037000
#define	_32_64_bitTimer_2_base 0x4004c000
#define	_32_64_bitTimer_3_base 0x4004d000
#define	_32_64_bitTimer_4_base 0x4004E000
#define	_32_64_bitTimer_5_base 0x4004F000


typedef struct {
	uint32_t GPTMCFG;
	uint32_t GPTMTAMR;
	uint32_t GPTMTBMR;
	uint32_t GPTMCTL;
	uint32_t GPTMSYNC;
	uint32_t reserved0;
	uint32_t GPTMIMR;
	uint32_t GPTMRIS;
	uint32_t GPTMMIS;
	uint32_t GPTMICR;
	uint32_t GPTMTAILR;
	uint32_t GPTMTBILR;
	uint32_t GPTMTAMATCHR;
	uint32_t GPTMTBMATCHR;
	uint32_t GPTMTAPR;
	uint32_t GPTMTBPR;
	uint32_t GPTMTAPMR;
	uint32_t GPTMTBPMR;
	uint32_t GPTMTAR;
	uint32_t GPTMTBR;
	uint32_t GPTMTAV;
	uint32_t GPTMTBV;
	uint32_t GPTMRTCPD;
	uint32_t GPTMTAPS;
	uint32_t GPTMTBPS;
	uint32_t GPTMTAPV;
	uint32_t GPTMTBPV;
	uint32_t reserved1[((0xFC0-0x068)/4)-1];				// = 0x3DA
	uint32_t GPTMPP;
}TimerRegisters;

#define	TIMER0_16_32	((volatile TimerRegisters*)_16_32_bitTimer_0_base)
#define	TIMER1_16_32	((volatile TimerRegisters*)_16_32_bitTimer_1_base)
#define	TIMER2_16_32	((volatile TimerRegisters*)_16_32_bitTimer_2_base)
#define	TIMER3_16_32	((volatile TimerRegisters*)_16_32_bitTimer_3_base)
#define	TIMER4_16_32	((volatile TimerRegisters*)_16_32_bitTimer_4_base)
#define	TIMER5_16_32	((volatile TimerRegisters*)_16_32_bitTimer_5_base)
						
#define	TIMER0_32_64	((volatile TimerRegisters*)_32_64_bitTimer_0_base)
#define	TIMER1_32_64	((volatile TimerRegisters*)_32_64_bitTimer_1_base)
#define	TIMER2_32_64	((volatile TimerRegisters*)_32_64_bitTimer_2_base)
#define	TIMER3_32_64	((volatile TimerRegisters*)_32_64_bitTimer_3_base)
#define	TIMER4_32_64	((volatile TimerRegisters*)_32_64_bitTimer_4_base)
#define	TIMER5_32_64	((volatile TimerRegisters*)_32_64_bitTimer_5_base)
	
 
////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
//  System Timer (SysTick) Registers
#define 	SysTick_Base						0xE000E000UL
#define 	STCTRL_Offset						0x010
#define		STRELOAD_Offset					0x014
#define		STCURRENT_Offset				0x018


typedef struct SSTCTRL_BF{
	 uint32_t		ENABLE	:1;
	 uint32_t		INTEN		:1;
	 uint32_t		CLK_SRC	:1;
	 uint32_t						:13;
	 uint32_t		COUNT		:1;
	 uint32_t						:15;
}STCTRL_BF;

typedef union {
	STCTRL_BF  BF;
	uint32_t		R;
}STCTRL_union;


#define		STCTRL				((volatile STCTRL_union*) (SysTick_Base+STCTRL_Offset))
#define		STRELOAD			*((volatile uint32_t*)(SysTick_Base+STRELOAD_Offset))
#define		STCURRENT			*((volatile uint32_t*)(SysTick_Base+STCURRENT_Offset))
#define		SysTickCURRENT_Offset			STCURRENT		// illustrative illias

//////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//   NVIC interrupts registers definions                                      ////////////////////////////////////
#define			NVIC_Base		 0xE000E000UL
#define			EN0_Offset		0x100
#define			EN1_Offset		0x104
#define			EN2_Offset		0x108
#define			EN3_Offset		0x10C
#define			EN4_Offset		0x110
#define			DIS0_Offset		0x180
#define			DIS1_Offset		0x184
#define			DIS2_Offset		0x188
#define			DIS3_Offset		0x18C
#define			DIS4_Offset		0x190

#define			PEND0_Offset		0x200
#define			PEND1_Offset		0x204
#define			PEND2_Offset		0x208
#define			PEND3_Offset		0x20C
#define			PEND4_Offset		0x210

#define			UNPEND0_Offset		0x280
#define			UNPEND1_Offset		0x284
#define			UNPEND2_Offset		0x288
#define			UNPEND3_Offset		0x28C
#define			UNPEND4_Offset		0x290

#define			ACTIVE0_Offset		0x300
#define			ACTIVE1_Offset		0x304
#define			ACTIVE2_Offset		0x308
#define			ACTIVE3_Offset		0x30C
#define			ACTIVE4_Offset		0x310


#define			PRI0_Offset		0x400
#define			PRI1_Offset		0x404
#define			PRI2_Offset		0x408
#define			PRI3_Offset		0x40C
#define			PRI4_Offset		0x410
#define			PRI5_Offset		0x414
#define			PRI6_Offset		0x418
#define			PRI7_Offset		0x41C
#define			PRI8_Offset		0x420
#define			PRI9_Offset		0x424
#define			PRI10_Offset		0x428
#define			PRI11_Offset		0x42C
#define			PRI12_Offset		0x430
#define			PRI13_Offset		0x434
#define			PRI14_Offset		0x438
#define			PRI15_Offset		0x43C
#define			PRI16_Offset		0x440
#define			PRI17_Offset		0x444
#define			PRI18_Offset		0x448
#define			PRI19_Offset		0x44C
#define			PRI20_Offset		0x450
#define			PRI21_Offset		0x454
#define			PRI22_Offset		0x458
#define			PRI23_Offset		0x45C
#define			PRI24_Offset		0x460
#define			PRI25_Offset		0x464
#define			PRI26_Offset		0x468
#define			PRI27_Offset		0x46C
#define			PRI28_Offset		0x470
#define			PRI29_Offset		0x474
#define			PRI30_Offset		0x478
#define			PRI31_Offset		0x47C
#define			PRI32_Offset		0x480
#define			PRI33_Offset		0x484
#define			PRI34_Offset		0x488

#define			SWTRIG_Offset		0xF00


#define			EN0_R				*((volatile uint32_t*)(NVIC_Base + EN0_Offset))		
#define			EN1_R				*((volatile uint32_t*)(NVIC_Base + EN1_Offset		))	
#define			EN2_R				*((volatile uint32_t*)(NVIC_Base + EN2_Offset		))	
#define			EN3_R				*((volatile uint32_t*)(NVIC_Base + EN3_Offset		))	
#define			EN4_R				*((volatile uint32_t*)(NVIC_Base + EN4_Offset		))	
	
#define			DIS0_R				*((volatile uint32_t*)(NVIC_Base + DIS0_Offset	))		
#define			DIS1_R				*((volatile uint32_t*)(NVIC_Base + DIS1_Offset	))
#define			DIS2_R				*((volatile uint32_t*)(NVIC_Base + DIS2_Offset	))		
#define			DIS3_R				*((volatile uint32_t*)(NVIC_Base + DIS3_Offset	))		
#define			DIS4_R				*((volatile uint32_t*)(NVIC_Base + DIS4_Offset	))		

#define			PEND0_R				*((volatile uint32_t*)(NVIC_Base + PEND0_Offset	))		
#define			PEND1_R				*((volatile uint32_t*)(NVIC_Base + PEND1_Offset	))		
#define			PEND2_R				*((volatile uint32_t*)(NVIC_Base + PEND2_Offset	))		
#define			PEND3_R				*((volatile uint32_t*)(NVIC_Base + PEND3_Offset	))		
#define			PEND4_R				*((volatile uint32_t*)(NVIC_Base + PEND4_Offset	))		

#define			UNPEND0_R				*((volatile uint32_t*)(NVIC_Base + UNPEND0_Offset	))		
#define			UNPEND1_R				*((volatile uint32_t*)(NVIC_Base + UNPEND1_Offset	))		
#define			UNPEND2_R				*((volatile uint32_t*)(NVIC_Base + UNPEND2_Offset	))		
#define			UNPEND3_R				*((volatile uint32_t*)(NVIC_Base + UNPEND3_Offset	))		
#define			UNPEND4_R				*((volatile uint32_t*)(NVIC_Base + UNPEND4_Offset	))		

#define			ACTIVE0_R				*((volatile uint32_t*)(NVIC_Base + ACTIVE0_Offset	))		
#define			ACTIVE1_R				*((volatile uint32_t*)(NVIC_Base + ACTIVE1_Offset	))		
#define			ACTIVE2_R				*((volatile uint32_t*)(NVIC_Base + ACTIVE2_Offset	))		
#define			ACTIVE3_R				*((volatile uint32_t*)(NVIC_Base + ACTIVE3_Offset	))		
#define			ACTIVE4_R				*((volatile uint32_t*)(NVIC_Base + ACTIVE4_Offset	))		


#define			PRI0_R				*((volatile uint32_t*)(NVIC_Base + PRI0_Offset	))		
#define			PRI1_R				*((volatile uint32_t*)(NVIC_Base + PRI1_Offset	))		
#define			PRI2_R				*((volatile uint32_t*)(NVIC_Base + PRI2_Offset	))		
#define			PRI3_R				*((volatile uint32_t*)(NVIC_Base + PRI3_Offset	))		
#define			PRI4_R				*((volatile uint32_t*)(NVIC_Base + PRI4_Offset	))		
#define			PRI5_R				*((volatile uint32_t*)(NVIC_Base + PRI5_Offset	))		
#define			PRI6_R				*((volatile uint32_t*)(NVIC_Base + PRI6_Offset	))		
#define			PRI7_R				*((volatile uint32_t*)(NVIC_Base + PRI7_Offset	))		
#define			PRI8_R				*((volatile uint32_t*)(NVIC_Base + PRI8_Offset	))		
#define			PRI9_R				*((volatile uint32_t*)(NVIC_Base + PRI9_Offset	))		
#define			PRI10_R				*((volatile uint32_t*)(NVIC_Base + PRI10_Offset	))		
#define			PRI11_R				*((volatile uint32_t*)(NVIC_Base + PRI11_Offset	))		
#define			PRI12_R				*((volatile uint32_t*)(NVIC_Base + PRI12_Offset	))		
#define			PRI13_R				*((volatile uint32_t*)(NVIC_Base + PRI13_Offset	))		
#define			PRI14_R				*((volatile uint32_t*)(NVIC_Base + PRI14_Offset	))		
#define			PRI15_R				*((volatile uint32_t*)(NVIC_Base + PRI15_Offset	))		
#define			PRI16_R				*((volatile uint32_t*)(NVIC_Base + PRI16_Offset	))		
#define			PRI17_R				*((volatile uint32_t*)(NVIC_Base + PRI17_Offset	))		
#define			PRI18_R				*((volatile uint32_t*)(NVIC_Base + PRI18_Offset	))		
#define			PRI19_R				*((volatile uint32_t*)(NVIC_Base + PRI19_Offset	))		
#define			PRI20_R				*((volatile uint32_t*)(NVIC_Base + PRI20_Offset		))	
#define			PRI21_R				*((volatile uint32_t*)(NVIC_Base + PRI21_Offset	))		
#define			PRI22_R				*((volatile uint32_t*)(NVIC_Base + PRI22_Offset	))		
#define			PRI23_R				*((volatile uint32_t*)(NVIC_Base + PRI23_Offset	))		
#define			PRI24_R				*((volatile uint32_t*)(NVIC_Base + PRI24_Offset	))		
#define			PRI25_R				*((volatile uint32_t*)(NVIC_Base + PRI25_Offset	))		
#define			PRI26_R				*((volatile uint32_t*)(NVIC_Base + PRI26_Offset	))		
#define			PRI27_R				*((volatile uint32_t*)(NVIC_Base + PRI27_Offset		))	
#define			PRI28_R				*((volatile uint32_t*)(NVIC_Base + PRI28_Offset	))		
#define			PRI29_R				*((volatile uint32_t*)(NVIC_Base + PRI29_Offset	))		
#define			PRI30_R				*((volatile uint32_t*)(NVIC_Base + PRI30_Offset	))	
#define			PRI31_R				*((volatile uint32_t*)(NVIC_Base + PRI31_Offset	))		
#define			PRI32_R				*((volatile uint32_t*)(NVIC_Base + PRI32_Offset	))		
#define			PRI33_R				*((volatile uint32_t*)(NVIC_Base + PRI33_Offset	))		
#define			PRI34_R				*((volatile uint32_t*)(NVIC_Base + PRI34_Offset	))		

#define			SWTRIG_R				*((volatile uint32_t*)(NVIC_Base + SWTRIG_Offset	))		



typedef struct {
	
	volatile uint32_t EN0;
	volatile uint32_t EN1;
	volatile uint32_t EN2;
	volatile uint32_t EN3;
	volatile uint32_t EN4;
	uint32_t BLANK0[(0x70)];
	volatile uint32_t DIS0;
	volatile uint32_t DIS1;
	volatile uint32_t DIS2;
	volatile uint32_t DIS3;
	volatile uint32_t DIS4;
	volatile uint8_t BALNK1[0X70];
	volatile uint32_t PEND0;
	volatile uint32_t PEND1;
	volatile uint32_t PEND2;
	volatile uint32_t PEND3;
	volatile uint32_t PEND4;
	volatile uint8_t BLANK2[0x70];
	volatile uint32_t UNPEND0;
	volatile uint32_t UNPEND1;
	volatile uint32_t UNPEND2;
	volatile uint32_t UNPEND3;
	volatile uint32_t UNPEND4;
	volatile uint8_t BLANK3[0x70];
	volatile uint32_t ACTIVE0;
	volatile uint32_t ACTIVE1;
	volatile uint32_t ACTIVE2;
	volatile uint32_t ACTIVE3;
	volatile uint32_t ACTIVE4;
	volatile uint8_t BLANK4[(0x400-0x310)];
	volatile uint32_t PRI0;
	volatile uint32_t PRI1;
	volatile uint32_t PRI2;
	volatile uint32_t PRI3;
	volatile uint32_t PRI4;
	volatile uint32_t PRI5;
	volatile uint32_t PRI6;
	volatile uint32_t PRI7;
	volatile uint32_t PRI8;
	volatile uint32_t PRI9;
	volatile uint32_t PRI10;
	volatile uint32_t PRI11;
	volatile uint32_t PRI12;
	volatile uint32_t PRI13;
	volatile uint32_t PRI14;
	volatile uint32_t PRI15;
	volatile uint32_t PRI16;
	volatile uint32_t PRI17;
	volatile uint32_t PRI18;
	volatile uint32_t PRI19;
	volatile uint32_t PRI20;
	volatile uint32_t PRI21;
	volatile uint32_t PRI22;
	volatile uint32_t PRI23;
	volatile uint32_t PRI24;
	volatile uint32_t PRI25;
	volatile uint32_t PRI26;
	volatile uint32_t PRI27;
	volatile uint32_t PRI28;
	volatile uint32_t PRI29;
	volatile uint32_t PRI30;
	volatile uint32_t PRI31;
	volatile uint32_t PRI32;
	volatile uint32_t PRI33;
	volatile uint32_t PRI34;
	volatile uint8_t	BLANK5[(0xF00-0x488)];
	volatile uint32_t SWTRIG;
}NVIC_type;


#define NVIC_P		((NVIC_type *)(NVIC_Base))







//////////////////////////////////////////////////////////////////////////////////////////
//  System Control Block (SCB) Registers
#define SCB_Base									0xE000E000

#define		ACTLR_Offset						0x008
#define		CPUID_Offset						0xD00
#define		INTCTRL_Offset					0xD04
#define		VTABLE_Offset						0xD08
#define		APINT_Offset						0xD0C
#define		SYSCTRL_Offset					0xD10
#define		CFGCTRL_Offset					0xD14
#define		SYSPRI1_Offset					0xD18
#define		SYSPRI2_Offset					0xD1C
#define		SYSPRI3_Offset					0xD20
#define		SYSHNDCTRL_Offset				0xD24
#define		FAULTSTAT_Offset				0xD28
#define		HFAULTSTAT_Offset				0xD2C
#define		MMADDR_Offset						0xD34
#define		FAULTADDR_Offset				0xD38


#define		ACTLR_R					*((volatile uint32_t*)(SCB_Base+ACTLR_Offset))
#define		CPUID_R					*((volatile uint32_t*)(SCB_Base+CPUID_Offset))
#define		INTCTRL_R				*((volatile uint32_t*)(SCB_Base+INTCTRL_Offset))	
#define		VTABLE_R				*((volatile uint32_t*)(SCB_Base+VTABLE_Offset))	
#define		APINT_R					*((volatile uint32_t*)(SCB_Base+APINT_Offset))
#define		SYSCTRL_R				*((volatile uint32_t*)(SCB_Base+SYSCTRL_Offset))
#define		CFGCTRL_R				*((volatile uint32_t*)(SCB_Base+CFGCTRL_Offset))
#define		SYSPRI1_R				*((volatile uint32_t*)(SCB_Base+SYSPRI1_Offset))
#define		SYSPRI2_R				*((volatile uint32_t*)(SCB_Base+SYSPRI2_Offset))
#define		SYSPRI3_R				*((volatile uint32_t*)(SCB_Base+SYSPRI3_Offset))
#define		SYSHNDCTRL_R		*((volatile uint32_t*)(SCB_Base+SYSHNDCTRL_Offset))
#define		FAULTSTAT_R			*((volatile uint32_t*)(SCB_Base+FAULTSTAT_Offset))
#define		HFAULTSTAT_R		*((volatile uint32_t*)(SCB_Base+HFAULTSTAT_Offset))
#define		MMADDR_R				*((volatile uint32_t*)(SCB_Base+MMADDR_Offset))
#define		FAULTADDR_R			*((volatile uint32_t*)(SCB_Base+FAULTADDR_Offset))



////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////
//   General-Purpose Input/Output Run Mode Clock Gating Control (RCGCGPIO)
#define			RCGCGPIO_Base 					0x400FE000
#define			RCGCGPIO_Offset					0x608
#define			RCGCGPIO								(*((volatile uint32_t *) (RCGCGPIO_Base + RCGCGPIO_Offset)))
/////////////////////////////////////////////////////////////////////////////////////
/*   RCGC2    = Run Mode Clock Gating Control Register*/
#define 		RCGC2_Base							0x400FE000
#define			RCGC2_Offset						0x108
#define			RCGC2										(*((volatile uint32_t *) (RCGC2_Base + RCGC2_Offset)))
/* /////////////////////////////////////////////////////////////////////////////////////// */




//////////////////////////////////////////////////////////////////////////////////////
// GPIO A definitions
/////////     APB
#define		GPIOA_APB_BASE			0x40004000	
#define		GPIOB_APB_BASE			0x40005000
#define		GPIOC_APB_BASE			0x40006000
#define		GPIOD_APB_BASE			0x40007000
#define		GPIOE_APB_BASE			0x40024000
#define		GPIOF_APB_BASE			0x40025000

////////      AHB
#define		GPIOA_AHB_BASE			0x40058000	
#define		GPIOB_AHB_BASE			0x40059000
#define		GPIOC_AHB_BASE			0x4005A000
#define		GPIOD_AHB_BASE			0x4005B000
#define		GPIOE_AHB_BASE			0x4005C000
#define		GPIOF_AHB_BASE			0x4005D000


///////////////////////////////////////////////////////////////////////////////////////////
//   offset definitions
#define		GPIODATA_offset							0x000
#define		GPIODIR_offset							0x400
#define		GPIOIS_offset								0x404
#define		GPIOIBE_offset							0x408
#define		GPIOIEV_offset							0x40C
#define		GPIOIM_offset								0x410
#define		GPIORIS_offset							0x414
#define		GPIOMIS_offset							0x418
#define		GPIOICR_offset							0x41C
#define		GPIOAFSEL_offset						0x420
#define		GPIODR2R_offset							0x500
#define		GPIODR4R_offset							0x504
#define		GPIODR8R_offset							0x508
#define		GPIOODR_offset							0x50C
#define		GPIOPUR_offset							0x510
#define		GPIOPDR_offset							0x514
#define		GPIOSLR_offset							0x518
#define		GPIODEN_offset							0x51C
#define		GPIOLOCK_offset							0x520
#define		GPIOCR_offset								0x524
#define		GPIOAMSEL_offset						0x528
#define		GPIOPCTL_offset							0x52C
#define		GPIOADCCTL_offset						0x530
#define		GPIODMACTL_offset						0x534
#define		GPIOPeriphID4_offset				0xFD0
#define		GPIOPeriphID5_offset				0xFD4
#define		GPIOPeriphID6_offset				0xFD8
#define		GPIOPeriphID7_offset				0xFDC
#define		GPIOPeriphID0_offset				0xFE0
#define		GPIOPeriphID1_offset				0xFE4
#define		GPIOPeriphID2_offset				0xFE8
#define		GPIOPeriphID3_offset				0xFEC
#define		GPIOPCellID0_offset					0xFF0
#define		GPIOPCellID1_offset					0xFF4
#define		GPIOPCellID2_offset					0xFF8
#define		GPIOPCellID3_offset					0xFFC   

//////////////////////////////////////////////////////////

typedef struct {
	volatile		uint32_t 	GPIODATA;
	volatile		uint8_t  	BitMasking[(0x400-4)];
	volatile		uint32_t	GPIODIR;			
	volatile		uint32_t	GPIOIS;		
	volatile		uint32_t	GPIOIBE;			
	volatile		uint32_t	GPIOIEV;		
	volatile		uint32_t	GPIOIM;		
	volatile		uint32_t	GPIORIS;			
	volatile		uint32_t	GPIOMIS;			
	volatile		uint32_t	GPIOICR;			
	volatile		uint32_t	GPIOAFSEL;		
	volatile		uint8_t		RESERVED2[0x500-0x420-4];
	volatile		uint32_t	GPIODR2R;		
	volatile		uint32_t	GPIODR4R;		
	volatile		uint32_t	GPIODR8R;		
	volatile		uint32_t	GPIOODR	;		
	volatile		uint32_t	GPIOPUR	;		
	volatile		uint32_t	GPIOPDR	;		
	volatile		uint32_t	GPIOSLR;	
	volatile		uint32_t	GPIODEN;		
	volatile		uint32_t	GPIOLOCK	;	
	volatile		uint32_t	GPIOCR;			
	volatile		uint32_t	GPIOAMSEL	;	
	volatile		uint32_t	GPIOPCTL	;	
	volatile		uint32_t	GPIOADCCTL;	
	volatile		uint32_t	GPIODMACTL;	
	volatile		uint8_t		RESERVED3[0xFD0-0x534-4];
	volatile		uint32_t	GPIOPeriphID4;
	volatile		uint32_t	GPIOPeriphID5	;
	volatile		uint32_t	GPIOPeriphID6	;
	volatile		uint32_t	GPIOPeriphID7;
	volatile		uint32_t	GPIOPeriphID0	;
	volatile		uint32_t	GPIOPeriphID1	;
	volatile		uint32_t	GPIOPeriphID2	;
	volatile		uint32_t	GPIOPeriphID3	;
	volatile		uint32_t	GPIOPCellID0	;
	volatile		uint32_t	GPIOPCellID1	;
	volatile		uint32_t	GPIOPCellID2	;
	volatile		uint32_t	GPIOPCellID3	;
}GPIO_Register_Type;


#define		GPIOA_APB		((GPIO_Register_Type* )(GPIOA_APB_BASE))
#define		GPIOB_APB		((GPIO_Register_Type* )(GPIOB_APB_BASE))
#define		GPIOC_APB		((GPIO_Register_Type* )(GPIOC_APB_BASE))
#define		GPIOD_APB		((GPIO_Register_Type* )(GPIOD_APB_BASE))
#define		GPIOE_APB		((GPIO_Register_Type* )(GPIOE_APB_BASE))
#define		GPIOF_APB		((GPIO_Register_Type* )(GPIOF_APB_BASE))

#define		GPIOA_AHB		((GPIO_Register_Type* )(GPIOA_AHB_BASE))
#define		GPIOB_AHB		((GPIO_Register_Type* )(GPIOB_AHB_BASE))
#define		GPIOC_AHB		((GPIO_Register_Type* )(GPIOC_AHB_BASE))
#define		GPIOD_AHB		((GPIO_Register_Type* )(GPIOD_AHB_BASE))
#define		GPIOE_AHB		((GPIO_Register_Type* )(GPIOE_AHB_BASE))
#define		GPIOF_AHB		((GPIO_Register_Type* )(GPIOF_AHB_BASE))
////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#define							*((volatile uint32_t*)(GPIOA_APB_BASE+GPIODATA)
#define							*((volatile uint32_t*)(GPIOA_APB_BASE+GPIODIR)
#define							*((volatile uint32_t*)(GPIOA_APB_BASE)
#define							*((volatile uint32_t*)(GPIOA_APB_BASE)
#define							*((volatile uint32_t*)(GPIOA_APB_BASE)
#define							*((volatile uint32_t*)(GPIOA_APB_BASE)
#define							*((volatile uint32_t*)(GPIOA_APB_BASE)
#define							*((volatile uint32_t*)(GPIOA_APB_BASE)
#define							*((volatile uint32_t*)(GPIOA_APB_BASE)
#define							*((volatile uint32_t*)(GPIOA_APB_BASE)
#define							*((volatile uint32_t*)(GPIOA_APB_BASE)
#define							*((volatile uint32_t*)()
#define							*((volatile uint32_t*)()
#define							*((volatile uint32_t*)()


*/


#endif
