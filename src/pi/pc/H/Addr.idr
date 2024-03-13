module H.Addr

export
%foreign "C:idris_primitive_memset_Char"
setWideCharOffAddr: Ptr Char -> Int -> Int -> Char -> PrimIO ()

%foreign "C:idris_plusAddr_IdrisChar"
plusPtrChar: Ptr Char -> Bits32 -> Ptr Char


export
interface Pointer a where
  plusPtr : Ptr a -> Bits32 -> Ptr a

export
Pointer Char where
  plusPtr = plusPtrChar



