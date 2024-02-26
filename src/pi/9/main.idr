module Main

main : IO ()
main =
  let t = 2+10
  in do
    putStrLn "Hello from Idris2" 
    putStrLn $ show t

