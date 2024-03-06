plip [] = []
plip ((x,y) : zs) = (x*y, x+y) : plip zs

main :: IO ()
main = print $ plip [(1,2), (3,4), (5,6)]
