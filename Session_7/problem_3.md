# Question
In some languages we have range types that allow us to specify that a value must be
within a certain interval of integers or characters. If we wanted to model the Danish grading scale,
we might want to have variable declarations such as 

```
var dkgrade = -3...12 
```

If we wanted to model the ECTS grading scale, we might want to have variable declarations such as

```
var ectsgrade = ’A’...’F’
```

How easy is it to use static typing with types of this form? How about dynamic typing? 0
* Discuss the pros and cons; be as precise as possible.

## Static typing
In statically typed languages, variables' types are known at compile time. This can be advantageous for range types in several ways:

**Pros:**
* *Type Safety:* Statically typed languages can enforce that values assigned to variables fall within the specified range at compile time, preventing runtime errors related to out-of-range values.
* *Performance:* Since types are known at compile time, the compiler can optimize the generated code for operations involving these range types, potentially leading to better performance.
* *Tooling:* IDEs and static analysis tools can offer better support, such as autocompletion and early detection of type-related errors, because the range constraints are known upfront.

**Cons:**
*Complexity in Type System:* Implementing range types in the type system can increase its complexity. The language needs mechanisms to define and enforce ranges, which might not be straightforward for all types of values, especially when considering inheritance and polymorphism.
*Limited Flexibility:* Once a range type is defined, extending or modifying its bounds can require changes in the type definition, potentially impacting all usage points in the codebase.
*Verbose Declarations:* For some scenarios, especially when dealing with complex or non-contiguous ranges, the type declarations might become verbose and less readable.

## Dynamic Typing
In dynamically typed languages, variables' types are determined at runtime. This affects the use of range types differently:

**Pros:**
* *Flexibility:* It's easier to create and manipulate range types at runtime since the type checks and enforcement happen during execution. This can allow for more dynamic and flexible code structures.
* *Ease of Use:* Developers can define and use range types without needing to extend the language's type system explicitly. This can lead to quicker implementation and potentially more readable code for simple range checks.
**Cons:**
* *Runtime Errors:* Since type checks occur at runtime, errors resulting from values falling outside the specified range are detected later in the development cycle, potentially leading to runtime exceptions and less predictable software behavior.
* *Performance Overhead:* Dynamic type checking and enforcement of range constraints at runtime can introduce performance overhead, as checks need to be performed every time a value is assigned or manipulated.
* *Lack of Early Feedback:* Unlike static typing, dynamic typing does not provide early feedback during development (e.g., through compile-time errors), which can lead to more debugging and testing to catch type-related errors.

## Notes
* Lav køretidstjek hvis en variable kommer udenfor et interval.