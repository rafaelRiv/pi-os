module Main

%foreign "C:print"
print : String -> PrimIO ()

main : IO ()
main = primIO $ print "Hello from Idris2"

