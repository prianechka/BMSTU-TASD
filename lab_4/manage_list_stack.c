#include "manage_list_stack.h"


struct stack_list * create_node_in_stack(char *new_string)
{
    struct stack_list* new_elem = (struct stack_list*) malloc (sizeof (struct stack_list));
    if (new_elem != NULL)
	{
        strcpy(new_elem->string, new_string);
		new_elem->next_node = NULL;
    }
	return new_elem;
}

void print_list_stack(struct stack_list *stack)
{
    printf("Стек в виде связного списка:\n------------------------------------\n");
    for (struct stack_list *new = stack; new != NULL; new = new->next_node)
        printf("%s\n", new->string);
    printf("------------------------------------\n");
}

void print_stack_address(struct stack_list *stack)
{
    printf("Адреса, используемые в связном списке:\n------------------------------------\n");
    for (struct stack_list *new = stack; new != NULL; new = new->next_node)
        printf("%p\n", new->string);
    printf("------------------------------------\n");
}

void push_list_stack(struct stack_list **stack, char* new_string)
{
    struct stack_list *new_elem = create_node_in_stack(new_string);
    new_elem->next_node = *stack;
    *stack = new_elem;
}

char* pop_list_stack(struct stack_list **stack)
{
    char *pop_string = (*stack)->string;
    struct stack_list *temp_stack = (*stack);
	(*stack) = temp_stack->next_node;
    free(temp_stack);
    return pop_string;
}

void print_list_exersize(struct stack_list **stack)
{
    clock_t start, stop;
    start = clock();
    struct stack_list *temp_stack = (struct stack_list *)malloc(sizeof(struct stack_list));
    strcpy(temp_stack->string, "Hello");
    temp_stack->next_node = NULL;
    pop_list_stack(&temp_stack);
    for (struct stack_list *new = *stack; new != NULL; new = new->next_node)
        push_list_stack(&temp_stack, new->string);
    printf("Элементы стека (в виде связного списка) в обратном порядке:\n\n------------------------------------\n");
    for (struct stack_list *new = temp_stack; new != NULL; new = new->next_node)
        printf("%s\n", new->string);
     printf("------------------------------------\n");
     stop = clock();
     printf("\n\nВремя работы программы: ");
     double time = ((double)stop - (double)start) / CLK_TCK;
     printf("%fs\n", time);
     printf("------------------------------------\n");
}
