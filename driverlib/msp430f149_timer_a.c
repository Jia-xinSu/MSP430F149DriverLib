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

void TIMER_A_init(TIMER_A_initTypedef TIMER_A_initParam)
{
  TACTL=(TACTL&0xfffe)+ \
  	    TIMER_A_initParam.clockSource+ \
  	    TIMER_A_initParam.clockSourceDivider+ \
  	    TIMER_A_initParam.timerClear+ \
  	    TIMER_A_initParam.timerInterruptEnable+ \
  	    TIMER_A_initParam.timerMode;
}

void TIMER_A_initCompera(TIMER_A_initCCRCompareModeTypedef TIMER_A_initCCRCompareModeParam)
{

}