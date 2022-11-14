



#ifndef		__CORE_H__
#define 	__CORE_H__


#include <stdint.h>


typedef enum {
	APSR_nzcvq, APSR_g, APSR_nzcvqg, MSP, PSP, PRIMASK, BASEPRI,
BASEPRI_MAX, FAULTMASK, CONTROL

}SpecialRegisterWriteType;

typedef enum {APSR, IPSR, EPSR, IEPSR, IAPSR, EAPSR, PSR, MSP_r, PSP_r, PRIMASK_r, BASEPRI_r,
BASEPRI_MAX_r, FAULTMASK_r, CONTROL_r}SpecialRegisterReadType;


uint32_t	writeSpecialRegister(SpecialRegisterWriteType registerName, uint32_t word);
uint32_t readSpecialRegister(SpecialRegisterReadType registerName);


void enableFAULTMASK(void);
void disableFAULTMASK(void);

void enablePRIMASK(void);
void disablePRIMASK(void);


#endif