CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

CFLAGS = -mcpu=cortex-m4 -mthumb -nostdlib -g -O0
LDFLAGS = -T linker.ld -nostdlib

all: firmware.bin

firmware.elf: main.c startup.c linker.ld
	$(CC) $(CFLAGS) $(LDFLAGS) main.c startup.c -o firmware.elf

firmware.bin: firmware.elf
	$(OBJCOPY) -O binary firmware.elf firmware.bin

flash: firmware.bin
	st-flash write firmware.bin 0x08000000

clean:
	rm -f firmware.elf firmware.bin
