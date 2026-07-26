#include "stm32f407xx_GPIO_driver.h"
#include "stm32f407xx.h"

/*
some generic macros
*/

#define ENABLE 1
#define DISABLE 0
#define SET ENABLE
#define RESET DISABLE
#define GPIO_PIN_SET SET
#define GPIO_PIN_RESET RESET

/*
GPIO API Requirements
1. Peripheral Clock Setup
2. Init and De-init
3. Data Read and Write
4. IRQ Configuration and ISR Handling
*/

/*
 * @brief Maps a GPIO peripheral base address to its RCC clock enable index.
 * @param pGPIOx Pointer to the GPIO port register block.
 * @return Port index used for clock control; returns 8 for unknown ports.
 */
static uint8_t GPIO_GetPortCode(GPIO_RegDef_t *pGPIOx)
{
    if (pGPIOx == GPIOA) return 0;
    if (pGPIOx == GPIOB) return 1;
    if (pGPIOx == GPIOC) return 2;
    if (pGPIOx == GPIOD) return 3;
    if (pGPIOx == GPIOE) return 4;
    if (pGPIOx == GPIOF) return 5;
    if (pGPIOx == GPIOG) return 6;
    if (pGPIOx == GPIOH) return 7;
    return 8;
}

/*
 * @brief Enables or disables the peripheral clock for a given GPIO port.
 * @param pGPIOx Pointer to the GPIO port register block.
 * @param EnorDi Enable or disable value (ENABLE or DISABLE).
 * @return None.
 */
void GPIO_PeriClockCtrl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        if(pGPIOx == GPIOA)
        {
            GPIOA_PCLK_EN() ;
        }
        else if(pGPIOx == GPIOB)
        {
            GPIOB_PCLK_EN() ;
        }
        else if(pGPIOx == GPIOC)
        {
            GPIOC_PCLK_EN() ;
        }
        else if(pGPIOx == GPIOD)
        {
            GPIOD_PCLK_EN() ;
        }
        else if(pGPIOx == GPIOE)
        {
            GPIOE_PCLK_EN() ;
        }
        else if(pGPIOx == GPIOF)
        {
            GPIOF_PCLK_EN() ;
        }
        else if(pGPIOx == GPIOG)
        {
            GPIOG_PCLK_EN() ;
        }
        else if(pGPIOx == GPIOH)
        {
            GPIOH_PCLK_EN() ;
        }
    }
    else
    {
        // Disable the clock for the specified GPIO port
    }

}

/*
 * @brief Initializes a GPIO pin using the configuration stored in the handle.
 * @param pGPIOHandle Pointer to the GPIO handle containing port and pin settings.
 * @return None.
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
    //configure the mode of GPIO pin
    uint32_t temp = 0; // Temporary variable to hold register values
    if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
    {
        // Configure the pin mode (input, output, alternate function, analog)
    temp = ((pGPIOHandle->GPIO_PinConfig.GPIO_PinMode) << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); // Clear the bits 
    pGPIOHandle->pGPIOx->MODER |= temp;
    }
    else
    {
        // Configure the pin for interrupt mode (falling edge, rising edge, both)
    }
    temp = 0;
    //configure the speed
    temp = ((pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed) << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); // Clear the bits

    pGPIOHandle->pGPIOx->OSPEEDR |= temp;
    temp = 0;
    //configure the pull-up/pull-down
    temp = ((pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPd) << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); // Clear the bits
    pGPIOHandle->pGPIOx->PUPDR |= temp;
    //configure the output type
    temp = ((pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType) << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); // Clear the bit
    pGPIOHandle->pGPIOx->OTYPER |= temp;
    temp = 0;
    //configure the alternate functionality
    if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
    {
        //configure the alternate function registers
        uint8_t temp1, temp2;
        temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
        temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
        pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2)); // Clear the bits
        pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
    }
    
}

/*
 * @brief Resets the selected GPIO peripheral.
 * @param pGPIOx Pointer to the GPIO port register block.
 * @return None.
 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
        if(pGPIOx == GPIOA)
        {
            GPIOA_PCLK_DI();
        }
        else if(pGPIOx == GPIOB)
        {
            GPIOB_PCLK_DI() ;
        }
        else if(pGPIOx == GPIOC)
        {
            GPIOC_PCLK_DI() ;
        }
        else if(pGPIOx == GPIOD)
        {
            GPIOD_PCLK_DI() ;
        }
        else if(pGPIOx == GPIOE)
        {
            GPIOE_PCLK_DI() ;
        }
        else if(pGPIOx == GPIOF)
        {
            GPIOF_PCLK_DI() ;
        }
        else if(pGPIOx == GPIOG)
        {
            GPIOG_PCLK_DI() ;
        }
        else if(pGPIOx == GPIOH)
        {
            GPIOH_PCLK_DI() ;
        } 
}

/*
 * @brief Reads the current state of a GPIO input pin.
 * @param pGPIOx Pointer to the GPIO port register block.
 * @param PinNumber GPIO pin number to read.
 * @return 1 if the pin is high, 0 if the pin is low.
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
    uint8_t bitvalue = 0;
    bitvalue = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);
    return bitvalue;
}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
    uint16_t portvalue = 0;
    portvalue = (uint16_t)(pGPIOx->IDR);
    return portvalue;
}
/*
 * @brief Writes a value to a GPIO output pin.
 * @param pGPIOx Pointer to the GPIO port register block.
 * @param PinNumber GPIO pin number to modify.
 * @param Value Value to write: 0 or 1.
 * @return Status value for the operation.
 */
uint16_t GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
    if(Value == GPIO_PIN_SET)
    {
        //write 1 to the output data register at the bit field corresponding to the pin number
        pGPIOx->ODR |= (1 << PinNumber);
    }
    else
    {
        //write 0 to the output data register at the bit field corresponding to the pin number
        pGPIOx->ODR &= ~(1 << PinNumber); //clear the bit field corresponding to the pin number
    }
    return 0;

}

/*
 * @brief Configures the interrupt state for a GPIO IRQ number.
 * @param IRQNumber Interrupt number to configure.
 * @param EnorDi Enable or disable value (ENABLE or DISABLE).
 * @return None.
 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{
}

/*
 * @brief Handles the IRQ for the selected GPIO pin.
 * @param PinNumber GPIO pin number that generated the interrupt.
 * @return None.
 */
void GPIO_IRQHandling(uint8_t PinNumber)
{
}

/*
 * @brief Toggles the current state of a GPIO output pin.
 * @param pGPIOx Pointer to the GPIO port register block.
 * @param PinNumber GPIO pin number to toggle.
 * @return None.
 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
}