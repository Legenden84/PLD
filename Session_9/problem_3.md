# Question
We can think of the `new C` constructor in Java as a method that is invoked at the
level of the `class C` as opposed to at the level of a single instance of it. This might be a useful idea.
In Java, we cannot create a function that returns the list of all objects of a given class. Sometimes
it would be nice to be able to do this, though. Suggest an extension of Java that would make this
possible by drawing an analogy from the example with `new`.

* Could this have other uses as well? And are there any disadvantages?

## Answer
* Modify the `new` function in the compiler.
* So that the new `new` function creates an array of pointers to any object that inherits a super class.