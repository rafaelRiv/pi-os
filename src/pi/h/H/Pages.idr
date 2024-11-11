module H.Pages

import H.Monad

------------------------ INTERFACE -----------------------------------------

-- type Page a = Ptr a 

Page: a -> Ptr a

%foreign "C:idris2_heap_size"
prim__idris2_heap_size: Int

export
heapSize: Int
heapSize = prim__idris2_heap_size

export
pageSize: Int
pageSize = 4096

export
numPages : Double
numPages = (cast {to=Double} heapSize) / (cast {to=Double} pageSize)

-- allocPage: H (Maybe (Page a))
-- freePage: Page a -> H ()
-- registerPage: Page a -> b -> (Page a -> H ()) -> H ()
-- zeroPage: Page a -> H ()
-- validPage: Page a -> Bool

