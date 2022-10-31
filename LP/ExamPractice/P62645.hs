s2i :: String -> Int
s2i = read


computesum :: String -> String
computesum input = 
            let separated = words input
                numbers = map s2i separated
            in show (sum numbers)


main = do
    x <- getContents
    putStrLn $ computesum x