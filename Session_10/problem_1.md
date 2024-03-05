# Question
Here is a Prolog program.
```
nat(z).                                                 // fact z(z = zeor) will always be a 'nat'
nat(s(X)) :− nat(X).                                    // if nat(X) is a natural number, then nat(s(X)) is also a natural number (s = successor)
add(X,z,X) :− nat(X).                                   // if nat(X) then add(X + 0 = X)
add(z,Y,Y) :− nat(Y).                                   // if nat(Y) then add (0 + Y = Y)
add(s(X),Y,s(R)) :− add(X,Y,R), nat(X), nat(Y), nat(R). // if add(X + Y = R) & nat(X) & nat(Y) & nat(R) then add((successor of X) + Y = (successor of R))
```

Explain what it defines.