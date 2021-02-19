#pragma once
#include <iostream>
#include <limits.h>
using namespace std;

typedef long long (*PllF) (void *, long long);


// Operations Struct
struct oper_link
{
    oper_link *next;
    int oper;
    PllF fct;

    oper_link(int oo, PllF ff, oper_link * nn) : oper(oo), fct(ff), next(nn) {}
};


// Class holding a stack and possible operations
class ll_object
{
    // For Rep 
    void *p;

    // List of Operations allowed
    oper_link* oper_table;

public:
    ll_object(oper_link* tbl = 0 , void* rep = 0) : oper_table(tbl), p(rep) { }
    long long operator() (int oper ,long long arg = 0);
    void add_oper (int, PllF);
    void clear_oper();
    void clear_oper_util(oper_link*);
};

