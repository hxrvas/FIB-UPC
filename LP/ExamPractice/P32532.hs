divisors::Int -> [Int]
divisors n = [x | x <- [1..n], n `mod` x == 0]

nbDivisors::Int -> Int
nbDivisors n = length (divisors n)

moltCompost::Int->Bool
moltCompost n = and [nbDivisors x < nDivs | x <- [1..n-1]]
                where nDivs = nbDivisors n