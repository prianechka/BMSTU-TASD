#include "functions.h"

int input_string(char *string)
{
    int c, result = 0, count = 0;
    while ((c = getchar()) != '\n')
    {
        if (count >= LEN_STRING)
            result = -1;
        else
            string[count++] = (char)c;
    }
    if (count == 0)
        result = -1;
    return result;
}

void print_word(char *string)
{
    size_t len = strlen(string);
    for (size_t i = len - 1; i >= 0; i--)
        printf("%c", string[i]);
    printf("\n");
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

void print_menu(void)
{
    printf("------------------------------------\n");
    printf("1 - Добавить элемент в стек\n");
    printf("2 - Удалить элемент из стека\n");
    printf("3 - Вывести текущее состояние стека\n");
    printf("4 - Вывести элементы стека в обратном порядке\n");
    printf("0 - Выход\n");
    printf("Выберите пункт меню: ");
}


int find_add_in_array(struct address **address, char **add_str)
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
