#include "functions.h"

double generate_time(int t_start, int t_end)
{
    double time_result = (t_end - t_start) * rand() / (double)RAND_MAX + t_start;
    return time_result;
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


int find_add_in_array(struct address **address, int *add_str)
{
    int len_address = (*address)->len_address;
    int result_index = -1;
    for (int i = 0; (i < len_address) && result_index == -1; i++)
    {
        if ((void *)((*address)->address[i]) == (void *)add_str)
        {
            result_index = i;
            for (int j = i; j < len_address; j++)
            {
                if (j - 1 != len_address)
                    (*address)->address[j] = (*address)->address[j + 1];
                else
                    (*address)->address[j] = NULL;
            }
            (*address)->len_address--;
        }
    }
    return result_index;
}
