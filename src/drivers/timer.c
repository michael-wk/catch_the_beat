#include "timer.h"
#include "mem.h"
#include "gpio.h"

void timer_debug_init(void)
{
   // set pre div
   // set auto reload value
   // set downcounting
   // setting event generation to 1
   // setting SR to 0
   // enable interrupts
   // enable counting
   
   // setting prescaler
   REG(TIM3_Base_Addr + 0x28U) &= ~(0xFFFFU);
   REG(TIM3_Base_Addr + 0x28U) |= (47999U); // 48MHz / 48kHz = 1ms  

   // setting auto reload 
   REG(TIM3_Base_Addr + 0x2CU) &= ~(0xFFFFU);
   REG(TIM3_Base_Addr + 0x2CU) |= (100U); // 100 ms;

   // setting UG in EGR to 1 to re-init counter, take auto reload val
   REG(TIM3_Base_Addr + 0x14U) |= (1U << 0U);

   // reset SR UIF, clear interrupt
   REG(TIM3_Base_Addr + 0x10U) &= ~(1U);

   // set UIE interrupt enabled
   REG(TIM3_Base_Addr + 0x0CU) |= (1U << 0U);

   // set CEN
   REG(TIM3_Base_Addr) |= (1U << 0U);
}

/* Timer 3 interrupt handler
*/
void TIM3_Handler(void)
{
   // clear UIF
   REG(TIM3_Base_Addr + 0x10U) &= ~(1U);

   // toggling GPIO
   gpio_debug_toggle_pin();
}
