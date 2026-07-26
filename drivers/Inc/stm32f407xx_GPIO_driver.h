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
This is to configure Structure of a GPIO pin
*/
typedef struct
{
    uint8_t GPIO_PinNumber; /* This holds the pin number of the GPIO pin */
    uint8_t GPIO_PinMode; /* This holds the mode of the GPIO pin @GPIO_PIN_MODES*/
    uint8_t GPIO_PinSpeed; /* This holds the speed of the GPIO pin */
    uint8_t GPIO_PinPuPd; /* This holds the pull-up/pull-down configuration of the GPIO pin */
    uint8_t GPIO_PinOPType; /* This holds the output type of the GPIO pin */
    uint8_t GPIO_PinAltFunMode; /* This holds the alternate function mode of the GPIO pin */
} GPIO_PinConfig_t;

/*
This is to handle structure of GPIO pin
*/
typedef struct
{
    GPIO_RegDef_t *pGPIOx; /* This holds the base address of the GPIO port to which the pin belongs */
    GPIO_PinConfig_t GPIO_PinConfig; /* This holds the configuration of the GPIO pin */ 
} GPIO_Handle_t;

/*
GPIO API Requirements
1. Peripheral Clock Setup
2. Init and De-init
3. Data Read and Write
4. IRQ Configuration and ISR Handling
*/

/* peripheral clock setup */
void GPIO_PeriClockCtrl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/* GPIO init and de-init */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/* data read and write */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);

/* IRQ configuration and ISR handling */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
IRQ configuration and ISR handling
*/

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);

/*
@GPIO_PIN_MODES
GPIO pin possible modes
*/

#define GPIO_MODE_IN 0 /* GPIO pin input mode */
#define GPIO_MODE_OUT 1 /* GPIO pin output mode */
#define GPIO_MODE_ALTFN 2 /* GPIO pin alternate function mode */
#define GPIO_MODE_ANALOG 3 /* GPIO pin analog mode */   
#define GPIO_MODE_IT_FT 4 /* GPIO pin interrupt mode falling edge trigger */
#define GPIO_MODE_IT_RT 5 /* GPIO pin interrupt mode rising edge trigger */
#define GPIO_MODE_IT_RFT 6 /* GPIO pin interrupt mode rising/falling edge trigger */

/*
@GPIO_PIN_NUMBER
GPIO pin possible numbers
*/
#define GPIO_PIN_0 0 /* GPIO pin 0 */
#define GPIO_PIN_1 1 /* GPIO pin 1 */
#define GPIO_PIN_2 2 /* GPIO pin 2 */
#define GPIO_PIN_3 3 /* GPIO pin 3 */
#define GPIO_PIN_4 4 /* GPIO pin 4 */
#define GPIO_PIN_5 5 /* GPIO pin 5 */
#define GPIO_PIN_6 6 /* GPIO pin 6 */
#define GPIO_PIN_7 7 /* GPIO pin 7 */
#define GPIO_PIN_8 8 /* GPIO pin 8 */
#define GPIO_PIN_9 9 /* GPIO pin 9 */
#define GPIO_PIN_10 10 /* GPIO pin 10 */
#define GPIO_PIN_11 11 /* GPIO pin 11 */
#define GPIO_PIN_12 12 /* GPIO pin 12 */
#define GPIO_PIN_13 13 /* GPIO pin 13 */
#define GPIO_PIN_14 14 /* GPIO pin 14 */
#define GPIO_PIN_15 15 /* GPIO pin 15 */

/*
@GPIO_PIN_SPEED
GPIO pin possible output speeds
*/
#define GPIO_SPEED_LOW 0 /* GPIO pin low speed */
#define GPIO_SPEED_MEDIUM 1 /* GPIO pin medium speed */
#define GPIO_SPEED_FAST 2 /* GPIO pin fast speed */
#define GPIO_SPEED_HIGH 3 /* GPIO pin high speed */ 

/*
@GPIO_PIN_PUPD
GPIO pin possible pull-up/pull-down configurations
*/
#define GPIO_NO_PUPD 0 /* GPIO pin no pull-up/pull-down */
#define GPIO_PIN_PU 1 /* GPIO pin pull-up */
#define GPIO_PIN_PD 2 /* GPIO pin pull-down */   
/*
@GPIO_PinOPType
GPIO pin possible output types
*/
#define GPIO_OP_TYPE_PP 0 /* GPIO pin push-pull output type */
#define GPIO_OP_TYPE_OD 1 /* GPIO pin open-drain output type */
#define GPIO_OP_TYPE_AF 2 /* GPIO pin alternate function output type */
#define GPIO_OP_TYPE_ANALOG 3 /* GPIO pin analog output type */ 
#define GPIO_OP_TYPE_IT 4 /* GPIO pin interrupt output type */

/*
@GPIO_PinAltFunMode
GPIO pin possible alternate function modes
*/

#define GPIO_AF0 0 /* GPIO pin alternate function mode 0 */
#define GPIO_AF1 1 /* GPIO pin alternate function mode 1 */
#define GPIO_AF2 2 /* GPIO pin alternate function mode 2 */
#define GPIO_AF3 3 /* GPIO pin alternate function mode 3 */
#define GPIO_AF4 4 /* GPIO pin alternate function mode 4 */
#define GPIO_AF5 5 /* GPIO pin alternate function mode 5 */
#define GPIO_AF6 6 /* GPIO pin alternate function mode 6 */
#define GPIO_AF7 7 /* GPIO pin alternate function mode 7 */
#define GPIO_AF8 8 /* GPIO pin alternate function mode 8 */
#define GPIO_AF9 9 /* GPIO pin alternate function mode 9 */
#define GPIO_AF10 10 /* GPIO pin alternate function mode 10 */
#define GPIO_AF11 11 /* GPIO pin alternate function mode 11 */
#define GPIO_AF12 12 /* GPIO pin alternate function mode 12 */
#define GPIO_AF13 13 /* GPIO pin alternate function mode 13 */
#define GPIO_AF14 14 /* GPIO pin alternate function mode 14 */
#define GPIO_AF15 15 /* GPIO pin alternate function mode 15 */