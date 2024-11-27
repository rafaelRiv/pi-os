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

zalloc : Page a -> H ()
dealloc : Page a -> H ()

---------------------- PRIVATE IMPLEMENTATION FOLLOWS --------------------

%foreign "C:idris2_heap_size"
prim__idris2_heap_size: Int

export
heapSize : Int
heapSize = prim__idris2_heap_size

%foreign "C:idris2_heap_start"
prim__idris2_heap_start: Ptr Bits8

export
heapStart : Ptr Bits8
heapStart = prim__idris2_heap_start

export
numPages : Int
numPages = cast {to=Int} $ (cast {to=Double} heapSize) / (cast {to=Double} pageSize)

export
init : H ()
init = traverse_ clear [0..numPages]  
  where 
    clear : Int -> H () 
    clear page = pure () -- poke (plusAddr heapStart (cast {to=Bits32} page)) 0




  




