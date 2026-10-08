#ifndef _CLOCK_
#define _CLOCK_


/* Initializes RCC clock for APB peripherals to 48MHz
 * using HSI through PLL.
*/
 void clock_init(void);


void clock_peripherals_enable(void);

#endif

