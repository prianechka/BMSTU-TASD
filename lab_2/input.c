#include "input.h"

void change_last_symbol_after_input(char *string)
{
    size_t length = strlen(string);
    if (string[length - 1] == '\n')
        string[length - 1] = '\0';
}



int read_common_struct_from_file(FILE *f, struct book *array, int i)
{
    int result = error, res;
    if ((res = (fgets(array[i].author, LEN_NAME + 1, f)) != NULL) && (res != 0) && (i < MAX_STRUCTURES))
    {
        if ((res = (fgets(array[i].bookname, LEN_NAME + 1, f)) != NULL) && (res != 0))
        {
            if ((res = (fgets(array[i].publishing_house, LEN_NAME + 1, f)) != NULL) && (res != 0))
            {
                if (fscanf(f, "%d", &array[i].number_pages) == 1)
                {
                    //fscanf(f, "%d", &rubbery);
                    result = ok;
                    change_last_symbol_after_input(array[i].author);
                    change_last_symbol_after_input(array[i].bookname);
                    change_last_symbol_after_input(array[i].publishing_house);
                }
                else
                    result = error;
            }
            else
                result = error;
        }
        else
            result = error;
    }
    else if (i == MAX_STRUCTURES)
        result = error;
    else
        result = end_reading;
    return result;
}

int read_private_struct_from_file(FILE *f, struct book *array, int i)
{
    int result = error, res, rubbery;
    if (fscanf(f, "%u", &array[i].book_type) == 1)
    {
        if (array[i].book_type == technical)
        {
            fscanf(f, "%d", &rubbery);
            if ((res = (fgets(array[i].technic.branch, LEN_NAME + 1, f)) != NULL) && (res != 0))
            {
                if (fscanf(f, "%u %d", &array[i].technic.language, &array[i].technic.age) == 2)
                {
                    fscanf(f, "%d", &rubbery);
                    result = ok;
                    change_last_symbol_after_input(array[i].technic.branch);
                }
                else
                    result = error;
            }
            else
                result = error;
        }
        else if (array[i].book_type == fictions)
        {
            if (fscanf(f, "%u", &array[i].fiction.genre) == 1)
            {
                fscanf(f, "%d", &rubbery);
                result = ok;
            }
            else
                result = error;
        }
        else if (array[i].book_type == children)
        {
            if (fscanf(f, "%u", &array[i].children.genre) == 1)
            {
                fscanf(f, "%d", &rubbery);
                result = ok;
            }
            else
                result = error;
        }
        else
            result = error;
    }
    return result;
}

int read_array_struct_from_file(FILE *f, struct book *array)
{
    int length_array = 0;
    int result = ok;
    while (result == ok)
    {
        result = read_common_struct_from_file(f, array, length_array);
        if (result == error)
            length_array = -1;
        else if (result == ok)
        {
            result = read_private_struct_from_file(f, array, length_array);
            if (result == ok)
                length_array++;
            else
                length_array = -1;
        }
    }
    return length_array;
}
