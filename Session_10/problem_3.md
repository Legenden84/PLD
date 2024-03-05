# Question
Write the definition of a Prolog predicate last such that last (X,L) holds if X is the
last element of the list L. Do this by extending the program from the podcast
```
list(nil).
list(cons(A, As)) :− list(As).
append(nil, Bs, Bs) :− list(Bs).
append(cons(A, As), Bs, cons(A, Cs)) :−
                                append(As, Bs, Cs).
```

with new clauses that define last

## Answer
last(X, cons(X, nil)).
last(X, cons(_, As)) :- last(X, As).
