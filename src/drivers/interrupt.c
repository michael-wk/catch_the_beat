#include "interrupt.h"

void interrupt_peripherals_enable()
{
    // enable interrupts for TIM3 (Position 16)  (ISER)
    REG(NVIC_Base_Addr + 0x100U) |= (0x1U << 16);

}
