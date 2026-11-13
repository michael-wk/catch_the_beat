#ifndef _GPIO_
#define _GPIO_

#include <stdint.h>


/* GPIO Driver
 * 
 * 
*/

#define GPIO_Base 0x48000000U

// the pin info contains data of GPIO port & pin number
// bits 7:4 - gpio port     | A = 0, F = 6
// bits 3:0 - pin number    | 0 to 15
// ROWS:
#define MATRIX_C0 (uint8_t)((3U << 4U) & (2U))
#define MATRIX_C1 (uint8_t)((2U << 4U) & (12U))
#define MATRIX_C2 (uint8_t)((2U << 4U) & (11U))
#define MATRIX_C3 (uint8_t)((2U << 4U) & (10U))
// COLUMNS:
#define MATRIX_RA (uint8_t)(0U)
#define MATRIX_RB (uint8_t)(1U)
#define MATRIX_RC (uint8_t)(4U)
#define MATRIX_RD (uint8_t)((1U << 4U))
#define MATRIX_RE (uint8_t)((2U << 4U) & (1U))
#define MATRIX_RF (uint8_t)((2U << 4U))

// Matrix Row & Position getter macros.

// Matrix Row & Position getter macros.
#define MATRIX_RC

// Matrix Row & Position getter macros.
#define MATRIX_RC

// Matrix Row & Position getter macros.

// Matrix Row & Position getter macros.
#define MATRIX_RC

// Matrix Row & Position getter macros.
#define MATRIX_RC

// Matrix Row & Position getter macros.

// Matrix Row & Position getter macros.
#define MATRIX_ROW(p) ((uint8_t)(p >> 4))
#define MATRIX_COLUMN(p) ((uint8_t)(p & 0xFU))

// initializes the GPIOs of LED matrix
void led_init(void);

/* Toggles passed rows on passed column of the matrix
 * - bits 0:3 - row data
 * - bits 4:7 - column data
*/ 
void led_toggle_column(uint8_t position);


void led_clear_column(uint8_t column);


// LED matrix GPIO DEBUG AND EXPERIMENT: (2x1 matrix)
//==========================================================

static struct {
    int s;
} m_info;
/* Initializes GPIO pins for 2x1 matrix debug:
 * PA0  - a (column 0) GPIO out
 * PA1  - b (column 1) GPIO out
 * PC0  - b (row 0 NPN base GPIO out)
 * PC1  - c (row 1 NPN base GPIO out)
*/ 
void gpio_debug_matrix_init();

void gpio_debug_matrix_toggle();

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
