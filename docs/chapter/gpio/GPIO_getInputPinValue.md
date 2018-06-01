# GPIO_getInputPinValue
uint8_t GPIO_getInputPinValue(</br>uint8_t GPIO_Port_x,</br>uint8_t GPIO_Pin_x</br>)
## @function
获取选择的管脚上的电平状态
## @parammeters
**GPIO_Port_x**选择的Port口，可用参数有：</br>
GPIO_Port_1</br>
GPIO_Port_2</br>
GPIO_Port_3</br>
GPIO_Port_4</br>
GPIO_Port_5</br>
GPIO_Port_6</br>

**GPIO_Pin_x**选择的具体管脚，可用参数有：</br>
GPIO_Pin_0</br>
GPIO_Pin_1</br>
GPIO_Pin_2</br>
GPIO_Pin_3</br>
GPIO_Pin_4</br>
GPIO_Pin_5</br>
GPIO_Pin_6</br>
GPIO_Pin_7</br>
## @retVal
会有以下返回值：
GPIO_PIN_INPUT_HIGH</br>
GPIO_PIN_INPUT_LOW</br>
指示选择管脚的电平状态

返回[GPIO目录](gpioindex.md)