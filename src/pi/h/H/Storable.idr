module H.Storable

import H.Addr

public export
interface Storable a where
  size : Int

  poke: HasIO io => Ptr a -> a -> io ()

public export
Storable Bits8 where
  size = prim__sizeOfBits8
  poke ptr v = setBits8OffAddr ptr 0 v

public export
Storable Bits16 where
  size = prim__sizeOfBits16
  poke ptr v = setBits16OffAddr ptr 0 v

public export
Storable Bits32 where
  size = prim__sizeOfBits32
  poke ptr v = setBits32OffAddr ptr 0 v

public export
Storable Bits64 where
  size = prim__sizeOfBits64
  poke ptr v = setBits64OffAddr ptr 0 v

public export
Storable Double where
  size = prim__sizeOfDouble
  poke ptr v = setDoubleOffAddr ptr 0 v

public export
Storable Char where
  size = prim__sizeOfChar
  poke ptr v = setCharOffAddr ptr 0 v

