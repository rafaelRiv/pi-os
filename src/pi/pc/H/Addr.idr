module H.Addr

export
%foreign "C:idris2_primitive_memset_Char"
setWideCharOffAddr: Ptr Char -> Int -> Int -> Char -> PrimIO ()

%foreign "C:idris2_plusAddr_Char"
plusAddrChar: Ptr Char -> Bits32 -> Ptr Char

export
interface Addr a where
  plusAddr : Ptr a -> Bits32 -> Ptr a

export
Addr Char where
  plusAddr = plusAddrChar

