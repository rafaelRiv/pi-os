ENTRY(start);
 
. = 0x80000000;
 
MEMORY
{
  ram   (wxa!ri) : ORIGIN = 0x80000000, LENGTH = 128M
}

SECTIONS {
	/* Include entry point at start of binary */
	.text : ALIGN(4K) {
		*(.init);
		*(.text);
	}
	.bss : ALIGN(4K) {
		PROVIDE(bss_start = .);
		*(.bss);
		. += 4096;
		PROVIDE(stack_top = .);
		. += 4096;
		PROVIDE(global_pointer = .);
		PROVIDE(bss_end = .);
    PROVIDE(_memory_start = ORIGIN(ram));
    /*
       Our kernel stack starts at the end of the bss segment (_bss_end). However, we're allocating
     0x80000 bytes (524 KiB) to our kernel stack. This should be PLENTY of space. The reason
     we add the memory is because the stack grows from higher memory to lower memory (bottom to top).
     Therefore we set the stack at the very bottom of its allocated slot.
     When we go to allocate from the stack, we'll subtract the number of bytes we need.
    */
    PROVIDE(_stack_start = bss_end);
    PROVIDE(_stack_end = _stack_start + 0x8000);
    PROVIDE(_memory_end = ORIGIN(ram) + LENGTH(ram));

    /* 
       Finally, our heap starts right after the kernel stack. This heap will be used mainly
     to dole out memory for user-space applications. However, in some circumstances, it will
     be used for kernel memory as well.

     We don't align here because we let the kernel determine how it wants to do this.
    */
    PROVIDE(_heap_start = _stack_end);
    PROVIDE(_heap_size = _memory_end - _heap_start);
	}
	.rodata : ALIGN(4K) {
		*(.rodata);
	}
	.data : ALIGN(4K) {
		*(.data);
	}
}
