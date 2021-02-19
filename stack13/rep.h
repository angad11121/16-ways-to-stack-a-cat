#pragma once
#include "stack.h"

// Struct for representation
struct rep
{
    class stack_node
    {
        friend rep;
        private:
            long long value;
            stack_node *below;
    };
    stack_node *top;

    void push(long long);
    long long pop();
    void print(int);
    void destroy();
};

/* 
    Stack Functions (Interface) 
*/
static long long stack_push_fct(void *p , long long value)
{
    ((rep *) p)->push(value);
    return LONG_LONG_MIN;
}

static long long stack_pop_fct(void *p , long long)
{
    return ((rep *) p)->pop();
}

static long long stack_print_fct(void *p , long long value)
{
    ((rep *) p)->print((int) value);
    return LONG_LONG_MIN;
}


static long long stack_destroy_fct(void *p , long long)
{
    ((rep *) p)->destroy();
    delete ((rep *)p);
    p = NULL;
    return LONG_LONG_MIN;
}

