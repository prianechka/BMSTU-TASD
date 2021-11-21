#include "process.h"
#include <windows.h>
#include <time.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int result = -1;
    struct stack_array new;
    struct stack_array *stack_a = &new;
    stack_a->len_array = 0;
    struct stack_list *stack_l = (struct stack_list*) malloc(sizeof (struct stack_list));
    strcpy(stack_l->string, "Hello");
	stack_l->next_node = NULL;
    pop_list_stack(&stack_l);
    struct address new_add;
    struct address *address = &new_add;
    address->len_address = 0;
    while (result != 0)
        result = process_menu(&stack_a, &stack_l, &address);
    free(stack_l);
    return result;
}
