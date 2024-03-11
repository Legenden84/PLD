# Question
Let us add the following construct to the functional language presented in the session
on program semantics.

```private x = e1 within e2```

The intention is that we inside `e2` (but only there) can mention the variable `x` and that its value is
that of the expression `e2`. For instance, the expression

```private x = 5 within x + 12```

should evaluate to the value 17.

* Extend the *type rules* of the functional language with rules for this new construct.

## Answer
To extend the type rules of the functional language to accommodate the new construct `private x = e1 within e2`, we need to establish a rule that ensures the types of expressions `e1` and `e2` are handled correctly, and that within `e2`, the variable `x` is bound to the value of `e1`.

In a functional language, the type rules ensure that expressions are well-typed according to the language's type system. These rules typically involve judgments that relate expressions to their types in the context of a given environment (which maps variables to types).

Let's denote the judgment as `Γ ⊢ e : τ`, meaning "under the environment `Γ`, expression `e` has type `τ`."

For the new construct, the type rule needs to:

1. Ensure that `e1` has a type (let's call it `τ1`).
2. Add `x` with type `τ1` to the environment for the evaluation of `e2`.
3. Ensure that `e2`, under this updated environment, has a type (let's call it `τ2`).
4. Conclude that the whole construct has type `τ2` since the value of the construct is the value of `e2`.

Given these requirements, the rule can be written as follows:

```
Γ ⊢ e1 : τ1    Γ, x:τ1 ⊢ e2 : τ2
--------------------------------- (Private)
    Γ ⊢ (private x = e1 within e2) : τ2
```

This rule reads as: If `e1` evaluates to a type `τ1` under the environment `Γ`, and if under the environment extended with `x` of type `τ1`, the expression `e2` evaluates to a type `τ2`, then the entire construct `private x = e1` within `e2` evaluates to type `τ2` under the original environment `Γ`.

This rule ensures that `x` is only available within `e2` and that it carries the type of the expression `e1`. It also maintains the type safety of the language by ensuring that the types are consistent within the scope of x and that the overall construct has the type of `e2`, which is the expression that provides the value of the construct.