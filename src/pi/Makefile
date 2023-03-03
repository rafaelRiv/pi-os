all: 
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany kernel.c -o kernel.o -ffreestanding
	riscv64-unknown-elf-as -c entry.s -o entry.o
	riscv64-unknown-elf-ld -T linker.ld -nostdlib kernel.o entry.o -o kernel.elf

clean:
	rm *.o *.elf
