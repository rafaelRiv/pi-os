#pragma once

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

