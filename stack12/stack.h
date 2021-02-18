#include "rep.h"

// Actual definition of the stack 
class stack
{
    rep *p;
public:
    stack(){p = NULL; }
    ~stack() = default;
    rep* get_rep() {return p;}
    void put_rep(rep *q) {p = q;}
    void push(long long value) {p->push(value);}
    long long pop() { return p->pop();}
    void print(int i) {p->print(i);}
    int size() {return p->size();}
    static void convert_l_to_a(stack *);

};
