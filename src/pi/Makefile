CC := riscv64-unknown-elf-gcc 
CFLAGS=-fno-builtin -Wno-pointer-to-int-cast -Wall -Wextra -c -mcmodel=medany

RTSDIR = rts
RTSSOURCES := $(shell find $(RTSDIR) -name '*.c')
RTSOBJS:= $(RTSSOURCES:%.c=%.o)

PCBOOTDIR= pcboot
PCBOOTSOURCES := $(shell find $(PCBOOTDIR) -name '*.s')
PCBOOTOBJS:= $(PCBOOTSOURCES:%.s=%.o)

all:
	$(MAKE) -C rts
	$(MAKE) -C pcboot
	$(MAKE) -C pc
	cp pc/kernel.c kernel.c
	${CC} ${CFLAGS} kernel.c -o kernel.o -ffreestanding
	riscv64-unknown-elf-ld -T pcboot/linker.ld -nostdlib kernel.o  $(PCBOOTOBJS) $(RTSOBJS) -o kernel.elf


clean:	
	$(MAKE) clean -C rts
	$(MAKE) clean -C pcboot
	$(MAKE) clean -C h
	$(MAKE) clean -C pc
	rm *.o *.elf kernel.c
