import Data.List (sort)

type Pos = (Int, Int) 

dins :: Pos -> Bool
dins (i, j) = ((i < 9 && i > 0) && (j < 9 && j > 0)) 

moviments :: Pos -> [Pos]
