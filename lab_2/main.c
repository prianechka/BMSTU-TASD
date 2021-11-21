#include "process.h"

int main(void)
{
    int result = ok;
    int length_array = 0;
    struct book array[MAX_STRUCTURES];
    char *name_file = "base.txt";
    FILE *f;
    f = fopen(name_file, "r");
    length_array = read_array_struct_from_file(f, array);
    if (!length_array)
        result = error;
    else
    {
        process_print_array(array, length_array);
        int res = process_menu(array, &length_array, name_file);
        while (res == 0)
            res = process_menu(array, &length_array, name_file);
    }
    return result;
}
