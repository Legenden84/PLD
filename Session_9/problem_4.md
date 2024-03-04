# Question
In Smalltalk there are no control structures! Biconditionals and while loops do not
exist, and nor does assignment. But it is still possible to write useful programs. How would
Smalltalk programmers express the following simple piece of code which we can easily write in
imperative languages such as C or Java? Why and how is the Smalltalk approach different?
```
i=7;
sum=484000;
w hil e i > 0 do
{ i = i − 1;
    if ( i mod 2 ) = 0
    then sum = sum + i
    else sum = sum + 17 }
```