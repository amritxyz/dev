Object-Oriented Programming (OOP) is a programming paradigm based on the concept of "objects," which can contain data in the form of fields (often called **attributes**) and code in the form of methods (functions or procedures). OOP organizes software design around data, or objects, rather than functions and logic.

Here are the **core concepts of OOP**:

### 1. **Classes and Objects**
   - **Class**: A blueprint or template for creating objects. It defines the properties (attributes) and behaviors (methods) that the objects of that class will have.
     ```java
     class Person {
         String name;
         int age;

         void speak() {
             System.out.println("Hello, my name is " + name);
         }
     }
     ```
   - **Object**: An instance of a class. When you create an object, you are creating an instance of the class with its own set of data.
     ```java
     Person p1 = new Person();  // Creating an object of class Person
     p1.name = "John";
     p1.age = 30;
     p1.speak();  // Outputs: Hello, my name is John
     ```

### 2. **Encapsulation**
   - **Encapsulation** is the concept of wrapping data (attributes) and methods (functions) into a single unit called a class and restricting access to the inner workings of the class.
   - This is achieved by using **access modifiers** such as `private`, `protected`, and `public` to control how the data can be accessed.
   - It helps in data hiding and ensures the integrity of the data.

   ```java
   class Person {
       private String name;
       private int age;

       public String getName() {
           return name;
       }

       public void setName(String name) {
           this.name = name;
       }
   }
   ```

### 3. **Abstraction**
   - **Abstraction** is the concept of hiding complex implementation details and showing only the essential features of an object.
   - It helps to reduce complexity and allows the programmer to focus on high-level logic rather than details.
   - This is typically achieved using **abstract classes** and **interfaces**.

   ```java
   abstract class Animal {
       abstract void sound();
   }

   class Dog extends Animal {
       void sound() {
           System.out.println("Bark");
       }
   }
   ```

   In the above example, `sound()` is abstract in the `Animal` class, meaning it doesn't have an implementation. The `Dog` class provides its own implementation of the `sound()` method.

### 4. **Inheritance**
   - **Inheritance** allows a class (subclass/child class) to inherit the properties and methods of another class (superclass/parent class).
   - It promotes code reuse and establishes a relationship between classes.
   - A class can inherit from only one superclass in languages like Java (single inheritance), though multiple interfaces can be implemented.

   ```java
   class Animal {
       void eat() {
           System.out.println("Eating...");
       }
   }

   class Dog extends Animal {
       void bark() {
           System.out.println("Barking...");
       }
   }

   public class Main {
       public static void main(String[] args) {
           Dog d = new Dog();
           d.eat();  // Inherited method
           d.bark(); // Own method
       }
   }
   ```

### 5. **Polymorphism**
   - **Polymorphism** means "many forms." It allows a method or object to take on multiple forms, and it can be achieved in two ways:
     - **Method Overloading**: Same method name but with different parameter types or number of parameters.
     - **Method Overriding**: A method in a subclass that has the same name, return type, and parameters as a method in the superclass, but with a different implementation.

   **Method Overloading Example**:
   ```java
   class Calculator {
       int add(int a, int b) {
           return a + b;
       }

       double add(double a, double b) {
           return a + b;
       }
   }
   ```

   **Method Overriding Example**:
   ```java
   class Animal {
       void sound() {
           System.out.println("Some sound");
       }
   }

   class Dog extends Animal {
       @Override
       void sound() {
           System.out.println("Bark");
       }
   }
   ```

   In the above case, `Dog` overrides the `sound()` method of the `Animal` class.

### 6. **Composition**
   - **Composition** is the concept where one class is made up of one or more objects of other classes.
   - It's often referred to as a "has-a" relationship because one class **has** another class as part of it.
   - Composition provides more flexibility and is preferred over inheritance in many cases.

   ```java
   class Engine {
       void start() {
           System.out.println("Engine starting...");
       }
   }

   class Car {
       Engine engine = new Engine();

       void drive() {
           engine.start();
           System.out.println("Car is driving");
       }
   }
   ```

### 7. **Interfaces**
   - An **interface** defines a contract that a class must follow, but it does not provide implementation. Any class that implements the interface must provide the behavior described in the interface.
   - Interfaces allow multiple classes to implement the same methods in different ways.

   ```java
   interface Animal {
       void sound();
   }

   class Dog implements Animal {
       public void sound() {
           System.out.println("Bark");
       }
   }
   ```

### 8. **Constructor**
   - A **constructor** is a special method used to initialize objects. It is called when an object is instantiated.
   - Constructors can have parameters and can be overloaded.

   ```java
   class Person {
       String name;
       int age;

       // Constructor
       Person(String name, int age) {
           this.name = name;
           this.age = age;
       }

       void introduce() {
           System.out.println("Hello, my name is " + name + " and I'm " + age + " years old.");
       }
   }
   ```

### 9. **Method and Constructor Overloading**
   - **Method Overloading**: When two or more methods in a class have the same name but different parameter types.
   - **Constructor Overloading**: When a class has more than one constructor with different parameter lists.

   ```java
   class Box {
       int length;
       int width;

       // Constructor with two parameters
       Box(int l, int w) {
           length = l;
           width = w;
       }

       // Constructor with one parameter
       Box(int l) {
           length = l;
           width = l;  // Default width equals length
       }
   }
   ```

---

### Summary of OOP Concepts:
1. **Classes and Objects**: Blueprint and instances.
2. **Encapsulation**: Hiding internal details and exposing controlled access.
3. **Abstraction**: Hiding complex implementation and exposing only necessary functionality.
4. **Inheritance**: Deriving new classes from existing ones.
5. **Polymorphism**: Many forms, method overloading and overriding.
6. **Composition**: Building complex objects from simpler ones.
7. **Interfaces**: Defining behavior that must be implemented.
8. **Constructor**: Initializing objects.
9. **Overloading**: Having multiple methods or constructors with the same name but different signatures.

Together, these concepts form the foundation of object-oriented programming and are key to designing flexible, modular, and reusable code.
