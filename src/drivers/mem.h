#ifndef _MEM_
#define _MEM_

#include <stdint.h>

// util definitions
#define REG(addr) (*(volatile uint32_t*)(addr))

// address definitions
#define RCC_Base_Addr 0x40021000U
#define NVIC_Base_Addr 0xE000E000U
#define GPIO_Base_Addr 0x48000000U
#define TIM3_Base_Addr 0x40000400U


#endif
