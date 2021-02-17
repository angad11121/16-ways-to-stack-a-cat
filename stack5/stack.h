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
        class stack_node
        {
            friend rep;
            friend stack;

            private:
                long long value;
                struct stack_node *below;
        };
        stack_node *top;

        rep() = default;
        rep(const rep&);
        void operator= (const rep &);
    };
    typedef rep* id;
    static id create_stack();
    static void destroy_stack(id);
    static void push_stack(id, long long);
    static long long pop_stack(id);
    static void print_stack(id,int);

private:
    virtual void dummy() = 0;
};
