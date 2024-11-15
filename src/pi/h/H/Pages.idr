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

export
numPages : Int
numPages = cast {to=Int} $ (cast {to=Double} heapSize) / (cast {to=Double} pageSize)

init : H ()
init = traverse_ clear [0..numPages]  
  where 
    nullPtr: Ptr Bits8
    nullPtr = (prim__castPtr prim__getNullAnyPtr)

    clear : Int -> H () 
    clear page = poke (plusAddr nullPtr (cast {to=Bits32} (page*pageSize))) 0

alloc : Int -> H ()
alloc pages = firstFreeContiguous 0 pages >>= takePages

  where 
    nullPtr: Ptr Bits8
    nullPtr = (prim__castPtr prim__getNullAnyPtr)

    isFreeContiguous : Int -> Int -> H Bool
    isFreeContiguous page 0 = do
        val <- peek (plusAddr nullPtr (cast {to=Bits32} (page*pageSize)))
        pure (val == 0)
    isFreeContiguous page size = do
      val <- peek (plusAddr nullPtr (cast {to=Bits32} ((page+size)*pageSize)))
      if val == 0
        then isFreeContiguous page (size-1)
        else pure False

    firstFreeContiguous : Int -> Int -> H (Maybe Int)
    firstFreeContiguous page 1 = do
        val <- peek (plusAddr nullPtr (cast {to=Bits32} (page*pageSize)))
        if val == 0 
           then pure (Just page)
           else pure Nothing
    firstFreeContiguous page size = do
        val <- isFreeContiguous page size
        if val
           then pure (Just page)
           else firstFreeContiguous (page+1) size

    takePage : Int -> H ()
    takePage page =  poke (plusAddr nullPtr (cast {to=Bits32} (page*pageSize))) 1

    takePages : Maybe Int -> H ()
    takePages Nothing = pure ()
    takePages (Just page) = traverse_ takePage [page..pages]



  




