#include "gpio.h"
#include <stdint.h>
#include "mem.h"

static struct
{
    volatile uint8_t set;
} gpio_debug;


void gpio_debug_init(void)
{
   REG(GPIO_Base_Addr) &= ~(3U << 0U); // clear
   REG(GPIO_Base_Addr) |= (1U << 0U); // MODER GPOut
    
   gpio_debug.set = 0;
}

void gpio_debug_toggle_pin(void)
{
    if (gpio_debug.set) // toggle off
    {
        REG(GPIO_Base_Addr + 0x18U) |= (0x1U << 16U);
        gpio_debug.set = 0;
    } else // toggle on
    {
        REG(GPIO_Base_Addr + 0x18U) |= (0x1U << 0U);
        gpio_debug.set = 1;
    }
}
