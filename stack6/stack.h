#include<iostream>
using namespace std;

// Actual definition of the stack

// Forward Declaration
class stack_rep;

class stack
{
public:
    typedef stack_rep* id;
    
    static id create_stack();
    static void destroy_stack(id);
    static void push_stack(id, long long);
    static long long pop_stack(id);
    static void print_stack(id,int);

private:
    virtual void dummy() = 0;
};

