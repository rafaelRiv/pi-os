CC := riscv64-unknown-elf-gcc 
CFLAGS=-fno-builtin -Wno-pointer-to-int-cast -Wall -Wextra -c -mcmodel=medany

RTSDIR = rts
RTSSOURCES := $(shell find $(RTSDIR) -name '*.c')
RTSOBJS:= $(RTSSOURCES:%.c=%.o)

PCBOOTDIR= pcboot
PCBOOTSOURCES := $(shell find $(PCBOOTDIR) -name '*.s')
PCBOOTOBJS:= $(PCBOOTSOURCES:%.s=%.o)

.PHONY: tests

all:
	$(MAKE) -C rts
	$(MAKE) -C pcboot
	$(MAKE) -C pc
	cp pc/kernel.c kernel.c
	${CC} ${CFLAGS} kernel.c -o kernel.o -ffreestanding
	riscv64-unknown-elf-ld -T pcboot/linker.ld -nostdlib kernel.o  $(PCBOOTOBJS) $(RTSOBJS) -o kernel.elf

tests:
	$(MAKE) -C rts
	$(MAKE) -C pcboot
	$(MAKE) -C pc
	cp tests/kernel-tests.c kernel-tests.c
	${CC} ${CFLAGS} kernel-tests.c -o kernel-tests.o -ffreestanding
	riscv64-unknown-elf-ld -T pcboot/linker.ld -nostdlib kernel-tests.o  $(PCBOOTOBJS) $(RTSOBJS) -o kernel-tests.elf

clean:	
	$(MAKE) clean -C rts
	$(MAKE) clean -C pcboot
	$(MAKE) clean -C h
	$(MAKE) clean -C pc
	$(MAKE) clean -C tests
	rm -f *.o *.elf *.c || true
