#include "drivers/clock.h"


int main()
{
    
    clock_init();
    clock_peripherls_enable();

    for(;;);
}

