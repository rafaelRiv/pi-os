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
typedef uint8_t IdrisWord8;
typedef int16_t IdrisWord16;
typedef int32_t IdrisWord32;
typedef int64_t IdrisWord64;
typedef uint64_t IdrisWord;

typedef void* IdrisPtr; 
typedef float IdrisFloat;
typedef double  IdrisDouble;
typedef char  IdrisChar;

void idris_primitive_memcpy(void *dst, ptrdiff_t doff, void *src, ptrdiff_t soff, size_t len);
void idris_primitive_memmove(void *dst, ptrdiff_t doff, void *src, ptrdiff_t soff, size_t len);

int idris2_isNull(void *);
void *idris2_getNull();

Char* idris2_plusAddr_Char(Char *p, Bits32 offset);

void idris2_primitive_memset_Word8(Bits8 *, ptrdiff_t, size_t, Bits8);
void idris2_primitive_memset_Word16(Bits16 *, ptrdiff_t, size_t, Bits16);
void idris2_primitive_memset_Word32(Bits32 *, ptrdiff_t, size_t, Bits32);
void idris2_primitive_memset_Word64(Bits64 *, ptrdiff_t, size_t, Bits64);
void idris2_primitive_memset_Ptr(Ptr *, ptrdiff_t, size_t, Ptr);
void idris2_primitive_memset_Float(Float *, ptrdiff_t, size_t, Float);
void idris2_primitive_memset_Double(Double *, ptrdiff_t, size_t, Double);
void idris2_primitive_memset_Char(Char *, ptrdiff_t, size_t, Char);

Value *onCollect(Value *, Value *, Value *, Value *);
Value *onCollectAny(Value *, Value *, Value *);

Value *voidElim(Value *, Value *);

