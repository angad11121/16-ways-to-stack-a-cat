#include<iostream>
using namespace std;

// Actual definition of the stack 
struct stack_id {int id ;};

stack_id create_stack();
void destroy_stack(stack_id);
void push_stack(stack_id, long long);
long long pop_stack(stack_id);
void print_stack(stack_id);
