#include "manage_queue.h"

void init_queue_array(struct queue_array *array)
{
    array->first = -1;
    array->last = -1;
}

int is_full_array(struct queue_array *array)
{
    int result = not;
    if (array->first == array->last + 1)
        result = yes;
    else if (array->first == 0 && array->last == MAX_Q - 1)
        result = yes;
    return result;
}

int is_empty_array(struct queue_array *array)
{
    int result = not;
    if (array->first == -1)
        result = yes;
    return result;
}

void add_queue_array(struct queue_array *array, int added_elem)
{
    if (is_full_array(array) == yes)
        printf("Очередь переполнена, нельзя добавить новый элемент!");
    else
    {
        if (array->first == -1)
            array->first = 0;
        array->last = (array->last + 1) % MAX_Q;
        array->queue[array->last] = added_elem;
    }
}

int pop_queue_array(struct queue_array *array)
{
    int pop_elem = -1;
    if (is_empty_array(array))
        printf("Удаление невозможно: очередь пустая!");
    else
    {
        pop_elem = array->queue[array->first];
        if (array->first == array->last)
            init_queue_array(array);
        else
            array->first = (array->first + 1) % MAX_Q;
    }
    return pop_elem;
}

void print_queue_array(struct queue_array *array)
{
    if (is_empty_array(array))
        printf("Удаление невозможно: очередь пустая!");
    else
    {
        printf("Очередь в виде списка: \n");
        for (int i = array->first; i < array->last; i++)
            printf("%d <-- ", array->queue[i]);
        printf("%d\n", array->queue[array->last]);
    }
}

void init_queue_list(struct queue_list **list)
{
    (*list)->first = (struct leaf*) malloc(sizeof(struct leaf));
    (*list)->last = (struct leaf*) malloc(sizeof(struct leaf));
    (*list)->first->next = (*list)->last;
    (*list)->first->value = 0;
    (*list)->last->next = NULL;
    (*list)->last->value = 0;

    (*list)->size = 0;
}

void add_queue_list(struct queue_list **list, int added_elem)
{
    struct leaf *tmp = (*list)->last;
    tmp->value = added_elem;

    (*list)->last = (struct leaf*) malloc(sizeof(struct leaf));

    (*list)->last->next = NULL;
    (*list)->last->value = 0;

    tmp->next = (*list)->last;
    (*list)->size++;
}

int pop_queue_list(struct queue_list **list)
{
    struct leaf *tmp = (*list)->first->next;

    (*list)->first->next = tmp->next;
    (*list)->size -= 1;
    int pop_elem = tmp->value;
    return pop_elem;

}

void print_queue_list(struct queue_list **list)
{
    printf("Очередь в виде связного списка:\n");
    if ((*list)->first)
        for (struct leaf *tmp = (*list)->first->next; tmp != (*list)->last; tmp = tmp->next)
        {
            if (tmp->next != (*list)->last)
                printf("%d <-- ", tmp->value);
            else
                printf("%d\n", tmp->value);
        }
}

void delete_queue_list(struct queue_list **list)
{
    while ((*list)->size != 0)
        pop_queue_list(list);

    free((*list)->first);
    free((*list)->last);

    (*list)->first = NULL;
    (*list)->last = NULL;
}
