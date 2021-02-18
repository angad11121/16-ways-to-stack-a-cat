#include "stack.h"

class astack: public stack
{
    //jjj 
private:
    int max_size;
    int curr_size;
    long long * arr;

public:
    public:
    astack(int);
    ~astack();
    void push(long long);
    long long pop();
    void print(int);
};