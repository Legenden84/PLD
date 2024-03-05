older(christian, frederik).
older(frederik, knud).
older(knud, margrethe).
older(margrethe, benedikte).


older_transitive(X, Y) :- older(X, Y).
older_transitive(X, Y) :- older(X, Z), older_transitive(Z, Y).

