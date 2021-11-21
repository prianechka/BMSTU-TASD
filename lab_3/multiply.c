#include "multiply.h"

void multiply_sparce_matrix(struct sparce_matrix *sp_matrix_one, struct sparce_matrix *vector, struct sparce_matrix *result)
{
    result->number_columns = vector->number_columns;
    result->number_strings = sp_matrix_one->number_strings;
    result->IA = calloc(result->number_strings, sizeof(int));

    double count_arr;
    int length = 0, count = 0;
    for (int i = 0; i < result->number_strings; i++)
    {
        count_arr = 0;
        int len;
        int ind = i + 1;
        if (ind < result->number_strings)
        {
            while (sp_matrix_one->IA[ind] == -1)
            {
                ind++;
                if (ind == sp_matrix_one->number_strings)
                    break;
            }
            if (ind == sp_matrix_one->number_strings)
                len = sp_matrix_one->nonzero_elems;
            else
                len = sp_matrix_one->IA[ind];
        }
        else
            len = sp_matrix_one->nonzero_elems;
        while (length < len)
        {
            int index = sp_matrix_one->JA[length];
            if (vector->IA[index] != -1)
                count_arr += (vector->A[vector->IA[index]] * sp_matrix_one->A[length]);
            length++;
        }
        if (fabs(count_arr) > 1e-7)
            count++;
    }
    result->A = calloc(count, sizeof (double));
    result->JA = calloc(count, sizeof (int));
    result->nonzero_elems = count;
    count = 0;
    length = 0;
    for (int i = 0; i < result->number_strings; i++)
    {
        count_arr = 0;
        int len, ind = i + 1;
        if (ind < result->number_strings)
        {
            while (sp_matrix_one->IA[ind] == -1)
            {
                ind++;
                if (ind == sp_matrix_one->number_strings)
                    break;
            }
            if (ind == sp_matrix_one->number_strings)
                len = sp_matrix_one->nonzero_elems;
            else
                len = sp_matrix_one->IA[ind];
        }
        else
            len = sp_matrix_one->nonzero_elems;
        while (length < len)
        {
            int index = sp_matrix_one->JA[length];
            if (vector->IA[index] != -1)
            {
                count_arr += (vector->A[vector->IA[index]] * sp_matrix_one->A[length]);
            }
            length++;
        }
        if (fabs(count_arr) > 1e-5)
        {
            result->A[count] = count_arr;
            result->JA[count] = 0;
            result->IA[i] = count;
            count++;
        }
        else
            result->IA[i] = -1;
    }
}

void multiply_matrix(struct matrix *sp_matrix_one, struct matrix *vector, struct matrix *result)
{
    result->number_columns = vector->number_columns;
    result->number_strings = sp_matrix_one->number_strings;
    for (int i = 0; i < sp_matrix_one->number_strings; i++)
    {
        for (int j = 0; j < sp_matrix_one->number_columns; j++)
            result->array[i] += (sp_matrix_one->array[i * sp_matrix_one->number_columns + j] * vector->array[j]);
    }
}
