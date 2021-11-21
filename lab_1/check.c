#include "check.h"

//Функция проверки ввода вещественного числа на корректность
int check_real_number(char *real_number_string)
{
    int result = ok;
    size_t length;
    if ((length = strlen(real_number_string)) == 0)
    {
        printf("Empty number!");
        result = error;
    }
    else if ((real_number_string[0] != '-') && (real_number_string[0] != '+') && (real_number_string[0] != '.') &&
             ((real_number_string[0] < 48) || (real_number_string[0] > 57)))
        result = error;
    else
    {
        int count_minus = 0, count_plus = 0, count_E = 0, count_point = 0;
        size_t index_E = 0;
        for (size_t i = 0; (i < length) && (result == ok); i++)
        {
            if (real_number_string[i] == '-')
            {
                if ((i == 0) || ((index_E != 0) && (i == index_E + 1)))
                    count_minus++;
                else
                    result = error;
            }
            else if (real_number_string[i] == '+')
            {
                if (i == 0)
                    count_plus++;
                else
                    result = error;
            }
            else if (real_number_string[i] == '.')
            {
                if ((index_E != 0) && (i > index_E))
                    result = error;
                else if (count_point == 1)
                    result = error;
                else
                    count_point++;
            }
            else if (real_number_string[i] == 'E')
            {
                count_E++;
                if (count_E == 1)
                    index_E = i;
                else
                    result = error;
            }
            else if ((real_number_string[i] < 48) || (real_number_string[i] > 57))
                result = error;
        }
        if ((index_E == (length - 1)) && (length > 1))
            result = error;
    }
    if ((length == 1) && ((real_number_string[0] == '.') || (real_number_string[0] == '-') || (real_number_string[0] == '+')))
        result = error;
    if ((length == 1) && (real_number_string[0] == '0'))
        result = ok;
    if ((result == error) && (length != 0))
        printf("Incorrect input!");
    return result;
}

//Функция проверки ввода целого числа на корректность
int check_integer_number(char *int_number_string)
{
    int result = ok;
    size_t length;
    if ((length = strlen(int_number_string)) == 0)
    {
        printf("Empty number!");
        result = error;
    }
    else if ((int_number_string[0] != '-') && (int_number_string[0] != '+') &&
             ((int_number_string[0] < 48) || (int_number_string[0] > 57)))
        result = error;
    else
    {
        int count_minus = 0;
        int count_plus = 0;
        for (size_t i = 0; (i < length) && (result == ok); i++)
        {
            if (int_number_string[i] == '-')
            {
                if (i == 0)
                    count_minus++;
                else
                    result = error;
            }
            else if (int_number_string[i] == '+')
            {
                if (i == 0)
                    count_plus++;
                else
                    result = error;
            }
            else if ((int_number_string[i] < 48) || (int_number_string[i] > 57))
                result = error;
        }
    }
    if ((result == error) && (length != 0))
        printf("Incorrect input!");
    return result;
}

//Функция проверки мантиссы и порядка вещественного числа на корректность
int check_real_mantiss_and_order(char *real_number_string)
{
    int result = ok;
    size_t length = strlen(real_number_string);
    int len_mantiss = 0, len_order = 0, ind_E = 0;
    for (size_t i = 0; ((i < length) && (result == ok)); i++)
    {
        if (real_number_string[i] == 'E')
            ind_E = 1;
        else if ((ind_E == 1) && (real_number_string[i] != '-'))
            len_order++;
        else if ((real_number_string[i] != '.') && (real_number_string[i] != '-') && (real_number_string[i] != '+'))
            len_mantiss++;
        if ((len_order > MAX_LEN_ORDER) || (len_mantiss > MAX_LEN_MANTISS))
            result = error;
    }
    if (result == error)
        printf("Incorrect input!");
    if (length == 0)
        result = error;
    return result;
}

//Функция проверки длины мантиссы целого числа на корректность
int check_int_mantiss(char *int_number_string)
{
    int result = ok;
    size_t length = strlen(int_number_string);
    int len_mantiss = 0;
    for (size_t i = 0; ((i < length) && (result == ok)); i++)
    {
        if ((int_number_string[i] != '-') && (int_number_string[i] != '+'))
            len_mantiss++;
        if (len_mantiss > MAX_LEN_MANTISS)
        {
            printf("Incorrect input!");
            result = error;
        }
    }
    if (length == 0)
        result = error;
    return result;
}

//Функция проверки порядка числа на корректность
int check_order(int order)
{
    int result = ok;
    if ((order > LIMIT_MAX_ORDER) || (order < LIMIT_MIN_ORDER))
        result = error;
    return result;
}

//Функция проверяет, является ли введённое вещественное число нулём
int check_real_be_null(char *real_number_string)
{
    size_t length = strlen(real_number_string);
    int result = error;
    for (size_t i = 0; (i < length) && (result == error) && (real_number_string[i] != 'E'); i++)
        if ((real_number_string[i] > 48) && (real_number_string[i] < 58))
            result = ok;
    return result;
}

//Функция проверяет, является ли введённое целое число нулём
int check_int_be_null(char *i_number)
{
    size_t length = strlen(i_number);
    int result = ok;
    if (length == 1 && i_number[0] == '0')
        result = error;
    return result;
}
