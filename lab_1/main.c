#include "process.h"

int main()
{
    int result = ok;
    char real_number_string[MAX_LEN_NUMBER], int_number_string[MAX_LEN_NUMBER];
    if (result == ok)    result = process_input_numbers(real_number_string, int_number_string);

    {
        int count = 0;
        while ((real_number_string[count] == '0') && (real_number_string[count + 1] == '0'))
            for (size_t i = count + 1; i < MAX_LEN_NUMBER; i++)
                real_number_string[i] = real_number_string[i + 1];
        count++;
        while ((real_number_string[count] == '0') && (real_number_string[count + 1] == '0'))
            for (size_t i = count + 1; i < MAX_LEN_NUMBER; i++)
                real_number_string[i] = real_number_string[i + 1];
        struct real real_number_struct;
        struct integer int_number_struct;
        result = reading_real_string_in_array(real_number_string, &real_number_struct);
        if (result == ok)
        {
            reading_int_string_in_array(int_number_string, &int_number_struct);
            struct real finish_count_struct;
            if (check_int_be_null(int_number_string) || (check_real_be_null(real_number_string)))
                printf("\nResult of multiply: 0E0");
            else
            {
                process_multiply(&real_number_struct, &int_number_struct, &finish_count_struct);
                if ((result == ok) && (check_order(finish_count_struct.order) == ok))
                    print_answer(&finish_count_struct);
                else
                    result = error;
            }
        }
    }
    return result;
}
