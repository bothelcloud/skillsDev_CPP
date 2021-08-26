# How Compilers Work
The C++ takes your source code to application through three major steps:
1. **Preprocessing** that gathers the source and performs other operations to prepare for compiling that file into an object
2. **Compilation** that takes the source from the file along with the source from other imported code and renders a compiled object for use in the overall program
3. **Linking** where all the objects and assembles them into the final executable from all the different objects

Here are some great sources to read up on compilation in C++:
* [How C++ Works: Understanding Compilation | Toptal](https://www.toptal.com/c-plus-plus/c-plus-plus-understanding-compilation)
* [Quick overview of how Clang works internally](https://cppdepend.com/blog/?p=321)

# Namespaces
Namespaces are organization containers for functions, classes, etc. that may have the same names within them. So two functions name `myfunction()` could exist in the `space0` and `space1` namespace and do two completely different things. You could call each in the same source file using them in the following manner:
    
    space0::myfunction();
    space0::myfunction();

And by having a `using` statement in our code before the different functions, you let the compiler know which one to assume when it is not implicit which one is appropriate. For example, this makes it so `space0::myfunction()` is assumed and you would have to explicitly type in `space1::` to use it's version:

    using space0;
    myfunction();
    space1::myfunction();

Here are some resources on namespaces:
* [Namespaces (C++) | Microsoft Docs](https://docs.microsoft.com/en-us/cpp/cpp/namespaces-cpp?view=msvc-160)
* [Namespaces in C++](https://www.tutorialspoint.com/cplusplus/cpp_namespaces.htm)

# Variables and their Types
For right now, a variable **type** is a definition of what can be stored within it and how that data is handled in memory. 

Say you have a variable with the type `int` specified for it. Because `int` is specified, there are certain things you can do with `int` variables that you can't with antoher variable and things `int` variables can't do that others can. Like, `int` variables are only whole numbers that are either positive or negative; `float` and `double` are types that allow decimal values within them (whcih we will get to later). To understand the ranges, we have look at how computers store data first.

Computers store data in the form of 1s and 0s at the most rudamentary level. The patterns of those 1s and 0s are what gives us all that we do and see on computers today. Wehn we are programming and storing data in computer memory, we have to define what set of 1s and 0s is the data we are working with at that moment. That's where a variable comes in; it says to the computer "when referencing the set of 1s and 0s known as `myvariable`, it exists here." when the compiler is done assmnbling the program. How big and how much of that space is that pattern of 1s and 0s is defined by, you guessed it, the type `int` for the variable.

`int` type variables are constructed using 32-bits within the memory (4 bytes of memory; each byte is 8 bits). Because we have to use these bits in patterns of 1s and 0 as a base for our numbers that can be worked with in the integer, we are then limited by the amount of 1 and 0 patterns we can make when we have 32 of them and order matters. 1 bit will go to the sign of the variable, whether its positive or negative, so thats alread one bit down. Thus, we have -2,147,483,648 to 2,147,483,647 as our range of whole numbers that we can store with the variable based on that limitation. As a challenge question: if one bit is for the sign, then why are the positiev and negative sides no equal?

Here are some references I thought looked good on variables and types:
* [C++ Data Types](https://www.geeksforgeeks.org/c-data-types/#:~:text=C%2B%2B%20provides%20the%20following%20user-defined%20datatypes%3A%20This%20article,Character%20data%20type%20is%20used%20for%20storing%20characters.)
* [C++ Variables](https://www.w3schools.com/cpp/cpp_variables.asp)
* [Data Type Ranges | Microsoft Docs](https://docs.microsoft.com/en-us/cpp/cpp/data-type-ranges?view=msvc-160)
