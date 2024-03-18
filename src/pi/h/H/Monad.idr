module H.Monad

------------------------------- INTERFACE --------------------------------------

record H a where
  constructor MkH
  unH: IO a


runH : H a -> IO a

trappedRunH : H a -> IO ()

trace : Show a => a -> H ()

{-

To uncomment when an implementation for Applicative will be written

Monad H where
    (MkH x) >>= xm2 = H (runH . xm2 =<< m1)
-}
