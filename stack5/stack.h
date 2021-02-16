#include<iostream>
using namespace std;

// Actual definition of the stack 
class stack
{
public:
    class rep 
    {
        friend stack;

    private:
        int i ;
        rep(int i) {this->i =i;};
        rep(const rep&);
        void operator= (const rep &);
    };
    typedef rep* id;
    static id create_stack();
    static void destroy_stack(id);
    static void push_stack(id, long long);
    static long long pop_stack(id);
    static void print_stack(id);

private:
    virtual void dummy() = 0;
};
