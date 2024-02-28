# Question
We can define a type constructor Association on an interval types and some other
type. Values of type Association (T1,T2) are lists of pairs whose first elements are values of type
T1 and whose second elements are values of type T2 and such that all first elements are distinct.
As an example, the list
```
[(-3, 'f'), (0, 'f'), (2, 'e'), (4, 'd'), (7, 'c'), (10, 'b'), (12, 'a')]
```

is a value whose type is `Association(DanishGrades,Char)`.
We would now like to extend the subtype ordering to types of the form `Association(T1,T2)` where
`T1` and `T2` are interval types, where we assume the subtype ordering ⊑ on interval types that you
defined in the solution to the subproblem above.
The type constructor `Association` takes two types as arguments. 
* Should the constructor be covariant or contravariant wrt. the subtype ordering ⊑ for its first argument?
    * Given this analysis, covariance is the more appropriate choice for the first argument of `Association` in relation to the subtype ordering `⊑` for interval types. This is because a subtype relationship for the first type argument in `Association` would mean that the elements of the list maintain their distinctness and specific behavior as required by the narrower type, which is a safe and logical extension of behavior from the supertype to the subtype in a read or use context.

* Should it be covariant or contravariant wrt. the subtype ordering `⊑` for its second argument?
    * Given the nature of `Association` as a structure that pairs values of one type with values of another, where the focus is often on retrieving or using these paired values rather than storing new ones, covariance seems more suitable for the second argument as well.This is because: \
        1. **Readability and Usability**: In most scenarios, `Association` would be used to read or extract values of the second type. Covariance ensures that values of a subtype $T2'$ can be safely used wherever its supertype $T2$ is expected, which aligns with the principle of substitutability and the "is-a" relationship in object-oriented design.
        2. **Flexibility in Return Types**: When functions or methods return values from an Association, they can benefit from the flexibility of returning a more specific (subtype) value where a less specific (supertype) is expected, enhancing the utility and reusability of such methods.
* You must justify your answers.