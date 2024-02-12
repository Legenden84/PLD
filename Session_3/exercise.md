# Problems we will definitely talk about
1.  Addition (+) and multiplication (×) are associative in the mathematical sense, so x + (y + z) =
    (x + y) + z and x × (y × z) = (x × y) × z. This allows us to leave out parentheses.
    Most programming languages allow expressions such as x + y + x and x ∗ y ∗ x without parentheses,
    but specify that the meaning of these are equivalent to (x + y) + x and (x ∗ y)∗x, respectively, and
    not to x + (y + x) or x ∗ (y ∗ x).
    An alternative would be to let the grouping be unspecified (as in mathematics).
    What are the benefits and hazards of doing this in a programming language? Assume that there
    are no side effects.

    #### ANSWER:
    * If it is non associative. It will cause problems when parsing the math.

2.  Some LISP variants allow a single bracket to close all open (normal) parentheses. What are the 
    benefits and hazards of allowing this? Describe how you would implement this.

    #### ANSWER: 
    * Advantages: Very easy to close all open parethesis.
    * Disadvatages: The code will get unmanageable (uoverskuelig)

3.  Assuming the usual operator precedences, convert the following infix expression to prefix (polish)
    and postfix (reverse polish) notation. Keep the constants in the same order as below.

    $$(2 + 3 ∗ (4 − 5)) ∗ \frac{6}{7}$$ 

    #### ANSWER:
    * post fix: 2345-*+6*7/
    * pre fix: /*+2*3-4567

    Next, write a program/function (in any language of your choosing) that inputs an infix expression 
    and outputs the equivalent prefix and postfix expressions, while keeping the constants in the same 
    order. The syntax of infix expressions is given by the formation rules

    ```fsharp
    E ::= n | (E) | E op E
    ```

    where op is one of the infix operators +, −, ∗ and / with the usual precedence and associativity. 
    Assume that numbers n are one digit only. You can decide whether or not spaces are allowed. Use 
    the expression given above as a test case.

# More problems
1. When we define a function or procedure f(x1 . . . xn) with n formal parameters, we of course want
to check that every invocation f(a1 . . . am) satisfies that m = n. This should be a purely syntactic
property. Where does it live? Can it be handled at the lexical level, at the grammatical level or not
even there? What is the appropriate way of handling it?

#### ANSWER:
* Do it in conjuction with Type Checking.
* Not appropritate do it under the lexical level, because regexes cannot count. 
  Also not appropriaate under the grammar level, because context free grammars (CFGs) 
  are not able to count this.
  * when applying arguments for a function, its not context free anymore.