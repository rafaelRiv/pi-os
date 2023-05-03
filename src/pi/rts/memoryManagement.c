#include "memoryManagement.h"
#include "stringOps.h"
#include "../pc/uart.h"


size_t PAGE_SIZE = 1 << 12;

Value *newValue(size_t size) {
 // Value *retVal = (Value *)malloc(size);
//  IDRIS2_REFC_VERIFY(retVal, "malloc failed");
 // retVal->header.refCounter = 1;
 // retVal->header.tag = NO_TAG;
 // return retVal;
}

char hex_digit(int v) {
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v - 10; // <-- Here
}

void print_address_hex(void* p0) {
    int i;
    int p = (int)p0;

    putchar('0'); putchar('x');
    for(i = (sizeof(p) << 3) - 4; i>=0; i -= 4) {
      putchar(hex_digit((p >> i) & 0xf));
    }
}

void init () {
  char log[10];

  int num_pages = HEAP_SIZE / PAGE_SIZE;

  int *iptr = HEAP_START;
  int *ptr = HEAP_START;

  for(int i = 0; i < num_pages; i++)
    *ptr++ = Empty;

  toString(log,*iptr++);

  print(log);
 }

void *alloc(size_t pages) {

}
