module H.Pages

import H.Monad

------------------------ INTERFACE -----------------------------------------

data Page a = Ptr a 

data PageBits = Empty | Taken | Last

export
pageSize: Int
pageSize = 4096

allocPage: H (Maybe (Page a))
freePage: Page a -> H ()
registerPage: Page a -> b -> (Page a -> H ()) -> H ()
zeroPage: Page a -> H ()
validPage: Page a -> Bool

---------------------- PRIVATE IMPLEMENTATION FOLLOWS --------------------

%foreign "C:idris2_heap_size"
prim__idris2_heap_size: Int

export
heapSize: Int
heapSize = prim__idris2_heap_size

export
numPages : Double
numPages = (cast {to=Double} heapSize) / (cast {to=Double} pageSize)

init: H ()

