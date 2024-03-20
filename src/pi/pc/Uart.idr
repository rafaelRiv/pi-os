module Uart

import H.Addr
import H.AdHocMem
import H.Monad
import H.Storable

UART : Ptr Char
UART = absolutePtr 0x10000000

export
println: String -> H ()
println xs = println' (unpack xs)
  where 
    println': List Char -> H ()
    println' [] = poke UART '\n'
    println' (x :: xs) = do
      poke UART x
      println' xs

