LIBSTM32 = ../
TUPLE    = arm-none-eabi-

CC      = $(TUPLE)gcc
LD      = $(TUPLE)ld
SIZE    = $(TUPLE)size

CFLAGS  = -mcpu=cortex-m3 -mthumb -Wall -Werror -Wno-unused -g -fno-hosted --std=gnu99 -Os -I$(LIBSTM32)/include
LDFLAGS = -nostdlib -L$(LIBSTM32)/lib -Tstm32f100rb.ld -lstm32

OBJECTS = main.o

all: firmware.elf

firmware.elf: $(OBJECTS)
	$(LD) -o $@ $^ $(LDFLAGS)
	$(SIZE) $@

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm -f firmware.elf *.o
