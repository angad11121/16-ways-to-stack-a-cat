#pragma once
#include<iostream>
#include <limits.h>
using namespace std;

class rep
{
public:
    virtual void push(long long) = 0;
    virtual long long pop() = 0;
    virtual int size() = 0;
    virtual void print(int) = 0;
    virtual ~rep(){;}
};