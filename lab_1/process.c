#include "process.h"

int input_real_number(char *real_number_string)
{
    printf("Input real number: ");
    int result = ok;
    for (int i = 0; i < MAX_LEN_NUMBER; i++)
        real_number_string[i] = '\0';
    gets(real_number_string);
    size_t length = strlen(real_number_string);
    if (real_number_string[length - 1] == '\n')
        real_number_string[length - 1] = '\0';
    for (size_t i = 0; i < length; i++)
    {
        if (real_number_string[i] == ' ')
        {
            if (real_number_string[i + 1] == 'E')
                for (size_t j = i; j < length; j++)
                    real_number_string[j] = real_number_string[j + 1];
            else
                result = error;
        }
    }
    if (result == ok)
    {
        if ((check_real_number(real_number_string) == ok) && (check_real_mantiss_and_order(real_number_string) == ok))
            result = ok;
        else
            result = error;
    }
    return result;
}

int input_int_number(char *int_number_string)
{
    printf("Input int number: ");
    int result = error;
    for (int i = 0; i < MAX_LEN_NUMBER; i++)
        int_number_string[i] = '\0';
    if (scanf("%s", int_number_string) == 1)
        if ((check_integer_number(int_number_string) == ok) && (check_int_mantiss(int_number_string) == ok))
            result = ok;
    return result;
}

int process_input_numbers(char *real_number_string, char *int_number_string)
{
    int result = error;
    if ((input_real_number(real_number_string) == ok) && (input_int_number(int_number_string) == ok))
        result = ok;
    return result;
}

int reading_real_string_in_array(char *real_number_string, struct real *real_number_struct)
{
    int result = ok;
    parse_all_real_number(real_number_string, real_number_struct);
    if (check_real_be_null(real_number_string) == error)
        real_number_struct->order = 0;
    return result;
}

void reading_int_string_in_array(char *int_number_string, struct integer *int_number_struct)
{
    parse_int_number(int_number_string, int_number_struct);
    if (check_int_be_null(int_number_string) == error)
        for (int i = 0; i < MAX_LEN_MANTISS; i++)
            int_number_struct->mantiss[i] = 0;
}

int process_multiply(struct real *real_number_struct, struct integer *int_number_struct, struct real *finish_count_struct)
{
    int result = ok;
    struct result result_of_multiply = multiply(real_number_struct, int_number_struct);
    int order = length_int(real_number_struct->mantiss) - real_number_struct->order + 1;
    *finish_count_struct = translate(&result_of_multiply, order);
    if ((finish_count_struct->order > LIMIT_MAX_ORDER) || (finish_count_struct->order < LIMIT_MIN_ORDER))
    {
        printf("Error: order overflow!");
        result = error;
    }
    finish_count_struct->mantiss_sigh = result_of_multiply.result_sigh;
    return result;
}
