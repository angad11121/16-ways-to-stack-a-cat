#include "lstack.h"
#include "astack.h"
int main()
{
    // Input
    int m,n;
    cin>>m>>n;

    // Stack Creation
    astack* stacks[m];
    for (int i = 0; i < m; i++)
    {
        stacks[i] = new astack(n);
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
            stacks[id-1]->push(value);
        }
        else if(instruction == "pop")
        {
            stacks[id-1]->pop();
        }
    }

    // Printing and Deleting Final Stacks
    for (int i = 1; i <= m; i++)
    {
        stacks[i-1]->print(i);
        delete(stacks[i-1]); 
    }
    return 0;
}