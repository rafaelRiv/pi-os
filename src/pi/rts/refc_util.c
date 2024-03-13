#include "refc_util.h"

// Used by `IDRIS2_REFC_VERIFY`, do not use directly.
void idris2_refc_verify_failed(const char *ptr, const char *line,  const char *cond,
                               const char *fmt, ...) {
  //print(fmt);
  exit();
}

