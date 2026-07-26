#include <stm32f407xx.h>
#include <stm32f407xx_GPIO_driver.h>

void delay(void)
{
    for (uint32_t i = 0; i < 500000; i++);
}

int main(void)
{
    // Your application code here
GPIO_Handle_t gpioLed;
gpioLed.pGPIOx = GPIOD; // Assuming the LED is connected to GPIOA
gpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_12; // Assuming the LED is connected to pin 12
gpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
gpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
gpioLed.GPIO_PinConfig.GPIO_PinPuPd = GPIO_NO_PUPD;
gpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;

GPIO_periClockCtrl(gpioLed.pGPIOx, ENABLE); // Enable the clock for the GPIO port
GPIO_Init(&gpioLed); // Initializeð the GPIO pin
GPIO_toggleOutputPin(GPIOD,GPIO_PIN_12); // Toggle the LED pin
    return 0;
}