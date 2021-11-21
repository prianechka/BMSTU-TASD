#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types.h"

void print_sparce_array(struct sparce_matrix *sp_matrix);
void print_menu();
void print_matrix(struct matrix *matr);

#endif // OUTPUT_H
