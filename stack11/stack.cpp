#include "llstack.h"
#include <limits.h>


// Pushes a value at the top of stack
void lstack::push(long long value)
{
    // Pushing the value
    stack_node * temp = new stack_node();
    temp->value = value;
    temp->below = top;
    top = temp;
}
void llstack::push(long long value)
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
long long lstack::pop()
{
    // Nothing to pop
    if(top == NULL) return LONG_LONG_MIN;
    
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
long long llstack::pop()
{
    // Nothing to pop
    if(top == NULL) return LONG_LONG_MIN;
    
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
lstack::lstack(int)
{
    top = NULL;
}
lstack::lstack(noop x)
{
    top = NULL;
}
lstack::~lstack()
{
    while(pop() != LONG_LONG_MIN);
}
llstack::~llstack()
{
    while(pop() != LONG_LONG_MIN);
}

// Prints the required stack
void lstack::print(int i)
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
void llstack::print(int i)
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
void llstack::l_to_ll(lstack &s)
{
    noop xx;
    new (&s) llstack(xx);
}