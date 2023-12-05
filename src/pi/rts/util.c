#include "util.h"

void exit() {
  while (1) {
    __asm__("lui a1, 0x100");
    __asm__("lui a2, 0x5");
    __asm__("addi a2, a2, 0x555");
    __asm__("sw a2, 0(a1)");
  }
}
