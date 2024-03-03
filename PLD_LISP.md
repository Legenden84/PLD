I will provide you with 5 chapters for a dialect of LISP called PLD LISP. PLEASE READ THEM CAREFULLY!
And do not provide any feedback before i ask for it (NOT EVEN A SINGLE COMMENT ABOUT THE CONTENT)

# PLD LISP documentation

##  Simple expressions (Sexpr)
The simplest expression you can type is an integer, which evaluates to itself:
> 42
= 42
>
Funnction applications are fully parenthesized prefix expressions using spaces between function names
and arguments. For example
> (* 3 4 (+ 5 6 7))
= 216
>
Note that + and * can take more than two arguments. This is true of many functions, including -,
where it means the first argument minus all the subsequent arguments. / and % (modulus) only take two
arguments, as these operations are not naturally defined on more than this:
> (/ 3 4 5)
! Wrong number of arguments to /
>
All arithmetic is on integers, and division round towards zero.
PLD LISP does not have Booleans, so comparison returns the first argument if the comparison is true
and a special value () (pronounced “nil”) if false:
> ( < 3 4)
= 3
> ( < 3 2)
= ()
>
Conditionals treat () as false and every other value a true:
> ( if ( < 2 3) 7 9)
= 7
> ( if ( > 2 3) 7 9)
= 9
>
Most comparison operators work on arbitrary many arguments, including none:
> ( <)
= ()
> ( < 2 3 4)
= 2
> ( < 2)
= 2
> ( < 2 3 3)
= ()
> ( <= 2 3 3)
= 2
>
With more than two arguments, the comparison is true if the arguments are ordered by the operator, so
(< 2 3 4) is true (indicated by the non-nil value 2), but (< 2 3 3) is false. Operators <, >, <=, >=,
= work this way, but != (different from) only accepts exactly two arguments.
Predefined operator names evaluate to themselves:
> +
= +
> -
= -
> <
= <
> (+ + <)
= ()
>
Arithmetic and comparison operators are only defined on numbers, so if any argument is not a number
(e.g., +), they return (), as seen in the last expression above. So () is not just used for the false value,
but also to indicate certain kinds of undefined behaviour and, as we will see later, the empty list.

## Symbols, variables and functions
Operator names such as +, >, and if are symbols.
A symbol is a name constructed from letters (Danish alphabet, both upper and lower case), digits,
and the following special characters: +-*/%=<>?!\#,:{}&@~_$. Any such sequence that is not recognized
as an integer constant is a valid symbol. For example, the sequence 0x3f is a hexadecimal number, but
0x3g is a symbol.
Predefined symbols such as + and if evaluate to themselves, but other symbols are used as names of
variables and user-defined functions and are initially undefined:
> if
= if
> x
! Undefined variable x
>
Global variables can be defined using the define keyword:
( define x (+ 3 4))
= x
> x
= 7
> (+ x x )
= 14
>
Global functuions can be defined using the fun keyword:
> ( fun square ( x ) (* x x ))
= square
> ( square 7)
= 49
>
Note that the arguments in the definition are enclosed in parentheses. Functions of no or multiple
parameters can easily be defined
> ( fun getx () x )
= getx
> ( getx )
= 7
> ( fun average ( x y )
(/ (+ x y 1) 2))
= average
> ( average 4 7)
= 6
> getx
= λ
> average
= λ
>
Note that since x is not bound locally in getx, the global variable x (which we previously defined to
be 7) is used. Note, also, that the defintion of average spans several lines. The REPL waits until all
parentheses are closed before completing the expression.
When a fnction name such as getx or average is used as a variable, its value is a closure, i.e., a
functional value which can not be displayed, so the text λ is shown instead. This is not an actual value,
just an indication that the value can not be displayed.
We can define anonymous functions using the \ symbol (chosen, as in Haskell, because it looks a bit
like λ):
> ((\ ( x ) (* x x )) 9)
= 81
> (\ ( x ) (* x x ))
= λ
>
In fact, the definition (fun f (x) (* x x)) is just shorthand for (define f (\ (x) (* x x))).

## Lists, pairs, and quoted values
We noted above that using a symbol that is not bound to a value gives an “undefined variable” error,
and that a bound symbol evaluates to the value to which it is bound. But we can also use symbols as
values: If we prefix a symbol by a single quote, it evaluates to the symbol itself. In fact, any expression
prefixed by a quote evaluates to the expression itself (and not its value):
> ’ hello
= hello
> ’()
= ()
> ’7
= 7
> ’(+ 2 3)
= (+ 2 3)
> ’ ’(+ 2 3)
= ’(+ 2 3)
>
Note that a double-quoted expression evaluates to a single-quoted expression. We can also use a notation
that looks like a function application:
> ( quote (+ 2 3))
= (+ 2 3)
> ( quote ( quote (+ 2 3)))
= ’(+ 2 3)
>
In fact, ’e is just a short notation for (quote e), but quote is not a real function, as a function always
evaluates its arguments.
We saw that ’(+ 2 3) evaluated to (+ 2 3). This value is actually a list of three elements, +, 2, and
3. Lists are shown in parentheses with elements separated by whitespace. We can add elements in front
of a list using the :: operator (as in F# and Standard ML):
> (:: 1 ’(+ 2 3))
= (1 + 2 3)
> (:: 1 (:: 2 (:: 3 ())))
= (1 2 3)
>
Note that () is the empty list, so the expression (:: 1 (:: 2 (:: 3 ()))) is equivalent to the F#
expression 1 :: 2 :: 3 :: [] that evaluates to the list [1; 2; 3]. The difference is that F# uses
an infix operator while PLD LISP uses a parenthesized prefix operator, and that the notation for lists is
different.
Since PLD LISP is dynamically typed, a list does not have to end with (). Some examples:
> (:: 2 3)
= (2 . 3)
> (:: 2 (:: 3 4))
= (2 3 . 4)
> ’(1 . (2 . (3 . ())))
= (1 2 3)
>
The first of these expressions essentially builds a pair of 2 and 3, and the second adds 2 in front of the
pair of 3 and 4. In essence, a list in PLD LISP is nested pairs ending with (), as the last evaluation
above shows. Note the difference between . and :: – the dot is used infix in values to indicate pairs
(but it is not an operator), and the double-colon is a prefix operator/function that builds pairs.
A list that ends in () (so it can be shown without a dot) is called a proper list.

## Pattern matching
The function definitions we have seen so far specify formal parameters as a list of variables, but functions
can use pattern matching. As an example, the factorial function can be defined as shown here:
( fun factorial
(0) 1
( n ) (* n ( factorial ( - n 1))))
The body of the function consists of two rules, each consisting of a pattern and an expression. The pattern
(0) matches an argument list consisting of a single value, which is equal to 0. The pattern (n) matches
an argument list consisting of any single value v and binds n to v when evaluating the expression to the
right of the pattern. Note that newlines and indentation do not matter, so we could lay the function out
on one line or split it over more lines with no indentation.
We can also use pattern matching on lists and pairs, and that is actually the only way to access the
elements of lists or components of pairs – that is, until we define functions that can do so. These functions
must, initially, be defined using pattern matching. We can, for example, define functions that takes the
left or right components of a pair by:
( fun # L (( L . R )) L )
( fun # R (( L . R )) R )
Note that, if the argument is not a pair, the pattern does not match, so a run-time error is reported, as
shown below
> (# L 7)
! No patterns matched arguments (7)
! when applying (\ (( L . R )) L )
! to (7)
>
Note that, since (fun #L ((L . R)) L) is a shorthand for (define #L (\ ((L . R)) L)), the error
message is given in terms of this.
Note that, if applied to a list, #L returns the first element of the list, and #R returns the tail of the
list:
> (# L ’(1 2 3))
= 1
> (# R ’(1 2 3))
= (2 3)
>
We can define and use a function that returns the second element of a list by
> ( fun #2 (( _1 _2 . rest )) _2 )
= #2
> (#2 ’(1 2 3))
= 2
>
Note that underscores are allowed in variable names. A single underscore is not a wildcard pattern, but
just a “normal” variable.
If a variable occurs several times in a pattern, it will only match values if all the occurrences of the
same variable match the same value. So, a general equality function can be defined by
( fun equal
( x x ) ’T
( x y ) ())
If the two arguments are equal, the function returns the symbol T (which is considered a true Boolean
value), and otherwise it returns () (which is considered a false Boolean value). Note that, while + only
works on numbers, equal works on arbitrary values.
In the examples above, functions are defined on a fixed number of parameters, but you can define
functions that can take different number of arguments. For example, we can define and use a function
that builds a list of its arguments by
> ( fun list x x )
= list
> ( list 1 2 3)
= (1 2 3)
>
The pattern x (not in parentheses!) matches the complete argument list.
We can also use this to define a function that can take either one or two parameters by using patterns
with different length. This allows us to define a reverse function using an accumulating parameter in a
single function definition:
( fun reverse
( as ) ( reverse as ())
(() bs ) bs
(( a . as ) bs ) ( reverse as (:: a bs )))
The first rule matches a list of one argument, and calls reverse with two arguments, the second of
which is an empty list, which will be used as an accumulating parameter in the other rules. The second
rule matches the case where the first argument is an empty list, and returns the second argument (the
accumulating parameter). The third rule matches the case where the first argument is a non-empty
list, and calls reverse with the rest of the list as firt parameter and adding the first element to the
accumulating parameter.
This facility should not be over-used, as it can make code quite unreadable.

## Miscellaneous

### Comments
When a semicolon (;) is encountered, the rest of the line is a comment.

### The apply function
The binary function apply takes a function and a list of arguments and applies the function to these
arguments. For example,
> ( apply + ’(1 2 3))
= 6
>
This is useful when you compute a list and want to apply a variadic function to it. For example, we can
define a function that checks if a list is ordered by a comparison operator given a argument:
> ( fun orderedBy ( op list ) ( apply op list ))
= orderedBy
> ( orderedBy < ’(1 2 4))
= 1
>
We can also use it to define a variadic equality function:
> ( fun Equal
( x ) ’T
( x x . rest ) ( apply Equal (:: x rest ))
otherwise ())
= Equal
> ( Equal ’x ’x ’x )
= T
> ( Equal ’x ’x ’x ’ xx )
= ()
>

### Let-expressions
PLD LISP supports let-expressions similar to those found in F#, ML, or Haskell. The syntax is
(let p e1 e2)
It evaluates e1 and matches the pattern p to this. If successful, it evaluates e2 in the current envionment
extended with the bindings made by matching p to the value of e1. Otherwise, an error is reported.

### Symbol and number tests
The predefined unary operators symbol? and number? test if their arguments are symbols or numbers,
respectively:
> ( symbol ? ’x )
= x
> ( number ? 7)
= 7
> ( symbol ? 7)
= ()
> ( number ? ’x )
= ()
>
If the test succeeds, they return their arguments, otherwise they return ().

### Variadic conditional
The if expression actually works with any number of arguments, which is mostly used as a shorter form
to write nested conditionals. See Section 7 for details.

### Dynamically scoped functions
A λ-expression can be defined using lambda instead of \, as for example in
(define g ( lambda ( x ) (+ x y )))
The difference is that this defines a dynamically scoped function. This means that the variable y in the
body does not need to be defined when the function is defined (as would be the case with static scoping),
but it must be defined when the function is used.

## PLD LISP keywords
symbol?
number?
#L
#R
#2
list
equal
()
catch
throw
if
fun
