flatten :: [[Int]] -> [Int]
flatten x = concat x

myLength :: String -> Int
myLength x = length x

myReverse :: [Int] -> [Int]
myReverse x = reverse x

count :: [Int] -> Int -> Int
count list x = length (filter (== x) list)

countIn :: [[Int]] -> Int -> [Int]
countIn list x = map (\l -> count l x) list

firstWord :: String -> String
firstWord x = takeWhile (/= ' ') (dropWhile (== ' ') x)
