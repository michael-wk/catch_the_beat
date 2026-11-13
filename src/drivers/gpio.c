#include "gpio.h"
#include <stdint.h>
#include "mem.h"


// GPIO HAL:
void gpio_init(uint8_t pin_info, GPIO_Mode mode)
{
    uint8_t pin_num = GPIO_PIN(pin_info);
    GPIO_Type* gpio = GPIO(GPIO_BANK(pin_info));
    gpio->MODER &= (3U << (pin_num * 2));
    gpio->MODER |= (mode << (pin_num * 2));
}

// LED driver:
void led_init(void)
{
    gpio_init(MATRIX_C0, OUTPUT);
    gpio_init(MATRIX_C1, OUTPUT);
    gpio_init(MATRIX_C2, OUTPUT);
    gpio_init(MATRIX_C3, OUTPUT);
}






// DEBUG / TESTING FUNCTIONS:
//===========================================================================

/* Initializes GPIO pins for 2x1 matrix debug:
 * PA0  - a (column 0) GPIO out
 * PA1  - b (column 1) GPIO out
 * PC0  - b (row 0 NPN base GPIO out)
 * PC1  - c (row 1 NPN base GPIO out)
*/ 
void gpio_debug_matrix_init()
{
    m_info.s = 0;
   //PA0
   REG(GPIO_Base_Addr) &= ~(3U << 0U); // clear
   REG(GPIO_Base_Addr) |= (1U << 0U); // MODER GPOut
   //PA1
   REG(GPIO_Base_Addr) &= ~(3U << (1U * 2U)); // clear
   REG(GPIO_Base_Addr) |= (1U << (1U * 2U)); // MODER GPOut
   //PC0
   REG(GPIO_Base_Addr + 0x800U) &= ~(3U << 0U); // clear
   REG(GPIO_Base_Addr + 0x800U) |= (1U << 0U); // MODER GPOut
   //PC1
   //REG(GPIO_Base_Addr + 0x800U) &= ~(3U << (1U * 2U)); // clear
   //REG(GPIO_Base_Addr + 0x800U) |= (1U << (1U * 2U)); // MODER GPOut
}


void gpio_debug_matrix_toggle()
{
    if (m_info.s == 0)
    {
        REG(GPIO_Base_Addr + 0x18U) |= (0x1U << 16U);
        REG(GPIO_Base_Addr + 0x18U) |= (0x1U << 17U);
        REG(GPIO_Base_Addr + 0x800U + 0x18U) |= (0x1U << 16U);
    }
    else if (m_info.s == 1)
    {
        REG(GPIO_Base_Addr + 0x18U) |= (0x1U << 0U);
        REG(GPIO_Base_Addr + 0x18U) |= (0x1U << 1U);
        REG(GPIO_Base_Addr + 0x800U + 0x18U) |= (0x1U << 16U);
    }
    else if (m_info.s == 2)
    {
        REG(GPIO_Base_Addr + 0x18U) |= (0x1U << 0U);
        REG(GPIO_Base_Addr + 0x18U) |= (0x1U << 17U);
        REG(GPIO_Base_Addr + 0x800U + 0x18U) |= (0x1U << 0U);
    }
    else if (m_info.s == 3)
    {
        REG(GPIO_Base_Addr + 0x18U) |= (0x1U << 0U);
        REG(GPIO_Base_Addr + 0x18U) |= (0x1U << 1U);
        REG(GPIO_Base_Addr + 0x800U + 0x18U) |= (0x1U << 0U);
    }

    m_info.s++;
    if (m_info.s > 3) 
    {
        m_info.s = 0;
    }
}

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


//void gpio_debug_matrix_toggle(uint8_t row, uint8_t column)
//{
//    // will hard code this for the test just to test the wiring,
//
//    switch(row)
//    {
//        case 0:
//            // toggle PA0 high
//  `          REG(GPIO_Base_Addr + 0x18U) |= (0x1U << 16U);
//            break;
//        case 1:
//            // toggle PA1 high;
//            REG(GPIO_Base_Addr + 0x18U) |= (0x1U << 17U);
//            break;
//    }
//    
//    switch (column)
//    {
//        case 0:
//            // toggle PC0 high;
//            REG(GPIO_Base_Addr + 0x800U + 0x18U) |= (0x1U << 16U);
//            break;
//        case 1:
//            // toggle PC1 high;
//            REG(GPIO_Base_Addr + 0x800U + 0x18U) |= (0x1U << 17U);
//            break;
//    }
//}


