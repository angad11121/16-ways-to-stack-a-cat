#include<iostream>
using namespace std;

// Actual definition of the stack 

class stack
{
private:

    struct rep
    {
        class stack_node
        {
            friend stack;
    
            private:
                long long value;
                stack_node *below;
        };
        stack_node *top;
    };
    rep* p;
public:
    stack();
    ~stack();
    void push(long long);
    long long pop();
    void print(int);
};
