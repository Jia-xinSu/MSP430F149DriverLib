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

