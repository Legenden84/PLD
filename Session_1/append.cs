(load listfunctions)
(define one (list 1 2))
(define two (list 5 6))
(define three (list 7 8))

(
  fun append* lists
    (
      if (= (length lists) 1) 3 (append (#L lists) (#L (#R lists)))
    )
)

(append* one two three)

lists ((1 2 3 4))