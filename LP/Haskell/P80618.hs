data Queue a = Queue [a] [a]
    deriving (Show)

create :: Queue a
create = Queue [] []

push :: a -> Queue a -> Queue a
push a (Queue l1 l2) = Queue l1 (a:l2)

pop :: Queue a -> Queue a
pop (Queue [] l2) = pop (Queue (reverse l2) [])
pop (Queue (x:xs) l2) = Queue xs l2

top :: Queue a -> a
top (Queue [] l2) = last l2
top (Queue (x:_) _) = x

empty :: Queue a -> Bool
empty (Queue [] []) = True
empty (Queue _ _) = False

instance Eq a => Eq (Queue a) where
    Queue x1 x2 == Queue y1 y2 = x1++(reverse x2) == y1++(reverse y2)
    