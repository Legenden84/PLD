# Scopes, functions and parameter passing

*Static scoping oftens gives better code. Because we do not have to 'analyze' all our variables on runtime.*

## Question 1
```
begin
    var x := 0;
    var y := 42
    proc p is x := x + 3;
    proc q is call p ;
    begin
        var x := 9;
        proc p is x := x +1;
        call q ;
        y := x
    end
end
```

Now imagine that we have mixed scope rules. First consider the case where variables follow
static scope rules whereas procedures follow dynamic scope rules. What is the final value
of y then? And if we instead had dynamic scopes for variables but static scope rules for
procedures?

| Variables | procedures | result
|---------- | ------------| --------
|   static  |    dynamic  |    10
|  dynamic  |     static  |    12


## Question 2 
book on program design claims that in the language Pascal the construct while E do C
is equivalent to calling the procedure

```
procedure whiledo(e : Boolean; procedure c)
    begin
        if e then
            begin c;
                whiledo (e, c)
            end;
    end;
```

where the first parameter is a call-by-value parameter and the second parameter is a
procedure parameter, with the call `whiledo(E,PC)`, where PC is a parameterless procedure
whose body is C.
Why is this incorrect? Suggest a suitable correction

### ANSWER: 
If the procedure sets 'e' to false. It will still be considered true in `whiledo (e, c)`. 
Because 'e' is a call-by-value (a copy). Therefore, it will still call the whiledo function.
`whiledo(e,c)` will run recursively until we get stack overflow.

Correction:
Use call-by-name parameter passing (but Pascal does not have this feature).
Refactor 'e' into a procedure.

#### call-by-*
* call-by-value
    * Where arguments are evaluated before the function call.
* call-by-name
    * The argument expressions are not evaluated before the function call. Instead, the expressions themselves are passed into the function.
    * Whenever the parameter is used within the function, the expression passed as an argument is evaluated in the context of the caller. This means the expression is re-evaluated each time the parameter is accessed.
* call-by-reference
    * Where the function is given access to the actual variables.

## Question 3 
Famous influencer on Instagram proposes to extend his favourite programming language
with formal parameter list definitions of the form

```
parlist mypars = (T1 X1 ,... , Tn Xn)
```

where the 'T1, ..., Tn' are types.
This could save a lot of space. Instead of writing e.g.

```
function f1(T1 X1 ,... , Tn Xn)
... { body of f1 appears here }

function f2(T1 X1 ,... , Tn Xn)
... { body of f2 appears here }
```

we could simply write

```
function f1 (mypars)
... { body of f1 appears here }
function f2 (mypars)
... { body of f2 appears here }
```

Why should the influencer be discouraged?

### ANSWER
Lets say that we define a variable T1 X1 again inbetween f1 and f2. And T1 X1 is also defined in the parameter list.
Then it will not be clear if we are referencing the X1 from the parameter list or the 'new' variable.

## Question 4
Here is an ALGOL60 procedure that returns a real number. Remember that the only parameter passing mechanism in this language is call-by-name.

```
real procedure bingo (k, l, u, ak)
        value l, u;
        integer k, l, u;
        real ak ;
        // comment k and ak are call-by-name formal parameters;
    begin
        real s;
        s := 0;
        for k := l step 1 until u do
            s := s + ak;
        bingo := s // return s
    end;
```

Now let V be a real-valued array with 100 entries.
What happens if we call `bingo(i, 1, 100, V[i])`?

### ANSWER
* `i` will be evaluated before `V[i]`. Therefore it will be out of sync.