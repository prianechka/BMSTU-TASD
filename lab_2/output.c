#include "output.h"

void print_struct(struct book *one)
{
    printf("%35s %35s %35s %25d ", one->author, one->bookname, one->publishing_house, one->number_pages);
    if (one->book_type == 0)
    {
        printf("     technical      %s ", one->technic.branch);
        if (one->technic.language == 0)
            printf("   domestic   %d", one->technic.age);
        else
            printf("   foreigh    %d", one->technic.age);
    }
    else if (one->book_type == 1)
    {
        printf("     fiction         ");
        if (one->fiction.genre == 0)
            printf("novel");
        else if (one->fiction.genre == 1)
            printf("play");
        else
            printf("verse");
    }
    else
    {
        printf("     child          ");
        if (one->children.genre == 0)
            printf("fairytale");
        else
            printf("child verse");
    }
    printf("\n");
}

void print_table_struct(struct table *arr, int length_array)
{
    if (length_array == 0)
    {
        printf("\nNo books in array!\n");
        return;
    }
    printf("All table:\n");
    char *s1 = "Index in table", *s2 = "Index in array", *s3 = "Number of pages";
    printf("%20s %20s %20s\n\n", s1, s2, s3);
    for (int i = 0; i < length_array; i++)
        printf("%20d %20d %20d\n", i, arr[i].index_in_table, arr[i].number_of_pages);
}

void print_all_without_table(struct book *array, int length_array)
{
    printf("All array:\n");
    char *s1 = "Author", *s2 = "Bookname", *s3 = "Publish House", *s4 = "Number of pages", *s5 = "Type of literature", *s0 = "Index";
    printf("%7s %35s %35s %35s %25s %20s\n\n", s0, s1, s2, s3, s4, s5);
    for (int i = 0; i < length_array; i++)
    {
        printf("%8d", i + 1);
        print_struct(&array[i]);
    }
}

void print_all_with_table(struct book *array, int length_array, struct table *arr)
{
    printf("All array:\n");
    char *s1 = "Author", *s2 = "Bookname", *s3 = "Publish House", *s4 = "Number of pages", *s5 = "Type of literature", *s0 = "Index";
    printf("%7s %35s %35s %35s %25s %20s\n\n", s0, s1, s2, s3, s4, s5);
    for (int i = 0; i < length_array; i++)
    {
        printf("%8d", arr[i].index_in_table);
        print_struct(&array[arr[i].index_in_table]);
    }
}

void print_menu()
{
    printf("\nChoose one menu item:\n");
    printf("1 - Add new book\n");
    printf("2 - Delete book\n");
    printf("3 - Find book\n");
    printf("4 - Print array\n");
    printf("5 - Print sorted table\n");
    printf("6 - Print quick sorted array without table\n");
    printf("7 - Print quick sorted array with table\n");
    printf("8 - Print bubble sorted array without table\n");
    printf("9 - Print bubble sorted array with table\n");
    printf("10 - Compare time of sorting array\n");
    printf("11 - Print technical domectic books with chosen branch\n");
    printf("12 - Save base of books\n");
    printf("0 - Quit\n\n");
    printf("Sorting occurs by field number of pages!\n\n");
    printf("Your input: ");
}
