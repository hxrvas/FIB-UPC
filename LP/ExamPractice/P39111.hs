import Data.List (sort)

type Pos = (Int, Int) 

dins :: Pos -> Bool
dins (i, j) = ((i < 9 && i > 0) && (j < 9 && j > 0)) 

moviments::Pos -> [Pos]
moviments (i, j) = [(x, y) | x <- [1.. 8], y <- [1..8], ((abs(i-x)==2 && abs(j-y)==1) || (abs(i-x)==1 && abs(j-y)==2))]

removeItem:: Pos -> [Pos] -> [Pos]
removeItem x [] = []
removeItem x (y:ys) | x == y = removeItem x ys
                    | otherwise = y : removeItem x ys
remove :: [Pos] -> [Pos] -> [Pos]
remove list [] = list
remove list (y:ys) = (remove (removeItem y list) ys)

potAnar3::Pos->Pos->Bool
potAnar3 p q = elem q positions where
                positions = concat (map moviments (concat (map moviments (moviments p))))

                