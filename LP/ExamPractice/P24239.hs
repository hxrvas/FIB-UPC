
symTable :: Char -> Int
symTable 'I' = 1
symTable 'V' = 5
symTable 'X' = 10
symTable 'L' = 50
symTable 'C' = 100
symTable 'D' = 500
symTable 'M' = 1000


roman2int :: String -> Int
roman2int [] = 0
roman2int [x] = symTable x
roman2int (x:y:rest) | valueX < valueY = roman2int (y:rest) - valueX
                     | otherwise = valueX + roman2int (y:rest)
                     where 
                        valueX = symTable x 
                        valueY = symTable y

{- romanSum :: Int -> Int -> Int
romanSum x y | x < y = y - x
             | otherwise = x+y
             
roman2int' :: String -> Int
roman2int' roman =  (romanSum) (map symTable roman) -}


arrels::Float->[Float]
arrels x = arrels
    where
        arrels = 1:zipWith (\acc i -> 0.5 * (i + (x / i))) arrels [1..]

-- arrel :: Float -> Float -> Float
-- arrel x e = sum $ takeWhile (<=e) (exps x)  