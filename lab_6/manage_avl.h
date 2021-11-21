#ifndef MANAGE_AVL_H
#define MANAGE_AVL_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

avl_node_t *avl_make_new_node(int value);
int count_height(avl_node_t *node);
int count_balance(avl_node_t *avl_node);
void change_height(avl_node_t *node);
avl_node_t* right_rotate(avl_node_t *node);
avl_node_t* left_rotate(avl_node_t *node);
avl_node_t *avl_balance(avl_node_t *node);
avl_node_t *avl_insert(avl_node_t *avl_tree, int value, int *count, int flag);
avl_node_t *find_min(avl_node_t *tree);
avl_node_t *remove_min(avl_node_t *tree);
void check_balance_in_del(avl_node_t *tree);
avl_node_t *avl_remove(avl_node_t *tree, int del_value);
avl_node_t *avl_find_node(avl_node_t *tree, int value);
void free_avl_tree(avl_node_t *tree);
void print_avl_tree(avl_node_t *tree, const char *dir, int level);
void avl_export_to_dot(FILE *f, avl_node_t *tree);
avl_node_t *avl_tree_find_del_node(avl_node_t *tree, avl_node_t **parent, int find_elem);
void avl_tree_delete(avl_node_t *del_node, avl_node_t **parent);

#endif // MANAGE_AVL_H
