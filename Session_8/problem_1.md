# Question
* Give a precise definition of a subtype ordering ⊑ on interval types and prove that it is a partial order.

## Definition of Subtype Ordering `⊑` on Interval Types

The subtype ordering `⊑` on interval types can be defined within a type system that includes interval types. An interval type is a type that specifies the range of values that an entity (such as a variable or expression) can hold. Let's consider interval types in the form `[L, U]`, where `L` and `U` are the lower and upper bounds of the interval, respectively, and are elements of an ordered set (e.g., numbers).

The subtype ordering `⊑` between two interval types `[L1, U1]` and `[L2, U2]` is defined as follows:

`[L1, U1] ⊑ [L2, U2]` if and only if `L2 <= L1` and `U1 <= U2`.

This definition implies that an interval type `[L1, U1]` is a subtype of another interval type `[L2, U2]` if and only if the range of `[L1, U1]` is entirely contained within the range of `[L2, U2]`.

## Proof that `⊑` is a Partial Order

To prove that the subtype ordering `⊑` is a partial order, we must show that it satisfies three properties: reflexivity, antisymmetry, and transitivity.

### Reflexivity

For any interval type `[L, U]`, it is clear that `L <= L` and `U <= U`. Therefore, `[L, U] ⊑ [L, U]`. This satisfies the reflexivity property, which states that every element is related to itself.

### Antisymmetry

Suppose we have two interval types `[L1, U1]` and `[L2, U2]` such that `[L1, U1] ⊑ [L2, U2]` and `[L2, U2] ⊑ [L1, U1]`. By the definition of `⊑`, this means `L2 <= L1 <= L2` and `U1 <= U2 <= U1`. Hence, `L1 = L2` and `U1 = U2`, which implies `[L1, U1] = [L2, U2]`. This satisfies the antisymmetry property, which states that if two elements are related in both directions, they must be equal.

### Transitivity

Suppose we have three interval types `[L1, U1]`, `[L2, U2]`, and `[L3, U3]` such that `[L1, U1] ⊑ [L2, U2]` and `[L2, U2] ⊑ [L3, U3]`. By the definition of `⊑`, we have `L2 <= L1`, `U1 <= U2`, `L3 <= L2`, and `U2 <= U3`. From `L3 <= L2 <= L1` and `U1 <= U2 <= U3`, we can conclude `L3 <= L1` and `U1 <= U3`, which implies `[L1, U1] ⊑ [L3, U3]`. This satisfies the transitivity property, which states that if one element is related to a second, and the second is related to a third, then the first element is related to the third.

Therefore, since the subtype ordering `⊑` satisfies reflexivity, antisymmetry, and transitivity, it is a partial order.
