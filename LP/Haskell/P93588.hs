myMap :: (a->b)->[a]->[b]
myMap f list = [f x | x <- list]

myFilter :: (a->Bool)-> [a]->[a]
myFilter cond list = [x | x <-list, cond x]

myZipWith :: (a->b->c)->[a]->[b]->[c]
myZipWith f lista listb = [ f x y | (x,y) <- zip lista listb]

thingify :: [Int] -> [Int] -> [(Int,Int)]
thingify lista listb = [(x,y) | x <- lista, y <- listb, x `mod` y == 0]

factors :: Int -> [Int] 
factors n = [x | x <- [1..n], n `mod` x == 0]