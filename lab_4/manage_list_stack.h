#ifndef MANAGE_LIST_STACK_H
#define MANAGE_LIST_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "types.h"

void init_list_stack(struct stack_list *stack);
void print_list_stack(struct stack_list *stack);
void push_list_stack(struct stack_list **stack, char *new_string);
char * pop_list_stack(struct stack_list **stack);
void print_address(struct stack_list *stack);
void print_list_exersize(struct stack_list **stack);
void print_stack_address(struct stack_list *stack);

#endif // MANAGE_LIST_STACK_H
