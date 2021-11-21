#ifndef TYPES_H
#define TYPES_H
#define MAX_Q 10001
#define TIME_OA_0 0.0
#define TIME_OA_1 4.0
#define TIME_1_0 0.0
#define TIME_1_1 5.0


#include <stdio.h>
#include <stdlib.h>

enum key_error
{
    ok,
    error
};

enum resulted
{
    not,
    yes
};

struct queue_array
{
    int queue[MAX_Q];
    int first;
    int last;
};

struct leaf
{
    int value;
    struct leaf *next;
};

struct queue_list
{
    struct leaf *first, *last;
    int size;
};

struct address
{
    int *address[MAX_Q];
    int len_address;
};

#endif // TYPES_H
