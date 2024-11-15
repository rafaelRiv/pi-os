module Main

import H.Monad
import H.Pages
import PC.Uart
import Hedgehog

charGen : Gen (List Char)
charGen = list (linear 0 30) alphaNum

propReverse : Property
propReverse = property $ do
  xs <- forAll charGen
  xs === reverse (reverse xs)

main : IO ()
main = runH $ do
  println "Welcome to PI OS Tests"
  println "Running Tests"
  println "Testing initializing the heap"
  init
  println "Test passing"


