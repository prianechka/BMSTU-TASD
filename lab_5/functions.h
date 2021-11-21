#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "manage_queue.h"

double generate_time(int t_start, int t_end);
int input_integer(int *new_number);
int find_add_in_array(struct address **address, int *add_str);

#endif // FUNCTIONS_H
