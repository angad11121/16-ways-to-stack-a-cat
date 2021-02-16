#include<iostream>
using namespace std;

// Actual definition of the stack 
class stack
{
public:
    struct id {int i ;};
    
    static id create_stack();
    static void destroy_stack(id);
    static void push_stack(id, long long);
    static long long pop_stack(id);
    static void print_stack(id);
};
