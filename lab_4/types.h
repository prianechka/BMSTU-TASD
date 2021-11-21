#ifndef TYPES_H
#define TYPES_H
#define MAX_IN_STACK 3
#define LEN_STRING 30

#include <stdio.h>
#include <stdlib.h>

enum key_error
{
    ok,
    error
};

struct stack_array
{
    char stack[MAX_IN_STACK][LEN_STRING];
    int len_array;
};

struct stack_list
{
    char string[LEN_STRING];
    struct stack_list *next_node;
};

struct address
{
    char *address[MAX_IN_STACK];
    int len_address;
};

#endif // TYPES_H
