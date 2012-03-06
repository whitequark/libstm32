BUILD_LIBSTM32 = yes

include Makefile.inc

all: lib/libstm32.a $(patsubst %.s,%.o,src/init.o $(wildcard src/soc/*))
	cp src/init.o src/soc/*.o lib/

lib/libstm32.a: src/rand.o src/memset.o
	$(AR) crs $@ $^

generate:
	tools/genreg.rb -d include/stm32 -- tools/def/*

.PHONY: clean distclean
clean:
	rm -f src/*.o src/soc/*.o lib/*.a lib/*.o

distclean:
	rm -f include/stm32/*.h