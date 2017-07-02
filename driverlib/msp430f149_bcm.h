/*
 *@file: msp430f149_gpio.h
 *@author:13鐢靛瓙-Jiaxin
 *@version:1.0
 *@date:2017骞�6鏈�22鏃�
 *@brif:msp430f149鐨凚asic Clock Module妯″潡
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
 *@brif: 瀹氫箟MCLK鐨勬椂閽熸簮
 *@for functions: BCM_initMCLKSignal
 *@{
 */
#define BCM_MCLK_SOURCE_DCOCLK              ((uint8_t)0x00)/*!<閫夋嫨DCOCLK浣滀负MCLK鐨勬椂閽熸簮*/
#define BCM_MCLK_SOURCE_XT2CLK              ((uint8_t)0x80)/*!<閫夋嫨XT2CLK浣滀负MCLK鐨勬椂閽熸簮*/
#define BCM_MCLK_SOURCE_LFXT1CLK            ((uint8_t)0xc0)/*!<閫夋嫨LFXT1CLK浣滀负MCLK鐨勬椂閽熸簮*/
/*
 *@}
 */
 
/*
 *@brif: 瀹氫箟SMCLK鐨勬椂閽熸簮
 *@for functions: BCM_initSMCLKSignal
 *@{
 */
#define BCM_SMCLK_SOURCE_DCOCLK              ((uint8_t)0x00)/*!<閫夋嫨DCOCLK浣滀负SMCLK鐨勬椂閽熸簮*/
#define BCM_SMCLK_SOURCE_XT2CLK              ((uint8_t)0x08)/*!<閫夋嫨XT2CLK浣滀负SMCLK鐨勬椂閽熸簮*/
/*
 *@}
 */
 
/*
 *@brif: 瀹氫箟鏃堕挓淇″彿鍒嗛
 *@for functions: BCM_initMCLKSignal
 *                BCM_initSMCLKSignal
 *                BCM_iniACLKSignal
 *@{
 */
#define BCM_DIVIDER_1                       ((uint8_t)0x00)/*!<閫夋嫨1鍒嗛*/
#define BCM_DIVIDER_2                       ((uint8_t)0x01)/*!<閫夋嫨2鍒嗛*/
#define BCM_DIVIDER_4                       ((uint8_t)0x02)/*!<閫夋嫨3鍒嗛*/
#define BCM_DIVIDER_8                       ((uint8_t)0x03)/*!<閫夋嫨4鍒嗛*/
/*
 *@}
 */

/*
 *@brif: XT1鐨勫伐浣滄ā寮�
 *@for functions:  BCM_selectXT1Mode
 *@{
 */
#define BCM_XT1_MODE_HIGH_FREQUENCY         ((uint8_t)0x40)/*!<閫夋嫨楂橀妯″紡*/
#define BCM_XT1_MODE_LOW_FREQUENCY          ((uint8_t)0x00)/*!<閫夋嫨浣庨妯″紡*/
/*
 *@}
 */
 
/*
 *@brif: 瀹氫箟鍒嗛鎺у埗浣嶇殑浣嶅亸缃�
 *@{
 */
#define BCM_OFSB_DIVM                       ((uint8_t)0x04)/*!<DIVM鐨勪綅鍋忕疆*/
#define BCM_OFSB_DIVS                       ((uint8_t)0x01)/*!<DIVS鐨勪綅鍋忕疆*/
#define BCM_OFSB_DIVA                       ((uint8_t)0x04)/*!<DIVA鐨勪綅鍋忕疆*/
/*
 *@}
 */

/*
 *@brif: 瀹氫箟鍒嗛鎺у埗浣嶇殑浣嶅亸缃�
 *@{
 */
#define BCM_RESISTOR_INTERNAL               ((uint8_t)0x00)/*!<閫夋嫨鍐呴儴鐢甸樆*/
#define BCM_RESISTOR_EXTERNAL               ((uint8_t)0x01)/*!<閫夋嫨澶栭儴鐢甸樆*/
/*
 *@}
 */
 
/*Struct------------------------------------------------------------------*/

/*
 *@brif: DCO鍒濆鍖栫粨鏋勪綋
 *@member resistorSelect闇囪崱鐢佃矾鐨勭數闃婚�夊彇锛屽悎娉曞弬鏁板涓�
 *  \arg  BCM_RESISTOR_INTERNAL
 *        BCM_RESISTOR_EXTERNAL
 *@member selectDCOFrequency閫夋嫨DCO棰戠巼
 *  \arg  0-7鏁存暟
 *@member modulator璋冨埗鍣ㄥ弬鏁�
 *  \arg  0-31鏁存暟
 *@member internalResistorSelect鍐呴儴鐢甸樆閫夋嫨
 *  \arg  0-7鏁存暟
 *@for function锛欱CM_initDCOCLK 
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
 *@brif:璁剧疆鍗曠墖鏈哄閮ㄦ椂閽熼鐜�
 *@param锛� XT1CLK_frequency XT1鏃堕挓鐨勬椂閽熼鐜�
 *@param锛� XT2CLK_frequency XT2鏃堕挓鐨勬椂閽熼鐜�
 *@retval锛歂one
 */
extern void BCM_setExternalClockSource(uint32_t XT1CLK_frequency,uint32_t XT2CLK_frequency);

/**
 *@brif:璁剧疆MCLK鐨勪俊鍙�
 *@param锛� BCM_MCLK_SOURCE_x MCLK鐨勪俊鍙锋簮,鍙�変互涓嬪弬鏁�
 *  \arg  BCM_MCLK_SOURCE_DCOCLK
 *        BCM_MCLK_SOURCE_XT2CLK
 *        BCM_MCLK_SOURCE_LFXT1CLK
 *@param锛� BCM_DIVIDER_x MCLK鐨勪俊鍙峰垎棰�,鍙�変互涓嬪弬鏁�
 *  \arg  BCM_DIVIDER_1
 *        BCM_DIVIDER_2
 *        BCM_DIVIDER_4
 *        BCM_DIVIDER_8
 *@retval锛歂one
 */
 
extern void BCM_initMCLKSignal(uint8_t BCM_MCLK_SOURCE_x,uint8_t BCM_DIVIDER_x);

/**
 *@brif:璁剧疆MSCLK鐨勪俊鍙�
 *@param锛� BCM_SMCLK_SOURCE_x SMCLK鐨勪俊鍙锋簮,鍙�変互涓嬪弬鏁�
 *  \arg  BCM_SMCLK_SOURCE_DCOCLK
 *        BCM_SMCLK_SOURCE_XT2CLK
 *@param锛� BCM_DIVIDER_x MCLK鐨勪俊鍙峰垎棰�,鍙�変互涓嬪弬鏁�
 *  \arg  BCM_DIVIDER_1
 *        BCM_DIVIDER_2
 *        BCM_DIVIDER_4
 *        BCM_DIVIDER_8
 *@retval锛歂one
 */
extern void BCM_initSMCLKSignal(uint8_t BCM_SMCLK_SOURCE_x,uint8_t BCM_DIVIDER_x);

/**
 *@brif:璁剧疆ACLK鐨勪俊鍙�
 *@param锛� BCM_DIVIDER_x ACLK鐨勪俊鍙峰垎棰�,鍙�変互涓嬪弬鏁�
 *  \arg  BCM_DIVIDER_1
 *        BCM_DIVIDER_2
 *        BCM_DIVIDER_4
 *        BCM_DIVIDER_8
 *@retval: None
 */
void BCM_iniACLKSignal(uint8_t BCM_DIVIDER_x);

/**
 *@brif: 鍚姩XT2鎸崱鍣�,鐩村埌鎸崱鍣ㄩ敊璇綅琚竻闆�
 *@param: None
 *@retval: None
 */
extern void BCM_turnOnXT2(void);

/**
 *@brif: 鍚姩XT2鎸崱鍣�,鐩村埌鎸崱鍣ㄩ敊璇綅琚竻闆舵垨瓒呮椂
 *@param: timeout 瓒呮椂鏃堕棿
 *@retval: None
 */
extern void BCM_turnOnXT2WithTimeout(uint32_t timeout);

/**
 *@brif: 鍏抽棴XT2鎸崱鍣�
 *@param: None
 *@retval: None
 */
extern void BCM_turnOffXT2(void);

/**
 *@brif: 鑾峰彇MCLK鐨勯鐜�
 *       鐢变簬瀵逛簬MSP430F149鍐呴儴闇囪崱鐢佃矾鎬ц兘涓嶇ǔ瀹�
 *       鏁呭鏋滀娇鐢―COCLK杩斿洖0
 *@param: None
 *@retval: MCLK鐨勯鐜�
 */
extern uint32_t BCM_getMCLK(void);

/**
 *@brif: 鑾峰彇SMCLK鐨勯鐜�
 *       鐢变簬瀵逛簬MSP430F149鍐呴儴闇囪崱鐢佃矾鎬ц兘涓嶇ǔ瀹�
 *       鏁呭鏋滀娇鐢―COCLK杩斿洖0
 *@param: None
 *@retval: SMCLK鐨勯鐜�
 */
extern uint32_t BCM_getSMCLK(void);

/**
 *@brif: 鑾峰彇ACLK鐨勯鐜�
 *@param: None
 *@retval: ACLK鐨勯鐜�
 */
extern uint32_t BCM_getACLK(void);

/**
 *@brif: 閫夋嫨XT1鏃堕挓婧愮殑宸ヤ綔妯″紡
 *@param: BCM_XT1_MODE_x_FREQUENCY XT1鏃堕挓婧愮殑宸ヤ綔妯″紡,鍙�変竴涓嬪弬鏁�
 *  \arg BCM_XT1_MODE_HIGH_FREQUENCY
 *       BCM_XT1_MODE_LOW_FREQUENCY
 *@retval: None
 */
extern void BCM_selectXT1Mode(uint8_t BCM_XT1_MODE_x_FREQUENCY);

/**
 *@brif: 鍒濆鍖朌OCCLK妯″潡
 *@param: BCM_initDCOParam DCOCLK妯″潡鐨勫垵濮嬪寲鍙傛暟
 *  \arg  BCM_initDCOTypedef绫诲瀷鐨勫弬鏁�
 *@retval: None
 */
extern void BCM_initDCOCLK(BCM_initDCOTypedef BCM_initDCOParam);

/**
 *@brif: 灏濊瘯娓呴櫎鎸崱鍣ㄩ敊璇腑鏂殑涓柇鏍囧織浣嶏紝鐩村埌瓒呮椂
 *@param: timeout瓒呮椂鏃堕棿
 *@retval: OFIFG涓柇鏍囧織浣嶇殑鐘舵��
 */
extern uint8_t BCM_clearOscFaultFlagsWithTimeout(uint8_t timeout);

/**
 *@brif: 鑾峰緱鎸崱鍣ㄩ敊璇腑鏂爣蹇楃殑鐘舵��
 *@param: None
 *@retval: OFIFG涓柇鏍囧織浣嶇殑鐘舵��
 */
extern uint8_t BCM_getOscFaultFlagStatus(void);

/**
 *@brif: 鍏佽鎸崱鍣ㄩ敊璇腑鏂�
 *@param: None
 *@retval: None
 */
extern void BCM_enableOscFaultInterrupt(void);

/**
 *@brif: 绂佹鎸崱鍣ㄩ敊璇腑鏂�
 *@param: None
 *@retval: None
 */
extern void BCM_disableOscFaultInterrupt(void);
#ifdef __cplusplus
}
#endif
#endif/*__MSP430F149_BCM_H*/
/***********************CAFUC Electric Disgn *******End of Flie*******/
