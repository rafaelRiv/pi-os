#include "memoryManagement.h"
#include "math.h"
#include "stringOps.h"
#include "../pc/uart.h"

//Value *newValue(size_t size) {
 // Value *retVal = (Value *)malloc(size);
//  IDRIS2_REFC_VERIFY(retVal, "malloc failed");
 // retVal->header.refCounter = 1;
 // retVal->header.tag = NO_TAG;
 // return retVal;
//}
//

char hex_digit(int v) {
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v - 10;
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
  int num_pages = divRoundClosest(HEAP_SIZE,PAGE_SIZE);
  size_t *ptr = (size_t*) HEAP_START;

  for(int i = 0; i < num_pages; i++)
      *ptr++ = Empty;
}

int8_t alloc(size_t pages) {
  size_t num_pages = divRoundClosest(HEAP_SIZE,PAGE_SIZE);
  size_t *ptr = (size_t*) HEAP_START;
  
  for(size_t i = 0; i < num_pages - pages; i++) {
    if(*ptr == Empty) {
      char found = 1;

      for(size_t j = 0; j < i+pages; j++) {
        if(*ptr == Taken) {
          found = 1;
          break;
        }
      }

      if(found) {
        for(size_t k = i; k < i+pages; k++) {
          ptr[i] = Taken;
        }

        ptr[i+pages-1] = Last;

        return ALLOC_START + PAGE_SIZE * i;
      }

    }
  }

  return -1;
}

void dealloc(int8_t *ptr) {
  int8_t *addr =  ((size_t)ptr - ALLOC_START) / PAGE_SIZE;

  if(*ptr == Empty) 
    return;

  if(addr >= HEAP_START && addr < HEAP_START + HEAP_SIZE)
    return;

	while (*ptr != Last) {
    *ptr = Empty;
    ptr++;
	}

  *ptr = Empty;
}


int8_t zalloc(size_t pages) {
  int8_t ret = alloc(pages);

  if(ret != -1) {
    size_t size = (PAGE_SIZE * pages) / 8;
    int8_t* big_ptr = ret;

    for(size_t i = 0; i < size; i++) {
      *big_ptr = Empty;
      big_ptr++;
    }
  }
}

