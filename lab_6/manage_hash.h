#ifndef MANAGE_HASH_H
#define MANAGE_HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

int get_key_for_value(int value, int hash_key);
void init_hash_table(int **hash_table, int hash_key);
int find_in_table(int value, int *hash_table, int hash_key, int collision);
int insert_in_table(int value, int **hash_table, int hash_key, int collision, int flag);
int remove_in_table(int value, int **hash_table, int hash_key, int collision);
void print_hash_table(int *hash_table, int hash_key);
int check_simple(int x);
void change_hash_key(int *hash_key);
void restruct_hash_table(int **hash_table, int *hash_key, int collision, int old_hash);

#endif // MANAGE_HASH_H
