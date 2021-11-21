#include "process.h"

int check_chars(char *real_number_string, char *int_number_string)
{
    int result = error;
    if ((check_real_number(real_number_string) == ok) && (check_real_mantiss_and_order(real_number_string) == ok))
        if ((check_integer_number(int_number_string) == ok) && (check_int_mantiss(int_number_string) == ok))
            result = ok;
    return result;
}

int check_answer(struct real *real_number_struct, char *right_answer)
{
    int result = ok;
    char word[MAX_LEN_MANTISS * 2];
    for (int i = 0; i < MAX_LEN_MANTISS * 2; i++)
        word[i] = '\0';
    int length = 0;
    if (real_number_struct->mantiss_sigh == '-')
    {
        word[length] = '-';
        length++;
    }
    word[length++] = '0';
    word[length++] = '.';
    int null_index = 0;
    for (int i = 0; i < MAX_LEN_MANTISS; i++)
    {
        if ((null_index == 0) && (real_number_struct->mantiss[i] != 0))
            null_index = 1;
        if (null_index == 1)
            word[length++] = real_number_struct->mantiss[i] + 48;
    }
    while (word[length - 1] == '0')
    {
        word[length - 1] = '\0';
        length--;
    }
    word[length++] = 'E';
    char order_string[MAX_LEN_ORDER];
    for (int i = 0; i < MAX_LEN_ORDER; i++)
        order_string[i] = '\0';
    int flag = 0;
    while (real_number_struct->order)
    {
        order_string[flag++] = (real_number_struct->order) % 10 + 48;
        real_number_struct->order /= 10;
    }
    flag--;
    while (flag > -1)
        word[length++] = order_string[flag--];
    if (strcmp(right_answer, word) != 0)
    {
        result = error;
        printf("\n%s", word);
    }
    else
        printf("Good!");
    return result;
}

int do_function(char *real_number_string, char *int_number_string, char *correct_result)
{
    int result = check_chars(real_number_string, int_number_string);
    if (result == ok)
    {
        struct real real_number_struct;
        struct integer int_number_struct;
        result = reading_real_string_in_array(real_number_string, &real_number_struct);
        if (result == ok)
        {
            reading_int_string_in_array(int_number_string, &int_number_struct);
            struct real finish_count_struct;
            if (check_int_be_null(int_number_string) || (check_real_be_null(real_number_string)))
                printf("Good!");
            else
            {
                process_multiply(&real_number_struct, &int_number_struct, &finish_count_struct);
                if (result == ok)
                    result = check_answer(&finish_count_struct, correct_result);
            }
        }
    }
    return result;
}


int test_negative()
{
    int check;
    int result = 0, num_test = 0;

    printf("\nTest %d:", num_test++);
    check = do_function("123", "1.34", "Error");
    if (check == ok)
        printf("Mistake in test: 123, 1.34\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function(".", "134", "Error");
    if (check == ok)
        printf("Mistake in test: ., 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("..", "134", "Error");
    if (check == ok)
        printf("Mistake in test: .., 123, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("...", "134", "Error");
    if (check == ok)
        printf("Mistake in test: ..., 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("+", "134", "Error");
    if (check == ok)
        printf("Mistake in test: +, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("++", "134", "Error");
    if (check == ok)
        printf("Mistake in test: ++, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("+++", "134", "Error");
    if (check == ok)
        printf("Mistake in test: +++, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("-", "134", "Error");
    if (check == ok)
        printf("Mistake in test: -, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("--", "134", "Error");
    if (check == ok)
        printf("Mistake in test: --, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("---", "134", "Error");
    if (check == ok)
        printf("Mistake in test: ---, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("E123", "134", "Error");
    if (check == ok)
        printf("Mistake in test: E123, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("EE123", "134", "Error");
    if (check == ok)
        printf("Mistake in test: EE123, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("1f23", "134", "Error");
    if (check == ok)
        printf("Mistake in test: 1f23, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("aaa", "134", "Error");
    if (check == ok)
        printf("Mistake in test: aaa, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("E", "134", "Error");
    if (check == ok)
        printf("Mistake in test: E, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("-23-3", "134", "Error");
    if (check == ok)
        printf("Mistake in test: -23-3, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("+25E+2", "134", "Error");
    if (check == ok)
        printf("Mistake in test: +25E+2, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("123E", "134", "Error");
    if (check == ok)
        printf("Mistake in test: 123E, 1.34\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("123E+", "134", "Error");
    if (check == ok)
        printf("Mistake in test: 123E+, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("123E-23-2", "134", "Error");
    if (check == ok)
        printf("Mistake in test: 123E-23-2, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("123.56E2", ".134", "Error");
    if (check == ok)
        printf("Mistake in test: 123.56E2, .134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("-123.56", "134E2", "Error");
    if (check == ok)
        printf("Mistake in test: -123.56, 134E2\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("123", "+134-2", "Error");
    if (check == ok)
        printf("Mistake in test: 123, +134-2\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("123", "134.", "Error");
    if (check == ok)
        printf("Mistake in test: 123, 134.\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("123", "134+", "Error");
    if (check == ok)
        printf("Mistake in test: 123, 134+\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("1234567890123456789012345678901", "134", "Error");
    if (check == ok)
        printf("Mistake in test: 1234567890123456789012345678901, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("123", "1234567890123456789012345678901", "Error");
    if (check == ok)
        printf("Mistake in test: 123, 1234567890123456789012345678901\n");
    result += (check == ok);


    printf("\nTest %d:", num_test++);
    check = do_function("1234567890123456789012345678901", "123456789012345678901234567890", "Error");
    if (check == ok)
        printf("Mistake in test: 1234567890123456789012345678901, 1234567890123456789012345678901\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("1234567890123456789012345678901", "134", "Error");
    if (check == ok)
        printf("Mistake in test: 1234567890123456789012345678901, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("-.1234567890123456789012345678901", "134", "Error");
    if (check == ok)
        printf("Mistake in test: -.1234567890123456789012345678901, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("-123.4567890123456789012345678901", "134", "Error");
    if (check == ok)
        printf("Mistake in test: -123.4567890123456789012345678901, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("-23.34E99999", "134", "Error");
    if (check == ok)
        printf("Mistake in test: -23.34E99999, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("1E99999", "100", "Error");
    if (check == ok)
        printf("Mistake in test: 1E99999, 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("", "100", "Error");
    if (check == ok)
        printf("Mistake in test: , 134\n");
    result += (check == ok);

    printf("\nTest %d:", num_test++);
    check = do_function("1.32", "", "Error");
    if (check == ok)
        printf("Mistake in test: , 134\n");
    result += (check == ok);

    printf("\nAll mistakes: %d\n", result);
    if (result == 0)
        printf("Well done!");

    return result;
}

int test_positive()
{
    int check;
    int result = 0, num_test = 0;

    printf("\nTest %d:", num_test++);
    check = do_function("12", "12", "0.144E3");
    if (check == error)
        printf("Mistake in test: 12, 12, 0.144E3\n");
    result += (check == error);

    printf("\nTest %d:", num_test++);
    check = do_function("1.12", "24", "0.2688E2");
    if (check == error)
        printf("Mistake in test: 1.12, 24, 0.2688E2\n");
    result += (check == error);

    printf("\nTest %d:", num_test++);
    check = do_function("-99.56", "33", "-0.328548E4");
    if (check == error)
        printf("Mistake in test: -99.56, 33, -0.328548E4\n");
    result += (check == error);

    printf("\nTest %d:", num_test++);
    check = do_function("12E2", "5", "0.6E4");
    if (check == error)
        printf("Mistake in test: 12E2, 5, 0.6E4\n");
    result += (check == error);

    printf("\nTest %d:", num_test++);
    check = do_function("3E-2", "76", "0.228E1");
    if (check == error)
        printf("Mistake in test: 3E-2, 76, 0.228E1\n");
    result += (check == error);

    printf("\nTest %d:", num_test++);
    check = do_function(".3792347", "03697", "0.14020306859E4");
    if (check == error)
        printf("Mistake in test: .3792347, 03697, 0.14020306859E4\n");
    result += (check == error);

    printf("\nTest %d:", num_test++);
    check = do_function("-4.182E-5", "-100000", "0.4182E1");
    if (check == error)
        printf("Mistake in test: -4.182E-5, -100000, 0.4182E1\n");
    result += (check == error);

    printf("\nTest %d:", num_test++);
    check = do_function("-.123", "+12", "-0.1476E1");
    if (check == error)
        printf("Mistake in test: -.123, +12, -0.1476E1\n");
    result += (check == error);

    printf("\nTest %d:", num_test++);
    check = do_function("12345679", "9", "0.111111111E9");
    if (check == error)
        printf("Mistake in test: 12345679, 9, 0.111111111E9\n");
    result += (check == error);

    printf("\nTest %d:", num_test++);
    check = do_function("123456789012345678901234567890", "123456789012345678901234567890", "0.152415787532388367504953515625E59");
    if (check == error)
        printf("Mistake in test: 123456789012345678901234567890, 123456789012345678901234567890, 0.152415787532388367504953515625E59\n");
    result += (check == error);

    printf("\nTest %d:", num_test++);
    check = do_function("99", "99", "0.9801E4");
    if (check == error)
        printf("Mistake in test: 99, 99, 0.9801E4\n");
    result += (check == error);

    printf("\nTest %d:", num_test++);
    check = do_function("12", "0", "0E0");
    if (check == error)
        printf("Mistake in test: 12, 0, 0E0\n");
    result += (check == error);

    printf("\nTest %d:", num_test++);
    check = do_function("0", "12", "0E0");
    if (check == error)
        printf("Mistake in test: 12, 0, 0E0\n");
    result += (check == error);

    printf("\nTest %d:", num_test++);
    check = do_function("00.00", "34", "0E0");
    if (check == error)
        printf("Mistake in test: 00.00, 34, 0E0\n");
    result += (check == error);

    printf("\nTest %d:", num_test++);
    check = do_function("-36.12E56", "1", "-0.3612E58");
    if (check == error)
        printf("Mistake in test: -36.12E56, 1, -0.3612E58\n");
    result += (check == error);

    printf("\nTest %d:", num_test++);
    check = do_function("-36.12E56", "-1", "0.3612E58");
    if (check == error)
        printf("Mistake in test: -36.12E56, -1, 0.3612E58\n");
    result += (check == error);

    printf("\nTest %d:", num_test++);
    check = do_function("1.", "123", "0.123E3");
    if (check == error)
        printf("Mistake in test: 1., 123, 0.123E3\n");
    result += (check == error);

    printf("\nTest %d:", num_test++);
    check = do_function(".9E99999", "1", "0.9E99999");
    if (check == error)
        printf("Mistake in test: .9E99999, 1, 0.9E99999\n");
    result += (check == error);

    printf("\nAll mistakes: %d\n", result);
    if (result == 0)
        printf("Well done!");

    return result;
}

int main()
{
    int result;
    printf("Negative tests:\n");
    result = test_negative();
    printf("\n\nPositive tests:\n");
    result = test_positive();
    if (result == 0)
        printf("\nGreen build!\n");
    return result;
}
