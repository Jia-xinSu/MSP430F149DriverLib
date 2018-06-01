# GPIO_setOutputLowOnPin
void GPIO_setOutputLowOnPin(</br>uint8_t GPIO_Port_x,</br>uint8_t GPIO_Pin_x</br>)
## @function
将选定管脚的电平设为低电平</br>
前提是管脚为普通I/O功能且为输出模式
## @parammeters
**GPIO_Port_x**选择的Port口，可用参数有：</br>
GPIO_Port_1</br>
GPIO_Port_2</br>
GPIO_Port_3</br>
GPIO_Port_4</br>
GPIO_Port_5</br>
GPIO_Port_6</br>

**GPIO_Pin_x**选择的具体管脚，可用下列参数的“逻辑或”值输入：</br>
GPIO_Pin_0</br>
GPIO_Pin_1</br>
GPIO_Pin_2</br>
GPIO_Pin_3</br>
GPIO_Pin_4</br>
GPIO_Pin_5</br>
GPIO_Pin_6</br>
GPIO_Pin_7</br>
GPIO_Pin_ALL</br>
会改变PxOUT的值
## @retVal
None

返回[GPIO目录](gpioindex.md)