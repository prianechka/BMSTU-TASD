#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

void change_last_symbol_after_input(char *string);
int read_common_struct_from_file(FILE *f, struct book *array, int i);
int read_private_struct_from_file(FILE *f, struct book *array, int i);
int read_array_struct_from_file(FILE *f, struct book *array);

#endif // INPUT_H
