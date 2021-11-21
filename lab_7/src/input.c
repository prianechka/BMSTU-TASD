#include "../inc/input.h"

int read_int_number(FILE *f, int *number)
{
    int result = ok, read;
    read = fscanf(f, "%d", number);
    if (read == 1)
        result = ok;
    else
        result = error;
    return result;
}

int read_size(FILE *f, int *n, int *m)
{
    int result = !((read_int_number(f, n) == ok) && (read_int_number(f, m) == ok));
    return result;
}

int **read_file(FILE *f, int n, int m)
{
    int result = ok;
    int **array;
    array = allocate_matrix(n, m);
    if (array == NULL)
        result = error;
    else
    {
        for (int i = 0; i < n && result == ok; i++)
            for (int j = 0; j < m && result == ok; j++)
                result = read_int_number(f, &array[i][j]);
        if (result == error)
        {
            free_matrix(array, n);
            array = NULL;
        }
    }
    return array;
}

int input_integer(int *new_number)
{
    int c, res = ok, result = 0, length = 0, flag_minus = 0;
    while ((c = getchar()) != '\n')
    {
        if (c >= '0' && c <= '9' && res == ok)
        {
            result = (result * 10 + c - 48);
            length++;
        }
        else if (length == 0 && c == '-')
        {
            flag_minus = 1;
            length++;
        }
        else
            res = error;
    }
    if (res == ok)
    {
        *new_number = result;
        if (flag_minus == 1)
        {
            if (length > 1)
                *new_number *= (-1);
            else
                res = error;
        }
    }

    if (length == 0)
        res = error;
    return res;
}

void change_last_symbol_after_input(char *string)
{
    size_t length = strlen(string);
    if (string[length - 1] == '\n')
        string[length - 1] = '\0';
}

int input_string(char *string)
{
    int c, result = 0, count = 0;
    while ((c = getchar()) != '\n')
    {
        if (count >= 30)
            result = -1;
        else
            string[count++] = (char)c;
    }
    if (count == 0)
        result = -1;
    return result;
}
