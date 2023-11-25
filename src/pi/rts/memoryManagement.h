#pragma once

#include "cBackend.h"

#define PAGE_SIZE 1 << 12
#define ALLOC_START 0

typedef signed char int8_t;

typedef struct Page {
  int8_t flags;
} Page;

struct FreePages {
	struct FreePages *next;
};

enum PageBits {
  Empty = 0,
  Taken = 1 << 0,
	Last = 1 << 1,
};

//Value *newValue(size_t size);
int8_t alloc(size_t pages);
void init();

extern size_t HEAP_START;
extern size_t HEAP_SIZE;
extern size_t KERNEL_STACK_START;
extern size_t KERNEL_STACK_END;
extern size_t KERNEL_TABLE;
extern size_t BSS_START;
extern size_t BSS_END;


