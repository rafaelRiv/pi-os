#pragma once

#include "../pc/uart.h"

// Crash is the condition is false.
#define IDRIS2_REFC_VERIFY(cond, ...)                                          \
  do {                                                                         \
    if (!(cond)) {                                                             \
      idris2_refc_verify_failed(__FILE__, __LINE__);       \
    }                                                                          \
  } while (0)

// Used by `IDRIS2_REFC_VERIFY`, do not use directly.
void idris2_refc_verify_failed(const char *ptr, const char *line) {
  if(ptr == NULL) {
    print(line);
  }
}
