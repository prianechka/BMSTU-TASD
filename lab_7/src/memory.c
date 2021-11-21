#include "../inc/memory.h"

int **allocate_matrix(int n, int m)
{
    int result = ok;
    int **array = calloc(n, sizeof(int*));
    if (array != NULL)
    {
        for (int i = 0; i < n && result == ok; i++)
        {
            array[i] = calloc(m, sizeof(int));
            if (array[i] == NULL)
            {
                free_matrix(array, n);
                array = NULL;
                result = error;
            }
        }
    }
    return array;
}

void free_matrix(int **array, int n)
{
    for (int i = 0; i < n; i++)
        free(array[i]);
    free(array);
}
