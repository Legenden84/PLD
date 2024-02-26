# Question
Functional programming languages support higher-order functions, but C-like languages do not.
However, if we use C-style functions we can simulate this by using function pointers. Suppose we
want to extend the syntax of C such that we can directly allow functions as parameters in C.
Below is an example of a incomplete program with a function applytoall that applies a function
to all elements of an array. We call applytoall with the square function and the array myarray
as actual parameters and should afterwards have that every element in the array myarray has been
squared.
We would like the program to be well-typed, whereas we would like the modified program where
myarray was a character array of type char [] (and nothing else was changed) not to be well-typed.
```c
void applytoall (T f, *int arr )
int n = sizeof(arr)
for (int i = 0; i < n ; i ++) {
    arr[i] = f(arr[i])
}
...
int myarray [4] = {1, 2, 3, 4}
...
T1 square(int x) ...
applytoall(square, myarray)
```
## Tasks
1. Suggest new type constructs that we should add to the type system for C. What should T be
in the above example?

* Function arrow as type constructor.
    * T1 -> T2
* Typecheck the function
    * T fun f(a:T_a) = expr
    * T = T1 -> T2

2. Suggest how we should type check function declarations and function calls if we extend the C
language in this way.
The extended type system should be able to handle cases such as
```c
T1 f(T2 g, T3 x) { return g(x); }
T4 h( T5 y) {...}
T6 j( T7 v) { return f(h, v)};
```
and tell us what the types are for the following:
* T1 = T6
* T2 = T3 -> T1
* T3 = T7
* T4 = T2
* T5 = T3 
* T6 = T1
* T7 = T3