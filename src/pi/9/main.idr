module Main

%foreign "C:idris_primitive_memset_Char"
setWideCharOffAddr: Ptr Char -> Int -> Int -> Char -> PrimIO ()

%foreign "C:idris_plusAddr"
plusPtr: Ptr a -> Int -> Ptr a

UART : Ptr Char
UART = plusPtr (prim__castPtr prim__getNullAnyPtr) 0x10000000

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

