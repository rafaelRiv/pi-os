
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
void* idris_plusAddr(Value* var_1, void *p, int offset);
int idris2_isNull(void *);

// Returns a NULL
void *idris2_getNull();
/*int  hsprimitive_memcmp(HsWord8 *s1, HsWord8 *s2, size_t n);
int  hsprimitive_memcmp_offset(HsWord8 *s1, HsInt off1, HsWord8 *s2, HsInt off2, size_t n);
*/
void idris_primitive_memset_Word8(IdrisWord8 *, ptrdiff_t, size_t, IdrisWord8);
void idris_primitive_memset_Word16(IdrisWord16 *, ptrdiff_t, size_t, IdrisWord16);
void idris_primitive_memset_Word32(IdrisWord32 *, ptrdiff_t, size_t, IdrisWord32);
void idris_primitive_memset_Word64(IdrisWord64 *, ptrdiff_t, size_t, IdrisWord64);
void idris_primitive_memset_Word(IdrisWord *, ptrdiff_t, size_t, IdrisWord);
void idris_primitive_memset_Ptr(IdrisPtr *, ptrdiff_t, size_t, IdrisPtr);
void idris_primitive_memset_Float(IdrisFloat *, ptrdiff_t, size_t, IdrisFloat);
void idris_primitive_memset_Double(IdrisDouble *, ptrdiff_t, size_t, IdrisDouble);
void idris_primitive_memset_Char(IdrisChar *, ptrdiff_t, size_t, IdrisChar);


Value *onCollect(Value *, Value *, Value *, Value *);
Value *onCollectAny(Value *, Value *, Value *);

Value *voidElim(Value *, Value *);

