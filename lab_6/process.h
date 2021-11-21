#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "types.h"
#include "manage_tree.h"
#include "manage_avl.h"
#include "manage_hash.h"
#include "input.h"
#include "output.h"

void process_input_file(FILE *f, node_t **tree, avl_node_t **avl_tree, int **hash_table, int *hash_key, int collision);
int process_menu(node_t **tree, avl_node_t **avl_tree, int **hash_table, int *hash_key, int *collision);


#endif // PROCESS_H
