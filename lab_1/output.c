#include <stdio.h>
#include <stdlib.h>
#include "types.h"

// Функция печати на экран вещественного числа
void print_real_number(struct real *real_number_struct)
{
    if (real_number_struct->mantiss_sigh == '-')
        printf("-");
    printf("0.");
    int null_index = 0;
    for (int i = 0; i < MAX_LEN_MANTISS; i++)
    {
        if ((null_index == 0) && (real_number_struct->mantiss[i] != 0))
            null_index = 1;
        if (null_index == 1)
            printf("%d", real_number_struct->mantiss[i]);
    }
    printf("E");
    printf("%d", real_number_struct->order);
}


// Функция печати на экран целого числа
void print_int_number(struct integer *int_number_struct)
{
    if (int_number_struct->mantiss_sigh == '-')
        printf("-");
    int null_index = 0;
    for (int i = 0; i < MAX_LEN_MANTISS; i++)
    {
        if ((null_index == 0) && (int_number_struct->mantiss[i] != 0))
            null_index = 1;
        if (null_index == 1)
            printf("%d", int_number_struct->mantiss[i]);
    }
}

// Функция печати результата с предшестующей ей обработкой
void print_answer(struct real *real_number_struct)
{
    printf("\nResult of multiply: ");
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
    int flag = 0, minus = 0;
    if (real_number_struct->order < 0)
    {
        minus = 1;
        real_number_struct->order *= -1;
    }
    if (real_number_struct->order)
    {
        while (real_number_struct->order)
        {
            order_string[flag++] = (real_number_struct->order) % 10 + 48;
            real_number_struct->order /= 10;
        }
    }
    else
        order_string[flag++] = '0';
    flag--;
    if (minus == 1)
        word[length++] = '-';
    while (flag > -1)
        word[length++] = order_string[flag--];
    printf("%s", word);
}
