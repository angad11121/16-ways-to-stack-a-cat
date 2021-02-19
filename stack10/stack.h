#pragma once
#include<iostream>
using namespace std;


// Actual definition of the stack 
class stack
{

public:
    virtual void push(long long) = 0;
    virtual long long pop() = 0;
    virtual void print(int) = 0;
    virtual ~stack() {;}
};
