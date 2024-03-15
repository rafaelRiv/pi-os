module H.Storable

import H.Addr

public export
interface Storable a where
  size : Int

  poke: HasIO io => Ptr a -> a -> io ()

public export
Storable Char where
  size = 256
  poke ptr v = primIO $ setCharOffAddr ptr 0 1 v
