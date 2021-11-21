#include "sort.h"

void make_copy(struct book *array, struct book *copy_array, int length_array)
{
    for (int i = 0; i < length_array; i++)
        copy_array[i] = array[i];
}

void change_table_structs(struct table *one, struct table *two)
{
    struct table change;
    change = *one;
    *one = *two;
    *two = change;
}

void quick_sort_all_table(struct book *array, int a, int b)
{
    int l = a, r = b;
    int piv = array[(l + r) / 2].number_pages;
    while (l <= r)
    {
        while (array[l].number_pages < piv)
            l++;
        while (array[r].number_pages > piv)
            r--;
        if (l <= r)
            change_structs(&array[l++], &array[r--]);
    }
    if (a < b)
    {
        quick_sort_all_table(array, a, r);
        quick_sort_all_table(array, l, b);
    }
}

void bubble_sort_all_table(struct book *array, int length_array)
{
    struct book change;
    for (int i = 0; i < (length_array - 1); i++)
    {
        int jmax = i;
        for (int j = i + 1; j < length_array; j++)
            if (array[j].number_pages < array[jmax].number_pages)
                jmax = j;
        change = array[jmax];
        for (int k = jmax; k > i; k--)
            change_structs(array + k, array + k - 1);
        array[i] = change;
    }
}

void make_table(struct book *array, struct table *table_array, int length_array)
{
    for (int i = 0; i < length_array; i++)
    {
        table_array[i].index_in_table = i;
        table_array[i].number_of_pages = array[i].number_pages;
    }

}

void quick_sort_table(struct table *table_array, int a, int b)
{
    int l = a, r = b;
    int piv = table_array[(l + r) / 2].number_of_pages;
    while (l <= r)
    {
        while (table_array[l].number_of_pages < piv)
            l++;
        while (table_array[r].number_of_pages > piv)
            r--;
        if (l <= r)
            change_table_structs(&table_array[l++], &table_array[r--]);
    }
    if (a < b)
    {
        quick_sort_table(table_array, a, r);
        quick_sort_table(table_array, l, b);
    }
}

void bubble_sort_table(struct table *table_array, int length_array)
{
    struct table change;
    for (int i = 0; i < (length_array - 1); i++)
    {
        int jmax = i;
        for (int j = i + 1; j < length_array; j++)
            if (table_array[j].number_of_pages < table_array[jmax].number_of_pages)
                jmax = j;
        change = table_array[jmax];
        for (int k = jmax; k > i; k--)
            change_table_structs(table_array + k, table_array + k - 1);
        table_array[i] = change;
    }
}
