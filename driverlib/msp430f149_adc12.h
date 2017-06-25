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

/*
 *@brief：选择记忆体
 *@for functions
 *@{
 */
#define ADC12_MEMORY_0                           ((uint16_t)0x00)/*!<选择记忆体0*/
#define ADC12_MEMORY_1                           ((uint16_t)0x01)/*!<选择记忆体1*/
#define ADC12_MEMORY_2                           ((uint16_t)0x02)/*!<选择记忆体2*/
#define ADC12_MEMORY_3                           ((uint16_t)0x03)/*!<选择记忆体3*/
#define ADC12_MEMORY_4                           ((uint16_t)0x04)/*!<选择记忆体4*/
#define ADC12_MEMORY_5                           ((uint16_t)0x05)/*!<选择记忆体5*/
#define ADC12_MEMORY_6                           ((uint16_t)0x06)/*!<选择记忆体6*/
#define ADC12_MEMORY_7                           ((uint16_t)0x07)/*!<选择记忆体7*/
#define ADC12_MEMORY_8                           ((uint16_t)0x08)/*!<选择记忆体8*/
#define ADC12_MEMORY_9                           ((uint16_t)0x09)/*!<选择记忆体9*/
#define ADC12_MEMORY_10                          ((uint16_t)0x0a)/*!<选择记忆体10*/
#define ADC12_MEMORY_11                          ((uint16_t)0x0b)/*!<选择记忆体11*/
#define ADC12_MEMORY_12                          ((uint16_t)0x0c)/*!<选择记忆体12*/
#define ADC12_MEMORY_13                          ((uint16_t)0x0d)/*!<选择记忆体13*/
#define ADC12_MEMORY_14                          ((uint16_t)0x0e)/*!<选择记忆体14*/
#define ADC12_MEMORY_15                          ((uint16_t)0x0f)/*!<选择记忆体15*/
/*
 **@}
 */
/*
 *@brief 输入信号选择
 *@for functions
 *@{
 */
#define ADC12_INPUT_A0                           ((uint8_t)0x00)/*!<选择A0输入*/
#define ADC12_INPUT_A1                           ((uint8_t)0x01)/*!<选择A1输入*/
#define ADC12_INPUT_A2                           ((uint8_t)0x02)/*!<选择A2输入*/
#define ADC12_INPUT_A3                           ((uint8_t)0x03)/*!<选择A3输入*/
#define ADC12_INPUT_A4                           ((uint8_t)0x04)/*!<选择A4输入*/
#define ADC12_INPUT_A5                           ((uint8_t)0x05)/*!<选择A5输入*/
#define ADC12_INPUT_A6                           ((uint8_t)0x06)/*!<选择A6输入*/
#define ADC12_INPUT_A7                           ((uint8_t)0x07)/*!<选择A7输入*/
#define ADC12_INPUT_VEREFP                       ((uint8_t)0x08)/*!<选择VEREF+输入*/
#define ADC12_INPUT_VEREFN                       ((uint8_t)0x09)/*!<选择VEREF-输入*/
#define ADC12_INPUT_TIMPSENSOR                   ((uint8_t)0x0a)/*!<选择温度传感器输入*/
#define ADC12_INPUT_BATTERYMONITOR               ((uint8_t)0x0b)/*!<选择电池监控输入*/
/*
 **@}
 */

/*
 *@brief：负极参考
 *@for functions
 *@{
 */
#define ADC12_VREFNEG_AVSS                        ((uint8_t)0x00)/*!<选择负极参考位AVSS*/
#define ADC12_VREFNEG_VREFN                       ((uint8_t)0x40)/*!<选择负极参考位AVSS*/
/*
 **@}
 */

/*
 *@brief 正极参考
 *@for functions
 *@{
 */
#define ADC12_VREFPOS_AVCC                         ((uint8_t)0x00)/*!<选择正极参考AVCC*/
#define ADC12_VREFPOS_VREFP                        ((uint8_t)0x10)/*!<选择正极参考VRef+*/
#define ADC12_VREFPOS_VEREFP                       ((uint8_t)0x20)/*!<选择正极参考VeRef+*/
/*
 **@}
 */

/*
 *@brief:是否为序列结束
 *@for functions
 *@{
 */
#define ADC12_NOTENDOFSEQUENCE                     ((uint8_t)0x00)/*!<非序列结束*/
#define ADC12_ENDOFSEQUENCE                        ((uint8_t)0x80)/*!<序列结束*/
/*
 **@}
 */

/*
 *@brief
 *@for functions
 *@{
 */
#define ADC12_IE_0                                 ((uint16_t)0x0001)/*!<ADC12允许中断0*/
#define ADC12_IE_1                                 ((uint16_t)0x0002)/*!<ADC12允许中断1*/
#define ADC12_IE_2                                 ((uint16_t)0x0004)/*!<ADC12允许中断2*/
#define ADC12_IE_3                                 ((uint16_t)0x0008)/*!<ADC12允许中断3*/
#define ADC12_IE_4                                 ((uint16_t)0x0010)/*!<ADC12允许中断4*/
#define ADC12_IE_5                                 ((uint16_t)0x0020)/*!<ADC12允许中断5*/
#define ADC12_IE_6                                 ((uint16_t)0x0040)/*!<ADC12允许中断6*/
#define ADC12_IE_7                                 ((uint16_t)0x0080)/*!<ADC12允许中断7*/
#define ADC12_IE_8                                 ((uint16_t)0x0100)/*!<ADC12允许中断8*/
#define ADC12_IE_9                                 ((uint16_t)0x0280)/*!<ADC12允许中断9*/
#define ADC12_IE_10                                ((uint16_t)0x0400)/*!<ADC12允许中断10*/
#define ADC12_IE_11                                ((uint16_t)0x0800)/*!<ADC12允许中断11*/
#define ADC12_IE_12                                ((uint16_t)0x1000)/*!<ADC12允许中断12*/
#define ADC12_IE_13                                ((uint16_t)0x2000)/*!<ADC12允许中断13*/
#define ADC12_IE_14                                ((uint16_t)0x4000)/*!<ADC12允许中断14*/
#define ADC12_IE_15                                ((uint16_t)0x8000)/*!<ADC12允许中断15*/
#define ADC12_OVERFLOW_IE                          ADC12OVIE/*!<ADC12溢出中断*/
#define ADC12_CONVERSION_TIMER_OVERFLOW_IE         ADC12TOVIE/*!<ADC12时间溢出中断*/
/*
 **@}
 */

/*
 *@brief：定义ADC12的中断标志位
 *@for functions
 *@{
 */
#define ADC12_IFG_0                                 ((uint16_t)0x0001)/*!<ADC12中断标志0*/
#define ADC12_IFG_1                                 ((uint16_t)0x0002)/*!<ADC12中断标志1*/
#define ADC12_IFG_2                                 ((uint16_t)0x0004)/*!<ADC12中断标志2*/
#define ADC12_IFG_3                                 ((uint16_t)0x0008)/*!<ADC12中断标志3*/
#define ADC12_IFG_4                                 ((uint16_t)0x0010)/*!<ADC12中断标志4*/
#define ADC12_IFG_5                                 ((uint16_t)0x0020)/*!<ADC12中断标志5*/
#define ADC12_IFG_6                                 ((uint16_t)0x0040)/*!<ADC12中断标志6*/
#define ADC12_IFG_7                                 ((uint16_t)0x0080)/*!<ADC12中断标志7*/
#define ADC12_IFG_8                                 ((uint16_t)0x0100)/*!<ADC12中断标志8*/
#define ADC12_IFG_9                                 ((uint16_t)0x0280)/*!<ADC12中断标志9*/
#define ADC12_IFG_10                                ((uint16_t)0x0400)/*!<ADC12中断标志10*/
#define ADC12_IFG_11                                ((uint16_t)0x0800)/*!<ADC12中断标志11*/
#define ADC12_IFG_12                                ((uint16_t)0x1000)/*!<ADC12中断标志12*/
#define ADC12_IFG_13                                ((uint16_t)0x2000)/*!<ADC12中断标志13*/
#define ADC12_IFG_14                                ((uint16_t)0x4000)/*!<ADC12中断标志14*/
#define ADC12_IFG_15                                ((uint16_t)0x8000)/*!<ADC12中断标志15*/

/*
 **@}
 */

/*
 *@brief:ADC12 转换序列模式
 *@for functions
 *@{
 */
#define ADC12_SINGLECHANNEL                         ((uint16_t)0x0000)/*!<选择单通道*/
#define ADC12_SEQOFCHANNELS                         ((uint16_t)0x0002)/*!<选择序列*/
#define ADC12_REPEATED_SINGLECHANNEL                ((uint16_t)0x0004)/*!<选择重复单通道*/
#define ADC12_REPEATED_SEQOFCHANNELS                ((uint16_t)0x0006)/*!<选择重复序列*/
/*
 **@}
 */

/*
 *@brief
 *@for functions
 *@{
 */
#define ADC12_NONINVERTEDSIGNAL                     ((uint16_t)0x0000)/*!<信号无翻转*/
#define ADC12_INVERTEDSIGNAL                        ((uint16_t)0x0100)/*!<信号翻转*/

/*
 **@}
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
 *@member:memoryBufferControlIndex MEM索引
 *  /arg  ADC12_MEMORY_0
 *        ADC12_MEMORY_1
 *        ADC12_MEMORY_2
 *        ADC12_MEMORY_3
 *        ADC12_MEMORY_4
 *        ADC12_MEMORY_5
 *        ADC12_MEMORY_6
 *        ADC12_MEMORY_7
 *        ADC12_MEMORY_8
 *        ADC12_MEMORY_9
 *        ADC12_MEMORY_10
 *        ADC12_MEMORY_11
 *        ADC12_MEMORY_12
 *        ADC12_MEMORY_13
 *        ADC12_MEMORY_14
 *        ADC12_MEMORY_15
 *@member:inputSourceSelect 选择信号输入
 *  /arg  ADC12_INPUT_A0
 *        ADC12_INPUT_A1
 *        ADC12_INPUT_A2
 *        ADC12_INPUT_A3
 *        ADC12_INPUT_A4
 *        ADC12_INPUT_A5
 *        ADC12_INPUT_A6
 *        ADC12_INPUT_A7
 *        ADC12_INPUT_VEREFP
 *        ADC12_INPUT_VEREFN
 *        ADC12_INPUT_TIMPSENSOR
 *        ADC12_INPUT_BATTERYMONITOR
 *@member positiveRefVoltageSourceSelect选择参考电压正极
 *  \arg  ADC12_VREFPOS_AVCC
 *        ADC12_VREFPOS_VREFP
 *        ADC12_VREFPOS_VEREFP
 *@member negativeRefVoltageSourceSelect选择参考电压负极
 *  \arg  ADC12_VREFNEG_AVSS
 *        ADC12_VREFNEG_VREFN
 *@member endOfSequence是否是序列结束
 *  \arg  ADC12_NOTENDOFSEQUENCE
 *        ADC12_ENDOFSEQUENCE
 *@for function
 *@{
 */
typedef struct
{
  uint8_t memoryBufferControlIndex;
  uint8_t inputSourceSelect;
  uint8_t positiveRefVoltageSourceSelect;
  uint8_t negativeRefVoltageSourceSelect;
  uint8_t endOfSequence;
}ADC12_configureMemoryTypeDef;
/*
 *@}
 */



/*Enumeration**********************************************/

/*
 *@brief:是否提前结束
 *@for function:
 *@{
 */
typedef enum
{
  ADC12_COMPLETECONVERSION,
  ADC12_PREEMPTCONVERSION
}preemptTypedef;
/*
 *@}
 */


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


/**
  *@brief：禁用ADC12采样计时器
  *@param:None
  *@retval:None
  */
extern void ADC12_disableSamplingTimer(void);


/**
  *@brief：ADC12记忆体配置
  *@param:ADC12_configureMemoryParam ADC12配置变量
  *  \arg  ADC12_configureMemoryTypeDef类型
  *@retval:None
  */
extern void ADC12_configureMemory(ADC12_configureMemoryTypeDef ADC12_configureMemoryParam);


/**
  *@brief：ADC12允许中断
  *@param:ADC12_interruptEnable ADC12的中断
  *  \arg  ADC12_IE_0
  *        ADC12_IE_1
  *        ADC12_IE_2
  *        ADC12_IE_3
  *        ADC12_IE_4
  *        ADC12_IE_5
  *        ADC12_IE_6
  *        ADC12_IE_7
  *        ADC12_IE_8
  *        ADC12_IE_9
  *        ADC12_IE_10
  *        ADC12_IE_11
  *        ADC12_IE_12
  *        ADC12_IE_13
  *        ADC12_IE_14
  *        ADC12_IE_15
  *@param: ADC12_overflowInterruptEnable ADC12的溢出与时钟溢出中断
  *  \arg  ADC12_OVERFLOW_IE
  *        ADC12_CONVERSION_TIMER_OVERFLOW_IE
  *@retval:
  */
extern void ADC12_enableInterrupt(uint16_t ADC12_interruptEnable,uint16_t ADC12_overflowInterruptEnable);

/**
  *@brief：ADC12禁止中断
  *@param:ADC12_interruptEnable ADC12的中断
  *  \arg  ADC12_IE_0
  *        ADC12_IE_1
  *        ADC12_IE_2
  *        ADC12_IE_3
  *        ADC12_IE_4
  *        ADC12_IE_5
  *        ADC12_IE_6
  *        ADC12_IE_7
  *        ADC12_IE_8
  *        ADC12_IE_9
  *        ADC12_IE_10
  *        ADC12_IE_11
  *        ADC12_IE_12
  *        ADC12_IE_13
  *        ADC12_IE_14
  *        ADC12_IE_15
  *@param: ADC12_overflowInterruptEnable ADC12的溢出与时钟溢出中断
  *  \arg  ADC12_OVERFLOW_IE
  *        ADC12_CONVERSION_TIMER_OVERFLOW_IE
  *@retval:
  */
extern void ADC12_disableInterrupt(uint16_t ADC12_interruptEnable,uint16_t ADC12_overflowInterruptEnable);

/**
  *@brief:清除ADC12中断标志位
  *@param:ADC12_interruptFlag ADC12的中断标志位
  *  \arg  ADC12_IFG_0
  *        ADC12_IFG_1
  *        ADC12_IFG_2
  *        ADC12_IFG_3
  *        ADC12_IFG_4
  *        ADC12_IFG_5       
  *        ADC12_IFG_6
  *        ADC12_IFG_7
  *        ADC12_IFG_8
  *        ADC12_IFG_9
  *        ADC12_IFG_10
  *        ADC12_IFG_11
  *        ADC12_IFG_12
  *        ADC12_IFG_13
  *        ADC12_IFG_14
  *        ADC12_IFG_15
  *@retval:None
  */
extern void ADC12_clearInterrupt(uint16_t ADC12_interruptFlag);

/**
  *@brief:获取ADC12中断标志位状态
  *@param:ADC12_interruptFlag ADC12的中断标志位
  *  \arg  ADC12_IFG_0
  *        ADC12_IFG_1
  *        ADC12_IFG_2
  *        ADC12_IFG_3
  *        ADC12_IFG_4
  *        ADC12_IFG_5       
  *        ADC12_IFG_6
  *        ADC12_IFG_7
  *        ADC12_IFG_8
  *        ADC12_IFG_9
  *        ADC12_IFG_10
  *        ADC12_IFG_11
  *        ADC12_IFG_12
  *        ADC12_IFG_13
  *        ADC12_IFG_14
  *        ADC12_IFG_15
  *@retval:ADC12中断标志位状态
  */
extern uint16_t ADC12_getInerruptStatus(uint16_t ADC12_interruptFlag);

/**
  *@brief：ADC12开始模数转换
  *@param:startMemoryBufferIndex 转换的起始位
  *  /arg  ADC12_MEMORY_0
  * 	   ADC12_MEMORY_1
  * 	   ADC12_MEMORY_2
  * 	   ADC12_MEMORY_3
  * 	   ADC12_MEMORY_4
  * 	   ADC12_MEMORY_5
  * 	   ADC12_MEMORY_6
  * 	   ADC12_MEMORY_7
  * 	   ADC12_MEMORY_8
  * 	   ADC12_MEMORY_9
  * 	   ADC12_MEMORY_10
  * 	   ADC12_MEMORY_11
  * 	   ADC12_MEMORY_12
  * 	   ADC12_MEMORY_13
  * 	   ADC12_MEMORY_14
  * 	   ADC12_MEMORY_15
  *@param：conversionSequenceModeSelect转换的序列模式
  *  \arg  ADC12_SINGLECHANNEL
  *        ADC12_SEQOFCHANNELS
  *        ADC12_REPEATED_SINGLECHANNEL
  *        ADC12_REPEATED_SEQOFCHANNELS
  *@retval:None
  */
extern void ADC12_startConversion(uint16_t startMemoryBufferIndex,uint16_t conversionSequenceModeSelect);

/**
  *@brief：停止转换
  *@param:ADC12_xCONVERSION立即停止或者等待停止
  *@retval:None
  */
extern void ADC12_disableConversion(preemptTypedef ADC12_xCONVERSION);

/**
  *@brief：判断ADC12是否忙
  *@param:None
  *@retval:ADC12是否正忙
  */
extern uint16_t ADC12_isBusy(void );

/**
  *@brief：获取ADC12结果
  *@param:选择记忆体
  *@retval:ADC12计算结果
  */
extern uint16_t ADC12_getResults(uint16_t memoryBufferControlIndex);

/**
  *@brief：选择保持时钟倒置
  *@param:invertedSignal是否倒置
  *  /arg  ADC12_NONINVERTEDSIGNAL
  *        ADC12_INVERTEDSIGNAL
  *@retval:None
  */
extern void ADC12_setSampleHoldSignalInversion(uint16_t invertedSignal);

#ifdef __cplusplus
}
#endif

#endif/*End __MSP430F149_ADC12_H*/
/******************CAFUC ELectic Disign*********End of File*/


