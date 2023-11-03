# ch423_for_stm32  
基于沁恒CH423模组开发的STM32（HAL）控制代码  
## 使用方法  
将头文件及函数文件加入工程  
配置头文件 CH423_SCL,CH423_SCL_Pin_GPIO_Port,CH423_SDA,CH423_SDA_Pin_GPIO_Port 引脚参数  
### GPIO读取  
```C
CH423_WriteByte(CH423_SYS_CMD | BIT_IO_OE);  
uint8_t data = CH423_ReadByte();  
```  
### GPIO输出  
```C
CH423_WriteByte(CH423_SYS_CMD);  
CH423_WriteByte(CH423_SET_IO_CMD|BIT_IO0_DAT); //Set GPIO_0 HIGH  
```  
### GPO输出  
```C
CH423_WriteByte(CH423_SYS_CMD);  
CH423_WriteByte(CH423_OC_L_CMD|BIT_OC0_L_DAT);//Set GPO_0 HIGH  
CH423_WriteByte(CH423_OC_H_CMD|BIT_OC8_L_DAT);//Set GPO_8 HIGH  
```  

