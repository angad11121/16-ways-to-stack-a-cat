#include "stack.h"
#include <limits.h>


// Pushes a value at the top of stack
void stack::push(long long value)
{
    // Pushing the value
    stack_node * temp = new stack_node();
    temp->value = value;
    temp->below = top;
    top = temp;
}

// Pops the value at the top of stack
// Returns the popped value on success
// or LONG_LONG_MIN if pop failed
long long stack::pop()
{

    // Nothing to pop
    if(top == NULL)
    {
        return LONG_LONG_MIN;
    }

    // Pop
    else
    {
        stack_node *temp = top;
        long long value = temp->value;
        top = top->below;
        delete temp;
        return value;
    }
}

// Initialises stack member
stack::stack()
{
    top = NULL;
}

stack::~stack()
{
    while(pop() != LONG_LONG_MIN);
}

// Prints the required stack
void stack::print(int i)
{
    // Printing
    stack_node * temp = top;
    cout<<(i)<<" ";
    while (temp)
    {
        cout<<(temp->value)<<" ";
        temp=temp->below;
    }
    cout<<endl;
    return; 
}