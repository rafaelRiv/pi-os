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
  int num_pages = divRoundClosest(HEAP_SIZE,PAGE_SIZE);
  size_t *ptr = (size_t*) HEAP_START;

  for(int i = 0; i < num_pages; i++)
      *ptr++ = Empty;
}

/*void *alloc(size_t pages) {
//  int num_pages = divRoundClosest(HEAP_SIZE,PAGE_SIZE);
//	Page *ptr = (Page) HEAP_START;

  
  for(int i = 0)

    for i in 0..num_pages - pages {
			let mut found = false;
			// Check to see if this Page is free. If so, we have our
			// first candidate memory address.
			if (*ptr.add(i)).is_free() {
				// It was FREE! Yay!
				found = true;
				for j in i..i + pages {
					// Now check to see if we have a
					// contiguous allocation for all of the
					// request pages. If not, we should
					// check somewhere else.
					if (*ptr.add(j)).is_taken() {
						found = false;
						break;
					}
				}
			} 
} */
