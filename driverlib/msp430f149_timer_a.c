#include "msp430f149_timer_a.h"

static const uint16_t TIMER_A_getTACCRCTLxAddress[]={
  0x0000,
  0x0162,
  0x0164,
  0x0166
};

static const uint16_t TIMER_A_getTACCRxAddress[]={
  0x0000,
  0x0172,
  0x0174,
  0x0176
};

void TIMER_A_start_Counter(uint16_t TIMER_A_x_MODE)
{
  TACTL=(TACTL&(0xffcf))+TIMER_A_x_MODE;
}

void Timer_A_initAsContinuousMode(Timer_A_initAsContinuousModeTypedef Timer_A_initAsContinuousModeParam)
{
  uint16_t newTACTL=(TACTL&0xfc09)+ \
  	       Timer_A_initAsContinuousModeParam.clockSource+ \
  	       Timer_A_initAsContinuousModeParam.clockSourceDivider+ \
  	       Timer_A_initAsContinuousModeParam.timerClear+ \
  	       Timer_A_initAsContinuousModeParam.timerInterruptEnable;
  if(Timer_A_initAsContinuousModeParam.timerStart==TIMER_A_START)
  {
    newTACTL|=TIMER_A_CONTINUOUS_MODE;
  }
  TACTL=newTACTL;
}

void Timer_A_initAsUpMode(Timer_A_initAsUpModeTypedef Timer_A_initAsUpModeParam)
{
  uint16_t newTACTL=(TACTL&0xfc09)+ \
  	                Timer_A_initAsUpModeParam.clockSource+\
  	                Timer_A_initAsUpModeParam.clockSourceDivider+\
  	                Timer_A_initAsUpModeParam.timerClear+\
  	                Timer_A_initAsUpModeParam.timerInterruptEnable;
  if(Timer_A_initAsUpModeParam.timerStart ==TIMER_A_START)
  {
    newTACTL|=TIMER_A_UP_MODE;
  }
  TACCR0=Timer_A_initAsUpModeParam.timerPeriod;
  TACCTL0=(TACCR0&0xffef)+Timer_A_initAsUpModeParam.captureCompareInterruptEnable0;
  TACTL=newTACTL;
}