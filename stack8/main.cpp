#include "stack.h"
int main()
{
    // Input
    int m,n;
    cin>>m>>n;

    // Stack Creation
    stack stacks[m];

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
            stacks[id-1].push(value);
        }
        else if(instruction == "pop")
        {
            stacks[id-1].pop();
        }
    }

    // Printing and Deleting Final Stacks
    for (int i = 1; i <= m; i++)
    {
        stacks[i-1].print(i);
    }
    for (int i = m; i >= 1; i--)
    {
        stacks[i-1].~stack();
    }

    return 0;
}