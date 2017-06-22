/*
 *@file: msp430f149_gpio.h
 *@author:13电子-Jiaxin
 *@version:1.0
 *@date:2017年6月22日
 *@brif:msp430f149的GPIO模块
 */
#ifndef __MSP430F149_GPIO_H
#define __MSP430F149_GPIO_H

#ifdef __cplusplus
extern "C"
{
#endif

/*Includes----------------------------------------------------------------*/
#include "hw_memmap.h"

/*Macro-------------------------------------------------------------------*/ 

/*
 *@brif: 定义GPIO的Port口
 *@for functions: GPIO_setAsOutputPin
 *                GPIO_setAsInputPin   
 *                GPIO_clearInierrupt
 *                GPIO_enableInterrupt
 *                GPIO_disableInterrupt
 *                GPIO_getInputPinValue
 *@{
 */
#define GPIO_Port_1                          ((uint8_t)1) /*!<选择Port1口*/
#define GPIO_Port_2                          ((uint8_t)2) /*!<选择Port2口*/
#define GPIO_Port_3                          ((uint8_t)3) /*!<选择Port3口*/
#define GPIO_Port_4                          ((uint8_t)4) /*!<选择Port4口*/
#define GPIO_Port_5                          ((uint8_t)5) /*!<选择Port5口*/
#define GPIO_Port_6                          ((uint8_t)6) /*!<选择Port6口*/
/*
 *@}
 */

/*
 *@brif: 定义GPIO的Pin管脚
 *@for functions: GPIO_setAsOutputPin
 *                GPIO_setAsInputPin   
 *                GPIO_clearInierrupt
 *                GPIO_enableInterrupt
 *                GPIO_disableInterrupt
 *                GPIO_getInputPinValue
 *@{
 */
#define GPIO_Pin_0                           ((uint8_t)0x01) /*!<选择Pin0管脚*/
#define GPIO_Pin_1                           ((uint8_t)0x02) /*!<选择Pin1管脚*/
#define GPIO_Pin_2                           ((uint8_t)0x04) /*!<选择Pin2管脚*/
#define GPIO_Pin_3                           ((uint8_t)0x08) /*!<选择Pin3管脚*/
#define GPIO_Pin_4                           ((uint8_t)0x10) /*!<选择Pin4管脚*/
#define GPIO_Pin_5                           ((uint8_t)0x20) /*!<选择Pin5管脚*/
#define GPIO_Pin_6                           ((uint8_t)0x40) /*!<选择Pin6管脚*/
#define GPIO_Pin_7                           ((uint8_t)0x80) /*!<选择Pin7管脚*/
#define GPIO_Pin_ALL                         ((uint8_t)0xff) /*!<选择Pin7管脚*/
/*
 *@}
 */
 
/*
 *@brif: 定义GPIOPort1-2的偏置:
 *@{
 */
#define GPIO_PA_OFSIN                        ((uint8_t)0x00)/*!<管脚P1,2的PxIN偏置*/
#define GPIO_PA_OFSOUT                       ((uint8_t)0x01)/*!<管脚P1,2的PxOUT偏置*/
#define GPIO_PA_OFSDIR                       ((uint8_t)0x02)/*!<管脚P1,2的PxDIR偏置*/
#define GPIO_PA_OFSIFG                       ((uint8_t)0x03)/*!<管脚P1,2的PxIFG偏置*/
#define GPIO_PA_OFSIES                       ((uint8_t)0x04)/*!<管脚P1,2的PxIES偏置*/
#define GPIO_PA_OFSIE                        ((uint8_t)0x05)/*!<管脚P1,2的PxIE偏置*/
#define GPIO_PA_OFSSEL                       ((uint8_t)0x06)/*!<管脚P1,2的PxSEL偏置*/
/*
 *@}
 */

/*
 *@brif: 定义GPIOPort3-6的偏置:
 *@{
 */
#define GPIO_PB_OFSSEL                       ((uint8_t)0x03)/*!<管脚P3-6的PxSEL偏置*/
/*
 *@}
 */
 
/*
 *@brif: 定义输入管脚的高低电平
 *@functions:  GPIO_getInputPinValue
 *@{
 */
#define GPIO_PIN_INPUT_HIGH                  ((uint8_t)0x01)/*!<管脚输入为高电平*/
#define GPIO_PIN_INPUT_LOW                   ((uint8_t)0x00)/*!<管脚输入为低电平*/
/*
 *@}
 */

/*
 *@brif: 判断当前GPIO口是否有中断功能
 *@{
 */
#define GPIO_HAVE_INTRRUPT(x)                  ((x==GPIO_Port_1)|| \
                                               (x==GPIO_Port_2))
/*
 *@}
 */
 
/*Enumeration-----------------------------------------------------------*/



/*Functions-------------------------------------------------------------*/

/**
 *@brif:设置GPIO口位输出模式
 *@param： GPIO_Port_x选择设置的Port口
 *  \arg  GPIO_Port_1
 *        GPIO_Port_2
 *        GPIO_Port_3
 *        GPIO_Port_4
 *        GPIO_Port_5
 *        GPIO_Port_6
 *@param： GPIO_Pin_x选择设置的管脚，可用以下值求或输入
 *  \arg  GPIO_Pin_0
 *        GPIO_Pin_1
 *        GPIO_Pin_2
 *        GPIO_Pin_3
 *        GPIO_Pin_4
 *        GPIO_Pin_5
 *        GPIO_Pin_6
 *        GPIO_Pin_7
 *        GPIO_Pin_ALL
 *@retval：None
 */
extern void GPIO_setAsOutputPin(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x);

/**
 *@brif:设置GPIO口位输入模式
 *@param： GPIO_Port_x选择设置的Port口
 *  \arg  GPIO_Port_1
 *        GPIO_Port_2
 *        GPIO_Port_3
 *        GPIO_Port_4
 *        GPIO_Port_5
 *        GPIO_Port_6
 *@param： GPIO_Pin_x选择设置的管脚，可用以下值求或输入
 *  \arg  GPIO_Pin_0
 *        GPIO_Pin_1
 *        GPIO_Pin_2
 *        GPIO_Pin_3
 *        GPIO_Pin_4
 *        GPIO_Pin_5
 *        GPIO_Pin_6
 *        GPIO_Pin_7
 *        GPIO_Pin_ALL
 *@retval：None
 */
extern void GPIO_setAsInputPin(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x);

/**
 *@brif:清除GPIO中P1,P2上的中断标志位
 *@param： GPIO_Port_x选择需要清除标志位的Port口
 *  \arg  GPIO_Port_1
 *        GPIO_Port_2
 *@param： GPIO_Pin_x选择清除标志位的管脚，可用以下值求或输入
 *  \arg  GPIO_Pin_0
 *        GPIO_Pin_1
 *        GPIO_Pin_2
 *        GPIO_Pin_3
 *        GPIO_Pin_4
 *        GPIO_Pin_5
 *        GPIO_Pin_6
 *        GPIO_Pin_7
 *        GPIO_Pin_ALL
 *@retval：None
 */
extern void GPIO_clearInierrupt(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x);
/**
 *@brif:允许GPIO中断
 *@param： 允许产生中断信号的GPIO口
 *  \arg  GPIO_Port_1
 *        GPIO_Port_2
 *@param： GPIO_Pin_x允许产生中断的GPIO管脚
 *  \arg  GPIO_Pin_0
 *        GPIO_Pin_1
 *        GPIO_Pin_2
 *        GPIO_Pin_3
 *        GPIO_Pin_4
 *        GPIO_Pin_5
 *        GPIO_Pin_6
 *        GPIO_Pin_7
 *        GPIO_Pin_ALL
 *@retval：None
 */
extern void GPIO_enableInterrupt(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x);

/**
 *@brif:禁止GPIO中断
 *@param： 禁止产生中断信号的GPIO口
 *  \arg  GPIO_Port_1
 *        GPIO_Port_2
 *@param： GPIO_Pin_x禁止产生中断的GPIO管脚
 *  \arg  GPIO_Pin_0
 *        GPIO_Pin_1
 *        GPIO_Pin_2
 *        GPIO_Pin_3
 *        GPIO_Pin_4
 *        GPIO_Pin_5
 *        GPIO_Pin_6
 *        GPIO_Pin_7
 *        GPIO_Pin_ALL
 *@retval：None
 */
extern void GPIO_disableInterrupt(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x);

/**
 *@brif:读GPIO管脚对应值
 *@param： GPIO_Port_x选择要读的Port口
 *  \arg  GPIO_Port_1
 *        GPIO_Port_2
 *        GPIO_Port_3
 *        GPIO_Port_4
 *        GPIO_Port_5
 *        GPIO_Port_6
 *@param： GPIO_Pin_x选择要读的管脚
 *  \arg  GPIO_Pin_0
 *        GPIO_Pin_1
 *        GPIO_Pin_2
 *        GPIO_Pin_3
 *        GPIO_Pin_4
 *        GPIO_Pin_5
 *        GPIO_Pin_6
 *        GPIO_Pin_7
 *@retval：读出的高低电平值
 *  \arg  GPIO_PIN_INPUT_HIGH
 *        GPIO_PIN_INPUT_LOW
 */
extern uint8_t GPIO_getInputPinValue(uint8_t GPIO_Port_x,uint8_t GPIO_Pin_x);

#ifdef __cplusplus
}
#endif
#endif/*__MSP430F149_GPIO_H*/
/***********************CAFUC Electric Disgn *******End of Flie*******/

