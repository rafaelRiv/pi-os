module Uart

import H.Addr
import H.Storable

UART : Ptr Char
UART = plusAddr nullPtr 0x10000000
  where 
    nullPtr: Ptr Char
    nullPtr = (prim__castPtr prim__getNullAnyPtr)

export
println: String -> IO ()
println xs = println' (unpack xs)
  where 
    println': List Char -> IO ()
    println' [] = poke UART '\n'
    println' (x :: xs) = do
      poke UART x
      println' xs

