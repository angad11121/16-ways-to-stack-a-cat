#include "stack.h"

class llstack : public lstack
{

public:
    public:
    class stack_node
    {
        friend llstack;
        private:
            long long value;
            stack_node *below;
    };
    stack_node *top;

    llstack(int i) : lstack(i){}
    llstack(noop x) : lstack(x){}
    ~llstack();
    static void l_to_ll(lstack&);
    void push(long long);
    long long pop();
    void print(int);
    void *  operator new (size_t, void * p) {return p;}
};