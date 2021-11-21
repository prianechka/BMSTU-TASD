#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

int **allocate_matrix(int n, int m);
void free_matrix(int **array, int n);

#endif // MEMORY_H
