MAKEFLAGS = -r

TRIPLE   ?= arm-none-eabi
TUPLE    ?= $(TRIPLE)-

CFLAGS    = -g -Wall -Werror -Iinclude \
	-nostdlib -ffreestanding -std=c99 \
	-march=armv7-m -mthumb

ifeq ($(BUILD_LIBSTM32),)
	CFLAGS     += -I$(LIBSTM32)/include
	LDFLAGS     = -L$(LIBSTM32)/lib -lstm32
	FIN_LDFLAGS = -L$(LIBSTM32)/lib -L$(LIBSTM32)/lib/scripts -T$(DEVICE).ld
endif

ifneq ($(CLANG),)
	CFLAGS    += -flto -Os -ccc-host-triple $(TRIPLE)
	LLVM      ?= /usr/lib/llvm-3.0

	CC         = clang
	LLD        = $(LLVM)/bin/llvm-ld
	LLC        = $(LLVM)/bin/llc
	LD         = $(TUPLE)ld
	AS         = $(TUPLE)as
	AR         = $(LLVM)/bin/llvm-ar
	RANLIB     = $(LLVM)/bin/llvm-ranlib
	SIZE       = $(LLVM)/bin/llvm-size

.SECONDEXPANSION:
%.elf: $$($$(subst .elf,,$$@)-objects)
	$(LLD) -o $(@:.elf=.llvm) $< $(LDFLAGS)
	$(LLC) $(@:.elf=.llvm.bc)
	$(AS) -o $(@:.elf=.llvm.elf) $(@:.elf=.llvm.s)
	$(LD) -o $@ $(@:.elf=.llvm.elf) $(FIN_LDFLAGS)
	$(RM) $(@:.elf=.llvm)*
	$(SIZE) $@

else
	CFLAGS    += -Os

	CC         = $(TUPLE)gcc
	LD         = $(TUPLE)ld
	AS         = $(TUPLE)as
	AR         = $(TUPLE)ar
	RANLIB     = $(TUPLE)ranlib
	SIZE       = $(TUPLE)size

.SECONDEXPANSION:
%.elf: $$($$(subst .elf,,$$@)-objects)
	$(LD) -o $@ $< $(LDFLAGS) $(FIN_LDFLAGS)
	$(SIZE) $@

endif

%.o: %.s
	$(AS) -o $@ $<

%.o: %.c
	$(CC) -o $@ $< -c $(CFLAGS)