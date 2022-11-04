{-# OPTIONS_GHC -Wno-incomplete-patterns #-}

eval1 :: String -> Int
eval1 s = eval1' (words s) []
    where
        eval1' :: [String] -> [Int] -> Int
        eval1' [] [r] = r
        eval1' (w:ws) p
            | w == "*"  = eval1' ws ((*) (head $ tail p) (head p):tail (tail p))
            | w == "+"  = eval1' ws ((+) (head $ tail p) (head p):tail (tail p))
            | w == "-"  = eval1' ws ((-) (head $ tail p) (head p):tail (tail p))
            | w == "/"  = eval1' ws (div (head $ tail p) (head p):tail (tail p))
            | otherwise = eval1' ws (read w:p)


fsmap :: a -> [a -> a] -> a
fsmap = foldl (\ x f -> f x)

data Racional = Racional Integer Integer

instance Show Racional where
    show (Racional p q) = show p ++ "/" ++ show q

instance Eq Racional where
  Racional p q == Racional p' q' = p == p' && q == q'

racional :: Integer -> Integer -> Racional
racional p q = Racional (div p mcd) (div q mcd)
            where mcd = gcd p q

numerador :: Racional -> Integer
numerador (Racional p q) = p

denominador :: Racional -> Integer
denominador (Racional p q) = q


data Tree a = Node a (Tree a) (Tree a)

recXnivells :: Tree a -> [a]
recXnivells t = recXnivells' [t]
    where recXnivells' ((Node x fe fd):ts) = x:recXnivells' (ts ++ [fe, fd])

rationalsTree :: Racional -> Tree Racional
rationalsTree (Racional a b) = Node (Racional a b) fe fd
  where
    fe = rationalsTree (Racional a (a+b))
    fd = rationalsTree (Racional (a+b) b)

racionals :: [Racional]
racionals =  recXnivells (rationalsTree (Racional 1 1))