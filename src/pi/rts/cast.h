#pragma once

#include "cBackend.h"
#include "printf.h"

#define	PRId8			"d"		/* int8_t */
#define	PRId16			"d"		/* int16_t */
#define	PRId32			"d"		/* int32_t */
#define	PRId64			"lld"		/* int64_t */

#define	PRIu8			"u"		/* uint8_t */
#define	PRIu16			"u"		/* uint16_t */
#define	PRIu32			"u"		/* uint32_t */
#define	PRIu64			"llu"		/* uint64_t */

Value *cast_i32_to_Bits8(Value *);
Value *cast_i32_to_Bits16(Value *);
Value *cast_i32_to_Bits32(Value *);
Value *cast_i32_to_Bits64(Value *);
Value *cast_i32_to_i64(Value *);
Value *cast_i32_to_double(Value *);
Value *cast_i32_to_char(Value *);
Value *cast_i32_to_string(Value *);

Value *cast_i64_to_Bits8(Value *);
Value *cast_i64_to_Bits16(Value *);
Value *cast_i64_to_Bits32(Value *);
Value *cast_i64_to_Bits64(Value *);
Value *cast_i64_to_i32(Value *);
Value *cast_i64_to_double(Value *);
Value *cast_i64_to_char(Value *);
Value *cast_i64_to_string(Value *);

Value *cast_double_to_Bits8(Value *);
Value *cast_double_to_Bits16(Value *);
Value *cast_double_to_Bits32(Value *);
Value *cast_double_to_Bits64(Value *);
Value *cast_double_to_i32(Value *);
Value *cast_double_to_i64(Value *);
Value *cast_double_to_char(Value *);
Value *cast_double_to_string(Value *);

Value *cast_char_to_Bits8(Value *);
Value *cast_char_to_Bits16(Value *);
Value *cast_char_to_Bits32(Value *);
Value *cast_char_to_Bits64(Value *);
Value *cast_char_to_i32(Value *);
Value *cast_char_to_i64(Value *);
Value *cast_char_to_double(Value *);
Value *cast_char_to_string(Value *);

Value *cast_string_to_Bits8(Value *);
Value *cast_string_to_Bits16(Value *);
Value *cast_string_to_Bits32(Value *);
Value *cast_string_to_Bits64(Value *);
Value *cast_string_to_i32(Value *);
Value *cast_string_to_i64(Value *);
Value *cast_string_to_double(Value *);
Value *cast_string_to_char(Value *);

Value *cast_Bits8_to_Bits16(Value *input);
Value *cast_Bits8_to_Bits32(Value *input);
Value *cast_Bits8_to_Bits64(Value *input);
Value *cast_Bits8_to_i32(Value *input);
Value *cast_Bits8_to_i64(Value *input);
Value *cast_Bits8_to_double(Value *input);
Value *cast_Bits8_to_char(Value *input);
Value *cast_Bits8_to_string(Value *input);
Value *cast_Bits16_to_Bits8(Value *input);
Value *cast_Bits16_to_Bits32(Value *input);
Value *cast_Bits16_to_Bits64(Value *input);
Value *cast_Bits16_to_i32(Value *input);
Value *cast_Bits16_to_i64(Value *input);
Value *cast_Bits16_to_double(Value *input);
Value *cast_Bits16_to_char(Value *input);
Value *cast_Bits16_to_string(Value *input);
Value *cast_Bits32_to_Bits8(Value *input);
Value *cast_Bits32_to_Bits16(Value *input);
Value *cast_Bits32_to_Bits64(Value *input);
Value *cast_Bits32_to_i32(Value *input);
Value *cast_Bits32_to_i64(Value *input);
Value *cast_Bits32_to_double(Value *input);
Value *cast_Bits32_to_char(Value *input);
Value *cast_Bits32_to_string(Value *input);
Value *cast_Bits64_to_Bits8(Value *input);
Value *cast_Bits64_to_Bits16(Value *input);
Value *cast_Bits64_to_Bits32(Value *input);
Value *cast_Bits64_to_i32(Value *input);
Value *cast_Bits64_to_i64(Value *input);
Value *cast_Bits64_to_double(Value *input);
Value *cast_Bits64_to_char(Value *input);
Value *cast_Bits64_to_string(Value *input);

