/*
 *@file: msp430f149_timer_a.h
 *@author:13电子-Jiaxin
 *@version:1.0
 *@date:2017年6月23日
 *@brif:msp430f149的TIMER_A模块
 */
#ifndef __MSP430F149_TIMER_A_H
#define __MSP430F149_TIMER_A_H
#ifdef __cplusplus
extern "C"
{
#endif

/*Includes----------------------------------------------------------------*/

#include "hw_memmap.h"

/*Macro-------------------------------------------------------------------*/ 

/*
 *@brif: 定义TimerA的启动模式
 *@for functions: TIMER_A_start_Counter
 *@{
 */
#define TIMER_A_STOP_MODE                  ((uint16_t)0x0000)/*!<停止模式*/
#define TIMER_A_UP_MODE                    ((uint16_t)0x0010)/*!<上升模式*/
#define TIMER_A_CONTINUOUS_MODE            ((uint16_t)0x0020)/*!<连续模式*/
#define TIMER_A_UPDOWN_MODE                ((uint16_t)0x0030)/*!<上下模式*/
/*
 *@}
  */

/*
 *@brif: 定义TimerA的时钟源
 *@{
 */
#define TIMER_A_SOURCE_TACLK               ((uint16_t)0x0000)/*!<选择TACLK*/
#define TIMER_A_SOURCE_ACLK                ((uint16_t)0x0100)/*!<选择TACLK*/
#define TIMER_A_SOURCE_SMCLK               ((uint16_t)0x0200)/*!<选择TACLK*/
#define TIMER_A_SOURCE_INCLK               ((uint16_t)0x0300)/*!<选择TACLK*/
/*
 *@}
  */

/*
 *@brif: 定义TimerA的时钟分频
 *@{
 */
#define TIMER_A_DIVIDER_1                  ((uint16_t)0x0000)/*!<选择1分频*/
#define TIMER_A_DIVIDER_2                  ((uint16_t)0x0040)/*!<选择2分频*/
#define TIMER_A_DIVIDER_4                  ((uint16_t)0x0080)/*!<选择4分频*/
#define TIMER_A_DIVIDER_8                  ((uint16_t)0x00c0)/*!<选择8分频*/
/*
 *@}
  */

/*
 *@brif: 定义TimerA是否允许中断
 *@{
 */
#define TIMER_A_ENABLE_INTERRUPT           ((uint16_t)0x0000)/*!<允许TA中断*/
#define TIMER_A_DISABLE_INTERRUPT          ((uint16_t)0x0002)/*!<禁止TA中断*/
/*
 *@}
  */

/*
 *@brif: 定义TimerA是否清零
 *@{
 */
#define TIMER_A_CLEAR                      ((uint16_t)0x0000)/*!<清零TimerA*/
#define TIMER_A_DONT_CLEAR                 ((uint16_t)0x0004)/*!<不清零TimerA*/
/*
 *@}
  */

/*
 *@brif: 顶以TimerA的Capture/Compare寄存器
 *@{
 */
#define TIMER_A_CCR0                       ((uint8_t)0x01)/*!<选择TACCR0寄存器*/
#define TIMER_A_CCR1                       ((uint8_t)0x02)/*!<选择TACCR1寄存器*/
#define TIMER_A_CCR2                       ((uint8_t)0x03)/*!<选择TACCR2寄存器*/
/*
 *@}
  */

/*
 *@brif: 定义是否允许TimerA CCRx的中断允许
 *@{
 */
#define TIMER_A_CCR_ENABLE_INTERRUPT       ((uint16_t)0x0010)/*!<允许CCRx中断*/
#define TIMER_A_CCR_DISABLE_INTERRUPT      ((uint16_t)0x0000)/*!<禁止CCRx中断*/
/*
 *@}
  */


/*Struct----------------------------------------------------------------*/

/*
 *@brif: 定义TimerA的初始化参数结构体
 *@member timerMode时钟运行模式，可选以下合法参数
 *  \arg  TIMER_A_STOP_MODE
 *        TIMER_A_UP_MODE
 *        TIMER_A_CONTINUOUS_MODE
 *        TIMER_A_UPDOWN_MODE
 *@member clockSource时钟源，可选以下合法参数
 *  \arg  TIMER_A_SOURCE_TACLK
 *        TIMER_A_SOURCE_ACLK
 *        TIMER_A_SOURCE_SMCLK
 *        TIMER_A_SOURCE_INCLK
 *@member clockSourceDivider 选择时钟分频，可选以下合法参数
 *  \arg  TIMER_A_DIVIDER_1
 *        TIMER_A_DIVIDER_2
 *        TIMER_A_DIVIDER_4
 *        TIMER_A_DIVIDER_8
 *@member timerInterruptEnable 是否允许TA中断，可选以下合法参数
 *  \arg  TIMER_A_ENABLE_INTERRUPT
 *        TIMER_A_DISABLE_INTERRUPT
 *@member timerClear 是否清零TimerA，可选以下合法参数
 *  \arg  TIMER_A_CLEAR
 *        TIMER_A_DONT_CLEAR
 *for function:  TIMER_A_init
 *@{
 */
typedef struct
{
  uint16_t timerMode;
  uint16_t clockSource;
  uint16_t clockSourceDivider;
  uint16_t timerInterruptEnable;
  uint16_t timerClear;
}TIMER_A_initTypedef;
/*
 *@}
  */

/*
 *@brif: 定义TimerACCR比较模式的初始化参数
 *@member：compareRegister选择初始化的CCR寄存器，可选以下合法值
 *  \arg  TIMER_A_CCR0
 *        TIMER_A_CCR1
 *        TIMER_A_CCR2
 *@member: compareInterruptEnable是否允许CCRx中断，可选以下合法值
 *  \arg  TIMER_A_CCR_ENABLE_INTERRUPT
 *        TIMER_A_CCR_DISABLE_INTERRUPT
 *for function:  
 *@{
 */
typedef struct
{
  uint8_t compareRegister;
  uint16_t compareInterruptEnable;
  
}TIMER_A_initCCRCompareModeTypedef;
/*
 *@}
  */

/*Functions-------------------------------------------------------------*/

/**
 *@brif: 启动TimerA，选择TimerA的启动模式
 *       假设你已经对时钟进行过初始化
 *@param：TIMER_A_x_MODE TimerA的启动模式,可选择以下合法参数
 *  \arg  TIMER_A_STOP_MODE
 *        TIMER_A_UP_MODE
 *        TIMER_A_CONTINUOUS_MODE
 *        TIMER_A_UPDOWN_MODE
 *@retval：None
 */
extern void TIMER_A_start_Counter(uint16_t TIMER_A_x_MODE);

/**
 *@brif: 初始化TimerA
 *@param：TIMER_A_initParam TimerA的初始化参数
 *  \arg TIMER_A_initTypedef 类型
 *@retval：None
 */
extern void TIMER_A_init(TIMER_A_initTypedef TIMER_A_initParam);

#ifdef __cplusplus
}
#endif
#endif/*__MSP430F149_TIMER_A_H*/
/***********************CAFUC Electric Disgn *******End of Flie*******/

