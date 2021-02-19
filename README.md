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

   

2. ####  Stack 1 / Stack Identifiers

   Almost similar to the previous one but uses `struct` to store the `id`. This has an advantage over Type-Def of an `int` as the compiler could easily catch any human error caused by mixing the 2 numerical values. Since this also uses a number to identify it uses  cycles through the list of stacks to reach the one with correct `stack_id` . Decreasing the efficiency.

   

3. #### Stack 2 / Modules

   We don't do anything major semantics-wise, but we are now able to pack our "Stack" in a module (class). This lays the base foundation of all other future methods we are going to use. This method not unlike the ones above cycles through an entire list. There however is a disadvantage: The use might abuse the class and make multiple objects from a class supposed to be just an interface (virtual).

   

4. #### Stack 3 / Sealed Identifiers

   We'll fix the above given problem by making the class constructor function private and virtual.

   ```c++
   private:
   	virtual dummy() = 0;
   ```

   Class stack is now an abstract class so that no objects of class stack can be created.

   One step up the recursive ladder we reach a combination of both 3 and 4. We  see nested classes. And the `friend` property used on the local class for the base class. This adds a layer of security to the program as any function/member outside base class: `stack` can't access the private members of local class `id`.

   ``` c++
   class stack
   {
   public:
   	class id
   	{
   		friend stack;
   	private:
   		int i;
   	};
   private:
   // Some private members/methods
   // Some more...  
       virtual dummy() = 0;
};
   ```
   
   
   
   
   
   
   
5. #### Stack 4 / Packages

   **(NOTE: The PDF provides with 2 nearly similar methods of Stack 4. For the sake of simplicity lets call them 4a. and 4b. Due to them having a very minor difference I chose to implement 4a in the assignment)**

   Instead of passing identifiers around we can actually pass around the the objects or their pointers. Now since the identifiers are not numbers rather their pointers we need not make a list and cycle through the stacks to find the correct one. We may use the address as a parameter to find the correct one this increases the efficiency.

   ``` c++
   class stack
   {
   public:
   	class rep
       {
   	friend stack;
   		private:
   			/ / actual representation of a stack object
   	};
   	typedef rep* id;
   // Some members
   private:
   	virtual dummy() = 0;
   };
   ```





6. #### Stack  5 / Packages with Controlled Representations

   **(NOTE: The PDF provides with Stack5 code derived from Stack 4. But uses the code of 4b to get Stack5("b"). Since I chose to implement 4a in the assignment my derivation of 5 is slightly different methods. Same difference as 4a and 4b, but it does not affect the theory concept described.)**

   Due to `class rep` being public users could abuse it to create reps on their own . This is countered by making the constructors private such that only friend `class stack` can access the functions.

   ```c++
   class stack{
   public:
   	class rep{
   	friend stack;
   		/ / actual representation of a stack object
   		rep(int) ; / / constructor
   		rep(const rep&) ; / / copy constructor
   		void operator=(const rep&) ; / / assignment operator
   	};
   // Some Methods (Read Note: This is the minor difference in implementation)
   private:
   	virtual dummy() = 0;
   };
   ```





#### **NOTE: The next few method use initialise() and cleanup() and keep create() / destroy() as dummy not to be used. I deleted the old functions and renamed initialise to create and cleanup to destroy. **

7. #### Stack 6 / Packages with Implicit Indirection

   We try to minimise the recompilation cost by reducing inlining. `rep` is taken out of base class and kept "elsewhere". Since C++ doesn't allow defining class elsewhere it must go global

   ```c++
   class stack_rep;
   
   class stack
   {
   public:
       typedef stack_rep* id;
       //Some Methods  
   
   private:
       virtual void dummy() = 0;
   };
   ```
   
   `rep` is renamed to `stac_rep`.
   
   
   
   
   
8. #### Stack 7 / Simple Minded Types

   We tend to not use base class as an interface but a real-world object holder. Consequently the virtual constructor is removed and representation is done in class. But this uses static method with object as a parameter to update the members.

   ```c++
   class stack
   {
       // Private.
   	// Actual representation of a stack object
   public:
   	typedef stack* id;
   	// Puclic Static Methods
       // Eg: static id  initialise(id,int);
   };
   ```



9. #### Stack 8 / Types 

   We remove the condition of class methods being static so that object can directly call the functions. This method is the epitome of how most general-life-programmers would use C++ OOPs in order to quickly finish a given problem/job thus being one of the favourite method to many for "Stacking-A-Cat".

   ``` c++
   class stack
   {
   private:
       // Representation of Stack Object
   
   public:
       // Constructor & Destructor
       stack();
       ~stack();
    	// Some non-static methods (unlike Stack7)
       void push(long long);
       long long pop();
       void print(int);
   };
   ```

   That's It!

   

10. #### Stack 9 / Types with Implicit Indirection

    This is done to be able to change the representation of stack without adhering to the recompilation penalty that comes with inlining. This may not be useful in case of bad dependency analyser, in such case we need to take `rep` elsewhere.

    ```c++
    class stack{
    	struct rep{
    	// actual representation of a stack object
    	};
    	rep* p;
    public:
    	stack();
    	˜stack();
    	void push(long long);
    	long long pop();
    };
    ```



11. #### Stack 10 / Multiple Representations

    We may have multiple representations available of a stack and might want to use different ones at different cases. This was done by have two different derived classes (astack and lstack for array and list implementation respectively), and providing the base class with pure virtual functions to be overridden.

    stack:

    ```c++
    class stack{
    public:
    	virtual void push(long long) = 0;
    	virtual long longpop() = 0;
    	// ...   
    };
    ```

    

    lstack:

    ```c++
    #include"stack.h"
    class lstack: public stack
    {
    	// actual representation of a stack object
    	// in this case a linked list
    	// ...
    public:
    	lstack();
    	˜lstack();
    	void push(long long);
    	// ...
    };
    ```

    astack: **Note I used size parameter for array declaration which unlike List cant vary without costly reallocation.**

    ```c++
    #include"stack.h"
    class astack: public stack
    {
    	// actual representation of a stack object
    	// in this case an array
    	// ...
    public:
    	astack(int size);
    	˜astack();
    	void push(long long);
    	// ...
    };
    ```

    