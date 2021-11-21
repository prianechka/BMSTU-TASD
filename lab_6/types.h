#ifndef TYPES_H
#define TYPES_H
#define MAX_SIZE 20000
#define MAX_GO 4
#define SPACING 5

typedef struct node node_t;
typedef struct avl_node avl_node_t;

struct node
{
    int data;
    node_t *left;
    node_t *right;
    node_t *parent;
};

struct avl_node
{
    int data;
    int heigth;
    avl_node_t *left;
    avl_node_t *right;
};

enum key_error
{
    ok,
    error
};

#endif // TYPES_H
