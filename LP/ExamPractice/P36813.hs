import Data.List

degree :: Eq a => [(a, a)] -> a -> Int
degree [] _ = 0
degree ((a, b):ls) x | x == a || x == b = 1 + (degree ls x)
                      | otherwise = (degree ls x)



inside :: Eq a => a -> (a, a) -> Int
inside x (a, b) | x == a || x == b =1
                |   otherwise = 0



degree' :: Eq a => [(a, a)] -> a -> Int
degree' list x = sum (map (inside x) list)

contains :: Eq a => a -> (a, a) -> Bool
contains x (a, b) = x == a || x == b

neighbor :: Eq a => a -> (a, a) -> a
neighbor x (a, b) | x == a = b
                  | x == b = a

neighbors :: Ord a => [(a, a)] -> a -> [a]
neighbors list x = map (neighbor x) (sort (filter (contains x) list))