



#include "CORE.H"
#include <stdint.h>



/////////////////////////////////////////////////////////////////////////////////
// function to write to the special registers
// arguments are the name of special registers
/*  APSR_nzcvq, APSR_g, APSR_nzcvqg, MSP, PSP, PRIMASK, BASEPRI,
BASEPRI_MAX, FAULTMASK, CONTROL*/
// and value_new = the word to be written
// and will return the old value of the register

uint32_t	writeSpecialRegister(SpecialRegisterWriteType registerName,uint32_t value_new){
	
	
	uint32_t value_old;

	switch(registerName){
		case APSR_nzcvq:
		__asm volatile(
				"mrs %[aaa1], APSR_nzcvq\n"			//output constrain
				"msr APSR_nzcvq, %[bbb2]\n"
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
				:[bbb2] "r" (value_new)				// input constrain
			);	
			break;
		
		case APSR_g:
			__asm volatile(
				"mrs %[aaa1], APSR_g\n"			//output constrain
				"msr APSR_g, %[bbb2]\n"
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
				:[bbb2] "r" (value_new)				// input constrain
			);
			break;
			
		case APSR_nzcvqg:
			__asm volatile(
				"mrs %[aaa1], APSR_nzcvqg\n"			//output constrain
				"msr APSR_nzcvqg, %[bbb2]\n"
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
				:[bbb2] "r" (value_new)				// input constrain
			);
			break;
		case MSP:
			__asm volatile(
				"mrs %[aaa1], MSP\n"			//output constrain
				"msr MSP, %[bbb2]\n"
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
				:[bbb2] "r" (value_new)				// input constrain
			);
			break;
		case PSP:
			__asm volatile(
				"mrs %[aaa1], PSP\n"			//output constrain
				"msr PSP, %[bbb2]\n"
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
				:[bbb2] "r" (value_new)				// input constrain
			);
			break;
		case PRIMASK:
			__asm volatile(
				"mrs %[aaa1], PRIMASK\n"			//output constrain
				"msr PRIMASK, %[bbb2]\n"
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
				:[bbb2] "r" (value_new)				// input constrain
			);
			break;
		case BASEPRI:
			__asm volatile(
				"mrs %[aaa1], BASEPRI\n"			//output constrain
				"msr BASEPRI, %[bbb2]\n"
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
				:[bbb2] "r" (value_new)				// input constrain
			);
			break;
		case BASEPRI_MAX:
			__asm volatile(
				"mrs %[aaa1], BASEPRI_MAX\n"			//output constrain
				"msr BASEPRI_MAX, %[bbb2]\n"
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
				:[bbb2] "r" (value_new)				// input constrain
			);
			break;
		case FAULTMASK:
			__asm volatile(
				"mrs %[aaa1], FAULTMASK\n"			//output constrain
				"msr FAULTMASK, %[bbb2]\n"
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
				:[bbb2] "r" (value_new)				// input constrain
			);
			break;
		case CONTROL:
			__asm volatile(
				"mrs %[aaa1], CONTROL\n"			//output constrain
				"msr CONTROL, %[bbb2]\n"
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
				:[bbb2] "r" (value_new)				// input constrain
			);
			break;
			
		
	}
	return value_old;
}
	

////////////////////////////////////////////////////////////////
// this function will return all special registers
// arguments are 
	/*APSR, IPSR, EPSR, IEPSR, IAPSR, EAPSR, PSR, MSP, PSP, PRIMASK, BASEPRI,
BASEPRI_MAX, FAULTMASK, or CONTROL.*/
/////////////////////////////////////////////////////////////////

uint32_t readSpecialRegister(SpecialRegisterReadType registerName){
	uint32_t value_old;
	switch(registerName){
		case APSR:
		__asm volatile(
				"mrs %[aaa1], APSR\n"			//output constrain
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
			);	
			break;
		case IPSR:
			__asm volatile(
				"mrs %[aaa1], IPSR\n"			//output constrain
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
			);
			break;
			
		case EPSR:
			__asm volatile(
				"mrs %[aaa1], EPSR\n"			//output constrain
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
			);
			break;
			
		case IEPSR:
			__asm volatile(
				"mrs %[aaa1], IEPSR\n"			//output constrain
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
			);
			break;
		case IAPSR:
			__asm volatile(
				"mrs %[aaa1], IAPSR\n"			//output constrain
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
			);
			break;
			
		case EAPSR:
			__asm volatile(
				"mrs %[aaa1], EAPSR\n"			//output constrain
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
			);
			break;
			
			
		case PSR:
			__asm volatile(
				"mrs %[aaa1], xPSR\n"			//output constrain
				//"ldr %[aaa1],r0\n"
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
			);
			break;
			
		case MSP_r:
			__asm volatile(
				"mrs %[aaa1], MSP\n"			//output constrain
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
			);
			break;
			
		case PSP_r:
			__asm volatile(
				"mrs %[aaa1], PSP\n"			//output constrain
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
			);
			break;
			
		case PRIMASK_r:
			__asm volatile(
				"mrs %[aaa1], PRIMASK\n"			//output constrain
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
			);
			break;
			
			
			case BASEPRI_r:
			__asm volatile(
				"mrs %[aaa1], BASEPRI\n"			//output constrain
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
			);
			break;
			
			case BASEPRI_MAX_r:
			__asm volatile(
				"mrs %[aaa1], BASEPRI_MAX\n"			//output constrain
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
			);
			break;
			
			case FAULTMASK_r:
			__asm volatile(
				"mrs %[aaa1], FAULTMASK\n"			//output constrain
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
			);
			break;
			
			case CONTROL_r:
			__asm volatile(
				"mrs %[aaa1], CONTROL\n"			//output constrain
				"isb\n"
				:[aaa1] "=&r" (value_old)		//decomment to declare output constrain
			);
			break;
	}
	return value_old;
}









//////////////////////////////////////////
//enable and disable  FAULTMASK,PRIMASK
void enableFAULTMASK(void){
	__asm(" cpsie		f");
}
void disableFAULTMASK(void){
	__asm(" cpsid		f");
}

void enablePRIMASK(void){
	__asm(" cpsie		i");
}
void disablePRIMASK(void){
	__asm(" cpsid		i");
}