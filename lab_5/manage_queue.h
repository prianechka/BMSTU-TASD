#ifndef MANAGE_QUEUE_H
#define MANAGE_QUEUE_H

#include <stdlib.h>
#include "types.h"

void init_queue_array(struct queue_array *array);
int is_empty_array(struct queue_array *array);
int is_full_array(struct queue_array *array);
void add_queue_array(struct queue_array *array, int added_elem);
int pop_queue_array(struct queue_array *array);
void print_queue_array(struct queue_array *array);

void init_queue_list(struct queue_list **list);
void add_queue_list(struct queue_list **list, int added_elem);
int pop_queue_list(struct queue_list **list);
void print_queue_list(struct queue_list **list);
void delete_queue_list(struct queue_list **list);

#endif // MANAGE_QUEUE_H
