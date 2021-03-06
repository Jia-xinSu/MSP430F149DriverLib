#include "msp430f149_gpio.h"

static const uint16_t GPIO_getBaseAddress[]={
  0x0000,
  0x0020,
  0x0028,
  0x0018,
  0x001c,
  0x0030,
  0x0034
};

void GPIO_setAsOutputPin(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x)
{
  if((GPIO_Port_x>6)||(GPIO_Port_x==0))
  {
    return;
  }
  uint16_t GPIOAddress=GPIO_getBaseAddress[GPIO_Port_x];
  HWREG8(GPIOAddress+GPIO_PA_OFSDIR)|=GPIO_Pin_x;
}

void GPIO_setAsInputPin(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x)
{
  if((GPIO_Port_x>6)||(GPIO_Port_x==0))
  {
    return;
  }
  uint16_t GPIOAddress=GPIO_getBaseAddress[GPIO_Port_x];
  HWREG8(GPIOAddress+GPIO_PA_OFSDIR)&=~(GPIO_Pin_x);
}

void GPIO_clearInierrupt(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x)
{
  if(GPIO_HAVE_INTRRUPT(GPIO_Port_x))
  {
    uint16_t GPIOAddress=GPIO_getBaseAddress[GPIO_Port_x];
    HWREG8(GPIOAddress+GPIO_PA_OFSIFG)&=~(GPIO_Pin_x);
  }
  else
  {
    return;
  }
}

void GPIO_enableInterrupt(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x)
{
  if(GPIO_HAVE_INTRRUPT(GPIO_Port_x))
  {
    uint16_t GPIOAddress=GPIO_getBaseAddress[GPIO_Port_x];
	HWREG8(GPIOAddress+GPIO_PA_OFSIE)|=GPIO_Pin_x;
  }
  else
  {
    return;
  }
}

void GPIO_disableInterrupt(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x)
{
  if(GPIO_HAVE_INTRRUPT(GPIO_Port_x))
  {
    uint16_t GPIOAddress=GPIO_getBaseAddress[GPIO_Port_x];
	HWREG8(GPIOAddress+GPIO_PA_OFSIE)&=~(GPIO_Pin_x);
  }
  else
  {
    return;
  }
}

uint8_t GPIO_getInputPinValue(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x)
{
  uint16_t GPIOAddress=GPIO_getBaseAddress[GPIO_Port_x];
  if(HWREG8(GPIOAddress)&GPIO_Pin_x)
  {
    return (GPIO_PIN_INPUT_HIGH);
  }
  else
  {
    return(GPIO_PIN_INPUT_LOW);
  }
}

void GPIO_setOutputHighOnPin(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x)
{
  if((GPIO_Port_x==0)||(GPIO_Port_x>6))
  {
    return;
  }
  uint16_t GPIOAddress=GPIO_getBaseAddress[GPIO_Port_x];
  HWREG8(GPIOAddress+GPIO_PA_OFSOUT)|=GPIO_Pin_x;
}

void GPIO_setOutputLowOnPin(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x)
{
  if((GPIO_Port_x==0)||(GPIO_Port_x>6))
  {
    return;
  }
  uint16_t GPIOAddress=GPIO_getBaseAddress[GPIO_Port_x];
  HWREG8(GPIOAddress+GPIO_PA_OFSOUT)&=~(GPIO_Pin_x);
}

void GPIO_writePort(uint8_t GPIO_Port_x,uint8_t value)
{
  if((GPIO_Port_x==0)||(GPIO_Port_x>6))
  {
    return;
  }
  uint16_t GPIOAddress=GPIO_getBaseAddress[GPIO_Port_x];
  HWREG8(GPIOAddress+GPIO_PA_OFSOUT)=value;
}

uint8_t GPIO_getPortInputValue(uint8_t GPIO_Port_x)
{
  uint16_t GPIOAddress=GPIO_getBaseAddress[GPIO_Port_x];
  return(HWREG8(GPIO_PA_OFSIN+GPIOAddress));
}

void GPIO_toggleOutputOnPin(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x)
{
  if((GPIO_Port_x==0)||(GPIO_Port_x>6))
  {
    return;
  }
  uint16_t GPIOAddress=GPIO_getBaseAddress[GPIO_Port_x];
  HWREG8(GPIOAddress+GPIO_PA_OFSOUT)^=GPIO_Pin_x;
}

void GPIO_setAsPeripheralModuleFunctionOutputPin(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x)
{
  if((GPIO_Port_x>6)||(GPIO_Port_x==0))
  {
    return;
  }
  uint16_t GPIOAddress=GPIO_getBaseAddress[GPIO_Port_x];
  HWREG8(GPIOAddress+GPIO_PA_OFSDIR)|=GPIO_Pin_x;
  if(GPIO_HAVE_INTRRUPT(GPIO_Port_x))
  {
    HWREG8(GPIOAddress+GPIO_PA_OFSSEL)|=GPIO_Pin_x;
  }
  if(GPIO_HAVE_NO_INTRRUPT(GPIO_Port_x))
  {
    HWREG8(GPIOAddress+GPIO_PB_OFSSEL)|=GPIO_Pin_x;
  }
}

void GPIO_setAsPeripheralModuleFunctionInputPin(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x)
{
  if((GPIO_Port_x>6)||(GPIO_Port_x==0))
  {
    return;
  }
  uint16_t GPIOAddress=GPIO_getBaseAddress[GPIO_Port_x];
  HWREG8(GPIOAddress+GPIO_PA_OFSDIR)&=~(GPIO_Pin_x);
  if(GPIO_HAVE_INTRRUPT(GPIO_Port_x))
  {
    HWREG8(GPIOAddress+GPIO_PA_OFSSEL)|=GPIO_Pin_x;
  }
  if(GPIO_HAVE_NO_INTRRUPT(GPIO_Port_x))
  {
    HWREG8(GPIOAddress+GPIO_PB_OFSSEL)|=GPIO_Pin_x;
  }
}

void GPIO_selectInterruptEdge(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x,GPIO_interruptEdge GPIO_A_TO_B_TRANSITION)
{
  if(GPIO_HAVE_INTRRUPT(GPIO_Port_x))
  {
    uint16_t GPIOAddress=GPIO_getBaseAddress[GPIO_Port_x];
	if(GPIO_A_TO_B_TRANSITION==GPIO_HIGH_TO_LOW_TRANSITION)
	{
	  HWREG8(GPIOAddress+GPIO_PA_OFSIES)|=(GPIO_Pin_x);
	}
	else if(GPIO_A_TO_B_TRANSITION==GPIO_LOW_TO_HIGH_TRANSITION)
	{
	  HWREG8(GPIOAddress+GPIO_PA_OFSIES)&=~(GPIO_Pin_x);
	}
  }
  else
  {
    return;
  }
}

uint8_t GPIO_getInterruptStatus(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x)
{
  uint16_t GPIOAddress=GPIO_getBaseAddress[GPIO_Port_x];
  return (HWREG8(GPIOAddress+GPIO_PA_OFSIFG)&GPIO_Pin_x);
}
