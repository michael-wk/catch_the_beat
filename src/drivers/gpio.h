#ifndef _GPIO_
#define _GPIO_

#include <stdint.h>

// LED matrix GPIO debug (2x1 matrix)
//==========================================================
static struct
{
    volatile uint8_t a;
} matrix_debug;

/* Initializes GPIO pins for 2x1 matrix debug:
 * PA0  - a (column 0) GPIO out
 * PA1  - b (column 1) GPIO out
 * PC0  - b (row 0 NPN base GPIO out)
 * PC1  - c (row 1 NPN base GPIO out)
*/ 
void gpio_debug_matrix_init();

void gpio_debug_matrix_toggle(uint8_t row, uint8_t column);



// Basic GPIO Debug (LED blink:)
//==========================================================
static struct
{
    volatile uint8_t set;
} gpio_debug;

/* Sets up debug pin (PA0) as GPIO out to blink test LED
*/ 
void gpio_debug_init(void);

/* Toggles GPIO PA0 high or low depending on current state
*/ 
void gpio_debug_toggle_pin(void);

#endif
