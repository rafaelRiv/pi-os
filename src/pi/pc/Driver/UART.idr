module Driver.UART

import H.Addr

UART : Ptr Char
UART = plusPtr nullPtr 0x10000000
  where 
    nullPtr: Ptr Char
    nullPtr = (prim__castPtr prim__getNullAnyPtr)

export
println: String -> IO ()
println xs = println' (unpack xs)
  where 
    println': List Char -> IO ()
    println' [] = primIO $ setWideCharOffAddr UART  0 1 '\n'
    println' (x :: xs) = do
      primIO $ setWideCharOffAddr UART  0 1 x
      println' xs

