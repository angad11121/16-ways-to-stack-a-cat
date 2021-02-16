#include "stack.h"
#include <limits.h>

// Node Structure for the stack
struct stack_node
{
    long long value;
    struct stack_node *below;
};

// Structure for holding Stacks 
struct stack_addresses
{
    bool exists;
    struct stack_node *top;
    struct stack_addresses * next;
}
// Global Stacks Struct 
stacks{true,(stack_node*)NULL,(stack_addresses*)NULL};

// Pushes a value at the top of stack
void stack::push_stack(stack::id id, long long value)
{
    // Check for non-positive ids
    if(id->i <= 0) return;

    // Iteration to the correct stack.
    struct stack_addresses * current = &stacks;
    int count = 0;
    while (count!= id->i && current->next)
    {
        current = current->next;
        count++;
    }
    // Out-of-Bounds Check
    if(count!= id->i) return;
    // Existance Check
    else if(!current->exists) return;

    // Pushing the value
    else
    {
        struct stack_node * temp = new stack_node();
        temp->value = value;
        temp->below = current->top;
        current->top = temp;
    }
}

// Pops the value at the top of stack
// Returns the popped value on success
// or LONG_LONG_MIN if pop failed
long long stack::pop_stack(stack::id id)
{
    // Check for non-positive ids
    if(id->i <= 0) return LONG_LONG_MIN;

    // Iteration to the correct stack.
    struct stack_addresses * current = &stacks;
    int count = 0;
    while (count!= id->i && current->next)
    {
        current = current->next;
        count++;
    }
    // Out-of-Bounds Check
    if(count!= id->i) return LONG_LONG_MIN;
    // Existance Check
    else if (current->exists) 
    {
        // Nothing to pop
        if(current->top == NULL)
        {
            return LONG_LONG_MIN;
        }

        // Pop
        else
        {
            stack_node * temp = current->top;
            long long value = temp->value;
            current->top = current->top->below;
            delete temp;
            return value;
        }
    }
    return LONG_LONG_MIN;
}

// Creates a stack and provides the stack id
stack::id stack::create_stack()
{
    // Iteration to the correct place for stack addition 
    stack_addresses *prev = &stacks; 
    int counter = 1;
    while (prev->next && (prev->next->exists == true))
    {
        prev = prev->next;
        counter++;
    }

    // Repurposing a previously deleted stack 
    if(prev->next)
    {
        prev->next->exists = true;
    }

    // Allocating New Memory
    else
    {
        stack_addresses *temp = new stack_addresses();
        temp->exists = true;
        temp->next = NULL;
        temp->top = NULL;
        prev->next = temp;
    }
    
    id tempid = new rep();
    tempid->i = counter;  
    return (tempid);
}

// Destroys the given stack
void stack::destroy_stack(stack::id id)
{
    // Check for non-positive ids
    if(id->i <= 0) return;

    // Iteration to the correct stack.
    struct stack_addresses * current = &stacks;
    struct stack_addresses * prev = &stacks;
    int count = 0;
    while (count!= id->i && current->next)
    {
        prev = current;
        current = current->next;
        count++;
    }

    // Out-of-Bounds Check
    if(count!= id->i) return;
    
    // Popping the values out
    while (current->top)
    {
        struct stack_node * temp = current->top;
        current->top = current->top->below;
        delete temp;
    }
    
    // Saving the stack in the middle of linked list to use it for future
    if (current->exists) current->exists = false;
    // Deleting the stack with the last stack_id
    if (!current->next) 
    {
        delete current;
        prev->next = NULL;
    }
}

// Prints the required stack
void stack::print_stack(stack::id id)
{
    // Check for non-positive ids
    if(id->i <= 0) return;

    // Iteration to the correct stack.
    struct stack_addresses * current = &stacks;
    int count = 0;
    while (count!= id->i && current->next)
    {
        current = current->next;
        count++;
    }

    // Out-of-Bounds Check
    if(count!= id->i) return;
    // Existance Check
    else if(!current->exists) return;
    
    // Printing
    struct stack_node * temp = current->top;
    cout<<(id->i)<<" ";
    while (temp)
    {
        cout<<(temp->value)<<" ";
        temp=temp->below;
    }
    cout<<endl;
    return; 
}