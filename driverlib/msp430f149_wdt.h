/*
 *@file: msp430f149_wdt.h
 *@author:13电子-Jiaxin
 *@version:1.0
 *@date:2017年6月22日
 *@brif:msp430f149的Watch Dog Timer模块
 */
#ifndef __MSP430f149_WDT_H
#define __MSP430f149_WDT_H
#ifdef __cplusplus
extern "C"
{
#endif

/*Includes----------------------------------------------------------------*/
#include "hw_memmap.h"

/*Macro-------------------------------------------------------------------*/

/*
 *@brif: 定义WDT的时钟源
 *@functions:  WDT_initAsIntervalTimer
 *             WDT_initAsWatchDogTimer
 *@{
 */
#define WDT_SOURCE_ACLK                   ((uint16_t)0x0004) /*!<选择ACLK作为时钟源*/
#define WDT_SOURCE_SMCLK                  ((uint16_t)0x0000) /*!<选择SMCLK作为时钟源*/
/*
 *@}
 */

/*
 *@brif: 定义WDT的时钟源
 *@functions:  WDT_initAsIntervalTimer
 *             WDT_initAsWatchDogTimer
 *@{
 */
#define WDT_CLOCKDIVIDER_32768            ((uint16_t)0x0000) /*!<时钟源分频/32768*/
#define WDT_CLOCKDIVIDER_8192             ((uint16_t)0x0001) /*!<时钟源分频/8192*/
#define WDT_CLOCKDIVIDER_512              ((uint16_t)0x0002) /*!<时钟源分频/512*/
#define WDT_CLOCKDIVIDER_64               ((uint16_t)0x0003) /*!<时钟源分频/64*/
/*
 *@}
 */
 
/*Enumeration-------------------------------------------------------------*/

/*
 *@brif: 定义WatchDog Timer的中断模式
 *@functions:  WDT_enableInterrupt
 *             WDT_disableInterrupt
 *             WDT_clearInterrupt
 *@{
 */
typedef enum{
  WDT_NMI_INTERRUPT_MODE,
  WDT_INTERVAL_INTERRUPT_MODE
}WDT_interruptMode;
/*
 *@}
 */

/*Functions---------------------------------------------------------------*/

/*
 *@brif: 看门狗定时器保持，停止定时
 *@param: None
 *@retval: None
 */
extern void WDT_hold(void);

/*
 *@brif: 启动看门狗定时器
 *@param: None
 *@retval: None
 */
extern void WDT_start(void);

/*
 *@brif: 允许看门狗定时器中断
 *@param: WDT_X_INTERRUPT_MODE 模式，允许使用下面输入参数
 *  /arg  WDT_NMI_INTERRUPT_MODE
 *        WDT_INTERVAL_INTERRUPT_MODE
 *@retval: None
 */
extern void WDT_enableInterrupt(WDT_interruptMode WDT_X_INTERRUPT_MODE);
/*
 *@brif: 禁止看门狗定时器中断
 *@param: WDT_X_INTERRUPT_MODE 工作模式，允许使用下面输入参数
 *  /arg  WDT_NMI_INTERRUPT_MODE
 *        WDT_INTERVAL_INTERRUPT_MODE
 *@retval: None
 */
extern void WDT_disableInterrupt(WDT_interruptMode WDT_X_INTERRUPT_MODE);

/*
 *@brif: 清除看门狗中断标识位
 *@param: WDT_X_INTERRUPT_MODE 工作模式，允许使用下面输入参数
 *  /arg  WDT_NMI_INTERRUPT_MODE
 *        WDT_INTERVAL_INTERRUPT_MODE
 *@retval: None
 */
extern void WDT_clearInterrupt(WDT_interruptMode WDT_X_INTERRUPT_MODE);

/*
 *@brif: 看门狗计数器清零
 *@param: None
 *@retval: None
 */
extern void WDT_resetTimer(void);

/*
 *@brif: 看门狗定时器初始化为interval timer定时器模式
 *@param: WDT_SOURCE_x 选择时钟源
 *  /arg  WDT_SOURCE_ACLK
 *        WDT_SOURCE_SMCLK
 *@param: WDT_CLOCKDIVIDER_x 时钟源分频
 *  /arg  WDT_CLOCKDIVIDER_32768
 *        WDT_CLOCKDIVIDER_8192
 *        WDT_CLOCKDIVIDER_512
 *        WDT_CLOCKDIVIDER_64
 *@retval: None
 */
extern void WDT_initAsIntervalTimer(uint16_t WDT_SOURCE_x,uint16_t WDT_CLOCKDIVIDER_x);

/*
 *@brif: 看门狗定时器初始化为WatchDog Timer模式
 *@param: WDT_SOURCE_x 选择时钟源
 *  /arg  WDT_SOURCE_ACLK
 *        WDT_SOURCE_SMCLK
 *@param: WDT_CLOCKDIVIDER_x 时钟源分频
 *  /arg  WDT_CLOCKDIVIDER_32768
 *        WDT_CLOCKDIVIDER_8192
 *        WDT_CLOCKDIVIDER_512
 *        WDT_CLOCKDIVIDER_64
 *@retval: None
 */
extern void WDT_initAsWatchDogTimer(uint16_t WDT_SOURCE_x,uint16_t WDT_CLOCKDIVIDER_x);


#ifdef __cplusplus
}
#endif
#endif/*__MSP430F149_WDT_H*/
/***********************CAFUC Electric Disgn *******End of Flie*******/