module H.Monad

record H a where
  constructor MkH
  unH: IO a

runH : H a -> IO a
runH = unH

liftIO = H

Functor H where
  map f (MkH m) = MkH (map f m)

Applicative H where
    pure x = MkH (pure x)
    (MkH m1) <*>  xm2 = MkH $ m1 <*> runH xm2

Monad H where
    (MkH m1) >>= xm2 = MkH $ runH . xm2 =<< m1


