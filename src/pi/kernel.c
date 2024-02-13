#include "pc/uart.h"
#include "rts/stringOps.h"
#include "rts/memoryManagement.h"

IORef_Storage * global_IORef_Storage;

void kmain(void) {
  print("execute kmain\n");
  init();
}
