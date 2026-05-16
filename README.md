# Nucleo F411RE bare-metal blink

   Minimal bare-metal LED blink for the STM32 Nucleo-F411RE board, using
   no vendor libraries (no HAL, no CMSIS). The toolchain is `arm-none-eabi-gcc`
   on Linux.

   ## Hardware
   - Board: STM32 Nucleo-F411RE
   - LED: LD2, wired to PA5

   ## Files
   - `linker.ld` — memory layout
   - `startup.c` — vector table and reset handler
   - `main.c` — application code
   - `Makefile` — build and flash

   ## Build and flas
    make
    make flash

    Requires `arm-none-eabi-gcc` and `stlink-tools`.

   ## Notes
   - Flash is 512 KB at 0x08000000, RAM is 128 KB at 0x20000000.
   - Reset handler copies `.data` from flash to RAM and zeroes `.bss` before
     calling `main`.
   - The vector table is placed at the start of flash via the `.isr_vector`
     section, kept by the linker with `KEEP()`.
