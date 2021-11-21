#ifndef INPUT_PARSE_H
#define INPUT_PARSE_H
#include <stdio.h>
#include "types.h"
#include "check.h"
#include <string.h>
#include <stdlib.h>

void mantiss_cycle(char *real_number_string, struct real *real_number_struct, size_t start, int stop);
void change_order(char *real_number_string, struct real *real_number_struct, size_t length, size_t start);
void parse_real_number_without_e(char *real_number_string, struct real *real_number_struct, size_t length);
void parse_all_real_number(char *real_number_string, struct real *real_number_struct);
void parse_int_number(char *int_number_string, struct integer *int_number_struct);
int length_int(int *mantiss);

#endif // INPUT_PARSE_H
