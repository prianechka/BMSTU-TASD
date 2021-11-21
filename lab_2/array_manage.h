#ifndef ARRAY_MANAGE_H
#define ARRAY_MANAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "input.h"
#include "output.h"

void change_structs(struct book *one, struct book *two);
int input_integer();
int input_string_of_book(char *string);
int input_struct(struct book *new_book);
int add_new_struct(struct book *array, int *length_array);
void delete_struct(struct book *array, int key, int *length_array);
int delete_author_struct(struct book *array, int *length_array);
int delete_bookname_struct(struct book *array, int *length_array);
int delete_publish_house_struct(struct book *array, int *length_array);
int delete_pages_struct(struct book *array, int *length_array);
int delete_struct_in_array(struct book *array, int *length_array);
void save_in_file(char *file_name, struct book *array, int length_array);
void find_author(struct book *array, int length_array);
void find_bookname(struct book *array, int length_array);
void find_publish_house(struct book *array, int length_array);
void find_number_of_pages(struct book *array, int length_array);
void find_structs(struct book *array, int *length_array);

#endif // ARRAY_MANAGE_H
