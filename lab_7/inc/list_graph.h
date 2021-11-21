#ifndef LIST_GRAPH_H
#define LIST_GRAPH_H


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "types.h"
#include "input.h"
#include "output.h"
#include "memory.h"

void init_list_graph(node_t **list, int n);
void create_list_graph(FILE *f, int n, node_t **list);
int get_value(node_t **list, int i, int j);
void print_list_graph(node_t **list, int n);
void floid_list(node_t **list, int n, int flag);
void dextra_list(node_t **list, int n, int flag);
void belman_list(node_t **list, int n, int flag);
int list_min_distance(int *min_len, int *vertex, int size);

#endif // LIST_GRAPH_H
