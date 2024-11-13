module PC.Main

import H.Monad
import PC.Uart
import H.Pages

main : IO ()
main = runH $ do
  println "Welcome to PI OS"
  println $ "Number of pages: " ++ show numPages


