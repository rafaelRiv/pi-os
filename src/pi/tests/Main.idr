module Main

import H.Monad
import PC.Uart

main : IO ()
main = runH $ do
  println "Hello from Idris2 on bare metal"
  println "For this example, we will concact two simple lists"
  println $ show $ [1,2,3,4] ++ [5,6,7,8]


