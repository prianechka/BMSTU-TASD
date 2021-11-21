#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.h"
#include "types.h"

int read_int_number(FILE *f, int *number);
int read_size(FILE *f, int *n, int *m);
int **read_file(FILE *f, int n, int m);
int input_integer(int *new_number);
void change_last_symbol_after_input(char *string);
int input_string(char *string);

#endif // INPUT_H
