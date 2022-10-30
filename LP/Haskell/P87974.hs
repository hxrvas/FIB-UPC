 main = do 
     char <- getChar
     res <- getLine
     if char == 'A' || char == 'a'
        then putStrLn "Hello!"
        else putStrLn "Bye!"