#include "prim.h"
#include "cBackend.h"
#include "datatypes.h"
#include "stringOps.h"
#include "../pc/uart.h"
#include "tiny-malloc.h"
#include "refc_util.h"
#include "runtime.h"
#include "buffer.h"
#include "memoryManagement.h"

IORef_Storage *newIORef_Storage(int capacity) {
  IORef_Storage *retVal = (IORef_Storage *)malloc(sizeof(IORef_Storage));
  IDRIS2_REFC_VERIFY(retVal, "malloc failed");
  retVal->filled = 0;
  retVal->total = capacity;
  retVal->refs = (Value **)malloc(sizeof(Value *) * retVal->total);
  return retVal;
}

void doubleIORef_Storage(IORef_Storage *ior) {
  Value **values = (Value **)malloc(sizeof(Value *) * ior->total * 2);
  IDRIS2_REFC_VERIFY(values, "malloc failed");
  ior->total *= 2;
  for (int i = 0; i < ior->filled; i++) {
    values[i] = ior->refs[i];
  }
  free(ior->refs);
  ior->refs = values;
}

Value *newIORef(Value *erased, Value *input_value, Value *_world) {
  // if no ioRef Storag exist, start with one
 /* if (!global_IORef_Storage) {
    global_IORef_Storage = newIORef_Storage(128);
  }
  // expand size of needed
  if (global_IORef_Storage->filled >= global_IORef_Storage->total) {
    doubleIORef_Storage(global_IORef_Storage);
  } */

  // store value
  Value_IORef *ioRef = IDRIS2_NEW_VALUE(Value_IORef);
  ioRef->header.tag = IOREF_TAG;
  ioRef->index = global_IORef_Storage->filled;
  global_IORef_Storage->refs[global_IORef_Storage->filled] =
      newReference(input_value);
  global_IORef_Storage->filled++;

  return (Value *)ioRef;
}

Value *readIORef(Value *erased, Value *_index, Value *_world) {
  Value_IORef *index = (Value_IORef *)_index;
  return newReference(global_IORef_Storage->refs[index->index]);
}

Value *writeIORef(Value *erased, Value *_index, Value *new_value,
                  Value *_world) {
  Value_IORef *index = (Value_IORef *)_index;
  removeReference(global_IORef_Storage->refs[index->index]);
  global_IORef_Storage->refs[index->index] = newReference(new_value);
  return newReference(_index);
}


// -----------------------------------
//       System operations
// -----------------------------------


Value *sysCodegen(void) { return (Value *)makeString("refc"); }

Value *idris2_crash(Value *msg) {
  Value_String *str = (Value_String *)msg;
  print(str->str);
  exit(-1);
}

//
//
//
// // -----------------------------------
// //         Array operations
// // -----------------------------------
/*
Value *newArray(Value *erased, Value *_length, Value *v, Value *_word) {
  int length = extractInt(_length);
  Value_Array *a = makeArray(length);

  for (int i = 0; i < length; i++) {
    a->arr[i] = newReference(v);
  }

  return (Value *)a;
}

Value *arrayGet(Value *erased, Value *_array, Value *_index, Value *_word) {
  Value_Array *a = (Value_Array *)_array;
  return newReference(a->arr[((Value_Int64 *)_index)->i64]);
}

Value *arraySet(Value *erased, Value *_array, Value *_index, Value *v,
                Value *_word) {
  Value_Array *a = (Value_Array *)_array;
  removeReference(a->arr[((Value_Int64 *)_index)->i64]);
  a->arr[((Value_Int64 *)_index)->i64] = newReference(v);
  return NULL;
}

//
// -----------------------------------
//      Pointer operations
// -----------------------------------

Value *onCollect(Value *_erased, Value *_anyPtr, Value *_freeingFunction,
                 Value *_world) {
  Value_GCPointer *retVal = IDRIS2_NEW_VALUE(Value_GCPointer);
  retVal->header.tag = GC_POINTER_TAG;
  retVal->p = (Value_Pointer *)newReference(_anyPtr);
  retVal->onCollectFct = (Value_Closure *)newReference(_freeingFunction);
  return (Value *)retVal;
}

Value *onCollectAny(Value *_anyPtr, Value *_freeingFunction, Value *_world) {
  Value_GCPointer *retVal = IDRIS2_NEW_VALUE(Value_GCPointer);
  retVal->header.tag = GC_POINTER_TAG;
  retVal->p = (Value_Pointer *)newReference(_anyPtr);
  retVal->onCollectFct = (Value_Closure *)newReference(_freeingFunction);
  return (Value *)retVal;
}

Value *voidElim(Value *erased1, Value *erased2) { return NULL; } */

