module H.AdHocMem

import H.Addr
import H.Monad
import H.Storable

public export
peek : (Storable a) => Ptr a -> H a
peek p = liftIO $ peek p

public export
poke : (Storable a) => Ptr a -> a -> H ()
poke p x = liftIO $ poke p x


