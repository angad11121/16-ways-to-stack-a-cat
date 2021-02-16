# Sixteen Ways to Stack a Cat

### (or long long in this case)



#### **INTRODUCTION**

This assignment looks onto various ways of implementing stacks. Through this problem it talks about various data-hiding techniques and their trade-offs. These are the techniques that are found in different languages like C, ADA, etc. It is a good example to show how malleable C++ can be. As the various methods are to be implemented in the above language.



#### **PRE-REQUISITES**

In order to be able to compile and run the assignment following steps are required:

- Unzip the Zipped File
- Open the directory Assignment
- Open the terminal in this directory and run `make` . This will compile the binaries that will saved in 'Assignment/Bin/'
- These binaries are compiled using three initial files *main.cpp, stack.cpp, and stack.h*  
- These Binaries can then be executed with the required input values



#### **STACKING TECHNIQUES**

1. #### Stack 0 / Files as Modules

   This method uses plain old C-like syntax for most of its aspects. There is an extensive usage of structures under linked list implementation in forming the stacks. Although, the true definition of the stack and its parameters (as seen in the header file) does not use any structure, rather it Type-Defines an `int` as a `stack_id` datatype. This is particularly a primitive and unsafe practice as the two datatypes are interchangeable and upon the mistake of the user may cause an error.  Another issue is that the stacks are numbered and the user does not have the ability to reach a stack directly through an object/pointer, instead cycles through the list of stacks to reach the one with correct `stack_id` .

   



