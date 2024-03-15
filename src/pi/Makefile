CC := riscv64-unknown-elf-gcc 
CFLAGS=-fno-builtin -Wno-pointer-to-int-cast -Wall -Wextra -c -mcmodel=medany

RTSDIR = rts
RTSSOURCES := $(shell find $(RTSDIR) -name '*.c')
RTSOBJS:= $(RTSSOURCES:%.c=%.o)

PCDIR= pc
PCSOURCES := $(shell find $(PCDIR) -name '*.s')
PCOBJS:= $(PCSOURCES:%.s=%.o)

all:
	$(MAKE) -C rts
	$(MAKE) -C pc
	cp pc/kernel.c kernel.c
	${CC} ${CFLAGS} kernel.c -o kernel.o -ffreestanding
	riscv64-unknown-elf-ld -T pc/cbits/linker.ld -nostdlib kernel.o  $(PCOBJS) $(RTSOBJS) -o kernel.elf


clean:	
	$(MAKE) clean -C rts
	$(MAKE) clean -C pc
	rm *.o *.elf kernel.c
