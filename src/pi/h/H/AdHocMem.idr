module H.AdHocMem

import H.Monad
import H.Storable

public export
poke : (Storable a) => Ptr a -> a -> H ()
poke p x = liftIO $ poke p x
