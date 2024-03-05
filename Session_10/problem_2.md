# Question
Here are some facts from 1971 about the Danish royal family:

* Christian is older than Frederik.
* Frederik is older than Knud.
* Knud is older than Margrethe.
* Margrethe is older than Benedikte.

Write a Prolog program that will always allow us to check if one royal person is older than another.
The program must be able to tell us that e.g. Christian is older than Benedikte

## Answer
```
older(christian, frederik).
older(frederik, knud).
older(knud, margrethe).
older(margrethe, benedikte).

older_transitive(X, Y) :- older(X, Y).
older_transitive(X, Y) :- older(X, Z), older_transitive(Z, Y).
```