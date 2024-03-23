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
plusAddrPtr: Ptr Void -> Bits32 -> Ptr Void

%foreign "C:idris2_plusAddr_Char"
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
Addr Void where
  plusAddr = plusAddrPtr

export
Addr Double where
  plusAddr = plusAddrDouble

export
Addr Char where
  plusAddr = plusAddrChar

export
%foreign "C:idris2_sizeOf_Bits8"
prim__sizeOfBits8: Int

export
%foreign "C:idris2_sizeOf_Bits16"
prim__sizeOfBits16: Int

export
%foreign "C:idris2_sizeOf_Bits32"
prim__sizeOfBits32: Int

export 
%foreign "C:idris2_sizeOf_Bits64"
prim__sizeOfBits64: Int

export 
%foreign "C:idris2_sizeOf_Double"
prim__sizeOfDouble: Int

export
%foreign "C:idris2_sizeOf_Char"
prim__sizeOfChar: Int

%foreign "C:idris2_primitive_memset_Bits8"
prim__setBits8OffAddr: Ptr Bits8 -> Int -> Int -> Bits8 -> PrimIO ()

export
setBits8OffAddr: HasIO io => Ptr Bits8 -> Int -> Bits8 -> io ()
setBits8OffAddr ptr offset val = primIO $ prim__setBits8OffAddr ptr offset prim__sizeOfBits8 val

%foreign "C:idris2_primitive_memset_Bits16"
prim__setBits16OffAddr: Ptr Bits16 -> Int -> Int -> Bits16 -> PrimIO ()

export
setBits16OffAddr: HasIO io => Ptr Bits16 -> Int -> Bits16 -> io ()
setBits16OffAddr ptr offset val = primIO $ prim__setBits16OffAddr ptr offset prim__sizeOfBits16 val

%foreign "C:idris2_primitive_memset_Bits32"
prim__setBits32OffAddr: Ptr Bits32 -> Int -> Int -> Bits32 -> PrimIO ()

export
setBits32OffAddr: HasIO io => Ptr Bits32 -> Int -> Bits32 -> io ()
setBits32OffAddr ptr offset val = primIO $ prim__setBits32OffAddr ptr offset prim__sizeOfBits32 val

%foreign "C:idris2_primitive_memset_Bits64"
prim__setBits64OffAddr: Ptr Bits64 -> Int -> Int -> Bits64 -> PrimIO ()

export
setBits64OffAddr: HasIO io => Ptr Bits64 -> Int -> Bits64 -> io ()
setBits64OffAddr ptr offset val = primIO $ prim__setBits64OffAddr ptr offset prim__sizeOfBits64 val

%foreign "C:idris2_primitive_memset_Double"
prim__setDoubleOffAddr: Ptr Double -> Int -> Int -> Double -> PrimIO ()

export
setDoubleOffAddr: HasIO io => Ptr Double -> Int -> Double -> io ()
setDoubleOffAddr ptr offset val = primIO $ prim__setDoubleOffAddr ptr offset prim__sizeOfDouble val

%foreign "C:idris2_primitive_memset_Char"
prim__setCharOffAddr: Ptr Char -> Int -> Int -> Char -> PrimIO ()

export
setCharOffAddr: HasIO io => Ptr Char -> Int -> Char -> io ()
setCharOffAddr ptr offset val = primIO $ prim__setCharOffAddr ptr offset prim__sizeOfChar val



