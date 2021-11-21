#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "check.h"
#include "input_parse.h"
#include "output.h"
#include "multiply.h"

int input_real_number(char *real_number_string);
int input_int_number(char *int_number_string);
int process_input_numbers(char *real_number_string, char *int_number_string);
int reading_real_string_in_array(char *real_number_string, struct real *real_number_struct);
void reading_int_string_in_array(char *int_number_string, struct integer *int_number_struct);
int process_multiply(struct real *real_number_struct, struct integer *int_number_struct, struct real *finish_count_struct);


#endif // PROCESS_H
