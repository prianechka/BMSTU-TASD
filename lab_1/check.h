#ifndef INPUT_H
#define INPUT_H

#include "types.h"
#include <string.h>
#include <stdio.h>

int check_real_number(char *real_number_string);
int check_integer_number(char *int_number_string);
int check_real_mantiss_and_order(char *real_number_string);
int check_int_mantiss(char *int_number_string);
int check_order(int order);
int check_real_be_null(char *r_number);
int check_int_be_null(char *i_number);
#endif // INPUT_H
