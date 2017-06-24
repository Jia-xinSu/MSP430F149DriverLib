/*
 *@file: msp430f149_adc12.h
 *@author:13电子-Jiaxin
 *@version:1.0
 *@date:2017年6月24日
 *@brif:msp430f149的ADC12模块
 */
#ifndef __MSP430F149_$MODE$_H
#define __MSP430F149_$MODE$_H

#ifdef __cplusplus
extern "C"
{
#endif

/*Marco****************************************************/
/*
 *@brief
 *@for functions
 *@{
 */
#define ADC_12_SAMPLEHOLDSOURCE_SC         ((uint16_t)0x0000)/*!<选择ADCSC时钟源*/
#define ADC_12_SAMPLEHOLDSOURCE_TA1        ((uint16_t)0x0040)/*!<选择TA1时钟源*/
#define ADC_12_SAMPLEHOLDSOURCE_TB0        ((uint16_t)0x0080)/*!<选择TB0时钟源*/
#define ADC_12_SAMPLEHOLDSOURCE_TB1        ((uint16_t)0x00c0)/*!<选择TB1时钟源*/
/*
 **@}
 */

/*
 *@brief
 *@for functions
 *@{
 */
#define ADC12_CLOCKSOURCE_ADC12OSC         ((uint16_t)0x0000)/*!<选择ADC12OSC*/
#define ADC12_CLOCKSOURCE_ACLK             ((uint16_t)0x0000)/*!<选择ADC12OSC*/
#define ADC12_CLOCKSOURCE_MCLK             ((uint16_t)0x0000)/*!<选择ADC12OSC*/
#define ADC12_CLOCKSOURCE_SMCLK            ((uint16_t)0x0000)/*!<选择ADC12OSC*/
/*
 **@}
 */


/*Struct***************************************************/
/*
 *@brief
 *@member
 *@for function:
 *{
 */
typedef struct
{
  uint16_t sampleHoldSignalSourceSelect;
  uint8_t clockSourceSelect;
  uint16_t clockSourceDivider;
}
/*
 *@}
 */

/*Enumeration**********************************************/

/*Function*************************************************/

#ifdef __cplusplus
}
#endif

#endif/*End __MSP430F149_ADC12_H*/
/******************CAFUC ELectic Disign*********End of File*/


