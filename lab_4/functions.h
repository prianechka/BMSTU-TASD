#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

int input_string(char *string);
void print_word(char *string);
int input_integer(int *new_number);
void print_menu(void);
int find_add_in_array(struct address **address, char** add_str);


#endif // FUNCTIONS_H
