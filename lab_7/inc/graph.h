#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "types.h"
#include "input.h"
#include "output.h"
#include "memory.h"

void free_matrix(int **array, int n);
int **allocate_matrix(int n, int m);
graph_t *create_graph(FILE *f);
void floid(graph_t *graph, int flag);
void dextra(graph_t *graph, int flag);
void belman(graph_t *graph, int flag);
int min_distance(int *min_len, int *vertex, int size);

#endif // GRAPH_H
