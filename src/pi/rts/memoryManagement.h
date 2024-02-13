#pragma once

#include "cBackend.h"
#include "tiny-malloc.h"

Value *newValue(size_t size);
void init();

#define IDRIS2_NEW_VALUE(t) ((t *)newValue(sizeof(t)))

