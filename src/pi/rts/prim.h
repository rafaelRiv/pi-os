
#include "cBackend.h"

// IORef

Value *newIORef(Value *, Value *, Value *);
Value *readIORef(Value *, Value *, Value *);
Value *writeIORef(Value *, Value *, Value *, Value *);

// Sys

Value *sysCodegen(void);
Value *idris2_crash(Value *msg);

// Array

Value *newArray(Value *, Value *, Value *, Value *);
Value *arrayGet(Value *, Value *, Value *, Value *);
Value *arraySet(Value *, Value *, Value *, Value *, Value *);

// Pointer
Value *onCollect(Value *, Value *, Value *, Value *);
Value *onCollectAny(Value *, Value *, Value *);

Value *voidElim(Value *, Value *);

