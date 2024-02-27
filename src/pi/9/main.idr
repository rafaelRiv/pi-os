module Main

%foreign "C:print"
println : String -> PrimIO ()

test : Int -> Int -> Int
test x y = x + y

main : IO ()
main = do
  primIO $ println "Hello from Idris2\n"
  primIO $ println (show (test 2 10))

