module Main

%foreign "C:idris_primitive_memset_Char"
setWideCharOffAddr: Ptr Char -> Int -> Int -> Char -> PrimIO ()

%foreign "C:idris_plusAddr_IdrisChar"
plusPtrChar: Ptr Char -> Bits32 -> Ptr Char

interface Pointer a where
    plusPtr : Ptr a -> Bits32 -> Ptr a

Pointer Char where
  plusPtr = plusPtrChar

UART : Ptr Char
UART = plusPtr nullPtr 0x10000000
  where 
    nullPtr: Ptr Char
    nullPtr = (prim__castPtr prim__getNullAnyPtr)

println: String -> IO ()
println xs = println' (unpack xs)
  where 
    println': List Char -> IO ()
    println' [] = primIO $ setWideCharOffAddr UART  0 1 '\n'
    println' (x :: xs) = do
      primIO $ setWideCharOffAddr UART  0 1 x
      println' xs

main : IO ()
main = do
  println "Hello from Idris2 on bare metal"
  println "For this example, we will concact two simple lists"
  println $ show $ [1,2,3,4] ++ [5,6,7,8]

