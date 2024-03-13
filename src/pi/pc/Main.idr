module Main

import Driver.UART

main : IO ()
main = do
  println "Hello from Idris2 on bare metal"
  println "For this example, we will concact two simple lists"
  println $ show $ [1,2,3,4] ++ [5,6,7,8]


