#ifndef _MEM_
#define _MEM_

#include <stdint.h>

// util definitions
#define REG(addr) *(volatile uint32_t*)(addr)

// address definitions
#define RCC_Base_Addr 0x40021000U

#endif
