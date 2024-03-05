# Programming paradigms learning goals

## 1. Classify Programming Languages According to Paradigms
Programming languages can be classified based on different paradigms, such as:

- **Imperative Paradigm**: Languages like C and Python, which focus on how a program operates via statements that change a program state.
- **Declarative Paradigm**: Languages such as SQL and HTML, where the focus is on what the program should accomplish, without explicitly listing commands or steps to achieve it.
- **Functional Paradigm**: Languages like Haskell and Erlang, which treat computation as the evaluation of mathematical functions without state changes.
- **Object-Oriented Paradigm**: Languages such as Java and C++, where data and methods are encapsulated within objects.
- **Logic Paradigm**: Languages like Prolog, which are based on formal logic.

Each paradigm can be characterized by its approach to data flow (how data is passed and transformed), execution ordering (sequential, concurrent, event-driven, etc.), and structuring (how the code is organized).

## 2. Object-Oriented Languages - Inheritance and Prototypes

### Simple Inheritance
Simple inheritance in object-oriented programming allows a class to inherit properties and methods from a single parent class. This means that the child class (subclass) can use the code defined in the parent class (superclass), promoting code reusability and reducing redundancy.

**Example in Java:**
```java
class Vehicle {
  public void move() {
    System.out.println("The vehicle is moving.");
  }
}

class Car extends Vehicle {
  public void display() {
    move(); // Inherited from Vehicle class
    System.out.println("This is a car.");
  }
}
```

In this Java example, Car inherits from Vehicle using the extends keyword. The Car class can access the move method defined in Vehicle.

### Multiple Inheritance
Multiple inheritance allows a class to inherit features from more than one parent class. However, not all programming languages support this due to the complexity it introduces (e.g., the Diamond Problem). Languages like C++ support multiple inheritance, while others like Java and C# do not.

**Example in C++:**
```c++
class Engine {
public:
  void startEngine() {
    std::cout << "Engine started." << std::endl;
  }
};

class Body {
public:
  void createBody() {
    std::cout << "Body created." << std::endl;
  }
};

// Inherits from both Engine and Body
class Car : public Engine, public Body {
public:
  void drive() {
    startEngine(); // Inherited from Engine
    createBody();  // Inherited from Body
    std::cout << "Driving the car." << std::endl;
  }
};

```
In this C++ example, Car inherits from both Engine and Body, meaning it has access to methods from both classes.

### Prototypes
Prototype-based programming is a style of object-oriented programming where cloning (prototyping) is used instead of class-based inheritance. JavaScript is a well-known prototype-based language where each object can serve as a prototype for another object.

- **Example in JavaScript:**
```javascript
let vehicle = {
  move: function() {
    console.log("The vehicle is moving.");
  }
};

let car = Object.create(vehicle); // car is an object with vehicle as its prototype
car.drive = function() {
  this.move(); // Inherits move from vehicle
  console.log("The car is driving.");
};

car.drive(); // Output: The vehicle is moving. The car is driving.

```
In this JavaScript example, car is an object that inherits from the vehicle object using Object.create. It has access to the move method from its prototype.

### Pointer Models Underlying Inheritance and Prototypes
The pointer model in programming languages refers to the way memory addresses (pointers) are used to access and manipulate data. In object-oriented languages with inheritance, pointers are crucial for polymorphism, where a base class pointer can refer to objects of derived classes.

**Example in C++ (Pointers with Inheritance):**
```c++
class Base {
public:
  virtual void show() {
    std::cout << "Base class show function called." << std::endl;
  }
};

class Derived : public Base {
public:
  void show() override {
    std::cout << "Derived class show function called." << std::endl;
  }
};

int main() {
  Base* basePtr;
  Derived derivedObj;
  basePtr = &derivedObj; // Base class pointer pointing to derived class
  basePtr->show();       // Calls Derived's show function due to virtual function
}

```
In the C++ example, a base class pointer (basePtr) points to an object of the derived class (derivedObj), and due to the virtual function show, the derived class's implementation is called.

## 3. Understanding and Using Prolog Terminology

Prolog is a logic programming language used in artificial intelligence and computational linguistics. It is based on the concept of logic programming, where the program logic is expressed in terms of relations, represented as facts and rules.

#### Key Terms:

- **Facts**: These are the basic assertions about information in the database, written in the form of `predicate(term1, term2, ...).`. 
  - Example: `sibling(alice, bob).` states that Alice is a sibling of Bob.

- **Rules**: These are logical statements that define how to infer new facts from existing facts, written as `head :- body.`.
  - Example: 
    ```prolog
    ancestor(X, Y) :- parent(X, Y).
    ancestor(X, Y) :- parent(X, Z), ancestor(Z, Y).
    ```
    This rule defines an ancestor recursively.

- **Queries**: These are questions posed to the Prolog system, checking if certain facts or rules can be satisfied, written as `?- body.`.
  - Example: `?- ancestor(alice, bob).` asks if Alice is an ancestor of Bob.

- **Predicates**: The basic form of Prolog programming, defining relations between terms.
  - Example: `parent` and `ancestor` are predicates in the earlier rule.

- **Terms**: The basic units of Prolog's data structure, which include constants, variables, and compound terms (functors applied to arguments).
  - Constants are typically atoms like 'alice' or numbers like `42`.
  - Variables are denoted by identifiers starting with an uppercase letter or underscore, like `X` or `_Y`.
  - Compound terms are combinations of functors with terms, like `parent(alice, bob)`.

- **Functors**: These are the "function" part of compound terms, which apply to a list of arguments (terms).
  - Example: In `parent(alice, bob)`, `parent` is the functor.

- **Atoms**: The simplest form of terms, usually lowercase identifiers like 'alice', or numbers.

- **Variables**: Placeholders for any term in a Prolog program, which are uppercase, such as `X`, `Y`, or `_Z`.

- **Lists**: Prolog uses lists to represent ordered collections of terms, denoted by square brackets `[term1, term2, ...]`.

- **Conjunction (and)**: Represented by a comma `,`, used to indicate that all included predicates must be satisfied.
- **Disjunction (or)**: Represented by a semicolon `;`, used when satisfying at least one of the predicates is sufficient.

- **Recursion**: The process by which a rule calls itself with different arguments to solve a problem incrementally.
- **Backtracking**: Prolog's mechanism of searching for all possible ways to satisfy a query, reversing previous decisions if a predicate fails.

### Reading and Understanding Simple Programs in Pure Prolog

Prolog programs consist of facts, rules, and queries:

- **Facts** represent foundational truths about the domain.
- **Rules** define logical relationships between facts.
- **Queries** are used to extract information from the database of facts and rules.

#### Example Prolog Program:

```prolog
% Facts about individuals' likes
likes(alice, ice_cream).
likes(bob, ice_cream).
likes(charlie, cheese).

% A simple rule defining friendship based on common interests
friend(X, Y) :- likes(X, Z), likes(Y, Z), X \= Y.

% Query to find out if two people are friends
?- friend(alice, bob).
```

The `likes` predicate describes a liking relationship between two entities. The `friend` rule infers a friendship based on common interests. The query checks if Alice and Bob have a common interest and thus are friends according to the `friend` rule.

Understanding Prolog Program Execution:

* **Matching**: Prolog attempts to match terms in a query with facts and the heads of rules in its database.
* **Binding**: Variables in queries are bound to actual terms during matching to satisfy the query.
* **Searching**: Prolog searches through facts and applicable rules in the order they're defined.
* **Backtracking**: If Prolog can't satisfy a rule or query, it backtracks to try different possibilities for variable bindings.

The `friend` predicate in the program above demonstrates these concepts. Prolog will bind `X` to alice and `Y` to bob, then search for a `Z` that they both like (which is `ice_cream`), fulfilling the friendship rule.

## 5. Understanding the Underlying Ideas of Resolution in Logic Programming

Logic programming, as exemplified by Prolog, relies on a few key computational processes—chief among these are **resolution**, **unification**, and **backtracking**. These processes are what allow Prolog to solve logical queries.

### Resolution
Resolution is a rule of inference that allows new knowledge to be inferred. In logic programming, it's used to derive conclusions from known facts and rules. When you pose a query to a Prolog program, the Prolog engine uses resolution to prove the query from the rules and facts it has.

### Unification
Unification is the process of making two logical terms identical. Prolog uses this process to match facts and rules in the database with the current goal it's trying to prove. When Prolog tries to match a rule or a fact with the goal, it attempts to unify the terms in the goal with the terms in the head of the rule or the fact.

- **Example of Unification**: Consider a fact `parent(bob, alice).` and a query `?- parent(X, alice).` Prolog will unify `X` with `bob` to satisfy the query.

### Backtracking
Backtracking is a search strategy that tries different possibilities sequentially. When Prolog tries to prove a goal, and there's more than one way to prove it, Prolog will try the first method. If that fails to prove the goal, Prolog will backtrack and try the next method. This process continues until either the goal is proved or all possibilities have been exhausted.

- **Example of Backtracking**: If there are several facts like `parent(bob, alice).`, `parent(charlie, alice).`, and the query `?- parent(X, alice).`, Prolog will first bind `X` to `bob`. If later rules or goals fail because of this binding, Prolog will backtrack and bind `X` to `charlie` to try again.

### Combined Example in Prolog

```prolog
% Facts
parent(bob, alice).
parent(alice, sarah).
parent(john, bob).

% Rule for grandparent relationship
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).

% Query to find a grandparent
?- grandparent(Grandparent, sarah).
