all: 
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany pc/uart.c -o pc/uart.o
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany rts/memoryManagement.c -o rts/memoryManagement.o
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany rts/stringOps.c -o rts/stringOps.o -ffreestanding
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany kernel.c -o kernel.o -ffreestanding
	riscv64-unknown-elf-as -c asm/entry.s -o asm/entry.o
	riscv64-unknown-elf-as -c asm/mem.s -o asm/mem.o
	riscv64-unknown-elf-as -c asm/trap.s -o asm/trap.o
	riscv64-unknown-elf-ld -T linker.ld -nostdlib kernel.o asm/mem.o asm/trap.o asm/entry.o pc/uart.o rts/stringOps.o rts/memoryManagement.o -o kernel.elf

clean:
	rm *.o *.elf rts/*.o asm/*.o pc/*.o
