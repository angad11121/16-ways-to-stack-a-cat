#include "stack.h"
int main()
{
    // Input
    int m,n;
    cin>>m>>n;

    // Stack Creation
    for (stack_id i = 1; i <= m; i++)
    {
        create_stack();
    }

    // Queries
    stack_id id;
    string instruction;
    long long value;
    for (int i = 0; i < n; i++)
    {
        cin>>id>>instruction;
        if (instruction == "push")
        {
            cin>>value;
            push_stack(id,value);
        }
        else if(instruction == "pop")
        {
            pop_stack(id);
        }
    }

    // Printing and Deleting Final Stacks
    for (stack_id i = 1; i <= m; i++)
    {
        print_stack(i);
    }
    for (stack_id i = m; i >= 1; i--)
    {
        destroy_stack(i);
    }

    return 0;
}