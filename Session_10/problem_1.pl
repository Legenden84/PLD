nat(z).
nat(s(X)) :- nat(X).
add(X,z,X) :- nat(X).
add(z,Y,Y) :- nat(Y).
add(s(X),Y,s(R)) :- add(X,Y,R), nat(X), nat(Y), nat(R).