TUPLE   = arm-none-eabi-

AS      = $(TUPLE)as
AR      = $(TUPLE)ar crs
CC      = $(TUPLE)cc

CFLAGS  = -mcpu=cortex-m3 -mthumb -Wall -Werror -fno-hosted --std=gnu99 -Os -Iinclude

all: lib/libstm32.a

lib/libstm32.a: src/init.o src/rand.o src/memset.o
	$(AR) $@ $^

%.o: %.s
	$(AS) -o $@ $<

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm -f src/*.o lib/*.a
