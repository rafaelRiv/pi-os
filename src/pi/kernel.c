#include "pc/uart.h"
#include "rts/stringOps.h"
#include "rts/memoryManagement.h"

void kmain(void) {
  print("execute kmain\n");
  alloc(8);
}
