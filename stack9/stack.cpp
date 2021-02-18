#include "stack.h"
#include <limits.h>


// Pushes a value at the top of stack
void stack::push(long long value)
{
    // Pushing the value
    rep::stack_node * temp = new rep::stack_node();
    temp->value = value;
    temp->below = p->top;
    p->top = temp;
}

// Pops the value at the top of stack
// Returns the popped value on success
// or LONG_LONG_MIN if pop failed
long long stack::pop()
{
    // Existence Check
    if(!p)
    {
        return LONG_LONG_MIN;
    }

    // Nothing to pop
    if(p->top == NULL)
    {
        return LONG_LONG_MIN;
    }

    // Pop
    else
    {
        rep::stack_node *temp = p->top;
        long long value = temp->value;
        p->top = p->top->below;
        delete temp;
        return value;
    }
}

// Initialises stack member
stack::stack()
{
    p = new rep();
    p->top = NULL;
}

stack::~stack()
{
    while(pop() != LONG_LONG_MIN);
    delete(p);
    p = NULL;   
}

// Prints the required stack
void stack::print(int i)
{
    // Existance check
    if(!p)
    {
        return;
    }

    // Printing
    rep::stack_node * temp = p->top;
    cout<<(i)<<" ";
    while (temp)
    {
        cout<<(temp->value)<<" ";
        temp=temp->below;
    }
    cout<<endl;
    return; 
}