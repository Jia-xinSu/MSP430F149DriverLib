#include "msp430f149_adc12.h"

void ADC12_init(ADC12_initTypedef ADC12_initParam)
{
  ADC12CTL0&=~ENC;
  ADC12CTL0&=~(ADC12ON+ADC12OVIE+ENC+ADC12SC);
  ADC12IE=0x0000;
  ADC12IFG=0x0000;
  uint16_t newADC12CTL1=(ADC12CTL1&0xf307)+\
                         ADC12_initParam.clockSourceDivider+\
                         ADC12_initParam.clockSourceSelect+\
                         ADC12_initParam.sampleHoldSignalSourceSelect;
  ADC12CTL1=newADC12CTL1;
}

void ADC12_enable(void)
{
  ADC12CTL0|=ADC12ON;
}

void ADC12_disable(void)
{
  ADC12CTL0&=~ADC12ON;
}

void ADC12_setupSamplingTimer(uint16_t clockCycleHoldCountLowMem, \
                              uint16_t clockCycleHoldCountHighMem, \
                              uint16_t multipleSamplesEnabled)
{
  ADC12CTL1|=SHP;
  ADC12CTL0=ADC12CTL0&(0x007f)+\
            clockCycleHoldCountLowMem+
            (uint16_t)((clockCycleHoldCountHighMem<<4)&0xf000)+\
            multipleSamplesEnabled;
}

void ADC12_disableSamplingTimer(void)
{
  ADC12CTL1&=~SHP;
}

ADC12_configureMemory()
{
  
}