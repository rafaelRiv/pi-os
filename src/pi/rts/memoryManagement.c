#include "memoryManagement.h"
#include "math.h"
#include "stringOps.h"
#include "../pc/uart.h"
#include "tiny-malloc.h"
#include "refc_util.h"

Value *newValue(size_t size) {
  Value *retVal = (Value *)malloc(size);
  IDRIS2_REFC_VERIFY(retVal, "malloc failed");
  retVal->header.refCounter = 1;
  retVal->header.tag = NO_TAG;
  return retVal;
}

void init () {
}


