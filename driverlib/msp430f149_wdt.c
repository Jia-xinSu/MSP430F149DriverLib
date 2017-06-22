
#include "msp430f149_wdt.h"

void WDT_hold(void)
{
  uint16_t wdtCotrolVal=(WDTCTL&0x00ff)|(WDTHOLD);
  WDTCTL=wdtCotrolVal|WDTPW;
}

void WDT_start(void)
{
  uint16_t wdtCotrolVal=(WDTCTL&0x00ff)&(~(WDTHOLD));
  WDTCTL=wdtCotrolVal|WDTPW;
}

void WDT_enableInterrupt(WDT_interruptMode WDT_X_INTERRUPT_MODE)
{
  if(WDT_X_INTERRUPT_MODE==WDT_NMI_INTERRUPT_MODE)
  {
    IE1|=NMIIE;
  }
  else if(WDT_X_INTERRUPT_MODE==WDT_INTERVAL_INTERRUPT_MODE)
  {
    IE1|=WDTIE;
  }
}

void WDT_disableInterrupt(WDT_interruptMode WDT_X_INTERRUPT_MODE)
{
  if(WDT_X_INTERRUPT_MODE==WDT_NMI_INTERRUPT_MODE)
  {
    IE1&=~NMIIE;
  }
  else if(WDT_X_INTERRUPT_MODE==WDT_INTERVAL_INTERRUPT_MODE)
  {
    IE1&=~WDTIE;
  }
}

void WDT_clearInterrupt(WDT_interruptMode WDT_X_INTERRUPT_MODE)
{
  if(WDT_X_INTERRUPT_MODE==WDT_NMI_INTERRUPT_MODE)
  {
    IFG1&=~NMIIFG;
  }
  else if(WDT_X_INTERRUPT_MODE==WDT_INTERVAL_INTERRUPT_MODE)
  {
    IFG1&=~WDTIFG;
  }
}

void WDT_resetTimer(void)
{
  uint16_t wdtCotrolVal=(WDTCTL&0x00ff)|(WDTCNTCL);
  WDTCTL=wdtCotrolVal|WDTPW;
}

void WDT_initAsIntervalTimer(uint16_t WDT_SOURCE_x,uint16_t WDT_CLOCKDIVIDER_x)
{
  uint16_t wdtCotrolVal=((WDTCTL&0x0060)| \
  	                     (WDTHOLD+WDTTMSEL+WDTCNTCL+\
  	                      WDT_SOURCE_x+WDT_CLOCKDIVIDER_x));
  WDTCTL=wdtCotrolVal|WDTPW;
}

void WDT_initAsWatchDogTimer(uint16_t WDT_SOURCE_x,uint16_t WDT_CLOCKDIVIDER_x)
{
  uint16_t wdtCotrolVal=((WDTCTL&0x0060)| \
  	                     (WDTHOLD+WDTCNTCL+\
  	                      WDT_SOURCE_x+WDT_CLOCKDIVIDER_x));
  WDTCTL=wdtCotrolVal|WDTPW;
}
