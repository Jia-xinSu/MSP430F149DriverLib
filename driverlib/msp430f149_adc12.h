/*
 *@file: msp430f149_adc12.h
 *@author:13电子-Jiaxin
 *@version:1.0
 *@date:2017年6月24日
 *@brif:msp430f149的ADC12模块
 */
#ifndef __MSP430F149_ADC12_H
#define __MSP430F149_ADC12_H

#ifdef __cplusplus
extern "C"
{
#endif
#include "hw_memmap.h"
/*Marco****************************************************/
/*
 *@brief 选择采用保持时钟源
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
 *@brief 选择ADC时钟源
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

/*
 *@brief:选择ADC时钟源分频
 *@for function:
 *@{
 */
#define ADC12_CLOCKDIVIDER_1               ((uint16_t)0x0000)/*!<选择1分频*/
#define ADC12_CLOCKDIVIDER_2               ((uint16_t)0x0020)/*!<选择2分频*/
#define ADC12_CLOCKDIVIDER_3               ((uint16_t)0x0040)/*!<选择3分频*/
#define ADC12_CLOCKDIVIDER_4               ((uint16_t)0x0060)/*!<选择4分频*/
#define ADC12_CLOCKDIVIDER_5               ((uint16_t)0x0080)/*!<选择4分频*/
#define ADC12_CLOCKDIVIDER_6               ((uint16_t)0x00a0)/*!<选择5分频*/
#define ADC12_CLOCKDIVIDER_7               ((uint16_t)0x00c0)/*!<选择6分频*/
#define ADC12_CLOCKDIVIDER_8               ((uint16_t)0x00e0)/*!<选择7分频*/
/*
 *@}
 */

/*
 *@brief:定义采样保持周期
 *@for function:
 *@{
 */
#define ADC12_A_CYCLEHOLD_4_CYCLES         ((uint16_t)0x0000)/*!<采样保持4个周期*/
#define ADC12_A_CYCLEHOLD_8_CYCLES         ((uint16_t)0x0100)/*!<采样保持8个周期*/
#define ADC12_A_CYCLEHOLD_16_CYCLES        ((uint16_t)0x0200)/*!<采样保持16个周期*/
#define ADC12_A_CYCLEHOLD_32_CYCLES        ((uint16_t)0x0300)/*!<采样保持32个周期*/
#define ADC12_A_CYCLEHOLD_64_CYCLES        ((uint16_t)0x0400)/*!<采样保持64个周期*/
#define ADC12_A_CYCLEHOLD_96_CYCLES        ((uint16_t)0x0500)/*!<采样保持96个周期*/
#define ADC12_A_CYCLEHOLD_128_CYCLES       ((uint16_t)0x0600)/*!<采样保持128个周期*/
#define ADC12_A_CYCLEHOLD_192_CYCLES       ((uint16_t)0x0700)/*!<采样保持192个周期*/
#define ADC12_A_CYCLEHOLD_256_CYCLES       ((uint16_t)0x0800)/*!<采样保持256个周期*/
#define ADC12_A_CYCLEHOLD_384_CYCLES       ((uint16_t)0x0900)/*!<采样保持384个周期*/
#define ADC12_A_CYCLEHOLD_512_CYCLES       ((uint16_t)0x0a00)/*!<采样保持512个周期*/
#define ADC12_A_CYCLEHOLD_768_CYCLES       ((uint16_t)0x0b00)/*!<采样保持768个周期*/
#define ADC12_A_CYCLEHOLD_1024_CYCLES      ((uint16_t)0x0f00)/*!<采样保持1024个周期*/

/*
 *@}
 */

/*
 *@brief:是否允许一个触发信号触发多个转换
 *@for function:
 *@{
 */
#define ADC12_MULTIPLESAMPLESDISABLE             ((uint16_t)0x0000)/*!<禁用多采样转换*/
#define ADC12_MULTIPLESAMPLESENABLE              ((uint16_t)0x0080)/*!<允许多采样转换*/
/*
 *@}
 */

/*Struct***************************************************/
/*
 *@brief 初始化ADC结构体
 *@member：sampleHoldSignalSourceSelect ADC12采样保持时钟选择
 *  \arg  ADC_12_SAMPLEHOLDSOURCE_SC
 *        ADC_12_SAMPLEHOLDSOURCE_TA1
 *        ADC_12_SAMPLEHOLDSOURCE_TB0
 *        ADC_12_SAMPLEHOLDSOURCE_TB1
 *@member:clockSourceSelect时钟源选择
 *  \arg  ADC12_CLOCKSOURCE_ADC12OSC
 *        ADC12_CLOCKSOURCE_ACLK
 *        ADC12_CLOCKSOURCE_SMCLK
 *        ADC12_CLOCKSOURCE_MCLK
 *@member clockSourceDivider  时钟分频选择
 *  \arg  ADC12_CLOCKDIVIDER_1
 *        ADC12_CLOCKDIVIDER_2
 *        ADC12_CLOCKDIVIDER_3
 *        ADC12_CLOCKDIVIDER_4
 *        ADC12_CLOCKDIVIDER_5
 *        ADC12_CLOCKDIVIDER_6
 *        ADC12_CLOCKDIVIDER_7
 *        ADC12_CLOCKDIVIDER_8
 *@for function: ADC12_init
 *{
 */
typedef struct
{
  uint16_t sampleHoldSignalSourceSelect;
  uint8_t clockSourceSelect;
  uint16_t clockSourceDivider;
}ADC12_initTypedef;
/*
 *@}
 */

/*
 *@brief:ADC12 MEM配置结构体
 *@member:
 *@member:
 *@for function
 *@{
 */
tpyedef struct
{
  uint16_t memoryBufferControlIndex;
}ADC12_configureMemoryTypeDef;
/*
 *@}
 */



/*Enumeration**********************************************/

/*Function*************************************************/

/*
 *@brief:ADC12初始化
 *@param:ADC12_initParam ADC12初始化结构体
 *@retval:None
 */
extern void ADC12_init(ADC12_initTypedef ADC12_initParam);

/*
 *@brief:是能ADC12
 *@param:None
 *@retval:None
 */
extern void ADC12_enable(void);

/*
 *@brief: 禁用ADC12
 *@param:None
 *@retval:None
 */
extern void ADC12_disable(void);

/*
 *@brief:设置ADC12采样计时器
 *@param:clockCycleHoldCountLowMem 0-7记忆体的采样计数
 *  \arg  ADC12_A_CYCLEHOLD_4_CYCLES
 *        ADC12_A_CYCLEHOLD_8_CYCLES
 *        ADC12_A_CYCLEHOLD_16_CYCLES
 *        ADC12_A_CYCLEHOLD_32_CYCLES
 *        ADC12_A_CYCLEHOLD_64_CYCLES
 *        ADC12_A_CYCLEHOLD_96_CYCLES
 *        ADC12_A_CYCLEHOLD_128_CYCLES
 *        ADC12_A_CYCLEHOLD_192_CYCLES
 *        ADC12_A_CYCLEHOLD_256_CYCLES
 *        ADC12_A_CYCLEHOLD_384_CYCLES
 *        ADC12_A_CYCLEHOLD_512_CYCLES
 *        ADC12_A_CYCLEHOLD_768_CYCLES
 *        ADC12_A_CYCLEHOLD_1024_CYCLES
 *@param:clockCycleHoldCountHighMem 8-15记忆体的采样计数
 *  \arg  ADC12_A_CYCLEHOLD_4_CYCLES
 *        ADC12_A_CYCLEHOLD_8_CYCLES
 *        ADC12_A_CYCLEHOLD_16_CYCLES
 *        ADC12_A_CYCLEHOLD_32_CYCLES
 *        ADC12_A_CYCLEHOLD_64_CYCLES
 *        ADC12_A_CYCLEHOLD_96_CYCLES
 *        ADC12_A_CYCLEHOLD_128_CYCLES
 *        ADC12_A_CYCLEHOLD_192_CYCLES
 *        ADC12_A_CYCLEHOLD_256_CYCLES
 *        ADC12_A_CYCLEHOLD_384_CYCLES
 *        ADC12_A_CYCLEHOLD_512_CYCLES
 *        ADC12_A_CYCLEHOLD_768_CYCLES
 *        ADC12_A_CYCLEHOLD_1024_CYCLES
 *@param:multipleSamplesEnabled 是否允许多采样，一次触发，多个转换
 *  \arg  ADC12_MULTIPLESAMPLESDISABLE
 *        ADC12_MULTIPLESAMPLESENABLE
 *@retval:None
 */
extern void ADC12_setupSamplingTimer(uint16_t clockCycleHoldCountLowMem, \
                               uint16_t clockCycleHoldCountHighMem, \
                               uint16_t multipleSamplesEnabled);



#ifdef __cplusplus
}
#endif

#endif/*End __MSP430F149_ADC12_H*/
/******************CAFUC ELectic Disign*********End of File*/


