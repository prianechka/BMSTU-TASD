#include "check.h"
#include "types.h"
#include <stdio.h>

int test_input_real_number()
{
    int check;
    int result = 0;

    check = check_real_number("123");
    if (check == error)
        printf("Mistake in test: 123\n");
    result += (check != ok);

    check = check_real_number("ABC");
    if (check == ok)
        printf("Mistake in test: ABC\n");
    result += (check != error);

    check = check_real_number("-12345.56");
    if (check == error)
        printf("Mistake in test: -12345.56\n");
    result += (check != ok);

    check = check_real_number("12s3");
    if (check == ok)
        printf("Mistake in test: 12s3\n");
    result += (check != error);

    check = check_real_number("123.a");
    if (check == ok)
        printf("Mistake in test: 123.a\n");
    result += (check != error);

    check = check_real_number("123.768.65");
    if (check == ok)
        printf("Mistake in test: 123.768.65\n");
    result += (check != error);

    check = check_real_number(".56789");
    if (check == error)
        printf("Mistake in test: .56789\n");
    result += (check != ok);

    check = check_real_number("123E20");
    if (check == error)
        printf("Mistake in test: 123E20\n");
    result += (check != ok);

    check = check_real_number("-123E-156");
    if (check == error)
        printf("Mistake in test: -123E-156\n");
    result += (check != ok);

    check = check_real_number(".123E20");
    if (check == error)
        printf("Mistake in test: .123E20\n");
    result += (check != ok);

    check = check_real_number(".123E20");
    if (check == error)
        printf("Mistake in test: .123E20\n");
    result += (check != ok);

    check = check_real_number("+123E23");
    if (check == error)
        printf("Mistake in test: +123E23\n");
    result += (check != ok);

    check = check_real_number("123E1.234");
    if (check == ok)
        printf("Mistake in test: 123E1.234\n");
    result += (check != error);

    check = check_real_number("123E+12");
    if (check == ok)
        printf("Mistake in test: 123E+12\n");
    result += (check != error);

    check = check_real_number("123E");
    if (check == ok)
        printf("Mistake in test: 123E\n");
    result += (check != error);

    check = check_real_number("E123-23");
    if (check == ok)
        printf("Mistake in test: E123-23\n");
    result += (check != error);

    check = check_real_number("");
    if (check == ok)
        printf("Mistake in test: \n");
    result += (check != error);

    printf("All mistakes: %d\n", result);
    if (result == 0)
        printf("Well done!");

    return result;
}


int test_input_integer_number()
{
    int check;
    int result = 0;

    check = check_integer_number("123");
    if (check == error)
        printf("Mistake in test: 123\n");
    result += (check != ok);

    check = check_integer_number("ABC");
    if (check == ok)
        printf("Mistake in test: ABC\n");
    result += (check != error);

    check = check_integer_number("-123");
    if (check == error)
        printf("Mistake in test: -123\n");
    result += (check != ok);

    check = check_integer_number("12s3");
    if (check == ok)
        printf("Mistake in test: 12s3\n");
    result += (check != error);

    check = check_integer_number("123.56");
    if (check == ok)
        printf("Mistake in test: 123.56\n");
    result += (check != error);

    check = check_integer_number("123E20");
    if (check == ok)
        printf("Mistake in test: 123E20\n");
    result += (check != error);

    check = check_integer_number("-123E-20");
    if (check == ok)
        printf("Mistake in test: 123E20\n");
    result += (check != error);

    check = check_integer_number("123E+20");
    if (check == ok)
        printf("Mistake in test: 123E+20\n");
    result += (check != error);

    check = check_integer_number(".123E20");
    if (check == ok)
        printf("Mistake in test: 123E20\n");
    result += (check != error);

    check = check_integer_number("");
    if (check == ok)
        printf("Mistake in test: \n");
    result += (check != error);

    printf("All mistakes: %d\n", result);
    if (result == 0)
        printf("Well done!");

    return result;
}

int test_check_real_mantiss_and_order()
{
    int check;
    int result = 0;

    check = check_real_mantiss_and_order("123");
    if (check == error)
        printf("Mistake in test: 123\n");
    result += (check != ok);

    check = check_real_mantiss_and_order("123E1000");
    if (check == error)
        printf("Mistake in test: 123E1000\n");
    result += (check != ok);

    check = check_real_mantiss_and_order("-12345.56");
    if (check == error)
        printf("Mistake in test: -12345.56\n");
    result += (check != ok);

    check = check_real_mantiss_and_order("123E99999");
    if (check == error)
        printf("Mistake in test: 123E99999\n");
    result += (check != ok);

    check = check_real_mantiss_and_order("123E100000");
    if (check == ok)
        printf("Mistake in test: 123E100000\n");
    result += (check != error);

    check = check_real_mantiss_and_order("123456789012345678901234567890");
    if (check == error)
        printf("Mistake in test: 123456789012345678901234567890\n");
    result += (check != ok);

    check = check_real_mantiss_and_order("1234567890123456.78901234567890E99999");
    if (check == error)
        printf("Mistake in test: 1234567890123456.78901234567890E99999\n");
    result += (check != ok);

    check = check_real_mantiss_and_order("12345678901234560.78901234567890E99999");
    if (check == ok)
        printf("Mistake in test: 123E20\n");
    result += (check != error);

    check = check_real_mantiss_and_order("");
    if (check == ok)
        printf("Mistake in test: \n");
    result += (check != error);

    printf("All mistakes: %d\n", result);
    if (result == 0)
        printf("Well done!");

    return result;
}

int main()
{
    int result;
    printf("Function 'check_real_number':\n");
    result = test_input_real_number();
    printf("\n\nFunction 'check_integer_number':\n");
    result = test_input_integer_number();
    printf("\n\nFunction 'check_real_mantiss_and_order':\n");
    result = test_check_real_mantiss_and_order();
    return result;
}
