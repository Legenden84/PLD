# Question
In part 3 of the podcast on types I claim that we can implement many other composite
types as function types. Explain how to do this for tuples and records.

# Tuples:
let y = (17, 13, 5) in e_1
    let y = fun z => z 17 13 5 in e_1
        let (a, b, c) = y in e_2
            (fun a b c => e_2) y

## let y = (17, 13, 5) in e_1
This defines a tuple y with the values (17, 13, 5) and then uses it in some expression e_1.

## let y = fun z => z 17 13 5 in e_1
Here, y is defined as a function that takes another function z as its argument and applies z to the elements of the original tuple (17, 13, 5). This is a higher-order function because it takes a function as an argument.

## let (a, b, c) = y in e_2
In a typical tuple deconstruction, a, b, and c would directly receive the values 17, 13, and 5, respectively. However, since y is now a function, this deconstruction doesn't directly apply.

## (fun a b c => e_2) y
However, this direct application is not syntactically correct because y is a function expecting another function as its argument, not the other way around. The correct transformation that captures the intent of tuple deconstruction and applies it to the higher-order function representation would look more like:

# Records
* Use enumerated types.

```
T_Fields: Field_1 + ... + Field_N
T_val: T_1 + ... + T_N
loopup: T_enum -> T_enum'

Record.A = e
Set: (
    T_Field -> T_val 
    -> T_Field(A) -> T_val(e)
    -> T_Field -> T_val
    )
```