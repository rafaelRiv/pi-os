module H.Pages

import H.Addr
import H.AdHocMem
import H.Storable
import H.Monad
------------------------ INTERFACE -----------------------------------------

data Page a = Ptr a 

data PageBits = Empty | Taken | Last

export
pageSize: Int
pageSize = 4096

-- From osblog
kzmalloc : Page a -> H ()
kmalloc : Page a -> H ()
kfree : Page a -> H ()
coalesce : H ()
printTable : H ()

---------------------- PRIVATE IMPLEMENTATION FOLLOWS --------------------

%foreign "C:idris2_heap_size"
prim__idris2_heap_size: Int

export
heapSize : Int
heapSize = prim__idris2_heap_size

export
numPages : Int
numPages = cast {to=Int} $ (cast {to=Double} heapSize) / (cast {to=Double} pageSize)

{-
  - I am pretty sure I am wrong here because we don't initialise the heap on the first bit of each page. 
  - We are initialising 0 to numPages here.
-}

init : H ()
init = traverse_ clear [0..numPages]  
  where 
    nullPtr: Ptr Bits8
    nullPtr = (prim__castPtr prim__getNullAnyPtr)

    clear : Int -> H () 
    clear addr = poke (plusAddr nullPtr (cast {to=Bits32} addr)) 0


