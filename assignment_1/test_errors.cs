(
  fun fff
    ((head) (if (symbol? head) head (throw (Lerror))))
    ((head . tail) (if (symbol? head) head (fff tail)))
)

(fff '(x b z c))

(throw 'Error)


(
  fun ff
    (head) (if (symbol? head) head (throw '(Error)))
    ((head . tail) (if (symbol? head) head (ff tail)))
)

(
  fun ff
    (head) (if (symbol? head) head (throw '(Error Expected a symbol))) 
    ((head . tail) (if (symbol? head) head (ff tail)))
)

(throw ('Error))
