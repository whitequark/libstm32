LIBSTM32 = ../
DEVICE   = stm32f100rb

include $(LIBSTM32)/Makefile.inc

blinkie-objects = blinkie.o

all: blinkie.elf

.PHONY: clean
clean:
	rm -f *.elf *.o
