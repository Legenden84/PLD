# Question
Use the Hindley-Milner algorithm for type inference on the append function as defined
in Haskell (in its uncurried version) as

```haskell
append ([], xs) = xs
append ((x:xs), (y:ys)) = x : ( append (xs,ys))
```

## Answer
The Hindley-Milner algorithm is a classical type inference algorithm used in functional languages like Haskell to deduce the types of expressions without explicit type annotations.

Here's a step-by-step walkthrough of how the algorithm infers the types for this `append` function:

1. **Case 1**: `append ([], xs) = xs`
    * The empty list `[]` implies that the function works on lists.
    * Since `xs` is returned as it is, `xs` must also be a list of the same type as the empty list.
    * This case gives us the type `([a], [a]) -> [a]` where `a` is a type variable that can represent any type.

2. **Case 2**: `append ((x:xs), (y:ys)) = x : (append (xs, ys))`
    * The pair `(x:xs)` is a non-empty list which suggests that `x` is of some type `a` and `xs` is a list of type `[a]`.
    * The pair `(y:ys)` is another non-empty list. Since there are no constraints relating `y` and `x`, we could infer that `y` is of type `b` and `ys` is of type `[b]`. However, because the function's signature must be consistent, `y` and `ys` must also be of type `a` and `[a]` respectively.
    * The recursive call `append (xs, ys)` must then take two lists of type `[a]`.
    * The cons operator `:` constructs a new list from `x` and the result of the recursive call, which ensures that `x` is of the same type `a` as the elements of `xs` and `ys`.
    * This case also supports the type `([a], [a]) -> [a]`.

Therefore, the Hindley-Milner algorithm would infer that the type of the `append` function is `([a], [a]) -> [a]`, meaning it takes two lists of elements of some type `a` and returns a new list of elements of the same type `a`.

## TA review
```haskell
append ([], xs) = xs
append ((x:xs), (y:ys)) = x : ( append (xs,ys))
```
### Base Case Analysis
1. The base case states that `append ([], xs) = xs`:
We can infer that `T1` must be the same as `T2` because the empty list `[]` and `xs` are being used interchangeably. This gives us the first unification: `T1 = T2`.

### Recursive Case Analysis
1. In the recursive case, `append ((x:xs), (y:ys)) = x : (append (xs, ys))`, we have:
    * The list `(x:xs)` suggests that `x` and the elements of `xs` are of the same type, so `T3` is the same as `T1` (from our previous unification), and `xs` is `[T3]`.
    * Similarly, `(y:ys)` suggests `T4 = T1` and `ys` is `[T4]`.
2. The recursive call to `append` implies:
    * The first argument to `append` is `xs`, which we've established is `[T3]`.
    * The second argument to `append` is `ys`, which we've established is `[T4]`.
    * The result of append (xs, ys) must be a list of the same type as its inputs, say [T5].
    * Since `append`'s inputs must be lists of the same type, we unify `T3` and `T4` with `T5: T3 = T4 = T5`.
3. The `:` operator combines `x` of type `T3` with the result of `append (xs, ys)` of type `[T5]` to form a list. This means `x` is of the same type as the elements of the list returned by `append`, so `T3 = T5`.

### Unification and Type Simplification:
1. From the previous steps, we can deduce:
    * `T1 = T2 = T3 = T4 = T5` due to the unification requirements of the base and recursive cases.
2. Therefore, we can simplify our type variables to just `T1`, indicating that all elements and lists involved are of the same type. This gives us a single unifying type for the `append` function.
3. Finally, we generalize this type for all types `a`, resulting in the type signature:
```
append :: ([a], [a]) -> [a]
```