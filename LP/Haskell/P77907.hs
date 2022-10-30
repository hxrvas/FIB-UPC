absValue :: Int -> Int

absValue n
    | n >= 0 = n
    | otherwise = -n

power :: Int -> Int -> Int

power _ 0 = 1
power x n
    | even n    = y * y
    | otherwise = y * y * x
    where
        y  = power x n_halved
        n_halved = div n 2

recPrime :: Int -> Int -> Bool
recPrime n i
    | n < 2 = False
    | n == 2 = True
    | even n = False
    | mod n i == 0 = False
    | i * i > n = True
    | otherwise = recPrime n (i+1)

isPrime :: Int -> Bool
isPrime n = recPrime n 2

slowFib :: Int -> Int
slowFib 0 = 0
slowFib 1 = 1
slowFib n = slowFib (n-1) + slowFib (n-2)

-- quicFib :: Int -> Int

