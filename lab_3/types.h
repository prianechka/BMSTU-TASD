#ifndef TYPES_H
#define TYPES_H
#define TIME 1000

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

enum key_error
{
    ok,
    error
};

struct sparce_matrix
{
    int number_strings;
    int number_columns;
    int nonzero_elems;

    double *A;
    int *JA;
    int *IA;
};

struct matrix
{
    int number_strings;
    int number_columns;
    double *array;
};

#endif // TYPES_H
