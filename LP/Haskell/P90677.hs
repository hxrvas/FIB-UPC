myFoldl :: (a->b->a) -> a -> [b] -> a
myFoldl fn acc [] = acc
myFoldl fn acc (x:xs) = myFoldl fn (fn acc x) xs

myFoldr :: (a->b->b) -> b -> [a] -> b
myFoldr fn acc [] = acc
myFoldr fn acc (x:xs) = fn x (myFoldr fn acc xs)

myIterate :: (a->a)->a->[a]
myIterate f a = a : myIterate f (f a)

myUntil :: (a->Bool)->(a->a)->a->a
myUntil cond f a | cond a = a
                 | otherwise = myUntil cond f (f a)

myMap :: (a -> b) -> [a] -> [b]
myMap fn [] = []
myMap fn (x:xs) = (fn x) : (myMap fn xs)

myFilter :: (a->Bool) -> [a] -> [a]
myFilter cond [] = []
myFilter cond (x:xs) | cond x = x : (myFilter cond xs)
                     | otherwise = (myFilter cond xs)

myAll :: (a -> Bool) -> [a] -> Bool
myAll f x = and $ map (\x-> f x) x

myAny :: (a -> Bool) -> [a] -> Bool
myAny f x = or $ map (\x-> f x) x

myZip :: [a] -> [b] -> [(a,b)]
myZip x [] = []
myZip [] y = []
myZip (x:xs) (y:ys) = (x,y) : myZip xs ys


myZipWith :: (a->b->c)->[a]->[b]->[c]
myZipWith f lista listb = [ f x y | (x,y) <- zip lista listb]