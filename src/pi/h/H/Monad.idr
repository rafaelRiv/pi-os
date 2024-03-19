module H.Monad

record H a where
  constructor MkH
  unH: IO a

runH : H a -> IO a
runH = unH

Functor H where
  map f m = MkH (map f m.unH)

Applicative H where
    pure x = MkH (pure x)
    m1 <*>  xm2 = MkH $ do
      fn <- runH m1
      x <- runH xm2
      pure (fn x)

Monad H where
    (MkH m1) >>= xm2 = MkH (runH . xm2 =<< m1)


