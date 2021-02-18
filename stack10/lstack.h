#include "stack.h"

class lstack: public stack
{
private:
    class stack_node
    {
        friend lstack;
        private:
            long long value;
            stack_node *below;
    };
    stack_node *top;

public:
    lstack();
    ~lstack();
    void push(long long);
    long long pop();
    void print(int);

};