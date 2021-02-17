#include "stack.h"
int main()
{
    // Input
    int m,n;
    cin>>m>>n;

    // Stack Creation
    stack::id stacks[m];
    for (int i = 1; i <= m; i++)
    {
       stacks[i-1] = stack::create_stack();
    }

    // Queries
    int id;
    string instruction;
    long long value;
    for (int i = 0; i < n; i++)
    {
        cin>>id>>instruction;
        if (instruction == "push")
        {
            cin>>value;
            stack::push_stack(stacks[id-1],value);
        }
        else if(instruction == "pop")
        {
            stack::pop_stack(stacks[id-1]);
        }
    }

    // Printing and Deleting Final Stacks
    for (int i = 1; i <= m; i++)
    {
        stack::print_stack(stacks[i-1],i);
    }
    for (int i = m; i >= 1; i--)
    {
        stack::destroy_stack(stacks[i-1]);
    }

    return 0;
}