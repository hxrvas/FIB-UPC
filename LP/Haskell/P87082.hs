s2f :: String -> Float
s2f = read

bmi :: Float -> Float -> String
bmi weight height 
    | (index < 18)  = "underweight"
    | (index < 25) = "normal weight"
    | (index < 30) = "overweight"
    | (index < 40) = "obese"
    | (index > 40) = "severely obese"
    where
        index = weight/(height*height)

computebmi :: String -> String
computebmi input = 
        let [a,b,c] = words input
            name = a
            weight = s2f b
            height = s2f c    
        in name ++ ": " ++ bmi weight height


main = do
    -- we define "loop" as a recursive IO action
    input <- getLine
    if input == "*"
        then return()
        else do
            putStrLn $ computebmi input
            main 
    -- start the first iteration 
