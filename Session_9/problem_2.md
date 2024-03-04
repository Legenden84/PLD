# Question
Consider this Java program:
```java
class A {
  void f () { System.out.println("A"); }
  void g () { this.f (); }
}

class B extends A {
  void f () {System.out.println("B"); }
}

public class Foo {
public static void main ( String [] args ) {
    B b = new B();
    b.g (); }
}
```

What does this program output, and why? Use the pointer model to justify your answer.
If we change the second line to
`private void f () {System.out.println("A"); }`
what will happen then, and why?

## Answer
1. B
2. A