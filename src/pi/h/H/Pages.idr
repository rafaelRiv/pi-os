module H.Pages

%foreign "C:idris2_heap_size"
prim__idris2_heap_size: Int

export
HEAP_SIZE: Int
HEAP_SIZE = prim__idris2_heap_size

export
PAGE_SIZE: Int
PAGE_SIZE = 4096

export
NUM_PAGES : Double
NUM_PAGES = (cast {to=Double} HEAP_SIZE) / (cast {to=Double} PAGE_SIZE)
