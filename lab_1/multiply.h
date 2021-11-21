#ifndef MULTIPLY_H
#define MULTIPLY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "input_parse.h"

struct result multiply(struct real *real_number_struct, struct integer *int_number_struct);
int len_result_of_multiply(struct result *result_of_multiply);
struct real translate(struct result *result_of_multiply, int order);

#endif // MULTIPLY_H
