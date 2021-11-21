#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "functions.h"
#include "manage_array_stack.h"
#include "manage_list_stack.h"

int process_menu(struct stack_array **stack_a, struct stack_list **stack_l, struct address **address);

#endif // PROCESS_H
