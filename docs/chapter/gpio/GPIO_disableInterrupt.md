# GPIO_disableInterrupt
void GPIO_disableInterrupt(</br>uint8_t GPIO_Port_x</br>uint8_t GPIO_Pin_x</br>)
## function：
禁用P1,P2上相应管脚的中断功能
## @parammeters
**GPIO_Port_x**选择的Port口，可用参数有：</br>
GPIO_Port_1</br>
GPIO_Port_2</br>
**GPIO_Pin_x**选择的具体管脚,可选参数有：</br>
GPIO_Pin_0</br>
GPIO_Pin_1</br>
GPIO_Pin_2</br>
GPIO_Pin_3</br>
GPIO_Pin_4</br>
GPIO_Pin_5</br>
GPIO_Pin_6</br>
GPIO_Pin_7</br>
GPIO_Pin_ALL</br>
会改变PxIE的值
## @retVal
None

返回[GPIO目录](gpioindex.md)