# Question
There are no Boolean expressions in our imperative language. But we could introduce
the syntactic category of Boolean expressions **Bexp** whose elements are given by the formation
rules

```b ::= a1 = a2 | a1 < a2 | b1 ∧ b2 | b1 ∨ b2 | ¬b1```

where `a1`, `a2` `∈` `Aexp`. Let `B = {true, false}`. In a big-step semantics of Bexp transitions should
have the format

`σ ⊢ b →b v`

where `v ∈ B`

1. Suggest a modification of the formation rules for statements that makes use of Boolean expressions.
2. Which format should transitions have and why?
3. Assume that you have defined the transition relation for **Aexp** in problem 1 above. Now
define the transition rules for **Bexp**.

## Answer
1.  Modification of the Formation Rules for Statements with Boolean Expressions
    To integrate Boolean expressions into the imperative language's syntax, we can modify the formation rules for statements that traditionally rely on conditions, such as conditional statements (if-then-else) and loops (while). Here’s how the modified formation rules might look:
    * **Conditional Statement:** Utilize a Boolean expression for the condition.
    ```
    S ::= ... | if b then S1 else S2
    ```
    Here, `b` is a Boolean expression (`Bexp`), making the decision to execute `S1` or `S2` based on the truth value of `b`.
    * **While Loop:** Incorporate a Boolean expression as the loop's condition.
    ```
    S ::= ... | while b do S1
    ```
    In this rule, `b` is also a `Bexp`, and the loop continues as long as `b` evaluates to `true`.
    These modifications allow statements to directly utilize the richer set of conditions provided by Boolean expressions, enhancing the language's expressiveness and control flow capabilities.

2. Transition Format for Statements with Boolean Expressions
    The transition format for statements involving Boolean expressions remains consistent with the general approach to semantics in imperative languages but specifically accommodates the evaluation of Boolean expressions. The format suggested by the problem statement is:
    ```
    σ ⊢ b →b v
    ```
    This format is appropriate and should be adopted because it clearly distinguishes the evaluation of Boolean expressions (`b`) from other expressions and statements within the language. Here, `σ` represents the state before the expression `b` is evaluated, `→b` indicates that this is a transition rule for Boolean expressions, and `v` is the Boolean value (`true` or `false`) resulting from the evaluation of `b` in the state `σ`. This format supports the clear and concise expression of semantics for Boolean expressions, aligning with the principles of big-step semantics.

3. Transition Rules for Bexp
    Assuming the transition relation for arithmetic expressions (Aexp) is already defined, we can define the transition rules for Bexp as follows:
    * **Equality:**
    ```
    σ ⊢ a1 →a n1   σ ⊢ a2 →a n2
    -------------------------------- (BEq)
    σ ⊢ (a1 = a2) →b (n1 = n2)
    ```
    Evaluates to `true` if `n1` and `n2` are equal, false otherwise.
    
    * **Less Than:**
    ```
    σ ⊢ a1 →a n1   σ ⊢ a2 →a n2
    -------------------------------- (BLt)
    σ ⊢ (a1 < a2) →b (n1 < n2)
    ```
    Evaluates to `true` if `n1` is less than `n2`, false otherwise.

    * **Conjunction:**
    ```
    σ ⊢ b1 →b v1   σ ⊢ b2 →b v2
    -------------------------------- (BAnd)
    σ ⊢ (b1 ∧ b2) →b (v1 ∧ v2)
    ```
    Evaluates to `true` if both `v1` and `v2` are `true`, `false` otherwise.

    * **Disjunction:**
    ```
    σ ⊢ b1 →b v1   σ ⊢ b2 →b v2
    -------------------------------- (BOr)
    σ ⊢ (b1 ∨ b2) →b (v1 ∨ v2)
    ```
    Evaluates to `true` if either `v1` or `v2` (or both) are `true`, `false` otherwise.

    * **Negation:**
    ```
    σ ⊢ b1 →b v1
    ----------------- (BNot)
    σ ⊢ (¬b1) →b (¬v1)
    ```
    Evaluates to the opposite of `v1`; `true` if `v1` is `false`, and vice versa.