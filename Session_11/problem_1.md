# Question
Let us introduce the syntactic category AExp of arithmetic expressions to the imperative language. The formation rules for arithmetic expressions are

```a ::= n | x | a1 ∗ a2 | a1 + a2 | (a1)```

Note that these expressions can contain variables! The goal of this exercise is to define a big-step
semantics for arithmetic expressions.

1. For statements, transitions have the format

```⊢ S, σ → σ```

What should the format of AExp-transitions be? Hint: Think about what would you need
to know to find the value of the expression x + y? What is σ?

2. Now define the transition rules for AExp-transitions.

## Answers
1. Create a rule for all elements in n `a` \
    `σ ⊢ a → n`
    Constant: `σ ⊢ n → n`
    X : `σ ⊢ x → σ(X)`
              
             `σ ⊢ a1 → n1` `σ ⊢ a2 → n2` 
    a1 * a2 : `σ ⊢ a1 * a2 → `

              `σ ⊢ a1 → n1` `σ ⊢ a2 → n2`
    a1 + a2 : `σ ⊢ a1 + a2 → `


    

