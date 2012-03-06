LIBSTM32 = ../
DEVICE   = stm32f100rb

firmware-objects = main.o

include $(LIBSTM32)/Makefile.inc

all: firmware.elf

.PHONY: clean
clean:
	rm -f firmware.* *.o
