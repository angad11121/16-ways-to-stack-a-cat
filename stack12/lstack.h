#include "rep.h"

class lstack: public rep
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
    int max_size;
    int curr_size;

public:
    lstack(int);
    ~lstack();
    void push(long long);
    long long pop();
    void print(int);
    int size();
};