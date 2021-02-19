#include "rep.h"

int main()
{
    // Input
    int m,n;
    cin>>m>>n;

    // Stack Creation
    ll_object * stacks[m];

    for (int i = 0; i < m; i++)
    {
        stacks[i] = make_stack();

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
            (*stacks[id-1])(stack_push,value);
        }
        else if(instruction == "pop")
        {
            (*stacks[id-1])(stack_pop);
        }
    }
    // Printing and Deleting Final Stacks
    for (int i = 1; i <= m; i++)
    {
        (*stacks[i-1])(stack_print,i);
        (*stacks[i-1])(stack_destroy);   
        stacks[i-1]->clear_oper();     
        delete stacks[i-1];
    }

    return 0;
}