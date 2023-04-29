#include "memoryManagement.h"
#include "stringOps.h"
#include "../pc/uart.h"

Value *newValue(size_t size) {
 // Value *retVal = (Value *)malloc(size);
//  IDRIS2_REFC_VERIFY(retVal, "malloc failed");
 // retVal->header.refCounter = 1;
 // retVal->header.tag = NO_TAG;
 // return retVal;
}

void *alloc(size_t pages) {
  char log[10];

  if(pages > 0) {
    //const int num_pages = HEAP_SIZE / PAGE_SIZE;
    struct Page *ptr = 402657395; // HEAP START TEST
    ptr->flags = 23;

    toString(log, ptr->flags);

    print(log);
  }
}
