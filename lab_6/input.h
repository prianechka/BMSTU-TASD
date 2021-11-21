#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

int read_int_number(FILE *f, int *number);
void read_file(FILE *f);
int input_integer(int *new_number);

#endif // INPUT_H
