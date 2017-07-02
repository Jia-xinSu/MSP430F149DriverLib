#include "msp430f149_adc12.h"
#include "assert.h"
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

void ADC12_configureMemory(ADC12_configureMemoryTypeDef ADC12_configureMemoryParam)
{
  assert(!(ADC12CTL0&ENC));
  if(!(ADC12CTL0&ENC))
   {
     HWREG8(0x0080+ADC12_configureMemoryParam.memoryBufferControlIndex)= \
  	  ADC12_configureMemoryParam.endOfSequence+ \
  	  ADC12_configureMemoryParam.inputSourceSelect+ \
  	  ADC12_configureMemoryParam.negativeRefVoltageSourceSelect+ \
  	  ADC12_configureMemoryParam.positiveRefVoltageSourceSelect;
  	}
}

void ADC12_enableInterrupt(uint16_t ADC12_interruptEnable,uint16_t ADC12_overflowInterruptEnable)
{
  ADC12IE|=ADC12_interruptEnable;
  ADC12CTL0=ADC12CTL0&(0xfff3)+ADC12_overflowInterruptEnable;
}

void ADC12_disableInterrupt(uint16_t ADC12_interruptEnable,uint16_t ADC12_overflowInterruptEnable)
{
  ADC12IE&=~ADC12_interruptEnable;
  ADC12CTL0&=ADC12_overflowInterruptEnable;
}

void ADC12_clearInterrupt(uint16_t ADC12_interruptFlag)
{
  ADC12IFG&=~ADC12_interruptFlag;
}

uint16_t ADC12_getInerruptStatus(uint16_t ADC12_interruptFlag)
{
  return(ADC12IFG&ADC12_interruptFlag);
}

void ADC12_startConversion(uint16_t startMemoryBufferIndex,uint16_t conversionSequenceModeSelect)
{
  ADC12CTL0&=~ENC;
  ADC12CTL1=(ADC12CTL1&0x0ff9)+ \
  	        (uint16_t)((startMemoryBufferIndex<<12)&0xf000)+ \
  	        conversionSequenceModeSelect;
  ADC12CTL0|=ENC+ADC12SC;
}

void ADC12_disableConversion(preemptTypedef ADC12_xCONVERSION)
{
  if(ADC12_xCONVERSION==ADC12_PREEMPTCONVERSION)
  {
    ADC12CTL1&=~CONSEQ_3;
  }
  else if(~ADC12CTL1&CONSEQ_3)
  {
    while(ADC12_isBusy())
    {
      __no_operation();
    }
  }
}

uint16_t ADC12_isBusy(void)
{
  return (ADC12CTL1&ADC12BUSY);
}

uint16_t ADC12_getResults(uint16_t memoryBufferControlIndex)
{
  return(HWREG16(0x0140+2*memoryBufferControlIndex));
}

void ADC12_setSampleHoldSignalInversion(uint16_t invertedSignal)
{
  ADC12CTL1&=~ISSH;
  ADC12CTL1|=invertedSignal;
}
