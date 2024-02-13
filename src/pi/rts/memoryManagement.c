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

Value_Arglist *newArglist(int missing, int total) {
  Value_Arglist *retVal = IDRIS2_NEW_VALUE(Value_Arglist);
  retVal->header.tag = ARGLIST_TAG;
  retVal->total = total;
  retVal->filled = total - missing;
  retVal->args = (Value **)malloc(sizeof(Value *) * total);
  memset(retVal->args, 0, sizeof(Value *) * total);
  return retVal;
}

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
}

Value_Int8 *makeInt8(int8_t i) {
  Value_Int8 *retVal = IDRIS2_NEW_VALUE(Value_Int8);
  retVal->header.tag = INT8_TAG;
  retVal->i8 = i;
  return retVal;
}

Value_Int16 *makeInt16(int16_t i) {
  Value_Int16 *retVal = IDRIS2_NEW_VALUE(Value_Int16);
  retVal->header.tag = INT16_TAG;
  retVal->i16 = i;
  return retVal;
}

Value_Int32 *makeInt32(int32_t i) {
  Value_Int32 *retVal = IDRIS2_NEW_VALUE(Value_Int32);
  retVal->header.tag = INT32_TAG;
  retVal->i32 = i;
  return retVal;
}

Value_Int64 *makeInt64(int64_t i) {
  Value_Int64 *retVal = IDRIS2_NEW_VALUE(Value_Int64);
  retVal->header.tag = INT64_TAG;
  retVal->i64 = i;
  return retVal;
}

Value_Int8 *makeBool(int p) { return makeInt8(p ? 1 : 0); }

Value_Integer *makeInteger(int i) {
  Value_Integer *retVal = IDRIS2_NEW_VALUE(Value_Integer);
  retVal->header.tag = INTEGER_TAG;
  retVal->i = i;
  return retVal;
}

Value_Integer *makeIntegerLiteral(char *i) {
  Value_Integer *retVal = makeInteger((int)*i);
  return retVal;
}

Value_String *makeEmptyString(size_t l) {
  Value_String *retVal = IDRIS2_NEW_VALUE(Value_String);
  retVal->header.tag = STRING_TAG;
  retVal->str = malloc(l);
  memset(retVal->str, 0, l);
  return retVal;
}

Value_String *makeString(char *s) {
  Value_String *retVal = IDRIS2_NEW_VALUE(Value_String);
  int l = strlen(s);
  retVal->header.tag = STRING_TAG;
  retVal->str = malloc(l + 1);
  memset(retVal->str, 0, l + 1);
  memcpy(retVal->str, s, l);
  return retVal;
}

Value_Pointer *makePointer(void *ptr_Raw) {
  Value_Pointer *p = IDRIS2_NEW_VALUE(Value_Pointer);
  p->header.tag = POINTER_TAG;
  p->p = ptr_Raw;
  return p;
}

void init () {
  char *test = (char *) malloc(15);
  IDRIS2_REFC_VERIFY(test, "malloc failed");
 }


