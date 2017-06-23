/*
 *@file: msp430f149_gpio.h
 *@author:13电子-Jiaxin
 *@version:1.0
 *@date:2017年6月22日
 *@brif:msp430f149的Basic Clock Module模块
 */
#ifndef __MSP430F149_BCM_H
#define __MSP430F149_BCM_H

#ifdef __cplusplus
extern "C"
{
#endif
/*Includes----------------------------------------------------------------*/

#include "hw_memmap.h"
/*Macro-------------------------------------------------------------------*/

/*
 *@brif: 定义MCLK的时钟源
 *@for functions: BCM_initMCLKSignal
 *@{
 */
#define BCM_MCLK_SOURCE_DCOCLK              ((uint8_t)0x00)/*!<选择DCOCLK作为MCLK的时钟源*/
#define BCM_MCLK_SOURCE_XT2CLK              ((uint8_t)0x80)/*!<选择XT2CLK作为MCLK的时钟源*/
#define BCM_MCLK_SOURCE_LFXT1CLK            ((uint8_t)0xc0)/*!<选择LFXT1CLK作为MCLK的时钟源*/
/*
 *@}
 */
 
/*
 *@brif: 定义SMCLK的时钟源
 *@for functions: BCM_initSMCLKSignal
 *@{
 */
#define BCM_SMCLK_SOURCE_DCOCLK              ((uint8_t)0x00)/*!<选择DCOCLK作为SMCLK的时钟源*/
#define BCM_SMCLK_SOURCE_XT2CLK              ((uint8_t)0x08)/*!<选择XT2CLK作为SMCLK的时钟源*/
/*
 *@}
 */
 
/*
 *@brif: 定义时钟信号分频
 *@for functions: BCM_initMCLKSignal
 *                BCM_initSMCLKSignal
 *                BCM_iniACLKSignal
 *@{
 */
#define BCM_DIVIDER_1                       ((uint8_t)0x00)/*!<选择1分频*/
#define BCM_DIVIDER_2                       ((uint8_t)0x01)/*!<选择2分频*/
#define BCM_DIVIDER_4                       ((uint8_t)0x02)/*!<选择3分频*/
#define BCM_DIVIDER_8                       ((uint8_t)0x03)/*!<选择4分频*/
/*
 *@}
 */

/*
 *@brif: XT1的工作模式
 *@for functions:  BCM_selectXT1Mode
 *@{
 */
#define BCM_XT1_MODE_HIGH_FREQUENCY         ((uint8_t)0x40)/*!<选择高频模式*/
#define BCM_XT1_MODE_LOW_FREQUENCY          ((uint8_t)0x00)/*!<选择低频模式*/
/*
 *@}
 */
 
/*
 *@brif: 定义分频控制位的位偏置
 *@{
 */
#define BCM_OFSB_DIVM                       ((uint8_t)0x04)/*!<DIVM的位偏置*/
#define BCM_OFSB_DIVS                       ((uint8_t)0x01)/*!<DIVS的位偏置*/
#define BCM_OFSB_DIVA                       ((uint8_t)0x04)/*!<DIVA的位偏置*/
/*
 *@}
 */

/*
 *@brif: 定义分频控制位的位偏置
 *@{
 */
#define BCM_RESISTOR_INTERNAL               ((uint8_t)0x00)/*!<选择内部电阻*/
#define BCM_RESISTOR_EXTERNAL               ((uint8_t)0x01)/*!<选择外部电阻*/
/*
 *@}
 */
 
/*Struct------------------------------------------------------------------*/

/*
 *@brif: DCO初始化结构体
 *@member resistorSelect震荡电路的电阻选取，合法参数如下
 *  \arg  BCM_RESISTOR_INTERNAL
 *        BCM_RESISTOR_EXTERNAL
 *@member selectDCOFrequency选择DCO频率
 *  \arg  0-7整数
 *@member modulator调制器参数
 *  \arg  0-31整数
 *@member internalResistorSelect内部电阻选择
 *  \arg  0-7整数
 *@for function：BCM_initDCOCLK 
 *@{
 */
typedef struct
{ 
  uint8_t resistorSelect;
  uint8_t selectDCOFrequency;
  uint8_t modulator;
  uint8_t internalResistorSelect;
}BCM_initDCOTypedef;
/*
 *@}
 */

/*Functions---------------------------------------------------------------*/

/**
 *@brif:设置单片机外部时钟频率
 *@param： XT1CLK_frequency XT1时钟的时钟频率
 *@param： XT2CLK_frequency XT2时钟的时钟频率
 *@retval：None
 */
extern void BCM_setExternalClockSource(uint32_t XT1CLK_frequency,uint32_t XT2CLK_frequency);

/**
 *@brif:设置MCLK的信号
 *@param： BCM_MCLK_SOURCE_x MCLK的信号源,可选以下参数
 *  \arg  BCM_MCLK_SOURCE_DCOCLK
 *        BCM_MCLK_SOURCE_XT2CLK
 *        BCM_MCLK_SOURCE_LFXT1CLK
 *@param： BCM_DIVIDER_x MCLK的信号分频,可选以下参数
 *  \arg  BCM_DIVIDER_1
 *        BCM_DIVIDER_2
 *        BCM_DIVIDER_4
 *        BCM_DIVIDER_8
 *@retval：None
 */
 
extern void BCM_initMCLKSignal(uint8_t BCM_MCLK_SOURCE_x,uint8_t BCM_DIVIDER_x);

/**
 *@brif:设置MSCLK的信号
 *@param： BCM_SMCLK_SOURCE_x SMCLK的信号源,可选以下参数
 *  \arg  BCM_SMCLK_SOURCE_DCOCLK
 *        BCM_SMCLK_SOURCE_XT2CLK
 *@param： BCM_DIVIDER_x MCLK的信号分频,可选以下参数
 *  \arg  BCM_DIVIDER_1
 *        BCM_DIVIDER_2
 *        BCM_DIVIDER_4
 *        BCM_DIVIDER_8
 *@retval：None
 */
extern void BCM_initSMCLKSignal(uint8_t BCM_SMCLK_SOURCE_x,uint8_t BCM_DIVIDER_x);

/**
 *@brif:设置ACLK的信号
 *@param： BCM_DIVIDER_x ACLK的信号分频,可选以下参数
 *  \arg  BCM_DIVIDER_1
 *        BCM_DIVIDER_2
 *        BCM_DIVIDER_4
 *        BCM_DIVIDER_8
 *@retval: None
 */
void BCM_iniACLKSignal(uint8_t BCM_DIVIDER_x);

/**
 *@brif: 启动XT2振荡器,直到振荡器错误位被清零
 *@param: None
 *@retval: None
 */
extern void BCM_turnOnXT2(void);

/**
 *@brif: 启动XT2振荡器,直到振荡器错误位被清零或超时
 *@param: timeout 超时时间
 *@retval: None
 */
extern void BCM_turnOnXT2WithTimeout(uint32_t timeout);

/**
 *@brif: 关闭XT2振荡器
 *@param: None
 *@retval: None
 */
extern void BCM_turnOffXT2(void);

/**
 *@brif: 获取MCLK的频率
 *       由于对于MSP430F149内部震荡电路性能不稳定
 *       故如果使用DCOCLK返回0
 *@param: None
 *@retval: MCLK的频率
 */
extern uint32_t BCM_getMCLK(void);

/**
 *@brif: 获取SMCLK的频率
 *       由于对于MSP430F149内部震荡电路性能不稳定
 *       故如果使用DCOCLK返回0
 *@param: None
 *@retval: SMCLK的频率
 */
extern uint32_t BCM_getSMCLK(void);

/**
 *@brif: 获取ACLK的频率
 *@param: None
 *@retval: ACLK的频率
 */
extern uint32_t BCM_getACLK(void);

/**
 *@brif: 选择XT1时钟源的工作模式
 *@param: BCM_XT1_MODE_x_FREQUENCY XT1时钟源的工作模式,可选一下参数
 *  \arg BCM_XT1_MODE_HIGH_FREQUENCY
 *       BCM_XT1_MODE_LOW_FREQUENCY
 *@retval: None
 */
extern void BCM_selectXT1Mode(uint8_t BCM_XT1_MODE_x_FREQUENCY);

/**
 *@brif: 初始化DOCCLK模块
 *@param: BCM_initDCOParam DCOCLK模块的初始化参数
 *  \arg  BCM_initDCOTypedef类型的参数
 *@retval: None
 */
extern void BCM_initDCOCLK(BCM_initDCOTypedef BCM_initDCOParam);

/**
 *@brif: 尝试清除振荡器错误中断的中断标志位，直到超时
 *@param: timeout超时时间
 *@retval: OFIFG中断标志位的状态
 */
extern uint8_t BCM_clearOscFaultFlagsWithTimeout(uint8_t timeout);

/**
 *@brif: 获得振荡器错误中断标志的状态
 *@param: None
 *@retval: OFIFG中断标志位的状态
 */
extern uint8_t BCM_getOscFaultFlagStatus(void);

/**
 *@brif: 允许振荡器错误中断
 *@param: None
 *@retval: None
 */
extern void BCM_enableOscFaultInterrupt(void);

/**
 *@brif: 禁止振荡器错误中断
 *@param: None
 *@retval: None
 */
extern void BCM_disableOscFaultInterrupt(void);
#ifdef __cplusplus
}
#endif
#endif/*__MSP430F149_BCM_H*/
/***********************CAFUC Electric Disgn *******End of Flie*******/