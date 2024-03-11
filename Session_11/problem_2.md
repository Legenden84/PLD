# Question
Suppose we solved the previous exercise such that we now have a big-step semantics
for arithmetic expressions. Let us now introduce them into the formation rules for statements such
that we get

```S ::= skip | x := a | S1; S2 | if a then S1 else S2 | while a do S1```

The goal of this exercise is to revise the big-step semantics for statements. Call the transition
relation for arithmetic expressions →a such that we can more easily tell transitions for expressions
apart from transitions for statements when we read our transition rules.

1. In the old big-step semantics for statements, transitions have the format

```⊢ S, σ → σ'```

Should this format change? Why – or why not? Justify your answer.
2. Define the new transition rule for assignments `x := a`.
3. Define the new transition rules for the remaining statements.

## Answers
1. No. The format `⊢ S, σ → σ'` for the transition relation for statements should not necessarily change even when introducing arithmetic expressions into the formation rules for statements. This format indicates that a statement `S`, when executed in the context of a state `σ`, results in a new state `σ'`. This conceptualization remains valid and useful when introducing arithmetic expressions, as the execution of both statements and arithmetic expressions can alter the state. The use of a separate transition relation `→a` for arithmetic expressions helps to clearly distinguish between the evaluation of expressions and the execution of statements, without needing to alter the fundamental format for how statements transition from one state to another. In essence, the introduction of arithmetic expressions affects the internal workings of how certain statements are evaluated (e.g., assignments, conditionals, loops) but does not change the overall structure of how statements update states.

2. For the assignment statement `x := a`, where `x` is a variable and `a` is an arithmetic expression, the new transition rule can be defined by incorporating the transition relation for arithmetic expressions. This can be expressed as follows:
    ```
    ⊢ a, σ →a n
    ----------------- (Assign)
    ⊢ x := a, σ → σ[x ↦ n]
    ```
    This rule states that if the arithmetic expression `a` evaluates to a number `n` in the state `σ` according to the arithmetic expression transition relation `→a`, then the assignment statement `x := a` transitions the state `σ` to a new state `σ'` where `σ'` is identical to `σ` except that x is now mapped to `n`.

3. The new transition rules for the remaining statements, incorporating arithmetic expressions, are as follows:
    * **Skip Statement:**
    ```
    ------------ (Skip)
    ⊢ skip, σ → σ
    ```
    The skip statement does not change the state.

    * **Sequence Statement:**
    ```
    ⊢ S1, σ → σ''   ⊢ S2, σ'' → σ'
    ----------------------------- (Seq)
            ⊢ S1; S2, σ → σ'
    ```
    If executing statement `S1` in state `σ` results in state `σ''`, and executing statement `S2` in state `σ''` results in state `σ'`, then the sequence of `S1` followed by `S2` transitions from σ to `σ'`.

    * **Conditional Statement:**
    ```
    ⊢ a, σ →a true    ⊢ S1, σ → σ'
    --------------------------------- (IfTrue) (a $\neq$ 0)
    ⊢ if a then S1 else S2, σ → σ'

    ⊢ a, σ →a false    ⊢ S2, σ → σ'
    --------------------------------- (IfFalse) (a == 0)
    ⊢ if a then S1 else S2, σ → σ'
    ```
    If the arithmetic expression `a` evaluates to `true`, then execute `S1`, otherwise execute `S2`.

    * **While Loop:**
    ```
    ⊢ a, σ →a true    ⊢ S1, σ → σ''    ⊢ while a do S1, σ'' → σ'
    --------------------------------------------------------------- (WhileTrue) (a $\neq$ 0)
                        ⊢ while a do S1, σ → σ'

    ⊢ a, σ →a false
    ----------------- (WhileFalse) (a == 0)
    ⊢ while a do S1, σ → σ
    ```
    If the arithmetic expression `a` evaluates to `true`, execute `S1` and then repeat the loop; if a evaluates to false, do not enter the loop and the state remains unchanged.