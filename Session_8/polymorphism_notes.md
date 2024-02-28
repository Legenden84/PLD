# Polymorphism notes
## Differences between ad-hoc polymorphism and parametric polymorphism
Ad-hoc polymorphism and parametric polymorphism are two types of polymorphism in programming languages that allow for a more flexible and reusable codebase. Here's a breakdown of their differences:

### Ad-hoc Polymorphism
* **Definition**: Ad-hoc polymorphism occurs when a function can operate on different types through specialized implementations for those types. It is achieved through function overloading or operator overloading, where the same function or operator name can have multiple implementations depending on the type of its arguments.
* **Examples**: In a language like C++, you might have two functions with the same name but different parameter types, and the compiler chooses which function to use based on the arguments passed to it.
* **Characteristics**:
    1. The function's behavior changes based on the types of the inputs.
    2. Implementations are explicitly provided for each type.
    3. It is less abstract and more concrete, as implementations are tied to specific types.

### Parametric Polymorphism
* **Definition**: Parametric polymorphism allows a function or a data type to be written generically, so that it can handle values identically without depending on their type. This is achieved through the use of generics in languages like Java or templates in C++.
* **Examples**: A generic list data structure that can hold elements of any type, where the same implementation is used regardless of the type of elements the list contains.
* **Characteristics**:
    1. Functions or data structures can operate on any type without being rewritten for each specific type.
    2. Type-specific behavior is not defined in the function or data structure itself. Instead, it works abstractly over any type that is passed.
    3. It promotes code reuse and flexibility, as the same piece of code can work with many types.

### Key Differences
* **Type-Specific Behavior**: Ad-hoc polymorphism is about creating specific implementations for different types, while parametric polymorphism is about creating a single implementation that can work with any type.
* **Implementation Versus Abstraction**: Ad-hoc polymorphism focuses on concrete implementations for each type it supports, whereas parametric polymorphism provides a high level of abstraction, allowing functions or data structures to work with any type.
* **Flexibility and Reuse**: Parametric polymorphism generally offers greater code reuse and flexibility, as the same code can apply to many types. Ad-hoc polymorphism requires explicit definitions for each type, which can lead to more code but allows for optimization and customization for specific types.

## Notation of subtyping and why common type of constructs are co- and contravariant
Subtyping is a fundamental concept in type theory and programming languages, often associated with polymorphism and inheritance. It allows for a type hierarchy where one type is considered to be a subtype of another if it has more specific behavior or properties. The notation and concepts of covariance and contravariance are closely related to subtyping, especially in the context of generic types (like collections or function types).

### Notation of Subtyping
The notation for subtyping is typically represented by the symbol "≤". If type $A$ is a subtype of type $B$, it is denoted as $A \leq B$. This relation means that an instance of $A$ can be used in any context where $B$ is expected, adhering to the Liskov Substitution Principle. This principle is a core concept in object-oriented programming, ensuring that a program remains correct when a subtype instance replaces a supertype instance.

### Covariance and Contravariance
In the context of generic types, covariance and contravariance describe how the type hierarchy of the generics' parameters relates to the type hierarchy of the generics themselves.
* **Covariant** ($A \leq B$ implies $Container < A >\leq Container < B >$): If a type operation is covariant in a certain parameter, it preserves the ordering of types from the subtype to the supertype for that parameter. It's common in types that produce or output values, like collections that can be read from but not written to. For instance, if  `cat` is a subtype of `Animal`, then a `List<Cat>` can be considered a subtype of `List<Animal>` in a covariant system, meaning you can safely read `Cat` instances from a `List<Animal>`. 
* **Contravariant** ($A \leq B$ implies $Container < B > \leq Container < A >$): Contravariance reverses the direction of subtyping for the operation's parameter. It's typical for types that consume or input values, such as function arguments. In a contravariant scenario, if you have a function that accepts an `Animal`, you can safely pass it a function that accepts a `Cat`, because every `Cat` is an `Animal`.

### Why Common Type Constructs are Co- and Contravariant
The variance of type constructs is determined by how they are used:

* **Covariance** is used in contexts where safety in reading from a generic container is necessary. Making a type construct covariant ensures that we can treat a container of a more specific type as a container of a more general type, allowing for flexibility in read-only scenarios.

* **Contravariance** is important for write scenarios, where we want to ensure that what we put into a container (or pass as an argument to a function) is acceptable. By making a type construct contravariant, we can accept containers or functions that work with more general types than the one specified.

## Identify parametric polymorphism
Parametric polymorphism is a concept in type theory and programming that allows functions or data types to be written generically, so that they can operate on values of any type in a type-safe manner. This concept is fundamental to achieving high levels of code reuse and abstraction in many programming languages. Here's a deeper dive into how to identify parametric polymorphism:

### Characteristics of Parametric Polymorphism
1. **Generic Types**: The most straightforward indication of parametric polymorphism is the presence of generic types in function signatures or data types. These are often denoted by placeholders (like `T`, `U`, `V`) that can be substituted with any actual type when the function is called or the data type is used.
2. **Type-Agnostic Operations**: Functions or data structures that operate in a way that does not depend on the specific types of their arguments or elements. For example, a function that returns the length of a list is parametrically polymorphic because it works the same way regardless of the type of elements in the list.
3. **Type Parameters in Definitions**: The definition of classes, interfaces, or functions includes type parameters. This means that the same class or function definition can be used for objects of different types without modification.

### Examples in Different Programming Languages
* **Java**: Generics in Java are a form of parametric polymorphism. For example, a generic class `ArrayList<T>` can hold elements of any type `T`.
```java
ArrayList<String> stringList = new ArrayList<>();
ArrayList<Integer> intList = new ArrayList<>();
```
* **C++**: Templates in C++ provide parametric polymorphism. A template function can work with any type passed to it.
```c++
template<typename T>
T add(T a, T b) {
    return a + b;
}
```
* **Haskell**: Haskell uses parametric polymorphism extensively. A simple example is the `length` function, which works for a list of any type.
```haskell
length :: [a] -> Int
```
* **Python**: Python’s type annotations, introduced in Python 3.5 with PEP 484, allow for parametric polymorphism through type hints, using the `typing` module's generic types.
```python
from typing import List

def concatenate(strings: List[str]) -> str:
    return ''.join(strings)
```

### How to Identify
When looking at code, you can identify parametric polymorphism by looking for:
* **Generic Type Declarations**: Functions, methods, or data types declared with generic type parameters.
* **Type-Agnostic Logic**: Code that operates on data without assuming or requiring knowledge of its specific type.
* **Use of Type Variables**: The use of placeholders for types in definitions, indicating that the function or data structure can work with any type.

## Informally infer types in the setting of parametric polymorphism
In the setting of parametric polymorphism, type inference involves determining the most general type of expressions without explicit type annotations, allowing functions and data structures to operate on any type. This polymorphism enables functions or types to be written in a way that they can handle values uniformly without depending on their specific types. Here's a basic approach to informally infer types in such a setting:

### Basic Type Inference Process
1. **Identify Generic Functions or Data Structures**: Look for functions or data structures that do not specify concrete types but use type variables instead.
2. **Analyze Usage**: See how these functions or data structures are used in the code. The way they are applied to specific types can give clues about the constraints on their type variables.
3. **Apply Constraints**: Based on the usage, apply constraints to the type variables. For instance, if a generic function is used with an integer, you know that in this instance, the type variable can be substituted with an integer type.
4. **Generalize**: Determine the most general type that the function or data structure can operate on, given its usage and constraints. This involves finding a common type that all instances can be considered as, or keeping the type variable if the function/data structure truly works with any type.

### Example
Consider a simple function `identity` that takes any value and returns that value.
* **Function Definition**: `identity(x) = x'`
* **Type Signature**: In a parametric polymorphism setting, its type can be inferred as `forall T . T -> T`, meaning for any type `T`, the function takes a value of type `T` and returns a value of the same type `T`.

### Inferring Types in Generic Collections
* **Generic List**: A list that can hold any type of elements.
* **Usage**: If you see a list being used to store integers, you can infer that instance of the list is of type `List<Int>`, but the general type of the list structure is `List<T>` for any type `T`.

## Central ideas in the Hindley-Milner algorithm for type inference
The Hindley-Milner (HM) type system is a foundational algorithm for type inference in programming languages, especially in functional languages like ML and Haskell. It's celebrated for its ability to automatically deduce the most general types of expressions without requiring explicit type annotations from the programmer. Here are the central ideas and mechanisms behind the Hindley-Milner algorithm:

### 1. Type Variables
The algorithm uses type variables to represent types that are not yet known. This allows it to work generically with any type until it gathers enough information to resolve these variables to specific types.

### 2. Type Expressions
Type expressions can be simple types (e.g., `Int`, `Bool`), type variables (representing unknown types), or compound types (like functions types `a -> b`, where `a` and `b` are type expressions).

### 3. Unification
Unification is a key process in HM type inference. It attempts to make different type expressions equivalent by finding a substitution that makes them the same. For example, if it knows that a function is applied to an `Int` and also that this function is of type `a -> b`, it can unify `a` with `Int` to further understand the function's type.

### 4. Type Environments
A type environment is a mapping from variable names to their types. It represents the types of all the variables in scope at any point in the program. The HM algorithm uses the type environment to keep track of the types of variables and functions.

### 5. Generalization and Instantiation
* **Generalization** is the process of determining the most general type of an expression, usually by introducing type variables where specific types are not necessary. This is what allows HM to achieve polymorphism.
* **Instantiation** involves replacing type variables with actual types, typically when an expression is used in a specific context that requires particular types.

### 6. Algorithm W
Algorithm W is a specific implementation of the HM type inference mechanism. It systematically walks through an expression, applying unification to infer types, and constructs a most general type for the expression. It does this by:

* Extending the type environment when it encounters new variables.
* Applying unification to resolve the types of expressions, especially in function application.
* Generalizing types in the context they are defined and instantiating them when they are used.

### 7. Principal Types
A central feature of the HM system is that it infers the "principal type" for each expression, which is the most general type that still makes the expression type-safe under any valid substitutions. This means the inferred type is as flexible as possible without leading to type errors.

### 8. Type Inference with Let-polymorphism
HM supports let-polymorphism (also known as ML-polymorphism), allowing variables defined in a `let` or equivalent binding to have polymorphic types. This is crucial for enabling functions to be reused with arguments of different types, as long as those types conform to the function's general type constraints.

## Identify forms of polymorphism in well-know programming languages such as Java and the languages of the ML family
Java is a statically typed, object-oriented programming language that supports several forms of polymorphism:

1. **Subtype Polymorphism (Inheritance and Interfaces)**: This is the most common form of polymorphism in Java. It allows instances of subclasses to be treated as instances of their superclass. Interfaces further abstract the concept by allowing classes to implement functionalities defined by the interface, enabling a form of multiple inheritance.

* **Parametric Polymorphism (Generics)**: Introduced in Java 5, generics enable classes, interfaces, and methods to operate on objects of various types while providing compile-time type safety. This form of polymorphism allows for code reuse across different data types.

* **Ad-hoc Polymorphism (Method Overloading)**: Java supports method overloading, where multiple methods can have the same name with different parameters in the same class. This allows different implementations based on the parameter types and counts.

* **Coercion (Automatic Type Conversion)**: While not often highlighted as a primary form of polymorphism, Java performs automatic type conversion in certain contexts, such as widening primitive conversions (e.g., from `int` to `long`).

## Understand the limitations of parametric polymorphism w.r.t. polymorphic recursion and mutable references
Parametric polymorphism, while powerful for creating highly generic and reusable code, encounters certain limitations when dealing with polymorphic recursion and mutable references. These limitations stem from the challenges of ensuring type safety and correct program behavior within the static type systems of most languages that support parametric polymorphism. Let's explore these limitations in more detail:

### Polymorphic Recursion
Polymorphic recursion refers to a recursive function where the type of the recursive call is different from the type of the function itself. This pattern is less common but can be particularly useful in certain algorithms that operate on nested or hierarchical data structures.

* **Limitation**: The main challenge with polymorphic recursion is type inference. In languages with parametric polymorphism, the type inference algorithm (like Hindley-Milner) generally requires the type of a function to be determined without considering its body. However, for polymorphic recursion, the type of the function depends on the types used in its recursive calls, creating a circular dependency that standard type inference algorithms struggle to resolve.

* **Example**: A classic example is a function that operates on a nested list structure where the depth of nesting determines the type. The recursive call might operate on a "simpler" or "less nested" version of the list, requiring a different type for each level of recursion.

* **Workaround**: To handle polymorphic recursion, languages or compilers often require explicit type annotations for such functions, as automatic type inference for these cases is undecidable in general.

### Resolution and Implications
To address these limitations:

* **Type Annotations**: Explicit type annotations can be required by the compiler for cases of polymorphic recursion, guiding the type inference process.
* **Type System Restrictions**: Restrictions on mutable references ensure that a reference cannot change the type of its contents, preventing type errors due to misuse of mutability.