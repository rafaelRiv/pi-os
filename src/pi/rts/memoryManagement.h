#pragma once

#include "cBackend.h"

struct Page {
  int flags;
};

enum PageBits {
  Empty = 0,
	Taken = 1 << 0,
	Last = 1 << 1,
};

Value *newValue(size_t size);
void *alloc(size_t pages);
void init();

extern size_t HEAP_START;
extern size_t HEAP_SIZE;
extern size_t KERNEL_STACK_START;
extern size_t KERNEL_STACK_END;
extern size_t KERNEL_TABLE;
extern size_t BSS_START;
extern size_t BSS_END;


