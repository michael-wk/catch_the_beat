#include "clock.h"
#include "mem.h"

void clock_init(void)
{
    // clock initialization sequence:
    // wait for HSIRDY
    // PLLON low, wait for PLLRDY cleared
    // HSI as PLLSRC ,PLLMUL as 12
    // set PLLON high, wait for PLLRDY
    // PPLCLK as SYSCLK
    // hpre nd ppre as 1
    
    // HSI on
    REG(RCC_Base_Addr) |= (1U << 0U);
    while (!(REG(RCC_Base_Addr) & (1U << 1U)));

    // PLL off
    REG(RCC_Base_Addr) &= ~(1U << 24U);
    while (REG(RCC_Base_Addr) & (1U << 25U));

    // PLL configure (PLLSRC = HSI RC)
    REG(RCC_Base_Addr + 0x04U) &= ~(3U << 15U);
    REG(RCC_Base_Addr + 0x04U) |= (1U << 15U);

    // PLL configure (PLLMUL = x12)
    REG(RCC_Base_Addr + 0x04U) &= ~(0xFU << 18U);
    REG(RCC_Base_Addr + 0x04U) |= (10U << 18U);

    // PLL on back on
    REG(RCC_Base_Addr) |= (1U << 24U);
    while (!(REG(RCC_Base_Addr) & (1U << 25U)));

    // PLLCLK as SYSCLK source (SW: b10, SWS b10)
    REG(RCC_Base_Addr + 0x04U) &= ~(3U << 0U);
    REG(RCC_Base_Addr + 0x04U) |= (2U << 0U);

}


void clock_peripherals_enable(void)
{
    // TIM3 enable
    REG(RCC_Base_Addr + 0x1CU) |= (1U << 1U);

    // GPIOA enable
    REG(RCC_Base_Addr + 0x14U) |= (1U << 17U);

    // GPIOC enable
    REG(RCC_Base_Addr + 0x14U) |= (1U << 19U);

}


