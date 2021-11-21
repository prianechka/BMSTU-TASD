#ifndef MANAGE_TREE_H
#define MANAGE_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

node_t* make_new_node(int value, node_t *parent);
void insert(node_t **tree, int value, int *count);
node_t *find_node(node_t *tree, int value);
node_t *find_min_node(node_t *tree);
node_t *find_max_node(node_t *tree);
void delete_node(node_t *del_node);
void delete_value(node_t *tree, int value);
void print_tree(node_t *tree, const char *dir, int level);
void free_tree(node_t *tree);
void new_print_tree(node_t *tree, int space);
void export_to_dot(FILE *f, node_t *tree);
void in_order_search(node_t *tree);
void pre_order_search(node_t *tree);
void post_order_search(node_t *tree);

#endif // MANAGE_TREE_H
