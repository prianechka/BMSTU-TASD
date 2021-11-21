#include "process.h"

void process_print_array(struct book *array, int length_array)
{
    print_all_without_table(array, length_array);
}

void process_print_table(struct book *array, int length_array)
{
    struct table arr[MAX_STRUCTURES];
    make_table(array, arr, length_array);
    quick_sort_table(arr, 0, length_array - 1);
    print_table_struct(arr, length_array);
}

void process_print_quick_sort_array_without_table(struct book *array, int length_array)
{
    //struct book copy_array[MAX_STRUCTURES];
    //make_copy(array, copy_array, length_array);
    quick_sort_all_table(array, 0, length_array - 1);
    print_all_without_table(array, length_array);
}

void process_print_bubble_sort_array_without_table(struct book *array, int length_array)
{
    //struct book copy_array[MAX_STRUCTURES];
    //make_copy(array, copy_array, length_array);
    bubble_sort_all_table(array, length_array);
    print_all_without_table(array, length_array);
}

void process_print_quick_sort_array_with_table(struct book *array, int length_array)
{
    struct table arr[MAX_STRUCTURES];
    make_table(array, arr, length_array);
    quick_sort_table(arr, 0, length_array - 1);
    print_all_with_table(array, length_array, arr);
}

void process_print_bubble_sort_array_with_table(struct book *array, int length_array)
{
    struct table arr[MAX_STRUCTURES];
    make_table(array, arr, length_array);
    bubble_sort_table(arr, length_array);
    print_all_with_table(array, length_array, arr);
}

void process_compare_sorts(struct book *array, int length_array)
{
    printf("Length of array = %d, number of circes = %d\n", length_array, EXPERIMENT);
    clock_t start, stop;

    printf("\nQuick sort array without table: ");
    start = clock();
    for (int i = 0; i < EXPERIMENT; i++)
    {
        struct book copy_array[MAX_STRUCTURES];
        make_copy(array, copy_array, length_array);
        quick_sort_all_table(copy_array, 0, length_array - 1);
    }
    stop = clock();
    double time = ((double)stop - (double)start) / CLK_TCK;
    printf("%fs\n", time);

    printf("\nBubble sort array without table: ");
    start = clock();
    for (int i = 0; i < EXPERIMENT; i++)
    {
        struct book copy_array[MAX_STRUCTURES];
        make_copy(array, copy_array, length_array);
        bubble_sort_all_table(copy_array, length_array);
    }
    stop = clock();
    time = ((double)stop - (double)start) / CLK_TCK;
    printf("%fs\n", time);

    printf("\nQuick sort array with table: ");
    start = clock();
    for (int i = 0; i < EXPERIMENT; i++)
    {
        struct table arr[MAX_STRUCTURES];
        make_table(array, arr, length_array);
        quick_sort_table(arr, 0, length_array - 1);
    }
    stop = clock();
    time = ((double)stop - (double)start) / CLK_TCK;
    printf("%fs\n", time);

    printf("\nBubble sort array with table: ");
    start = clock();
    for (int i = 0; i < EXPERIMENT; i++)
    {
        struct table arr[MAX_STRUCTURES];
        make_table(array, arr, length_array);
        bubble_sort_table(arr, length_array);
    }
    stop = clock();
    time = ((double)stop - (double)start) / CLK_TCK;
    printf("%fs\n", time);
}

void process_choose_books(struct book *array, int length_array)
{
    int res = 0;
    char branch[LEN_NAME];
    for (int i = 0; i < LEN_NAME; i++)
        branch[i] = '\0';
    printf("\nInput branch of book (Length of it < 31): ");
    res = input_string_of_book(branch);
    while (res == -1)
    {
        for (int i = 0; i < LEN_NAME; i++)
            branch[i] = '\0';
        printf("\n\nIncorrect input! Please, input branch of book (Length of it < 31): ");
        res = input_string_of_book(branch);
    }
    if (res != -1)
    {
        int count = 0;
        for (int i = 0; i < length_array; i++)
        {
            if (array[i].book_type == technical && array[i].technic.language == domestic && strcmp(array[i].technic.branch, branch) == 0)
            {
                if (count++ == 0)
                {
                    char *s1 = "Author", *s2 = "Bookname", *s3 = "Publish House", *s4 = "Number of pages", *s5 = "Type of literature", *s0 = "index";
                    printf("%7s %35s %35s %35s %25s %20s\n\n", s0, s1, s2, s3, s4, s5);
                }
                printf("%8d", i + 1);
                print_struct(&array[i]);
            }
        }
        if (count == 0)
            printf("No elements!\n");
    }
}

int process_menu(struct book *array, int *length_array, char *name_file)
{
    int result = 0;
    print_menu();
    int n;
    n = input_integer();
    while ((n == -1) || (n < 0) || (n > 12))
    {
        printf("\n\nIncorrect input! Please, choose another!: ");
        fflush(stdin);
        n = input_integer();
    }
    switch (n)
    {
    case 1:
        add_new_struct(array, length_array);
        break;
    case 2:
        delete_struct_in_array(array, length_array);
        break;
    case 3:
        find_structs(array, length_array);
        break;
    case 4:
        process_print_array(array, *length_array);
        break;
    case 5:
        process_print_table(array, *length_array);
        break;
    case 6:
        process_print_quick_sort_array_without_table(array, *length_array);
        break;
    case 7:
        process_print_quick_sort_array_with_table(array, *length_array);
        break;
    case 8:
        process_print_bubble_sort_array_without_table(array, *length_array);
        break;
    case 9:
        process_print_bubble_sort_array_with_table(array, *length_array);
        break;
    case 10:
        process_compare_sorts(array, *length_array);
        break;
    case 11:
        process_choose_books(array, *length_array);
        break;
    case 12:
        save_in_file(name_file, array, *length_array);
        printf("\nBase was saved!\n");
        break;
    case 0:
        save_in_file(name_file, array, *length_array);
        printf("\nEnd of work!\n");
        result = 1;
        break;
    default:
        printf("Choose another!");
    }
    return result;
}

