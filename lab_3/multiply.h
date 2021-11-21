#ifndef MULTIPLY_H
#define MULTIPLY_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types.h"
#include "output.h"

void multiply_sparce_matrix(struct sparce_matrix *sp_matrix_one, struct sparce_matrix *vector, struct sparce_matrix *result);
void multiply_matrix(struct matrix *sp_matrix_one, struct matrix *vector, struct matrix *result);

#endif // MULTIPLY_H
