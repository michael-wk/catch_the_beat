#ifndef _GPIO_
#define _GPIO_


/* Sets up debug pin (PA0) as GPIO out to blink test LED
*/ 
void gpio_debug_init(void);

/* Toggles GPIO PA0 high or low depending on current state
*/ 
void gpio_debug_toggle_pin(void);

#endif
