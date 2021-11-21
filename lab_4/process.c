#include "process.h"


void process_push_elem(struct stack_array *stack_a, struct stack_list **stack_l, struct address **address)
{
    if (stack_a->len_array >= MAX_IN_STACK)
    {
        printf("Ошибка добавления: в стеке максимальное число элементов!\n\n");
        return;
    }
    int res;
    char new_string[LEN_STRING];
    for (int i = 0; i < LEN_STRING; i++)
        new_string[i] = '\0';
    printf("\nВведите строку длиной до 30 символов: ");
    res = input_string(new_string);
    while (res == error)
    {
        printf("\n\nНеправильный ввод! Введите строку длиной до 30 символов: ");
        fflush(stdin);
        res = input_string(new_string);
    }
    size_t len = strlen(new_string);
    new_string[len] = '\0';
    push_array_stack(stack_a, new_string);
    push_list_stack(stack_l, new_string);
    find_add_in_array(address, (char **)((*stack_l)->string));
}


void process_pop_elem(struct stack_array *stack_a, struct stack_list **stack_l, struct address **address)
{
    if (stack_a->len_array <= 0)
    {
        printf("В стеке нет элементов\n");
        return;
    }
    char* pop_string;
    pop_string = pop_array_stack(stack_a);
    printf("------------------------------------\n");
    printf("Удалённый элемент из стека (в виде массива): %s \n", pop_string);
    printf("------------------------------------\n");
    (*address)->address[(*address)->len_address] = (char *)(*stack_l)->string;
    (*address)->len_address++;
    char new_pop_string[LEN_STRING];
    strcpy(new_pop_string, pop_list_stack(stack_l));
    printf("------------------------------------\n");
    printf("Удалённый элемент из стека (в виде связного списка): %s \n", pop_string);
    printf("------------------------------------\n");
    printf("Адрес удалённого элемента из стека: %p\n", (*address)->address[(*address)->len_address - 1]);
    printf("------------------------------------\n");

}
void process_print_stack(struct stack_array *stack_a, struct stack_list **stack_l, struct address **address)
{
    print_array_stack(stack_a);
    print_list_stack(*stack_l);
    print_stack_address(*stack_l);
    printf("Освободившиеся адреса для стека:\n");
    printf("------------------------------------\n");
    for (int i = 0; i < (*address)->len_address; i++)
        printf("%p\n", (*address)->address[i]);
    printf("------------------------------------\n");
}

void process_print_exercise(struct stack_array *stack_a, struct stack_list **stack_l)
{
    if (stack_a->len_array < 1)
    {
        printf("В стеке нет элементов!\n");
        return;
    }
    print_list_exersize(stack_l);
    print_array_exersize(stack_a);
}



int process_menu(struct stack_array **stack_a, struct stack_list **stack_l, struct address **address)
{
    int choose = 0, res;
    print_menu();
    res = input_integer(&choose);
    while ((res == error) || (choose < 0) || (choose > 4))
    {
        printf("\n\nНеправильный ввод! Введите заново: ");
        fflush(stdin);
        res = input_integer(&choose);
    }
    switch (choose)
    {
    case 1:
        process_push_elem(*stack_a, stack_l, address);
        break;
    case 2:
        process_pop_elem(*stack_a, stack_l, address);
        break;
    case 3:
        process_print_stack(*stack_a, stack_l, address);
        break;
    case 4:
        process_print_exercise(*stack_a, stack_l);
        break;
    }
    return choose;
}
