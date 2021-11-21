#include "input_parse.h"

//Функция заполнения мантиссы в выделенный под это массив с заданными параметрами цикла
void mantiss_cycle(char *real_number_string, struct real *real_number_struct, size_t start, int stop)
{
    int j = 0;
    for (int i = start; (i > stop); i--)
    {
        real_number_struct->mantiss[MAX_LEN_MANTISS - j - 1] = real_number_string[i] - 48;
        j++;
    }
}

//Функция вычисления порядка введённого вещественного числа с заданными параметрами цикла
void change_order(char *real_number_string, struct real *real_number_struct, size_t length, size_t start)
{
    int len_order = 0;
    for (size_t i = start; (i < length) && (real_number_string[i] == '0'); i++)
        if (real_number_string[i] == '0')
            len_order++;
    if (len_order > 0)
        real_number_struct->order -= len_order;
}

// Функция обработки части вещественного числа до достижения порядка
void parse_real_number_without_e(char *real_number_string, struct real *real_number_struct, size_t length)
{
    size_t index_point = 0;
    for (size_t i = 0; (i < length) && (index_point == 0); i++)
        if (real_number_string[i] == '.')
            index_point = i;
    if (real_number_string[0] == '.')
    {
        mantiss_cycle(real_number_string, real_number_struct, length - 1, 0);
        change_order(real_number_string, real_number_struct, length, 1);
    }
    else if (index_point == 0)
    {
        if ((real_number_string[0] == '+') || (real_number_string[0] == '-'))
        {
            mantiss_cycle(real_number_string, real_number_struct, length - 1, 0);
            real_number_struct->order = length - 1;
        }
        else
        {
            mantiss_cycle(real_number_string, real_number_struct, length - 1, -1);
            real_number_struct->order = length;
        }
    }
    else if (index_point == (length - 1))
    {
        if ((real_number_string[0] == '+') || (real_number_string[0] == '-'))
        {
            mantiss_cycle(real_number_string, real_number_struct, length - 2, 0);
            real_number_struct->order = length - 2;
        }
        else
        {
            mantiss_cycle(real_number_string, real_number_struct, length - 2, -1);
            real_number_struct->order = length - 1;
        }
    }
    else if (((real_number_string[0] == '+') || (real_number_string[0] == '-'))
             && (real_number_string[1] == '.'))
    {
        mantiss_cycle(real_number_string, real_number_struct, length - 1, 1);
        change_order(real_number_string, real_number_struct, length, 2);
    }
    else if ((real_number_string[0] == '0') && (real_number_string[1] == '.'))
    {
        mantiss_cycle(real_number_string, real_number_struct, length - 1, 1);
        change_order(real_number_string, real_number_struct, length, 2);
    }
    else if (((real_number_string[0] == '+') || (real_number_string[0] == '-'))
             && (real_number_string[1] == '0') && (real_number_string[2] == '.'))
    {
        mantiss_cycle(real_number_string, real_number_struct, length - 1, 2);
        change_order(real_number_string, real_number_struct, length, 3);
    }
    else if ((real_number_string[0] == '+') || (real_number_string[0] == '-'))
    {
        int j = 0;
        for (size_t i = length - 1; (i > index_point); i--)
        {
            real_number_struct->mantiss[MAX_LEN_MANTISS - j - 1] = real_number_string[i] - 48;
            j++;
        }
        for (int i = index_point - 1; (i > 0); i--)
        {
            real_number_struct->mantiss[MAX_LEN_MANTISS - j - 1] = real_number_string[i] - 48;
            j++;
        }
        change_order(real_number_string, real_number_struct, length, index_point);
        real_number_struct->order += (index_point - 1);
    }
    else
    {
        int j = 0;
        for (size_t i = length - 1; (i > index_point); i--)
        {
            real_number_struct->mantiss[MAX_LEN_MANTISS - j - 1] = real_number_string[i] - 48;
            j++;
        }
        for (int i = index_point - 1; (i > -1); i--)
        {
            real_number_struct->mantiss[MAX_LEN_MANTISS - j - 1] = real_number_string[i] - 48;
            j++;
        }
        change_order(real_number_string, real_number_struct, length, index_point);
        real_number_struct->order += (index_point);
    }
}

// Функция обработки в массив вещественного числа
void parse_all_real_number(char *real_number_string, struct real *real_number_struct)
{
    for (int i = 0; i < MAX_LEN_MANTISS; i++)
        real_number_struct->mantiss[i] = 0;
    real_number_struct->order = 0;
    if (real_number_string[0] == '-')
        real_number_struct->mantiss_sigh = '-';
    else
        real_number_struct->mantiss_sigh = '+';
    size_t length = strlen(real_number_string);
    int index_E = -1;
    for (size_t i = 0; (i < length) && (index_E == -1); i++)
        if (real_number_string[i] == 'E')
            index_E = i;
    if (index_E == -1)
        parse_real_number_without_e(real_number_string, real_number_struct, length);
    else
    {
        parse_real_number_without_e(real_number_string, real_number_struct, index_E);
        size_t i = index_E + 1;
        char order_string[MAX_LEN_ORDER];
        for (int j = 0; j < MAX_LEN_ORDER; j++)
            order_string[j] = '\0';
        if (real_number_string[i] == '-')
        {
            i++;
            for (size_t j = i; j < length; j++)
                order_string[j - index_E - 2] = real_number_string[j];
        }
        else
            for (size_t j = i; j < length; j++)
                order_string[j - index_E - 1] = real_number_string[j];
        int res_order = atoi(order_string);
        if (real_number_string[index_E + 1] == '-')
            res_order *= -1;
        real_number_struct->order += res_order;
    }
}

// Функция обработки в массив целого числа
void parse_int_number(char *int_number_string, struct integer *int_number_struct)
{
    for (int i = 0; i < MAX_LEN_MANTISS; i++)
        int_number_struct->mantiss[i] = 0;
    if (int_number_string[0] == '-')
        int_number_struct->mantiss_sigh = '-';
    else
        int_number_struct->mantiss_sigh = '+';
    size_t length = strlen(int_number_string);
    int j = 0;
    if ((int_number_string[0] == '-') || (int_number_string[0] == '+'))
        for (size_t i = length - 1;(i > 0); i--)
        {
            int_number_struct->mantiss[MAX_LEN_MANTISS - j - 1] = int_number_string[i] - 48;
            j++;
        }
    else
        for (int i = length - 1; (i >= 0); i--)
        {
            int_number_struct->mantiss[MAX_LEN_MANTISS - j - 1] = int_number_string[i] - 48;
            j++;
        }
}

// Функция подсчёта длины целого числа
int length_int(int *mantiss)
{
    int result = -1;
    for (int i = 0; i < MAX_LEN_MANTISS && result == -1; i++)
        if (mantiss[i] != 0)
            result = i;
    if (result == -1)
        result = 1;
    else
        result = MAX_LEN_MANTISS - result - 1;
    return result;
}
