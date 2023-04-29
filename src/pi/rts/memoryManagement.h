#pragma once

#include "cBackend.h"

static size_t HEAP_START;
//static size_t HEAP_SIZE;

//size_t PAGE_SIZE = 1 << 12;

struct Page {
  int flags;
};

Value *newValue(size_t size);
void *alloc(size_t pages);

