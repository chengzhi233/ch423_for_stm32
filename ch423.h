#ifndef	CH423IF_H
#define	CH423IF_H

#include "stm32f1xx_hal.h"
#include "gpio.h"
#include "main.h"

#define DELAY_0_1US    HAL_Delay(1);


#define   CH423_SCL SCL_Pin_Pin
#define 	CH423_SCL_Pin_GPIO_Port SCL_Pin_GPIO_Port
#define   CH423_SDA SDA_Pin_Pin
#define		CH423_SDA_Pin_GPIO_Port SDA_Pin_GPIO_Port

#define CH423_SCL_SET       HAL_GPIO_WritePin(CH423_SCL_Pin_GPIO_Port,CH423_SCL,GPIO_PIN_SET);
#define CH423_SCL_CLR       HAL_GPIO_WritePin(CH423_SCL_Pin_GPIO_Port,CH423_SCL,GPIO_PIN_RESET);
#define CH423_SCL_D_OUT     GPIO_InitTypeDef GPIO_InitStruct_SCL_OUT = {0}; \
														GPIO_InitStruct_SCL_OUT.Pin = CH423_SCL; \
														GPIO_InitStruct_SCL_OUT.Mode = GPIO_MODE_OUTPUT_PP; \
														GPIO_InitStruct_SCL_OUT.Pull = GPIO_NOPULL; \
														GPIO_InitStruct_SCL_OUT.Speed = GPIO_SPEED_FREQ_LOW; \
														HAL_GPIO_Init(CH423_SCL_Pin_GPIO_Port, &GPIO_InitStruct_SCL_OUT);
#define CH423_SDA_SET       HAL_GPIO_WritePin(CH423_SDA_Pin_GPIO_Port,CH423_SDA,GPIO_PIN_SET);
#define CH423_SDA_CLR       HAL_GPIO_WritePin(CH423_SDA_Pin_GPIO_Port,CH423_SDA,GPIO_PIN_RESET);
#define CH423_SDA_IN        HAL_GPIO_ReadPin(CH423_SDA_Pin_GPIO_Port,CH423_SDA)
#define CH423_SDA_D_OUT     GPIO_InitTypeDef GPIO_InitStruct_SDA_OUT = {0}; \
														GPIO_InitStruct_SDA_OUT.Pin = CH423_SDA; \
														GPIO_InitStruct_SDA_OUT.Mode = GPIO_MODE_OUTPUT_PP; \
														GPIO_InitStruct_SDA_OUT.Pull = GPIO_NOPULL; \
														GPIO_InitStruct_SDA_OUT.Speed = GPIO_SPEED_FREQ_LOW; \
														HAL_GPIO_Init(CH423_SDA_Pin_GPIO_Port, &GPIO_InitStruct_SDA_OUT);
#define CH423_SDA_D_IN      GPIO_InitTypeDef GPIO_InitStruct_SDA_IN = {0}; \
														GPIO_InitStruct_SDA_IN.Pin = CH423_SDA; \
														GPIO_InitStruct_SDA_IN.Mode = GPIO_MODE_INPUT; \
														GPIO_InitStruct_SDA_IN.Pull = GPIO_NOPULL; \
														HAL_GPIO_Init(CH423_SDA_Pin_GPIO_Port, &GPIO_InitStruct_SDA_IN);

#define     CH423_I2C_ADDR1     0x40
#define     CH423_I2C_MASK      0x3E

/*  SYS_CMD */ 

#define CH423_SYS_CMD     0x4800		//SYS_CMD
#define BIT_X_INT         0x08			//NO 
#define BIT_DEC_H         0x04			//awa
#define BIT_DEC_L         0x02			//awa
#define BIT_IO_OE         0x01      //GPIO IN or OUT

/* GPO_HIGH 0~7 */

#define CH423_OC_L_CMD    0x4400 		//GPO_HIGH_CMD
#define BIT_OC0_L_DAT     0x01			//GPO0
#define BIT_OC1_L_DAT     0x02			//GPO1
#define BIT_OC2_L_DAT     0x04			//GPO2
#define BIT_OC3_L_DAT     0x08			//GPO3
#define BIT_OC4_L_DAT     0x10			//GPO4
#define BIT_OC5_L_DAT     0x20			//GPO5
#define BIT_OC6_L_DAT     0x40			//GPO6
#define BIT_OC7_L_DAT     0x80			//GPO7

/* GPO_LOW 8~15 */

#define CH423_OC_H_CMD    0x4600		//GPO_LOW_CMD
#define BIT_OC8_L_DAT     0x01			//GPO8
#define BIT_OC9_L_DAT     0x02			//GPO9
#define BIT_OC10_L_DAT    0x04			//GPO10
#define BIT_OC11_L_DAT    0x08			//GPO11
#define BIT_OC12_L_DAT    0x10			//GPO12
#define BIT_OC13_L_DAT    0x20			//GPO13
#define BIT_OC14_L_DAT    0x40			//GPO14
#define BIT_OC15_L_DAT    0x80			//GPO15

/* GPIO 0~7 */

#define CH423_SET_IO_CMD   0x6000    //GPIO_CMD
#define BIT_IO0_DAT        0x01      //GPIO0
#define BIT_IO1_DAT        0x02      //GPIO1
#define BIT_IO2_DAT        0x04      //GPIO2
#define BIT_IO3_DAT        0x08      //GPIO3
#define BIT_IO4_DAT        0x10      //GPIO4
#define BIT_IO5_DAT        0x20      //GPIO5
#define BIT_IO6_DAT        0x40      //GPIO6
#define BIT_IO7_DAT        0x80      //GPIO7

/* GPIO_read I2C addr */

#define CH423_RD_IO_CMD		0x4D	//GPIO_read I2C addr

// code
void CH423_WriteByte( unsigned short cmd );//Write
unsigned char CH423_ReadByte( void );    	//Read
#endif
