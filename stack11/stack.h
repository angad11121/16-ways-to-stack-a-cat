#include<iostream>
#include <limits.h>
using namespace std;

class noop{};

// Actual definition of the stack 
class stack
{

public:
    virtual void push(long long) = 0;
    virtual long long pop() = 0;
    virtual void print(int) = 0;
    virtual ~stack() {};
};

class lstack: public stack
{
public:
    class stack_node
    {
        friend lstack;
        private:
            long long value;
            stack_node *below;
    };
    stack_node *top;

public:
    lstack(int);
    lstack(noop);
    ~lstack();
    void push(long long);
    long long pop();
    void print(int);

};