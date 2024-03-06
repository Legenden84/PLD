dingo [] = []
dingo (x:xs) = (x,x) : (dingo xs)

main :: IO ()
main = do
    print $ dingo [1, 2, 3]
    print $ dingo [True, False, True]