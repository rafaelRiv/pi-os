#include "math.h"
#include "runtime.h"
#include "memoryManagement.h"

int divRoundClosest(const int n, const int d)
{
  return ((n < 0) == (d < 0)) ? ((n + d/2)/d) : ((n - d/2)/d);
}

double unpackDouble(Value *d)
{
    return ((Value_Double *)d)->d;
}

Value *believe_me(Value *a, Value *b, Value *c)
{
    return c;
}

/* add */
Value *add_i32(Value *x, Value *y)
{
    return (Value *)makeInt32(((Value_Int32 *)x)->i32 + ((Value_Int32 *)y)->i32);
}
Value *add_i64(Value *x, Value *y)
{
    return (Value *)makeInt64(((Value_Int64 *)x)->i64 + ((Value_Int64 *)y)->i64);
}
Value *add_double(Value *x, Value *y)
{
    return (Value *)makeDouble(((Value_Double *)x)->d + ((Value_Double *)y)->d);
}

/* sub */
Value *sub_i32(Value *x, Value *y)
{
    return (Value *)makeInt32(((Value_Int32 *)x)->i32 - ((Value_Int32 *)y)->i32);
}
Value *sub_i64(Value *x, Value *y)
{
    return (Value *)makeInt64(((Value_Int64 *)x)->i64 - ((Value_Int64 *)y)->i64);
}

Value *sub_Integer(Value *x, Value *y) {
  return (Value *)makeInteger(((Value_Integer *)x)->i - ((Value_Integer *)y)->i);
}

Value *sub_double(Value *x, Value *y)
{
    return (Value *)makeDouble(((Value_Double *)x)->d - ((Value_Double *)y)->d);
}

/* mul */
Value *mul_i32(Value *x, Value *y)
{
    return (Value *)makeInt32(((Value_Int32 *)x)->i32 * ((Value_Int32 *)y)->i32);
}
Value *mul_i64(Value *x, Value *y)
{
    return (Value *)makeInt64(((Value_Int64 *)x)->i64 * ((Value_Int64 *)y)->i64);
}
Value *mul_double(Value *x, Value *y)
{
    return (Value *)makeDouble(((Value_Double *)x)->d * ((Value_Double *)y)->d);
}

/* div */
Value *div_i32(Value *x, Value *y)
{
    return (Value *)makeInt32(((Value_Int32 *)x)->i32 / ((Value_Int32 *)y)->i32);
}
Value *div_i64(Value *x, Value *y)
{
    return (Value *)makeInt64(((Value_Int64 *)x)->i64 / ((Value_Int64 *)y)->i64);
}
Value *div_double(Value *x, Value *y)
{
    return (Value *)makeDouble(((Value_Double *)x)->d / ((Value_Double *)y)->d);
}

/* mod */
Value *mod_i32(Value *x, Value *y)
{
    return (Value *)makeInt32(((Value_Int32 *)x)->i32 % ((Value_Int32 *)y)->i32);
}
Value *mod_i64(Value *x, Value *y)
{
    return (Value *)makeInt64(((Value_Int64 *)x)->i64 % ((Value_Int64 *)y)->i64);
}

/* shiftl */
Value *shiftl_i32(Value *x, Value *y)
{
    return (Value *)makeInt32(((Value_Int32 *)x)->i32 << ((Value_Int32 *)y)->i32);
}
Value *shiftl_i64(Value *x, Value *y)
{
    return (Value *)makeInt64(((Value_Int64 *)x)->i64 << ((Value_Int64 *)y)->i64);
}

/* shiftr */
Value *shiftr_i32(Value *x, Value *y)
{
    return (Value *)makeInt32(((Value_Int32 *)x)->i32 >> ((Value_Int32 *)y)->i32);
}
Value *shiftr_i64(Value *x, Value *y)
{
    return (Value *)makeInt64(((Value_Int64 *)x)->i64 >> ((Value_Int64 *)y)->i64);
}

/* and */
Value *and_i32(Value *x, Value *y)
{
    return (Value *)makeInt32(((Value_Int32 *)x)->i32 & ((Value_Int32 *)y)->i32);
}
Value *and_i64(Value *x, Value *y)
{
    return (Value *)makeInt64(((Value_Int64 *)x)->i64 & ((Value_Int64 *)y)->i64);
}

/* or */
Value *or_i32(Value *x, Value *y)
{
    return (Value *)makeInt32(((Value_Int32 *)x)->i32 | ((Value_Int32 *)y)->i32);
}
Value *or_i64(Value *x, Value *y)
{
    return (Value *)makeInt64(((Value_Int64 *)x)->i64 | ((Value_Int64 *)y)->i64);
}

/* xor */
Value *xor_i32(Value *x, Value *y)
{
    return (Value *)makeInt32(((Value_Int32 *)x)->i32 ^ ((Value_Int32 *)y)->i32);
}
Value *xor_i64(Value *x, Value *y)
{
    return (Value *)makeInt64(((Value_Int64 *)x)->i64 ^ ((Value_Int64 *)y)->i64);
}

/* lt */
Value *lt_Bits8(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits8 *)x)->ui8 < ((Value_Bits8 *)y)->ui8);
}
Value *lt_Bits16(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits16 *)x)->ui16 <
                           ((Value_Bits16 *)y)->ui16);
}
Value *lt_Bits32(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits32 *)x)->ui32 <
                           ((Value_Bits32 *)y)->ui32);
}
Value *lt_Bits64(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits64 *)x)->ui64 <
                           ((Value_Bits64 *)y)->ui64);
}
Value *lt_Int8(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int8 *)x)->i8 < ((Value_Int8 *)y)->i8);
}
Value *lt_Int16(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int16 *)x)->i16 < ((Value_Int16 *)y)->i16);
}
Value *lt_Int32(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int32 *)x)->i32 < ((Value_Int32 *)y)->i32);
}
Value *lt_Int64(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int64 *)x)->i64 < ((Value_Int64 *)y)->i64);
}
Value *lt_Integer(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Integer *)x)->i < ((Value_Integer *)y)->i);
}
Value *lt_double(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Double *)x)->d < ((Value_Double *)y)->d);
}
Value *lt_char(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Char *)x)->c < ((Value_Char *)y)->c);
}
Value *lt_string(Value *x, Value *y) {
  return (Value *)makeBool(
      strcmp(((Value_String *)x)->str, ((Value_String *)y)->str) < 0);
}

/* gt */
Value *gt_Bits8(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits8 *)x)->ui8 > ((Value_Bits8 *)y)->ui8);
}
Value *gt_Bits16(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits16 *)x)->ui16 >
                           ((Value_Bits16 *)y)->ui16);
}
Value *gt_Bits32(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits32 *)x)->ui32 >
                           ((Value_Bits32 *)y)->ui32);
}
Value *gt_Bits64(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits64 *)x)->ui64 >
                           ((Value_Bits64 *)y)->ui64);
}
Value *gt_Int8(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int8 *)x)->i8 > ((Value_Int8 *)y)->i8);
}
Value *gt_Int16(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int16 *)x)->i16 > ((Value_Int16 *)y)->i16);
}
Value *gt_Int32(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int32 *)x)->i32 > ((Value_Int32 *)y)->i32);
}
Value *gt_Int64(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int64 *)x)->i64 > ((Value_Int64 *)y)->i64);
}
Value *gt_Integer(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Integer *)x)->i > ((Value_Integer *)y)->i);
}
Value *gt_double(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Double *)x)->d > ((Value_Double *)y)->d);
}
Value *gt_char(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Char *)x)->c > ((Value_Char *)y)->c);
}
Value *gt_string(Value *x, Value *y) {
  return (Value *)makeBool(
      strcmp(((Value_String *)x)->str, ((Value_String *)y)->str) > 0);
}

/* eq */
Value *eq_Bits8(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits8 *)x)->ui8 == ((Value_Bits8 *)y)->ui8);
}
Value *eq_Bits16(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits16 *)x)->ui16 ==
                           ((Value_Bits16 *)y)->ui16);
}
Value *eq_Bits32(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits32 *)x)->ui32 ==
                           ((Value_Bits32 *)y)->ui32);
}
Value *eq_Bits64(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits64 *)x)->ui64 ==
                           ((Value_Bits64 *)y)->ui64);
}
Value *eq_Int8(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int8 *)x)->i8 == ((Value_Int8 *)y)->i8);
}
Value *eq_Int16(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int16 *)x)->i16 == ((Value_Int16 *)y)->i16);
}
Value *eq_Int32(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int32 *)x)->i32 == ((Value_Int32 *)y)->i32);
}
Value *eq_Int64(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int64 *)x)->i64 == ((Value_Int64 *)y)->i64);
}
Value *eq_Integer(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Integer *)x)->i == ((Value_Integer *)y)->i);
}
Value *eq_double(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Double *)x)->d == ((Value_Double *)y)->d);
}
Value *eq_char(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Char *)x)->c == ((Value_Char *)y)->c);
}
Value *eq_string(Value *x, Value *y) {
  return (Value *)makeBool(
      !strcmp(((Value_String *)x)->str, ((Value_String *)y)->str));
}

/* lte */
Value *lte_Bits8(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits8 *)x)->ui8 <= ((Value_Bits8 *)y)->ui8);
}
Value *lte_Bits16(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits16 *)x)->ui16 <=
                           ((Value_Bits16 *)y)->ui16);
}
Value *lte_Bits32(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits32 *)x)->ui32 <=
                           ((Value_Bits32 *)y)->ui32);
}
Value *lte_Bits64(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits64 *)x)->ui64 <=
                           ((Value_Bits64 *)y)->ui64);
}
Value *lte_Int8(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int8 *)x)->i8 <= ((Value_Int8 *)y)->i8);
}
Value *lte_Int16(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int16 *)x)->i16 <= ((Value_Int16 *)y)->i16);
}
Value *lte_Int32(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int32 *)x)->i32 <= ((Value_Int32 *)y)->i32);
}
Value *lte_Int64(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int64 *)x)->i64 <= ((Value_Int64 *)y)->i64);
}
Value *lte_Integer(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Integer *)x)->i <= ((Value_Integer *)y)->i);
}
Value *lte_double(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Double *)x)->d <= ((Value_Double *)y)->d);
}
Value *lte_char(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Char *)x)->c <= ((Value_Char *)y)->c);
}
Value *lte_string(Value *x, Value *y) {
  return (Value *)makeBool(
      strcmp(((Value_String *)x)->str, ((Value_String *)y)->str) <= 0);
}



/* gte */
Value *gte_Bits8(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits8 *)x)->ui8 >= ((Value_Bits8 *)y)->ui8);
}
Value *gte_Bits16(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits16 *)x)->ui16 >=
                           ((Value_Bits16 *)y)->ui16);
}
Value *gte_Bits32(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits32 *)x)->ui32 >=
                           ((Value_Bits32 *)y)->ui32);
}
Value *gte_Bits64(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Bits64 *)x)->ui64 >=
                           ((Value_Bits64 *)y)->ui64);
}
Value *gte_Int8(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int8 *)x)->i8 >= ((Value_Int8 *)y)->i8);
}
Value *gte_Int16(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int16 *)x)->i16 >= ((Value_Int16 *)y)->i16);
}
Value *gte_Int32(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int32 *)x)->i32 >= ((Value_Int32 *)y)->i32);
}
Value *gte_Int64(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Int64 *)x)->i64 >= ((Value_Int64 *)y)->i64);
}
Value *gte_Integer(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Integer *)x)->i >= ((Value_Integer *)y)->i);
}
Value *gte_double(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Double *)x)->d >= ((Value_Double *)y)->d);
}
Value *gte_char(Value *x, Value *y) {
  return (Value *)makeBool(((Value_Char *)x)->c >= ((Value_Char *)y)->c);
}
Value *gte_string(Value *x, Value *y) {
  return (Value *)makeBool(
      strcmp(((Value_String *)x)->str, ((Value_String *)y)->str) >= 0);
}
