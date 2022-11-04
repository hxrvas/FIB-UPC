multEq :: Int -> Int -> [Int]
multEq x y = [(x^i)*(y^i) | i <- [0..]]

index :: [Int] -> Int -> Int
index l r = index' l r 0
  where
    index' :: [Int] -> Int -> Int -> Int
    index' [] _ i = i+1
    index' (x:xs) r i
      | x /= r    = index' xs r (i+1)
      | otherwise = i

intersection :: [Int] -> [Int] -> [Int]
intersection xs ys = [x | x <-xs, y <- ys, x == y]

selectFirst :: [Int] -> [Int] -> [Int] -> [Int]
selectFirst l1 l2 l3 = [x | x <- aux, y<-l3 ,index l1 x < index l3 y]
  where
    aux = intersection l1 l2


myInfL :: a ->[a]
myInfL x = x:(myInfL x)

myIterate :: (a -> a) -> a -> [a]
myIterate f x = x:(scanl (\p _ -> f p) (f x) (myInfL x))

type SymTab a = String -> Maybe a

empty :: SymTab a
empty = (\_ -> Nothing)

get :: SymTab a -> String -> Maybe a
get st s = st s 

set :: SymTab a -> String -> a -> SymTab a
set st s x = (\a -> if (s == a) then Just x else st a)