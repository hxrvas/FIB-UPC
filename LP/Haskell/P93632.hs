eql :: [Int] -> [Int] -> Bool
eql lista listb = lista == listb

prod :: [Int] -> Int 
prod list = foldl (*) 1 list

prodOfEvens :: [Int] -> Int
prodOfEvens list = prod (filter even list)

powersOf2 :: [Int]
powersOf2 = iterate (*2) 1

scalarProduct :: [Float] -> [Float] -> Float 
scalarProduct lista listb = sum (zipWith (*) lista listb)