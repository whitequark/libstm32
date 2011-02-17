TUPLE   = arm-none-eabi-

AS      = $(TUPLE)as
AR      = $(TUPLE)ar crs

all: lib/libstm32.a

lib/libstm32.a: src/init.o
	$(AR) $@ $^

%.o: %.s
	$(AS) -o $@ $<

.PHONY: clean
clean:
	rm -f src/*.o lib/*.a
