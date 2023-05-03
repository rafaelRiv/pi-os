#pragma once

#include "cBackend.h"

struct Page {
  char flags;
};

Value *newValue(size_t size);
void *alloc(size_t pages);

extern size_t HEAP_START;
extern size_t HEAP_SIZE;
extern size_t KERNEL_STACK_START;
extern size_t KERNEL_STACK_END;
extern size_t KERNEL_TABLE;
extern size_t BSS_START;
extern size_t BSS_END;


