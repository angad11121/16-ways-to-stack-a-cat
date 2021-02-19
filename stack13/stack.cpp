#include "rep.h"

// Finds ll_object required operator 
long long ll_object::operator() (int oper, long long arg)
{
    oper_link* pp = oper_table;
    while(pp)
    {
        if (oper == pp->oper) return pp->fct(p,arg);
        pp = pp->next;
    }
    return LONG_LONG_MIN;
}

//  Adds operator to ll object
void ll_object::add_oper(int oper, PllF func)
{
    oper_link* pp = oper_table;
    oper_link* cc = oper_table;
    while(pp) 
    {
        cc = pp;
        pp = pp->next;
    }
    if(!oper_table)
        oper_table = new oper_link(oper,func,NULL);
    else
        cc->next = new oper_link(oper,func,NULL);

}

// Helps clearing operators
void ll_object::clear_oper_util(oper_link * pp)
{
    if (!pp) return;
    clear_oper_util(pp->next);
    delete (pp);
}

// Clears Operators
void ll_object::clear_oper()
{
    clear_oper_util(oper_table);
}

ll_object* make_stack(ll_object* p)
{
    if(p == 0)
        p = new ll_object(NULL, new rep);

    p->add_oper(stack_push, &stack_push_fct);
    p->add_oper(stack_pop, &stack_pop_fct);
    p->add_oper(stack_print, &stack_print_fct);
    p->add_oper(stack_destroy, &stack_destroy_fct);
    return p;
}


// Pushes a value at the top of stack
void rep::push(long long value)
{
    // Pushing the value
    stack_node * temp = new stack_node();
    temp->value = value;
    temp->below = top;
    top = temp;
}

// Pops the value at the top of stack
// Returns the popped value on success
// or LONG_LONG_MIN if pop failed
long long rep::pop()
{

    // Nothing to pop
    if(top == NULL)
    {
        return LONG_LONG_MIN;
    }

    // Pop
    else
    {
        stack_node *temp = top;
        long long value = temp->value;
        top = top->below;
        delete temp;
        return value;
    }
}


// Prints the required stack
void rep::print(int i)
{
    // Printing
    stack_node * temp = top;
    cout<<(i)<<" ";
    while (temp)
    {
        cout<<(temp->value)<<" ";
        temp=temp->below;
    }
    cout<<endl;
    return; 
}

void rep::destroy()
{
    while (pop() != LONG_LONG_MIN);
}