data STree a = Nil | Node Int a (STree a) (STree a)
    deriving (Show)
nNodes::STree a -> Int
nNodes Nil = 0
nNodes (Node _ _ l r) = 1 + nNodes l + nNodes r

isOk::STree a -> Bool
isOk Nil = True
isOk (Node n a l r) = n ==(nNodes (Node n a l r)) && isOk l && isOk r

-- inorderNth :: STree a -> Int 
-- inorderNth :: 
-- nthElement :: STree a -> Int -> Maybe a
-- nthElement (Node m a l r) 0 = Just a
-- nthElement Nil _ = Nothing
-- nthElement (Node m a l r) n = (nthElement l n-1

instance Functor STree where
  fmap f Nil              = Nil
  fmap f (Node s n lt rt) = (Node s (f n) (fmap f lt) (fmap f rt))