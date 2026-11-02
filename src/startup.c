#include <stdint.h>


// symbols defined in linker script
extern uint32_t _estack;
extern uint32_t _sdata, _edata, _sidata;
extern uint32_t _sbss, _ebss;
int main(void);


__attribute__((naked, noreturn))
void Reset_Handler(void)
{
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;

    // copy .data : Flash -> RAM
    while (dst < &_edata) *dst++ = *src++;

    // initialize bss to 0
    dst = &_sbss;
    while (dst < &_ebss) *dst++ = 0;

    main();
    for(;;);
}

void Default_Handler(void) { for(;;); }
void NMI_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void USART2_Handler(void)    __attribute__((weak, alias("Default_Handler")));

void TIM3_Handler(void) __attribute__((weak, alias("Default_Handler")));

__attribute__((section(".vectors")))
const uint32_t vector_table[] =
{
    [0]       = (uint32_t) &_estack,
    [1]       = (uint32_t) &Reset_Handler,
    [2]       = (uint32_t) &NMI_Handler,
    [3]       = (uint32_t) &HardFault_Handler,
    [16 + 16] = (uint32_t) &TIM3_Handler,      // IRQ 16, 0x80
    [16 + 28] = (uint32_t) &USART2_Handler,    // IRQ 28
    // TIM3 : 0x00000080
    //(uint32_t) &_estack,
    //(uint32_t) &Reset_Handler,
    //(uint32_t) &NMI_Handler,
    //(uint32_t) &HardFault_Handler,
    //0,0,0,0,0,0,0,0,0,0,
    //0,0,0,0,0,0,0,0,0,0,
    //0,0,0,0,0,0,0,0,
    //(uint32_t) &TIM3_Handler, // position 16 - 0x00000080
    //0,
    //0,0,0,0,0,0,0,0,0,0,
    //(uint32_t) &USART2_Handler
};


