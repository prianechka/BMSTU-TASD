#ifndef MANAGE_ARRAY_STACK_H
#define MANAGE_ARRAY_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include <time.h>

void print_array_stack(struct stack_array *stack);
void init_array_stack(struct stack_array *stack);
void push_array_stack(struct stack_array *stack, char * added_string);
char *pop_array_stack(struct stack_array *stack);
void print_array_exersize(struct stack_array *stack);

#endif // MANAGE_ARRAY_STACK_H
