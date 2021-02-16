#include "stack.h"
int main()
{
    // Input
    int m,n;
    cin>>m>>n;

    // Stack Creation
    stack_id stacks[m];
    for (int i = 1; i <= m; i++)
    {
       stacks[i-1] = create_stack();
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
            push_stack(stacks[id-1],value);
        }
        else if(instruction == "pop")
        {
            pop_stack(stacks[id-1]);
        }
    }

    // Printing and Deleting Final Stacks
    for (int i = 1; i <= m; i++)
    {
        print_stack(stacks[i-1]);
    }
    for (int i = m; i >= 1; i--)
    {
        destroy_stack(stacks[i-1]);
    }

    return 0;
}