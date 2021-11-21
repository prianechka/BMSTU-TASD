#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_manage.h"
#include "types.h"

void make_copy(struct book *array, struct book *copy_array, int length_array);
void change_table_structs(struct table *one, struct table *two);
void quick_sort_all_table(struct book *array, int a, int b);
void bubble_sort_all_table(struct book *array, int length_array);
void make_table(struct book *array, struct table *table_array, int length_array);
void quick_sort_table(struct table *table_array, int a, int b);
void bubble_sort_table(struct table *table_array, int length_array);


#endif // SORT_H
