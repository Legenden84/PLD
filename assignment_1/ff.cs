(load listfunctions)

( fun factorial
    (0) 1
    (n) (* n ( factorial ( - n 1)))
)

(
    fun ff
        (()) 'T
)


(
  fun ff
    (head) (if (symbol? head) head (ff (#L head))) 
    (head . tail) (if (symbol? head) (ff tail))
)

(
  fun ff (expr)
    (if (symbol? expr) expr (ff (#L expr)))
)

(
  fun ff
    (head) (if (symbol? head) head (ff (#L head))) 
    ((head . tail) (if (symbol? head) head (ff tail)))
)

(ff 'x)
(ff '(x . (y . ())))
(ff '(x . (y . (z . ()))))