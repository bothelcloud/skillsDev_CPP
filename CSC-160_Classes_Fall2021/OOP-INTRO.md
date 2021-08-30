# Quick Interoduction to Object-Oriented Programming (OOP)
A major differentiator between C and C++ is the inclusion of Object-Oriented Programming (OOP). This paradigm being core to C++, you want to understand how this works and ways it can be leveraged within your programs. So, what does OOP mean?

# Definition of OOP
When you are writing a program, you are work with data. That data may be representative of a number of different things in the real world. For the sake of this demonstration, let's say we are working to implement a program for managing the products for sale in a convenience store. Items we might find in a convenience store are as follows:
* Sodas
* Candy
* Beer
* Cigarettes
* Vehicle Fluids
* Donuts

Each of these items has their own characteristics and sizes to them, right? And tracking thos characteristics and attributes independently is going to require a number of different variables in your program too. Keepnig track of all that is going to be complicated as well as all the different items have attributes that will and will not relate to one another: all the items in the store will have a price, UPC, and an inventory count if not other information; items such as beer and cigarettes are going to have age restrictions while soda and donuts won't; food stuffs might also have data such as expiration of the products to track as well. So with all this data you have to track, what are you supposed to do?

So just thinking about this outside the context of progamming, we could think of all the items to relate to one another within the following chain:
- Store Items
   - Food Items
      - Candy items
      - Soda Items
      - Gum Items
      - Beer Items
   - Vehicle Items
      - Oil
      - Windshield fluid
   - Gasoline
   - Tabacco Items
      - Cigarettes
      - Chew

And again, all of these are going to have prices, UPCs, and other items that are going to be consistent between all the different items. That's where OOP provides us a solution for our programming issues. OOP is based on four core pinciples that we will talk about in a second, but essentially it allows you to define characteristics and methods of interaction for objects (items) that are created during program operation. Each type (class) of item is set with different attributes and characteristics, things that can happen to it, and how they interact with one another. This also allows defintion of one type (class) that get's it's attributes and methods of operation from another class, thereby allowing you to program those once and then reuse the programming again and again with each successive type (class).

So now that we have a basic understanding of what OOP is and how it is helpful, let's get into some specifics about the topic.

# Four Tenants of OOP Programming
Within the context of the C++ programming language, *objects* are the individual items that are created when implementing a specific **class** for that object in the programming languge. Just like `int` and `float` have classes within their own right, C++ allows programmers to create their own classes for use in programs. These classes are then utilized to create the objects that are worked on and handled by the program to define what they contain, how they operate. They provide programmers with different capabiltiies that were previously not available within programming languges, each discussed in the following sections.

## Encapsulation
**Encapsulation** allows the different classes and items to be uniquely contained within discrete units and treated as such. This provides you with the ability to make edits in one section of code, and so long as input and outputs are unchanged, the modifications will be self-contained within the class.

## Abstraction
**Abstraction** deals with the thought that "you don't need to know how the sausage is made." Like we were talking about aove, you can change how the item works internally without knowing all the details of it, and as long as input and output are not changed, there should be no issues and improve the abilities of the program.

## Inheritance
When one class uses another class as a basis, that is the allowance of **inheritance** of classes. This allows for a great deal of reuse of code and to reduce the time to delivery of a program to a customer. 

## Polymorphism
An extension of inheritence is **polymorphism** where you define how interactions between objects changes as well. This is where you have on class that will redefine how a `+` operator will treat `int`, `float`, `string` and other instances of that object when encountered in code.

# References
- [What Are the Four Basics of Object-Oriented Programming?](https://www.indeed.com/career-advice/career-development/what-is-object-oriented-programming)
- [What is Object-Oriented Programming? OOP Explained](https://blog.udemy.com/what-is-object-oriented-programming/)
- [C++ OOP](https://www.w3schools.com/cpp/cpp_oop.asp)