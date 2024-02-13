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

/*
Value_Arglist *newArglist(int missing, int total) {
  Value_Arglist *retVal = IDRIS2_NEW_VALUE(Value_Arglist);
  retVal->header.tag = ARGLIST_TAG;
  retVal->total = total;
  retVal->filled = total - missing;
  retVal->args = (Value **)malloc(sizeof(Value *) * total);
  memset(retVal->args, 0, sizeof(Value *) * total);
  return retVal;
} */


Value_Double *makeDouble(double d) {
  Value_Double *retVal = IDRIS2_NEW_VALUE(Value_Double);
  retVal->header.tag = DOUBLE_TAG;
  retVal->d = d;
  return retVal;
}

Value_Char *makeChar(char c) {
  Value_Char *retVal = IDRIS2_NEW_VALUE(Value_Char);
  retVal->header.tag = CHAR_TAG;
  retVal->c = c;
  return retVal;
}

/*
Value_Bits8 *makeBits8(uint8_t i) {
  Value_Bits8 *retVal = IDRIS2_NEW_VALUE(Value_Bits8);
  retVal->header.tag = BITS8_TAG;
  retVal->ui8 = i;
  return retVal;
}

Value_Bits16 *makeBits16(uint16_t i) {
  Value_Bits16 *retVal = IDRIS2_NEW_VALUE(Value_Bits16);
  retVal->header.tag = BITS16_TAG;
  retVal->ui16 = i;
  return retVal;
}

Value_Bits32 *makeBits32(uint32_t i) {
  Value_Bits32 *retVal = IDRIS2_NEW_VALUE(Value_Bits32);
  retVal->header.tag = BITS32_TAG;
  retVal->ui32 = i;
  return retVal;
}

Value_Bits64 *makeBits64(uint64_t i) {
  Value_Bits64 *retVal = IDRIS2_NEW_VALUE(Value_Bits64);
  retVal->header.tag = BITS64_TAG;
  retVal->ui64 = i;
  return retVal;
} */

void init () {
  char *test = (char *) malloc(15);
  IDRIS2_REFC_VERIFY(test, "malloc failed");
 }


