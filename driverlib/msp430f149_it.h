
#ifndef __MSP430F149_IT_H
#define __MSP430F149_IT_H

#ifdef __cplusplus
extern "C"
{
#endif
  
#include "driverlib.h"

void NMI_ISR(void);
void RESET_ISR(void);

#ifdef __cplusplus
}
#endif
#endif
