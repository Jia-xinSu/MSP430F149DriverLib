/*
 *@file: msp430f149_wdt.h
 *@author:13鐢靛瓙-Jiaxin
 *@version:1.0
 *@date:2017骞�6鏈�22鏃�
 *@brif:msp430f149鐨刉atch Dog Timer妯″潡
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
 *@brif: 瀹氫箟WDT鐨勬椂閽熸簮
 *@functions:  WDT_initAsIntervalTimer
 *             WDT_initAsWatchDogTimer
 *@{
 */
#define WDT_SOURCE_ACLK                   ((uint16_t)0x0004) /*!<閫夋嫨ACLK浣滀负鏃堕挓婧�*/
#define WDT_SOURCE_SMCLK                  ((uint16_t)0x0000) /*!<閫夋嫨SMCLK浣滀负鏃堕挓婧�*/
/*
 *@}
 */

/*
 *@brif: 瀹氫箟WDT鐨勬椂閽熸簮
 *@functions:  WDT_initAsIntervalTimer
 *             WDT_initAsWatchDogTimer
 *@{
 */
#define WDT_CLOCKDIVIDER_32768            ((uint16_t)0x0000) /*!<鏃堕挓婧愬垎棰�/32768*/
#define WDT_CLOCKDIVIDER_8192             ((uint16_t)0x0001) /*!<鏃堕挓婧愬垎棰�/8192*/
#define WDT_CLOCKDIVIDER_512              ((uint16_t)0x0002) /*!<鏃堕挓婧愬垎棰�/512*/
#define WDT_CLOCKDIVIDER_64               ((uint16_t)0x0003) /*!<鏃堕挓婧愬垎棰�/64*/
/*
 *@}
 */
 
/*Enumeration-------------------------------------------------------------*/

/*
 *@brif: 瀹氫箟WatchDog Timer鐨勪腑鏂ā寮�
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
 *@brif: 鐪嬮棬鐙楀畾鏃跺櫒淇濇寔锛屽仠姝㈠畾鏃�
 *@param: None
 *@retval: None
 */
extern void WDT_hold(void);

/*
 *@brif: 鍚姩鐪嬮棬鐙楀畾鏃跺櫒
 *@param: None
 *@retval: None
 */
extern void WDT_start(void);

/*
 *@brif: 鍏佽鐪嬮棬鐙楀畾鏃跺櫒涓柇
 *@param: WDT_X_INTERRUPT_MODE 妯″紡锛屽厑璁镐娇鐢ㄤ笅闈㈣緭鍏ュ弬鏁�
 *  /arg  WDT_NMI_INTERRUPT_MODE
 *        WDT_INTERVAL_INTERRUPT_MODE
 *@retval: None
 */
extern void WDT_enableInterrupt(WDT_interruptMode WDT_X_INTERRUPT_MODE);
/*
 *@brif: 绂佹鐪嬮棬鐙楀畾鏃跺櫒涓柇
 *@param: WDT_X_INTERRUPT_MODE 宸ヤ綔妯″紡锛屽厑璁镐娇鐢ㄤ笅闈㈣緭鍏ュ弬鏁�
 *  /arg  WDT_NMI_INTERRUPT_MODE
 *        WDT_INTERVAL_INTERRUPT_MODE
 *@retval: None
 */
extern void WDT_disableInterrupt(WDT_interruptMode WDT_X_INTERRUPT_MODE);

/*
 *@brif: 娓呴櫎鐪嬮棬鐙椾腑鏂爣璇嗕綅
 *@param: WDT_X_INTERRUPT_MODE 宸ヤ綔妯″紡锛屽厑璁镐娇鐢ㄤ笅闈㈣緭鍏ュ弬鏁�
 *  /arg  WDT_NMI_INTERRUPT_MODE
 *        WDT_INTERVAL_INTERRUPT_MODE
 *@retval: None
 */
extern void WDT_clearInterrupt(WDT_interruptMode WDT_X_INTERRUPT_MODE);

/*
 *@brif: 鐪嬮棬鐙楄鏁板櫒娓呴浂
 *@param: None
 *@retval: None
 */
extern void WDT_resetTimer(void);

/*
 *@brif: 鐪嬮棬鐙楀畾鏃跺櫒鍒濆鍖栦负interval timer瀹氭椂鍣ㄦā寮�
 *@param: WDT_SOURCE_x 閫夋嫨鏃堕挓婧�
 *  /arg  WDT_SOURCE_ACLK
 *        WDT_SOURCE_SMCLK
 *@param: WDT_CLOCKDIVIDER_x 鏃堕挓婧愬垎棰�
 *  /arg  WDT_CLOCKDIVIDER_32768
 *        WDT_CLOCKDIVIDER_8192
 *        WDT_CLOCKDIVIDER_512
 *        WDT_CLOCKDIVIDER_64
 *@retval: None
 */
extern void WDT_initAsIntervalTimer(uint16_t WDT_SOURCE_x,uint16_t WDT_CLOCKDIVIDER_x);

/*
 *@brif: 鐪嬮棬鐙楀畾鏃跺櫒鍒濆鍖栦负WatchDog Timer妯″紡
 *@param: WDT_SOURCE_x 閫夋嫨鏃堕挓婧�
 *  /arg  WDT_SOURCE_ACLK
 *        WDT_SOURCE_SMCLK
 *@param: WDT_CLOCKDIVIDER_x 鏃堕挓婧愬垎棰�
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
