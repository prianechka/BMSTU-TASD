#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types.h"
#include "output.h"
#include "multiply.h"

int input_integer(int *new_number);
int input_float(double *result);
void make_sparce_matrix(struct matrix *matr, struct sparce_matrix *sp_matrix, int count_nonzero);
void input_auto_matrix(struct matrix *matr, int *count_of_nonzero);
void input_hand_matrix(struct matrix *matr, int *count_of_nonzero);
void input_sparce_matrix(struct matrix *matr, int *count_nonzero);
void input_vector(struct matrix *matr, int *count_nonzero);

#endif // INPUT_H
