/*
 * stm32f407xx.h
 *
 *  Created on: Jun 23, 2026
 *      Author: srikanth
 */


#include <stdint.h>

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>

// base adress of SRAM and flash memory
#define flash_memory_baseAddress 0x08000000U /* Base address of flash memory */
#define SRAM1_baseAddress 0x20000000U /* Base address of SRAM1 */
#define SRAM2_baseAddress 0x2001C000U /* Base address of SRAM2 */
#define ROM_baseAddress 0x1FFF0000U /* Base address of ROM */
#define SRAM SRAM1_baseAddress /* Alias for SRAM1 */

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

 #define APB1_baseAddress 0x40000000U /* Base address of APB1 bus domain */
 #define APB2_baseAddress 0x40010000U /* Base address of APB2 bus domain */
 #define AHB1_baseAddress 0x40020000U /* Base address of AHB1 bus domain */
 #define AHB2_baseAddress 0x50000000U /* Base address of AHB2 bus domain */

 /* 
 Base address of peripherals hanging on AHB1 bus domain
 */

 #define GPIOA_baseAddress (AHB1_baseAddress + 0x0000U) /* Base address of GPIOA peripheral */
 #define GPIOB_baseAddress (AHB1_baseAddress + 0x0400U) /* Base address of GPIOB peripheral */
 #define GPIOC_baseAddress (AHB1_baseAddress + 0x0800U) /* Base address of GPIOC peripheral */
 #define GPIOD_baseAddress (AHB1_baseAddress + 0x0C00U) /* Base address of GPIOD peripheral */
 #define GPIOE_baseAddress (AHB1_baseAddress + 0x1000U) /* Base address of GPIOE peripheral */
 #define GPIOF_baseAddress (AHB1_baseAddress + 0x1400U) /* Base address of GPIOF peripheral */
 #define GPIOG_baseAddress (AHB1_baseAddress + 0x1800U) /* Base address of GPIOG peripheral */
 #define GPIOH_baseAddress (AHB1_baseAddress + 0x1C00U) /* Base address of GPIOH peripheral */  
 #define GPIOI_baseAddress (AHB1_baseAddress + 0x2000U) /* Base address of GPIOI peripheral */  

/* Peripheral register definitions (typecasted to their register-definition structs) */
#define GPIOA ((GPIO_RegDef_t *)GPIOA_baseAddress) /* GPIOA peripheral register definition structure */
#define GPIOB ((GPIO_RegDef_t *)GPIOB_baseAddress) /* GPIOB peripheral register definition structure */
#define GPIOC ((GPIO_RegDef_t *)GPIOC_baseAddress) /* GPIOC peripheral register definition structure */
#define GPIOD ((GPIO_RegDef_t *)GPIOD_baseAddress) /* GPIOD peripheral register definition structure */
#define GPIOE ((GPIO_RegDef_t *)GPIOE_baseAddress) /* GPIOE peripheral register definition structure */
#define GPIOF ((GPIO_RegDef_t *)GPIOF_baseAddress) /* GPIOF peripheral register definition structure */
#define GPIOG ((GPIO_RegDef_t *)GPIOG_baseAddress) /* GPIOG peripheral register definition structure */
#define GPIOH ((GPIO_RegDef_t *)GPIOH_baseAddress) /* GPIOH peripheral register definition structure */
#define GPIOI ((GPIO_RegDef_t *)GPIOI_baseAddress) /* GPIOI peripheral register definition structure */

#define RCC_baseAddress (AHB1_baseAddress + 0x3800U) /* Base address of RCC peripheral */   

#define RCC ((RCC_RegDef_t *)RCC_baseAddress) /* RCC peripheral register definition structure */

/* 
 clock Enable Macoros for GPIOx peripherals
 1. The clock enable macros are used to enable the clock for the GPIOx peripherals.
*/

#define GPIOA_PCLK_EN() (RCC->AHB1ENR |= (1 << 0)) /* Enable clock for GPIOA peripheral */
#define GPIOB_PCLK_EN() (RCC->AHB1ENR |= (1 << 1)) /* Enable clock for GPIOB peripheral */
#define GPIOC_PCLK_EN() (RCC->AHB1ENR |= (1 << 2)) /* Enable clock for GPIOC peripheral */
#define GPIOD_PCLK_EN() (RCC->AHB1ENR |= (1 << 3)) /* Enable clock for GPIOD peripheral */
#define GPIOE_PCLK_EN() (RCC->AHB1ENR |= (1 << 4)) /* Enable clock for GPIOE peripheral */
#define GPIOF_PCLK_EN() (RCC->AHB1ENR |= (1 << 5)) /* Enable clock for GPIOF peripheral */
#define GPIOG_PCLK_EN() (RCC->AHB1ENR |= (1 << 6)) /* Enable clock for GPIOG peripheral */
#define GPIOH_PCLK_EN() (RCC->AHB1ENR |= (1 << 7)) /* Enable clock for GPIOH peripheral */

 #define USB_OTG_FS_baseAddress (AHB2_baseAddress + 0x0000U) /* Base address of USB OTG FS peripheral */
 #define USB_OTG_HS_baseAddress (AHB2_baseAddress + 0x1000U) /* Base address of USB OTG HS peripheral */

/* 
 clock Enable Macoros for i2c peripherals
 1. The clock enable macros are used to enable the clock for the i2c peripherals.
*/

#define I2C1_PCLK_EN() (RCC->APB1ENR |= (1 << 21)) /* Enable clock for I2C1 peripheral */
#define I2C2_PCLK_EN() (RCC->APB1ENR |= (1 << 22)) /* Enable clock for I2C2 peripheral */
#define I2C3_PCLK_EN() (RCC->APB1ENR |= (1 << 23)) /* Enable clock for I2C3 peripheral */

/* 
 clock Enable Macoros for SPI peripherals
 1. The clock enable macros are used to enable the clock for the SPI peripherals.
*/
#define SPI1_PCLK_EN() (RCC->APB2ENR |= (1 << 12)) /* Enable clock for SPI1 peripheral */
#define SPI2_PCLK_EN() (RCC->APB1ENR |= (1 << 14)) /* Enable clock for SPI2 peripheral */
#define SPI3_PCLK_EN() (RCC->APB1ENR |= (1 << 15)) /* Enable clock for SPI3 peripheral */

/* 
 clock Enable Macoros for USARTx peripherals
 1. The clock enable macros are used to enable the clock for the USARTx peripherals.
*/

#define USART1_PCLK_EN() (RCC->APB2ENR |= (1 << 4)) /* Enable clock for USART1 peripheral */
#define USART2_PCLK_EN() (RCC->APB1ENR |= (1 << 17)) /* Enable clock for USART2 peripheral */
#define USART3_PCLK_EN() (RCC->APB1ENR |= (1 << 18)) /* Enable clock for USART3 peripheral */
#define UART4_PCLK_EN() (RCC->APB1ENR |= (1 << 19)) /* Enable clock for UART4 peripheral */
#define UART5_PCLK_EN() (RCC->APB1ENR |= (1 << 20)) /* Enable clock for UART5 peripheral */
#define USART6_PCLK_EN() (RCC->APB2ENR |= (1 << 5)) /* Enable clock for USART6 peripheral */

/*
    clock Enable Macoros for SYSCFG peripherals
    1. The clock enable macros are used to enable the clock for the SYSCFG peripherals.
*/

#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 14)) /* Enable clock for SYSCFG peripheral */
#define EXTI_PCLK_EN() (RCC->APB2ENR |= (1 << 10)) /* Enable clock for EXTI peripheral */   

/* 
 clock Disable Macoros for spi peripherals
 1. The clock enable macros are used to enable the clock for the i2c peripherals.
*/
#define SPI1_PCLK_DI() (RCC->APB2ENR &= ~(1 << 12)) /* Disable clock for SPI1 peripheral */
#define SPI2_PCLK_DI() (RCC->APB1ENR &= ~(1 << 14)) /* Disable clock for SPI2 peripheral */
#define SPI3_PCLK_DI() (RCC->APB1ENR &= ~(1 << 15)) /* Disable clock for SPI3 peripheral */ 


/* 
 clock Disable Macoros for i2c peripherals
 1. The clock enable macros are used to enable the clock for the i2c peripherals.
*/

#define I2C1_PCLK_DI() (RCC->APB1ENR &= ~(1 << 21)) /* Disable clock for I2C1 peripheral */
#define I2C2_PCLK_DI() (RCC->APB1ENR &= ~(1 << 22)) /* Disable clock for I2C2 peripheral */
#define I2C3_PCLK_DI() (RCC->APB1ENR &= ~(1 << 23)) /* Disable clock for I2C3 peripheral */
/* 
/* 
 clock Disable Macoros for USARTx peripherals
 1. The clock disable macros are used to disable the clock for the USARTx peripherals.
*/
#define USART1_PCLK_DI() (RCC->APB2ENR &= ~(1 << 4)) /* Disable clock for USART1 peripheral */
#define USART2_PCLK_DI() (RCC->APB1ENR &= ~(1 << 17)) /* Disable clock for USART2 peripheral */
#define USART3_PCLK_DI() (RCC->APB1ENR &= ~(1 << 18)) /* Disable clock for USART3 peripheral */
#define UART4_PCLK_DI() (RCC->APB1ENR &= ~(1 << 19)) /* Disable clock for UART4 peripheral */
#define UART5_PCLK_DI() (RCC->APB1ENR &= ~(1 << 20)) /* Disable clock for UART5 peripheral */
#define USART6_PCLK_DI() (RCC->APB2ENR &= ~(1 << 5)) /* Disable clock for USART6 peripheral */

/* 
 clock Enable Macoros for GPIOx peripherals
 1. The clock disable macros are used to enable the clock for the GPIOx peripherals.
*/
#define GPIOA_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 0)) /* Disable clock for GPIOA peripheral */
#define GPIOB_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 1)) /* Disable clock for GPIOB peripheral */
#define GPIOC_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 2)) /* Disable clock for GPIOC peripheral */
#define GPIOD_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 3)) /* Disable clock for GPIOD peripheral */
#define GPIOE_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 4)) /* Disable clock for GPIOE peripheral */
#define GPIOF_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 5)) /* Disable clock for GPIOF peripheral */
#define GPIOG_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 6)) /* Disable clock for GPIOG peripheral */
#define GPIOH_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 7)) /* Disable clock for GPIOH peripheral */    
#define GPIOI_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 8)) /* Disable clock for GPIOI peripheral */

/*
    clock Disable Macoros for SYSCFG peripherals
    1. The clock disable macros are used to disable the clock for the SYSCFG peripherals.
*/
#define SYSCFG_PCLK_DI() (RCC->APB2ENR &= ~(1 << 14)) /* Disable clock for SYSCFG peripheral */
#define EXTI_PCLK_DI() (RCC->APB2ENR &= ~(1 << 10)) /* Disable clock for EXTI peripheral */   

/*
 Base address of peripherals hanging on APB1 bus domain
 Different peripherals usart and uart is UART4 and UART5 does not work asynchronously with the other usart and uart peripherals.
 */

 #define I2C1_baseAddress (APB1_baseAddress + 0x5400U) /* Base address of I2C1 peripheral */
 #define I2C2_baseAddress (APB1_baseAddress + 0x5800U) /* Base address of I2C2 peripheral */
 #define I2C3_baseAddress (APB1_baseAddress + 0x5C00U) /* Base address of I2C3 peripheral */

 #define SPI2_baseAddress (APB1_baseAddress + 0x3800U) /* Base address of SPI2 peripheral */
 #define SPI3_baseAddress (APB1_baseAddress + 0x3C00U) /* Base address of SPI3 peripheral */

 #define USART2_baseAddress (APB1_baseAddress + 0x4400U) /* Base address of USART2 peripheral */
 #define USART3_baseAddress (APB1_baseAddress + 0x4800U) /* Base address of USART3 peripheral */
 #define UART4_baseAddress (APB1_baseAddress + 0x4C00U) /* Base address of UART4 peripheral */    
 #define UART5_baseAddress (APB1_baseAddress + 0x5000U) /* Base address of UART5 peripheral */


/* 
 Base address of peripherals hanging on APB2 bus domain
 */

 #define USART1_baseAddress (APB2_baseAddress + 0x1000U) /* Base address of USART1 peripheral */
 #define USART6_baseAddress (APB2_baseAddress + 0x1400U) /* Base address of USART6 peripheral */  
 #define syscfg_baseAddress (APB2_baseAddress + 0x3800U) /* Base address of SYSCFG peripheral */
 #define EXTI_baseAddress (APB2_baseAddress + 0x3C00U) /* Base address of EXTI peripheral */
 #define SPI1_baseAddress (APB2_baseAddress + 0x3000U) /* Base address of SPI1 peripheral */

 /*
 Peripheral register definition structures for GPIOx, RCC, EXTI and SYSCFG peripherals
 1. The peripheral register definition structures are defined in the header file of the peripheral.
 2. The peripheral register definition structures are used to access the peripheral registers.
 3. The peripheral register definition structures are defined in the header file of the peripheral.
 */

typedef struct
{
    volatile uint32_t MODER; /* GPIO port mode register */
    volatile uint32_t OTYPER; /* GPIO port output type register */
    volatile uint32_t OSPEEDR; /* GPIO port output speed register */
    volatile uint32_t PUPDR; /* GPIO port pull-up/pull-down register */
    volatile uint32_t IDR; /* GPIO port input data register */
    volatile uint32_t ODR; /* GPIO port output data register */
    volatile uint32_t BSRR; /* GPIO port bit set/reset register */
    volatile uint32_t LCKR; /* GPIO port configuration lock register */
    volatile uint32_t AFR[2]; /* GPIO alternate function registers */
} GPIO_RegDef_t;

GPIO_RegDef_t *pGPIOA = GPIOA;
GPIO_RegDef_t *pGPIOB = GPIOB;
GPIO_RegDef_t *pGPIOC = GPIOC;
GPIO_RegDef_t *pGPIOD = GPIOD;
GPIO_RegDef_t *pGPIOE = GPIOE;
GPIO_RegDef_t *pGPIOF = GPIOF;
GPIO_RegDef_t *pGPIOG = GPIOG;
GPIO_RegDef_t *pGPIOH = GPIOH;
GPIO_RegDef_t *pGPIOI = GPIOI;

/* GPIOA peripheral register definition structure */
typedef struct
{
    volatile uint32_t CR; /* RCC clock control register */
    volatile uint32_t PLLCFGR; /* RCC PLL configuration register */
    volatile uint32_t CFGR; /* RCC clock configuration register */
    volatile uint32_t CIR; /* RCC clock interrupt register */
    volatile uint32_t AHB1RSTR; /* RCC AHB1 peripheral reset register */
    volatile uint32_t AHB2RSTR; /* RCC AHB2 peripheral reset register */
    volatile uint32_t AHB3RSTR; /* RCC AHB3 peripheral reset register */
    uint32_t RESERVED0; /* Reserved */
    volatile uint32_t APB1RSTR; /* RCC APB1 peripheral reset register */
    volatile uint32_t APB2RSTR; /* RCC APB2 peripheral reset register */
    uint32_t RESERVED1[2]; /* Reserved */
    volatile uint32_t AHB1ENR; /* RCC AHB1 peripheral clock enable register */
    volatile uint32_t AHB2ENR; /* RCC AHB2 peripheral clock enable register */
    volatile uint32_t AHB3ENR; /* RCC AHB3 peripheral clock enable register */
    uint32_t RESERVED2; /* Reserved */
    volatile uint32_t APB1ENR; /* RCC APB1 peripheral clock enable register */
    volatile uint32_t APB2ENR; /* RCC APB2 peripheral clock enable register */
} RCC_RegDef_t;

RCC_RegDef_t *pRCC = RCC;



#endif /* INC_STM32F407XX_H_ */
