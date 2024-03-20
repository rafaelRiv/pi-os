module H.AdHocMem

import H.Addr
import H.Monad
import H.Storable

public export
poke : (Storable a) => Ptr a -> a -> H ()
poke p x = liftIO $ poke p x

nullPtr: Ptr a
nullPtr = (prim__castPtr prim__getNullAnyPtr)

absolutePtr : Bits32 -> Ptr a
absolutePtr n = nullPtr `plusAddr` n

