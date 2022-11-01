data Tree a = Empty | Node a (Tree a) (Tree a)

instance Show a => Show (Tree a) where
    show Empty = "()"
    show (Node x l r) = "(" ++ show l ++ "," ++ show x ++ "," ++ show r ++ ")"
