all: 
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany pc/uart.c -o pc/uart.o
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany rts/memoryManagement.c -o rts/memoryManagement.o
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany rts/stringOps.c -o rts/stringOps.o -ffreestanding
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany kernel.c -o kernel.o -ffreestanding
	riscv64-unknown-elf-as -c entry.s -o entry.o
	riscv64-unknown-elf-ld -T linker.ld -nostdlib kernel.o entry.o pc/uart.o rts/stringOps.o rts/memoryManagement.o -o kernel.elf

clean:
	rm *.o *.elf
