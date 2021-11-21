#include "manage_array_stack.h"

void print_array_stack(struct stack_array *stack)
{
    printf("\nСтек в виде массива:\n");
    printf("------------------------------------\n");
    for (int i = stack->len_array - 1; i >= 0; i--)
        printf("%s\n", stack->stack[i]);
    printf("------------------------------------\n\n");
}

void init_array_stack(struct stack_array *stack)
{
    stack->len_array = 0;
}

void push_array_stack(struct stack_array *stack, char *added_string)
{
    if (stack->len_array >= MAX_IN_STACK)
        printf("Ошибка добавления: в стеке уже максимальное число элементов!\n\n");
    else
    {
        strcpy(stack->stack[stack->len_array], added_string);
        (stack->len_array)++;
    }
}

char *pop_array_stack(struct stack_array *stack)
{
    char *res_string = NULL;
    if (stack->len_array < 1)
        printf("В стеке нет элементов!\n\n");
    else
    {
        res_string = stack->stack[stack->len_array - 1];
        stack->len_array--;
    }
    return res_string;
}

void print_array_exersize(struct stack_array *stack)
{
    clock_t start, stop;
    start = clock();
    int length = stack->len_array;
    struct stack_array new;
    struct stack_array *temp = &new;
    temp->len_array = 0;
    for (int i = length - 1; i >= 0; i--)
        push_array_stack(temp, stack->stack[i]);
    printf("\nЭлементы стека (в виде массива) в обратном порядке:\n");
    printf("------------------------------------\n");
    for (int i = temp->len_array - 1; i >= 0; i--)
        printf("%s\n", temp->stack[i]);
    printf("------------------------------------\n\n");
    stop = clock();
    printf("\n\nВремя работы программы: ");
    double time = ((double)stop - (double)start) / CLK_TCK;
    printf("%fs\n", time);
    printf("------------------------------------\n");
}
