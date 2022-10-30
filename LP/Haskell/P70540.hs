liftM2 f x y = do 
    vx<- x
    vy <- y
    return $ f vx vy    

data Expr = Val Int | Add Expr Expr | Sub Expr Expr | Mul Expr Expr | Div Expr Expr 

eval1::Expr->Int

eval1 (Val x) = x
eval1 (Add x y) = (+) (eval1(x)) (eval1(y))
eval1 (Sub x y) = (-) (eval1(x)) (eval1(y))
eval1 (Mul x y) = (*) (eval1(x)) (eval1(y))
eval1 (Div x y) = div (eval1(x)) (eval1(y))

eval2::Expr->Maybe Int
eval2 (Val x) = Just x
eval2 (Add x y) = liftM2 (+) (eval2 x) (eval2 y)
eval2 (Sub x y) = liftM2 (-) (eval2 x) (eval2 y)
eval2 (Mul x y) = liftM2 (*) (eval2 x) (eval2 y)
eval2 (Div x y) = do 
    vx <- eval2(x)
    vy <- eval2(y)
    if vy == 0 
        then Nothing else return $ div vx vy

eval3::Expr->Either String Int
eval3 (Val x) = Right x
eval3 (Add x y) = liftM2 (+) (eval3 x) (eval3 y)
eval3 (Sub x y) = liftM2 (-) (eval3 x) (eval3 y)
eval3 (Mul x y) = liftM2 (*) (eval3 x) (eval3 y)
eval3 (Div x y) = do 
    vx <- eval3(x)
    vy <- eval3(y)
    if vy == 0 
        then Left "div0"  else return $ div vx vy