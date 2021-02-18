#include "rep.h"

class astack: public rep
{
private:
    int max_size;
    int curr_size;
    long long * arr;

public:
    astack(int);
    ~astack();
    void push(long long);
    long long pop();
    void print(int);
    int size();
};