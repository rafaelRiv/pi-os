module H.Monad

public export
record H a where
  constructor MkH
  unH: IO a

public export
runH : H a -> IO a
runH = unH

public export
liftIO : IO a -> H a
liftIO = MkH

public export
Functor H where
  map f (MkH m) = MkH (map f m)

public export
Applicative H where
  pure x = MkH (pure x)
  (MkH m1) <*>  xm2 = MkH $ m1 <*> runH xm2

public export
Monad H where
  (MkH m1) >>= xm2 = MkH $ runH . xm2 =<< m1


