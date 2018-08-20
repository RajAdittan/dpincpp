# dpincpp
Design Patterns in C++

## SOLID Principle
### SRP: Single Responsibility Principle
- A class should only have one reason to change
- Separation of concerns - different classes handling different, independent tasks/problems

### OCP: Open-Close Principle
- Classes should be open for extension but closed for modification

### LSP: Liskov Substitution Principle
- You should be able to substitute a base type for a subtype

### ISP: Interface Segregation Principle
- Don't put too much into an interface; split into separate interfaces

### DIP: Dependency Inversion Principle
- High-level modules should not depend upon low-level ones; use abstractions

## GOF Patterns
GOF Patterns are described in "Design Patterns: Elements of Reusable Object-Oriented Software is a software engineering" book describing software design patterns. The book's authors are Erich Gamma, Richard Helm, Ralph Johnson and John Vlissides with a foreword by Grady Booch. The book is divided into two parts, with the first two chapters exploring the capabilities and pitfalls of object-oriented programming, and the remaining chapters describing 23 classic software design patterns. The book includes examples in C++ and Smalltalk. - wikipedia
### Creational Patterns
Creational patterns are ones that create objects for you, rather than having you instantiate objects directly. - wikipedia
#### AbstractFactory Pattern
Group object factories using a common theme by introducing a base factory class and relevant concrete factories. Specify class name to create instance of relevant implementation.
#### FactoryMethod Pattern
Creates objects without specifying exact class to create by adding create methods much closer to the implementation class.
#### Builder Pattern
Constructs complex objects by separating construction and representation by composing functional objects to a single multi functional complex object.
#### Singleton
Restricts object creation for a class to only one instance.
#### Prototype
Creates objects by cloning an existing object so that object creational complexity (time) is reduced.

### Structural Patterns
#### Adapter
#### Bridge
#### Composite
#### Decorator
#### Facade
#### Flyweight
#### Proxy

### Behavioral Patterns
