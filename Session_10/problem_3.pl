last(X, cons(X, nil)).
last(X, cons(_, As)) :- last(X, As).