module PC.Main

import H.Monad
import PC.Uart
import H.Pages

main : IO ()
main = runH $ do
  println "Welcome to PI OS"
  println "Initialise the heap"
  pageinit
  println "Finish initialise the heap"



