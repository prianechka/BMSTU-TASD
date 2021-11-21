#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "array_manage.h"
#include "input.h"
#include "output.h"
#include "sort.h"
#include "types.h"

void process_print_array(struct book *array, int length_array);
void process_print_table(struct book *array, int length_array);
void process_print_quick_sort_array_without_table(struct book *array, int length_array);
void process_print_bubble_sort_array_without_table(struct book *array, int length_array);
void process_print_quick_sort_array_with_table(struct book *array, int length_array);
void process_print_bubble_sort_array_with_table(struct book *array, int length_array);
void process_compare_sorts(struct book *array, int length_array);
int process_menu(struct book *array, int *length_array, char *name_file);

#endif // PROCESS_H
