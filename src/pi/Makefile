all:
	idris2 --cg refc 9/main.idr -o kernel
	sed -i 's/#include <runtime.h>/#include "pc\/uart.h"\n#include "rts\/buffer.h"\n#include "rts\/cast.h"\n#include "rts\/stringOps.h"\n#include "rts\/cBackend.h"\n#include "rts\/datatypes.h"\n#include "rts\/conCaseHelper.h"\n#include "rts\/math.h"\n#include "rts\/memoryManagement.h"\n#include "rts\/refc_util.h"\n#include "rts\/runtime.h"\n#include "rts\/stringOps.h"\n#include "rts\/tiny-malloc.h"\n#include "rts\/util.h"/g' build/exec/kernel.c
	sed -i 's/#include <idris_support.h>//g' build/exec/kernel.c
	sed -i 's/int main(int argc, char \*argv\[\])/int kmain\(\)/g' build/exec/kernel.c
	sed -i 's/idris2_setArgs(argc, argv);//g' build/exec/kernel.c
	cp build/exec/kernel.c kernel.c
	riscv64-unknown-elf-gcc -fno-builtin -Wno-pointer-to-int-cast -Wall -Wextra -c -mcmodel=medany pc/uart.c -o pc/uart.o
	riscv64-unknown-elf-gcc -Wno-pointer-to-int-cast -Wall -Wextra -c  -mcmodel=medany rts/tiny-malloc.c -o rts/tiny-malloc.o
	riscv64-unknown-elf-gcc -Wno-pointer-to-int-cast -Wall -Wextra -c -mcmodel=medany rts/libc.c -o rts/libc.o
	riscv64-unknown-elf-gcc -fno-builtin -Wno-pointer-to-int-cast -Wall -Wextra -c -mcmodel=medany rts/mini-gmp.c -o rts/mini-gmp.o
	riscv64-unknown-elf-gcc -fno-builtin -Wno-pointer-to-int-cast -Wall -Wextra -c -mcmodel=medany rts/util.c -o rts/util.o
	riscv64-unknown-elf-gcc -fno-builtin -Wno-pointer-to-int-cast -Wall -Wextra -c -mcmodel=medany rts/refc_util.c -o rts/refc_util.o
	riscv64-unknown-elf-gcc -fno-builtin -Wno-pointer-to-int-cast -Wall -Wextra -c -mcmodel=medany rts/runtime.c -o rts/runtime.o
	riscv64-unknown-elf-gcc -fno-builtin -Wno-pointer-to-int-cast -Wall -Wextra -c -mcmodel=medany rts/buffer.c -o rts/buffer.o
	riscv64-unknown-elf-gcc -fno-builtin -Wno-pointer-to-int-cast -Wall -Wextra -c -mcmodel=medany rts/cast.c -o rts/cast.o
	riscv64-unknown-elf-gcc -fno-builtin -Wno-pointer-to-int-cast -Wall -Wextra -c -mcmodel=medany rts/prim.c -o rts/prim.o
	riscv64-unknown-elf-gcc -fno-builtin -Wno-pointer-to-int-cast -Wall -Wextra -c -mcmodel=medany rts/conCaseHelper.c -o rts/conCaseHelper.o
	riscv64-unknown-elf-gcc -fno-builtin -Wno-pointer-to-int-cast -Wall -Wextra -c -mcmodel=medany rts/memoryManagement.c -o rts/memoryManagement.o
	riscv64-unknown-elf-gcc -fno-builtin -Wno-pointer-to-int-cast -Wall -Wextra -c -mcmodel=medany rts/stringOps.c -o rts/stringOps.o -ffreestanding
	riscv64-unknown-elf-gcc -fno-builtin -Wno-pointer-to-int-cast -Wall -Wextra -c -mcmodel=medany rts/math.c -o rts/math.o -ffreestanding
	riscv64-unknown-elf-gcc -fno-builtin -Wno-pointer-to-int-cast -Wall -Wextra -c -mcmodel=medany kernel.c -o kernel.o -ffreestanding
	riscv64-unknown-elf-as -c asm/entry.s -o asm/entry.o
	riscv64-unknown-elf-as -c asm/mem.s -o asm/mem.o
	riscv64-unknown-elf-as -c asm/trap.s -o asm/trap.o
	riscv64-unknown-elf-ld -T linker.ld -nostdlib kernel.o asm/mem.o asm/trap.o asm/entry.o rts/tiny-malloc.o  rts/mini-gmp.o rts/libc.o rts/util.o rts/refc_util.o rts/runtime.o rts/buffer.o rts/cast.o rts/conCaseHelper.o rts/prim.o pc/uart.o rts/math.o rts/stringOps.o rts/memoryManagement.o -o kernel.elf

clean:
	rm *.o *.elf rts/*.o asm/*.o
