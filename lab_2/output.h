#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_manage.h"
#include "types.h"

void print_struct(struct book *one);
void print_table_struct(struct table *arr, int length_array);
void print_all_without_table(struct book *array, int length_array);
void print_all_with_table(struct book *array, int length_array, struct table *arr);
void print_menu();

#endif // OUTPUT_H
