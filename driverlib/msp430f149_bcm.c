
#include "msp430f149_bcm.h"

static uint32_t privateXT1ClockFrequency = 0;
static uint32_t privateXT2ClockFrequency = 0;

void BCM_setExternalClockSource(uint32_t XT1CLK_frequency,uint32_t XT2CLK_frequency)
{
  privateXT1ClockFrequency=XT1CLK_frequency;
  privateXT2ClockFrequency=XT2CLK_frequency;
}

void BCM_initMCLKSignal(uint8_t BCM_MCLK_SOURCE_x,uint8_t BCM_DIVIDER_x)
{
  uint8_t newBCSCTL2=(BCSCTL2&0x0f)|BCM_MCLK_SOURCE_x|(BCM_DIVIDER_x<<BCM_OFSB_DIVM);
  BCSCTL2=newBCSCTL2;
}

void BCM_initSMCLKSignal(uint8_t BCM_SMCLK_SOURCE_x,uint8_t BCM_DIVIDER_x)
{
  uint8_t newBCSCTL2=(BCSCTL2&0xf1)|BCM_SMCLK_SOURCE_x|(BCM_DIVIDER_x<<BCM_OFSB_DIVS);
  BCSCTL2=newBCSCTL2;
}

void BCM_iniACLKSignal(uint8_t BCM_DIVIDER_x)
{
  uint8_t newBCSCTL1=(BCSCTL1&0xcf)|(BCM_DIVIDER_x<<BCM_OFSB_DIVA);
  BCSCTL1 = newBCSCTL1;
}

void BCM_turnOnXT2(void)
{
  BCSCTL1&=~XT2OFF;
  do
  {
    IFG1&=~OFIFG;
  }
  while(IFG1&OFIFG);
}

void BCM_turnOnXT2WithTimeout(uint32_t timeout)
{
  BCSCTL1&=~XT2OFF;
  do
  {
    IFG1&=~OFIFG;
	timeout--;
  }
  while((IFG1&OFIFG)&&(timeout>0));
}

void BCM_turnOffXT2(void)
{
  BCSCTL1|=XT2OFF;
}

uint32_t BCM_getMCLK(void)
{
  uint32_t sourceFrequency=0;
  uint8_t divider=1;
  switch(BCSCTL2&0xc0)
  {
  case 0x00:  //加入内部振荡器
  case 0x40:
    break;
  case 0x80:
    sourceFrequency=privateXT2ClockFrequency;
    break;
  case 0xc0:
    sourceFrequency=privateXT1ClockFrequency;
    break;
  default:
    break;
  }
  switch(BCSCTL2&0x30)
  {
  case 0x00:
    divider=1;
    break;
  case 0x10:
    divider=2;
    break;
  case 0x20:
    divider=4;
    break;
  case 0x30:
    divider=8;
    break;
  default:
    break;
  }
  return (sourceFrequency/divider);
}

uint32_t BCM_getSMCLK(void)
{
  uint32_t sourceFrequency=0;
  uint8_t divider=1;
  switch(BCSCTL2&0x08)
  {
  case 0x00:
    break;
  case 0x08:
    sourceFrequency=privateXT2ClockFrequency;
    break;
  default:
    break;
  }
  switch(BCSCTL2&0x06)
  {
  case 0x00:
    divider=1;
    break;
  case 0x02:
    divider=2;
    break;
  case 0x04:
    divider=4;
    break;
  case 0x06:
    divider=8;
    break;
  default:
    break;
  }
  return (sourceFrequency/divider);
}

uint32_t BCM_getACLK(void)
{
  uint8_t divider=1;
  switch(BCSCTL1&0x30)
  {
  case 0x00:
    divider=1;
    break;
  case 0x10:
    divider=2;
    break;
  case 0x20:
    divider=4;
    break;
  case 0x30:
    divider=8;
    break;
  }
  return (privateXT1ClockFrequency/divider);
}

void BCM_selectXT1Mode(uint8_t BCM_XT1_MODE_x_FREQUENCY)
{
  uint8_t newBCSCTL1=BCSCTL1&(0xbf)+BCM_XT1_MODE_x_FREQUENCY;
  BCSCTL1=newBCSCTL1;
}

void BCM_initDCOCLK(BCM_initDCOTypedef BCM_initDCOParam)
{
  BCSCTL2=BCSCTL2&(0xfe)+BCM_initDCOParam.resistorSelect;
  BCSCTL1=BCSCTL1&(0xf8)+BCM_initDCOParam.internalResistorSelect;
  DCOCTL=BCM_initDCOParam.modulator+(BCM_initDCOParam.selectDCOFrequency<<5);
}

uint8_t BCM_clearOscFaultFlagsWithTimeout(uint8_t timeout)
{
  do
  {
    IFG1&=~OFIFG;
	timeout--;
  }
  while((IFG1&OFIFG)||(timeout>0));
  return (IFG1&OFIFG);
}

uint8_t BCM_getOscFaultFlagStatus(void)
{
  return (IFG1&OFIFG);
}

void BCM_enableOscFaultInterrupt(void)
{
  IE1|=OFIE;
}

void BCM_disableOscFaultInterrupt(void)
{
  IE1&=~OFIE;
}
