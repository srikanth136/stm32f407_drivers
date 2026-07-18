/*
 * stm32f407xx.h
 *
 *  Created on: Jun 23, 2026
 *      Author: srikanth
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

// base adress of SRAM and flash memory
#define flash_memory_baseAddress = 0x08000000U /* Base address of flash memory */
#define SRAM1_baseAddress = 0x20000000U /* Base address of SRAM1 */
#define SRAM2_baseAddress = 0x2001C000U /* Base address of SRAM2 */
#define ROM_baseAddress = 0x1FFF0000U /* Base address of ROM */
#define SRAM = SRAM1_baseAddress /* Alias for SRAM1 */

/*
 Different bus domains of the stm32f407xx MCU 
 Preiph_Base Types: APB1, APB2, AHB1, AHB2
 1.Differennt peripherals are hanging on different bus domains. 
 The base address of the peripheral is calculated based on the bus domain it is hanging on. 
 2. AHB BUS are used for high speed peripherals and APB bus are used for low speed peripherals.
 3. from here onwards peripheral Register adresses will be defnied : 0x40000000U to 0x5FFFFFFFU
 4. the peripher at 0x40000000U is Timer 2
 5. by adding the offset of the peripheral to the base address of the bus domain, we can get the base address of the peripheral.
 6. the offset of the APB2 and AHB1 and AHB2 peripherals are 0x0010000, 0x00020000, 0x00010000 respectively.
 

 */

 /*
 base address of APBx and AHBx bus domains
 */

 #define APB1_baseAddress = 0x40000000U /* Base address of APB1 bus domain */
 #define APB2_baseAddress = 0x40010000U /* Base address of APB2 bus domain */
 #define AHB1_baseAddress = 0x40020000U /* Base address of AHB1 bus domain */
 #define AHB2_baseAddress = 0x50000000U /* Base address of AHB2 bus domain */

 /* 
 Base address of peripherals hanging on AHB1 bus domain
 */

 #define GPIOA_baseAddress = (AHB1_baseAddress + 0x0000U) /* Base address of GPIOA peripheral */
 #define GPIOB_baseAddress = (AHB1_baseAddress + 0x0400U) /* Base address of GPIOB peripheral */
 #define GPIOC_baseAddress = (AHB1_baseAddress + 0x0800U) /* Base address of GPIOC peripheral */
 #define GPIOD_baseAddress = (AHB1_baseAddress + 0x0C00U) /* Base address of GPIOD peripheral */
 #define GPIOE_baseAddress = (AHB1_baseAddress + 0x1000U) /* Base address of GPIOE peripheral */
 #define GPIOE_baseAddress = (AHB1_baseAddress + 0x1400U) /* Base address of GPIOF peripheral */
 #define GPIOG_baseAddress = (AHB1_baseAddress + 0x1800U) /* Base address of GPIOG peripheral */
 #define GPIOH_baseAddress = (AHB1_baseAddress + 0x1C00U) /* Base address of GPIOH peripheral */  
 #define GPIOI_baseAddress = (AHB1_baseAddress + 0x2000U) /* Base address of GPIOI peripheral */  

 /* 
 Base address of peripherals hanging on APB1 bus domain
 Different peripherals usart and uart is UART4 and UART5 does not work asynchronously with the other usart and uart peripherals.
 */

 #define I2C1_baseAddress = (APB1_baseAddress + 0x5400U) /* Base address of I2C1 peripheral */
 #define I2C2_baseAddress = (APB1_baseAddress + 0x5800U) /* Base address of I2C2 peripheral */
 #define I2C3_baseAddress = (APB1_baseAddress + 0x5C00U) /* Base address of I2C3 peripheral */

 #define SPI2_baseAddress = (APB1_baseAddress + 0x3800U) /* Base address of SPI2 peripheral */
 #define SPI3_baseAddress = (APB1_baseAddress + 0x3C00U) /* Base address of SPI3 peripheral */

 #define USART2_baseAddress = (APB1_baseAddress + 0x4400U) /* Base address of USART2 peripheral */
 #define USART3_baseAddress = (APB1_baseAddress + 0x4800U) /* Base address of USART3 peripheral */
 #define UART4_baseAddress = (APB1_baseAddress + 0x4C00U) /* Base address of UART4 peripheral */    
 #define UART5_baseAddress = (APB1_baseAddress + 0x5000U) /* Base address of UART5 peripheral */


/* 
 Base address of peripherals hanging on APB2 bus domain
 */

 #define USART1_baseAddress = (APB2_baseAddress + 0x1000U) /* Base address of USART1 peripheral */
 #define USART6_baseAddress = (APB2_baseAddress + 0x1400U) /* Base address of USART6 peripheral */  
 #define syscfg_baseAddress = (APB2_baseAddress + 0x3800U) /* Base address of SYSCFG peripheral */
 #define EXTI_baseAddress = (APB2_baseAddress + 0x3C00U) /* Base address of EXTI peripheral */
 #define SPI1_baseAddress = (APB2_baseAddress + 0x3000U) /* Base address of SPI1 peripheral */

 

#endif /* INC_STM32F407XX_H_ */
