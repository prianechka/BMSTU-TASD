#include "multiply.h"


// Функция умножения вещественного числа на целое
struct result multiply(struct real *real_number_struct, struct integer *int_number_struct)
{
    printf("\n");
    struct result result_of_multiply;
    for (int i = 0; i < 2 * MAX_LEN_MANTISS + 1; i++)
        result_of_multiply.mantiss[i] = 0;
    if ((real_number_struct->mantiss_sigh == '-') && (int_number_struct->mantiss_sigh == '+'))
        result_of_multiply.result_sigh = '-';
    else if ((real_number_struct->mantiss_sigh == '+') && (int_number_struct->mantiss_sigh == '-'))
        result_of_multiply.result_sigh = '-';
    else
        result_of_multiply.result_sigh = '+';
    int all_len = 0;
    for (int i = MAX_LEN_MANTISS - 1; i > -1; i--)
    {
        int num_len = 0;
        for (int j = MAX_LEN_MANTISS - 1; j > -1; j--)
        {
            int mul = real_number_struct->mantiss[j] * int_number_struct->mantiss[i];
            result_of_multiply.mantiss[2 * MAX_LEN_MANTISS - all_len - num_len] += (mul % 10);
            result_of_multiply.mantiss[2 * MAX_LEN_MANTISS - all_len - num_len - 1] += (mul / 10);
            if (result_of_multiply.mantiss[2 * MAX_LEN_MANTISS - all_len - num_len] > 9)
            {
                result_of_multiply.mantiss[2 * MAX_LEN_MANTISS - all_len - num_len - 1] +=
                        (result_of_multiply.mantiss[2 * MAX_LEN_MANTISS - all_len - num_len] / 10);
                result_of_multiply.mantiss[2 * MAX_LEN_MANTISS - all_len - num_len] %= 10;
            }
            num_len++;
        }
        all_len++;
    }
    return result_of_multiply;
}

// Функция вычисления длины результата
int len_result_of_multiply(struct result *result_of_multiply)
{
    int result = -1;
    for (int i = 0; i < 2 * MAX_LEN_MANTISS + 1 && result == -1; i++)
    {
        if (result_of_multiply->mantiss[i] != 0)
            result = i;
    }
    result = 2 * MAX_LEN_MANTISS - result + 1;
    return result;
}

struct real translate(struct result *result_of_multiply, int order)
{
    struct real count;
    count.mantiss_sigh = result_of_multiply->result_sigh;
    int len = len_result_of_multiply(result_of_multiply);
    count.order = len - order;
    if (len <= MAX_LEN_MANTISS)
        for (int i = MAX_LEN_MANTISS; i > -1; i--)
            count.mantiss[i - 1] = result_of_multiply->mantiss[MAX_LEN_MANTISS + i];
    else
    {
        int delta = len - MAX_LEN_MANTISS, count_len = 0;
        for (int i = 0; i < len; i++)
        {
            if (i == delta)
            {
                if (result_of_multiply->mantiss[2 * MAX_LEN_MANTISS + 1 - i] > 4)
                    result_of_multiply->mantiss[2 * MAX_LEN_MANTISS - i]++;
            }
            if (i > delta)
            {
                if (result_of_multiply->mantiss[2 * MAX_LEN_MANTISS + 1 - i] > 4)
                    result_of_multiply->mantiss[2 * MAX_LEN_MANTISS - i]++;
                count.mantiss[MAX_LEN_MANTISS - 1 - count_len] = result_of_multiply->mantiss[2 * MAX_LEN_MANTISS - i];
                if (count.mantiss[MAX_LEN_MANTISS - 1 - count_len] == 10)
                {
                    count.mantiss[MAX_LEN_MANTISS - 1 - count_len] = 0;
                    count.mantiss[MAX_LEN_MANTISS - 2 - count_len]++;
                }
                count_len++;
            }
        }
    }
    return count;
}
