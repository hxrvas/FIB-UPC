myLength :: [Int] -> Int
myLength [] = 0
myLength (x:xs) = 1 + myLength xs

listSum :: [Int] -> Int
listSum [] = 0
listSum (x:xs) = x + listSum xs

myMaximum :: [Int] -> Int
myMaximum (x:[]) = x
myMaximum (x:xs) = max x (myMaximum xs)

average :: [Int] -> Float
average list = fromIntegral (div (listSum list) (myLength list))

flatten :: [[Int]] -> [Int]
flatten [] = []
flatten (x:xs) = x ++ flatten xs

buildPalindrome :: [Int] -> [Int]
buildPalindrome list = (reverse list) ++ list

removeItem:: Int -> [Int] -> [Int]
removeItem x [] = []
removeItem x (y:ys) | x == y = removeItem x ys
                    | otherwise = y : removeItem x ys
remove :: [Int] -> [Int] -> [Int]
remove list [] = list
remove list (y:ys) = (remove (removeItem y list) ys)

oddsNevens :: [Int] -> ([Int],[Int]) 
oddsNevens [] = ([], [])
oddsNevens (x:xs) = let (odds, evens) = oddsNevens xs
                 in if even x 
                    then (odds, x:evens)
                    else (x:odds, evens)

isPrime :: Int -> Bool
isPrime 0 = False
isPrime 1 = False
isPrime 2 = True
isPrime x = (0 == length [y | y<-[2..x-1], mod x y == 0])

primeDivisors :: Int -> [Int]
primeDivisors x = [y | y <-[0..x], isPrime(y) && mod x y == 0]
