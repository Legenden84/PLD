% Facts
royal(frederik).
royal(joachim).
royal(X) :- married(X,Y), royal(Y).

% Rules
married(frederik, mary).
married(joachim, marie).
married(X,Y) :- married(Y,X).