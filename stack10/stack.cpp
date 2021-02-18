#include "stack.h"
#include "lstack.h"
#include "astack.h"
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
void astack::push(long long value)
{
    if (curr_size >= max_size) return;
    arr[curr_size] = value;
    curr_size++;
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

long long astack::pop()
{
    if (curr_size <= 0) return LONG_LONG_MIN;
    curr_size--;
    return arr[curr_size];
}
// Initialises stack member
lstack::lstack()
{
    top = NULL;
}
astack::astack(int n)
{
    max_size = n;
    curr_size = 0;
    arr = new long long [max_size];
}
lstack::~lstack()
{
    while(pop() != LONG_LONG_MIN);
}

astack::~astack()
{
    while(pop() != LONG_LONG_MIN);
    delete (arr);
    arr = NULL;
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

void astack::print(int i)
{
    cout<<(i)<<" ";
    for (int j = curr_size; j > 0 ; j--)
    {
        cout<<arr[j-1]<<" ";
    }
    cout<<endl;
    return;
}