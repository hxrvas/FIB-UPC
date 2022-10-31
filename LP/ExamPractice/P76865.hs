data Tree a = Empty | Node a (Tree a) (Tree a)
         deriving (Show)

instance Foldable Tree where
    foldr f z Empty = z 
    foldr f z (Node k l r) = f k (foldr f (foldr f z r) l)

size :: Tree a -> Int
size Empty = 0
size (Node k l r) = 1 + size l + size r

avg :: Tree Int -> Double
avg Empty = 0
avg tree = fromIntegral suma / fromIntegral elems where
                    suma = sum $ tree
                    elems = size $ tree

addSpace :: String -> String -> String
addSpace [] y  = y
addSpace x  [] = x
addSpace x  y  = x ++ " " ++  y

cat :: Tree String -> String
cat Empty = ""
cat tree = foldr addSpace [] tree