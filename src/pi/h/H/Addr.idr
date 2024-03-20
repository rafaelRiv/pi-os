module H.Addr

%foreign "C:idris2_plusAddr_Bits8"
plusAddrBits8: Ptr Bits8 -> Bits32 -> Ptr Bits8

%foreign "C:idris2_plusAddr_Bits16"
plusAddrBits16: Ptr Bits16 -> Bits32 -> Ptr Bits16

%foreign "C:idris2_plusAddr_Bits32"
plusAddrBits32: Ptr Bits32 -> Bits32 -> Ptr Bits32

%foreign "C:idris2_plusAddr_Bits64"
plusAddrBits64: Ptr Bits64 -> Bits32 -> Ptr Bits64

%foreign "C:idris2_plusAddr_Ptr"
plusAddrPtr: Ptr a -> Bits32 -> Ptr a

%foreign "C:idris2_plusAddr_Double"
plusAddrDouble: Ptr Double -> Bits32 -> Ptr Double

%foreign "C:idris2_plusAddr_Char"
plusAddrChar: Ptr Char -> Bits32 -> Ptr Char

export
interface Addr a where
  plusAddr : Ptr a -> Bits32 -> Ptr a

export
Addr Bits8 where
  plusAddr = plusAddrBits8

export
Addr Bits16 where
  plusAddr = plusAddrBits16

export
Addr Bits32 where
  plusAddr = plusAddrBits32

export
Addr Bits64 where
  plusAddr = plusAddrBits64

export
Addr a where
  plusAddr = plusAddrPtr

export
Addr Double where
  plusAddr = plusAddrDouble

export
Addr Char where
  plusAddr = plusAddrChar

export
%foreign "C:idris2_primitive_memset_Bits8"
setBits8OffAddr: Ptr Bits8 -> Int -> Int -> Bits8 -> PrimIO ()

export
%foreign "C:idris2_primitive_memset_Bits16"
setBits16OffAddr: Ptr Bits8 -> Int -> Int -> Bits16 -> PrimIO ()

export
%foreign "C:idris2_primitive_memset_Bits32"
setBits32OffAddr: Ptr Bits32 -> Int -> Int -> Bits32 -> PrimIO ()

export
%foreign "C:idris2_primitive_memset_Bits64"
setBits64OffAddr: Ptr Bits64 -> Int -> Int -> Bits64 -> PrimIO ()

export
%foreign "C:idris2_primitive_memset_Double"
setDoubleOffAddr: Ptr Double -> Int -> Int -> Double -> PrimIO ()

export
%foreign "C:idris2_primitive_memset_Char"
setCharOffAddr: Ptr Char -> Int -> Int -> Char -> PrimIO ()


