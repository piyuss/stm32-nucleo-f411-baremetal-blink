#include <stdint.h>

extern uint32_t _sdata, _edata, _sbss, _ebss, _sidata, _estack;

int main(void);

void Reset_Handler(void)
{
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;
    while (dst < &_edata) *dst++ = *src++;

    dst = &_sbss;
    while (dst < &_ebss) *dst++ = 0;

    main();

    while (1) { }
}

void Default_Handler(void)
{
    while (1) { }
}

__attribute__((section(".isr_vector")))
uint32_t *vector_table[] = {
    (uint32_t *)&_estack,
    (uint32_t *)Reset_Handler,
    (uint32_t *)Default_Handler,  // NMI
    (uint32_t *)Default_Handler,  // HardFault
};
