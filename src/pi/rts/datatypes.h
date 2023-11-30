#pragma once

#define NO_TAG 0
#define BITS8_TAG 1
#define BITS16_TAG 2
#define BITS32_TAG 3
#define BITS64_TAG 4
#define INT8_TAG 5
#define INT16_TAG 6
#define INT32_TAG 7
#define INT64_TAG 8
#define INTEGER_TAG 9
#define DOUBLE_TAG 10
#define CHAR_TAG 11
#define STRING_TAG 12

#define CLOSURE_TAG 15
#define ARGLIST_TAG 16
#define CONSTRUCTOR_TAG 17

#define IOREF_TAG 20
#define ARRAY_TAG 21
#define POINTER_TAG 22
#define GC_POINTER_TAG 23
#define BUFFER_TAG 24

#define MUTEX_TAG 30
#define CONDITION_TAG 31

#define COMPLETE_CLOSURE_TAG 98 // for trampoline tail recursion handling
#define WORLD_TAG 99

typedef struct {
  int refCounter;
  int tag;
} Value_header;

typedef struct {
  Value_header header;
  // `Value` is an "abstract" struct,
  // `Value_Xxx` structs have the same header
  // followed by type-specific payload.
} Value;

