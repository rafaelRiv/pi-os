CC := riscv64-unknown-elf-gcc 
AS := riscv64-unknown-elf-as 

CFLAGS=-fno-builtin -Wno-pointer-to-int-cast -Wall -Wextra -c -mcmodel=medany
RTSDIR = rts
RTSSOURCES := $(shell find $(RTSDIR) -name '*.c')
RTSOBJS:= $(RTSSOURCES:%.c=%.o)

PCDIR= pc
PCSOURCES := $(shell find $(PCDIR) -name '*.s')
PCOBJS:= $(PCSOURCES:%.s=%.o)

all:
	pack build pi.ipkg 	
	sed -i 's/#include <runtime.h>/#include "rts\/buffer.h"\n#include "rts\/cast.h"\n#include "rts\/printf.h"\n#include "rts\/prim.h"\n#include "rts\/stringOps.h"\n#include "rts\/cBackend.h"\n#include "rts\/datatypes.h"\n#include "rts\/conCaseHelper.h"\n#include "rts\/math.h"\n#include "rts\/memoryManagement.h"\n#include "rts\/refc_util.h"\n#include "rts\/runtime.h"\n#include "rts\/stringOps.h"\n#include "rts\/tiny-malloc.h"\n#include "rts\/util.h"/g' build/exec/kernel.c
	sed -i 's/#include <idris_support.h>//g' build/exec/kernel.c
	sed -i 's/int main(int argc, char \*argv\[\])/int kmain\(\)/g' build/exec/kernel.c
	sed -i 's/idris2_setArgs(argc, argv);//g' build/exec/kernel.c
	cp build/exec/kernel.c kernel.c
	${CC} ${CFLAGS} kernel.c -o kernel.o -ffreestanding
	$(MAKE) rts
	$(MAKE) pc
	riscv64-unknown-elf-ld -T pc/linker.ld -nostdlib kernel.o  $(PCOBJS) $(RTSOBJS) -o kernel.elf

rts: $(RTSOBJS)

pc: $(PCOBJS)

rts/%.o: %.c

pc/%.o: %.s

clean:
	rm *.o *.elf rts/*.o pc/*.o kernel.c
	rm -rf build
