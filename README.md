# MSP430F149DriverLib
仿照MSP430 Ware DriverLib写的用于MSP430F149的库文件，方便大家开发嘛。希望大家喜欢！！！

MSP430F149是国内用得较多的MSP430系列单片机的入门产品，但是因为产品实在比较久远TI官方并未对其有足够好的库文件支持，使得使用上比较困难，所以就仿照较新的MSP430F5529单片机设计了这个库文件，来提升开发效率。希望这个库文件可以帮助到大家对于MSP430单片机的学习。

由于这个库文件开发时是使用CCS开发的，而且当时的开发时间极短，是大学期间开发的项目，没有在IAR上尝试过运行，已毕业很久，由于种种原因当时并没有把完整版的软件上传到GitHub上，而且最终并没有从事嵌入式开发相关工作，仅仅是作为大学时期闲暇时间的兴趣爱好。现在想来难免有些遗憾。由于平时工作的空闲时间较多，故把准备把之前的软件加以**文档**，重新整理之后，慢慢传到GitHub上。
# File Struct
msp430f149DriverLibDocument.docx</br>
/driverlib</br>
[msp430f149_gpio.c](driverlib/msp430f149_gpio.c)</br>
[msp430f149_gpio.h](driverlib/msp430f149_gpio.h)</br>
msp430f149_ucs.c</br>
msp430f149_ucs.h</br>
msp430f149_timer_a.c</br>
msp430f149_timer_a.h</br>
msp430f149_timer_b.c</br>
msp430f149_timer_b.h</br>
msp430f149_config.h</br>
[msp430f149_it.c](driverlib/msp430f149_it.c)</br>
[msp430f149_it.h](driverlib/msp430f149_it.h)</br>
[msp430f149_wdt.c](driverlib/msp430f149_wdt.c)</br>
[msp430f149_wdt.h](driverlib/msp430f149_wdt.h)</br>
msp430f149_sysctl.c</br>
msp430f149_sysctl.h</br>
msp430f149_uasrt_uart.c</br>
msp430f149_uasrt_uart.h</br>
msp430f149_uasrt_spi.c</br>
msp430f149_uasrt_spi.h</br>
[driverlib.h](driverlib/driverlib.h)</br>
[msp430f149_adc12.c](driverlib/msp430f149_adc12.c)</br>
[msp430f149_adc12.h](driverlib/msp430f149_adc12.h)</br>
[msp430f149_bcm.c](driverlib/msp430f149_bcm.c)</br>
[msp430f149_bcm.h](driverlib/msp430f149_bcm.h)</br>
/driverlib/inc</br>
[hw_memmap.h](/driverlib/inc/hw_memmap.h)</br>

## 使用说明
配置说明见[配置](docs/config.md)</br>
详细API文档见[目录](docs/index,md)
