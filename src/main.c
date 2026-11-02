#include "drivers/clock.h"
#include "drivers/interrupt.h"
#include "drivers/gpio.h"
#include "drivers/timer.h"

int main()
{
    
    // enable clock
    clock_init();
    clock_peripherals_enable();

    // enable interrupts
    interrupt_peripherals_enable();

    // enable GPIO debug pins
    gpio_debug_init();
    gpio_debug_toggle_pin();
    //gpio_debug_toggle_pin();

    timer_debug_init();
    for(;;);
}

