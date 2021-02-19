#pragma once
#include "oper.h"

enum stack_oper {stack_destroy = 99, stack_push, stack_pop, stack_print};
ll_object* make_stack(ll_object* =0);