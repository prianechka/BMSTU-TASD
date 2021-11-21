#ifndef TYPES_H
#define TYPES_H
#define MAX_GRAPH 1000000

enum key_error
{
    ok,
    error,
};

typedef struct graph graph_t;

struct graph
{
    int *size;
    int **matrix;
};

typedef struct node node_t;

struct node
{
    int weight;
    int index;
    node_t *next;
};

#endif // TYPES_H
