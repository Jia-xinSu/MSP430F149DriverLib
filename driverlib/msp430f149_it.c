
#include "msp430f149_it.h"
#include "driverlib.h"

uint16_t adcResult=0;

/**
 *@brif：处理NMU中断
 *@param：无
 *@retval：无
 */
#pragma vector=NMI_VECTOR
__interrupt
void NMI_ISR(void)
{

}


#pragma vector=ADC12_VECTOR
__interrupt
void ADC12_ISR(void)
{
  switch(_even_in_range(ADC12IV, 44))
  {
  case ADC12IV_ADC12IFG0:
  	adcResult=ADC12_getResults(0);
	ADC12_clearInterrupt( ADC12_IE_0);
	break;
  }
}


/*
 *@attention：  可使用的中断向量有
 *  \vct  PORT2_VECTOR
 *        USART1TX_VECTOR
 *        USART1RX_VECTOR
 *        PORT1_VECTOR
 *        TIMERA1_VECTOR
 *        TIMERA0_VECTOR
 *        ADC12_VECTOR
 *        USART0TX_VECTOR
 *        USART0RX_VECTOR
 *        WDT_VECTOR
 *        COMPARATORA_VECTOR
 *        TIMERB1_VECTOR
 *        TIMERB0_VECTOR
 */
/**
 *@brif：处理PPP中断
 *@param：无
 *@retval：无
 */
/*
 *#pragma vector=PPP_VECTOR
 *__interrupt
 *void PPP_ISR(void)
 *{
 * 
 *}
 */

