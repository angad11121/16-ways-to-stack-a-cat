#include "stack.h"
#include <limits.h>

class stack_rep
{
    private:
        friend class stack;
    class stack_node
    {
        friend stack_rep;
        friend stack;

        private:
            long long value;
            stack_node *below;
    };
    stack_node *top;

    stack_rep() = default;
    stack_rep(const stack_rep&);
    void operator= (const stack_rep &);
};

// Pushes a value at the top of stack
void stack::push_stack(stack::id id, long long value)
{
    // Existance Check
    if(!id) return;

    // Pushing the value
    else
    {
        stack_rep::stack_node * temp = new stack_rep::stack_node();
        temp->value = value;
        temp->below = id->top;
        id->top = temp;
    }
}

// Pops the value at the top of stack
// Returns the popped value on success
// or LONG_LONG_MIN if pop failed
long long stack::pop_stack(stack::id id)
{

    // Existance Check
    if(!id) return LONG_LONG_MIN;

    // Nothing to pop
    else if(id->top == NULL)
    {
        return LONG_LONG_MIN;
    }

    // Pop
    else
    {
        stack_rep::stack_node *temp = id->top;
        long long value = temp->value;
        id->top = id->top->below;
        delete temp;
        return value;
    }
    return LONG_LONG_MIN;
}

// Creates a stack and provides the stack id
stack::id stack::create_stack()
{
    // Allocating New Memory
    
    id temp = new stack_rep();
    temp->top = NULL;

    return (temp);
}

// Destroys the given stack
void stack::destroy_stack(stack::id id)
{
    if (id) 
    {
        while (pop_stack(id) != LONG_LONG_MIN);
        stack::id temp = id;
        delete (temp);
        id = NULL;
    }
}

// Prints the required stack
void stack::print_stack(stack::id id, int i)
{
    // Existance Check
    if(!id) return;

    // Printing
    stack_rep::stack_node * temp = id->top;
    cout<<(i)<<" ";
    while (temp)
    {
        cout<<(temp->value)<<" ";
        temp=temp->below;
    }
    cout<<endl;
    return; 
}