/**
 * @file    system_stm32f4xx.c
 * @brief   System initialization for STM32F407 (FPU enable)
 */

#include <stdint.h>

#define SCB_CPACR (*(volatile uint32_t *)0xE000ED88UL)

void SystemInit(void)
{
    /* enable CP10 and CP11 full access for FPU */
    SCB_CPACR |= (0xFULL << 20);

    __asm volatile ("dsb");
    __asm volatile ("isb");
}
