#include "array_manage.h"

void change_structs(struct book *one, struct book *two)
{
    struct book change;
    change = *one;
    *one = *two;
    *two = change;
}

int input_integer()
{
    int c, result = 0;
    while ((c = getchar()) != '\n')
    {
        if (c >= '0' && c <= '9' && result != -1)
            result = (result * 10 + c - 48);
        else
        {
            result = -1;
            break;
        }
    }
    return result;
}

int input_string_of_book(char *string)
{
    int c, result = 0, count = 0;
    while ((c = getchar()) != '\n')
    {
        if (count >= LEN_NAME)
            result = -1;
        else
            string[count++] = (char)c;
    }
    if (count == 0)
        result = -1;
    return result;
}

int input_struct(struct book *new_book)
{
    int result = ok;
    int res;
    for (int i = 0; i < LEN_NAME; i++)
        new_book->author[i] = '\0';
    printf("\nInput author of book (Length of it < 31): ");
    res = input_string_of_book(new_book->author);
    while (res == -1)
    {
        for (int i = 0; i < LEN_NAME; i++)
            new_book->author[i] = '\0';
        printf("\n\nIncorrect input! Please, input author of book (Length of it < 31): ");
        res = input_string_of_book(new_book->author);
    }

    for (int i = 0; i < LEN_NAME; i++)
        new_book->bookname[i] = '\0';
    printf("\nInput bookname of book (Length of it < 31): ");
    res = input_string_of_book(new_book->bookname);
    while (res == -1)
    {
        for (int i = 0; i < LEN_NAME; i++)
            new_book->bookname[i] = '\0';
        printf("\n\nIncorrect input! Please, input bookname of book (Length of it < 31): ");
        res = input_string_of_book(new_book->bookname);
    }

    for (int i = 0; i < LEN_NAME; i++)
        new_book->publishing_house[i] = '\0';
    printf("\nInput publish house (Length of it < 31): ");
    res = input_string_of_book(new_book->publishing_house);
    while (res == -1)
    {
        for (int i = 0; i < LEN_NAME; i++)
            new_book->publishing_house[i] = '\0';
        printf("\n\nIncorrect input! Please, input publish house of book (Length of it < 31): ");
        res = input_string_of_book(new_book->publishing_house);
    }

    printf("\nInput number of pages (it is integer > 0): ");
    res = input_integer();
    while ((res == -1) || (res < 1))
    {
        printf("\n\nIncorrect input! Please, input number of pages (it is integer > 0): ");
        fflush(stdin);
        res = input_integer();
    }
    new_book->number_pages = res;

    printf("\nInput genre (1 - Tecnical literature, 2 - fiction, 3 - children literature): ");
    res = input_integer();
    while (res == -1 || res < 1 || res > 3)
    {
        printf("\n\nIncorrect input! Please, input genre (1 - Tecnical literature, 2 - fiction, 3 - children literature): ");
        fflush(stdin);
        res = input_integer();
    }
    new_book->book_type = res - 1;

    if (new_book->book_type == 0)
    {
        for (int i = 0; i < LEN_NAME; i++)
            new_book->technic.branch[i] = '\0';
        printf("\nInput branch of book (string, length < 31): ");
        res = input_string_of_book(new_book->technic.branch);
        while (res == -1)
        {
            for (int i = 0; i < LEN_NAME; i++)
                new_book->technic.branch[i] = '\0';
            printf("\n\nIncorrect input! Please, input branch of book (string, length < 31): ");
            res = input_string_of_book(new_book->technic.branch);
        }

        printf("\nInput language of technical literature: 1 - domestic, 2 - foreign: ");
        res = input_integer();
        while ((res == -1) || (res < 1) || (res > 2))
        {
            printf("\n\nIncorrect input! Please, input language of technical literature: 1 - domestic, 2 - foreign: ");
            fflush(stdin);
            res = input_integer();
        }
        new_book->technic.language = res - 1;

        printf("\nInput year of release (year < 2020): ");
        res = input_integer();
        while (res == -1 || res > 2020)
        {
            printf("\n\nIncorrect input! Please, input year of release (year < 2020): ");
            fflush(stdin);
            res = input_integer();
        }
        new_book->technic.age = res;
    }
    else if (new_book->book_type == 1)
    {
        printf("\nInput genre of fiction: 1 - novel, 2 - play, 3 - verse: ");
        res = input_integer();
        while ((res == -1) || (res < 1) || (res > 3))
        {
            printf("\n\nIncorrect input! Please, input genre of fiction: 1 - novel, 2 - play, 3 - verse: ");
            fflush(stdin);
            res = input_integer();
        }
        new_book->fiction.genre = res - 1;
    }
    else if (new_book->book_type == 2)
    {
        printf("\nInput genre of children literature: 1 - fairytale, 2 - child_verse: ");
        res = input_integer();
        while (res == -1 || res < 1 || res > 2)
        {
            printf("\n\nIncorrect input! Please, input genre children literature: 1 - fairytale, 2 - child_verse: ");
            fflush(stdin);
            res = input_integer();
        }
        new_book->children.genre = res - 1;
    }
    return result;
}

int add_new_struct(struct book *array, int *length_array)
{
    int result = ok;
    if (*length_array == MAX_STRUCTURES)
    {
        printf("\nYou can't add new books! Overflow of base!");
        return ok;
    }
    printf("Input specifications of new book!\n");
    result = input_struct(&array[*length_array]);
    if (result == ok)
        (*length_array)++;
    printf("\n");
    return result;
}

void delete_struct(struct book *array, int key, int *length_array)
{
    for (int i = key; i < (*length_array - 1); i++)
        array[i] = array[i + 1];
    (*length_array)--;
}

int delete_author_struct(struct book *array, int *length_array)
{
    int result = ok;
    char author[LEN_NAME];
    for (int i = 0; i < LEN_NAME; i++)
        author[i] = '\0';
    printf("\nInput author name for delete (length of it < 31): ");
    int res = input_string_of_book(author);
    while (res == -1)
    {
        for (int i = 0; i < LEN_NAME; i++)
            author[i] = '\0';
        printf("\n\nIncorrect input! Please, input author of book for delete (Length of it < 31): ");
        res = input_string_of_book(author);
    }
    if (res != -1)
    {
        change_last_symbol_after_input(author);
        for (int i = 0; i < *length_array; i++)
        {
            if (strcmp(author, array[i].author) == 0)
                delete_struct(array, i, length_array);
        }
    }
    return result;
}

int delete_bookname_struct(struct book *array, int *length_array)
{
    int res, result = ok;
    char name[LEN_NAME];
    for (int i = 0; i < LEN_NAME; i++)
        name[i] = '\0';
    printf("\nInput bookname for delete (length of it < 31): ");
    res = input_string_of_book(name);
    while (res == -1)
    {
        for (int i = 0; i < LEN_NAME; i++)
            name[i] = '\0';
        printf("\n\nIncorrect input! Please, input bookname for delete (Length of it < 31): ");
        res = input_string_of_book(name);
    }
    if (res != -1)
    {
        change_last_symbol_after_input(name);
        for (int i = 0; i < *length_array; i++)
            if (strcmp(name, array[i].bookname) == 0)
                delete_struct(array, i, length_array);
    }
    return result;
}

int delete_publish_house_struct(struct book *array, int *length_array)
{
    int res, result = ok;
    char pub_house[LEN_NAME];
    for (int i = 0; i < LEN_NAME; i++)
        pub_house[i] = '\0';
    printf("\nInput publish name to delete: ");
    res = input_string_of_book(pub_house);
    while (res == -1)
    {
        for (int i = 0; i < LEN_NAME; i++)
            pub_house[i] = '\0';
        printf("\n\nIncorrect input! Please, input author of book for delete (Length of it < 31): ");
        res = input_string_of_book(pub_house);
    }
    if (res != -1)
    {
        change_last_symbol_after_input(pub_house);
        for (int i = 0; i < *length_array; i++)
            if (strcmp(pub_house, array[i].publishing_house) == 0)
                delete_struct(array, i, length_array);
    }
    return result;
}

int delete_pages_struct(struct book *array, int *length_array)
{
    int res, result = ok;
    printf("\nInput number of pages for delete (it is integer > 0): ");
    res = input_integer();
    while ((res == -1) || (res < 1))
    {
        printf("\n\nIncorrect input! Please, input number of pages (it is integer > 0): ");
        fflush(stdin);
        res = input_integer();
    }
    if (res != -1)
    {
        for (int i = 0; i < *length_array; i++)
            if (array[i].number_pages == res)
                delete_struct(array, i, length_array);
    }
    return result;
}

int delete_struct_in_array(struct book *array, int *length_array)
{
    int result = ok;
    int choose;
    //getchar();
    if (*length_array == 0)
    {
        printf("\nYou can't delete books from empty base!");
        return ok;
    }
    printf("Choose field for delete (1 - author, 2 - bookname, 3 - publishing house, 4 - number of pages, 5 - index): ");
    choose = input_integer();
    while ((choose == -1) || (choose < 1) || (choose > 5))
    {
        printf("\n\nIncorrect input! Please, choose field for delete (1 - author, 2 - bookname, 3 - publishing house, 4 - number of pages, 5 - index): ");
        fflush(stdin);
        choose = input_integer();
    }
    if (choose == 1)
        delete_author_struct(array, length_array);
    else if (choose == 2)
        delete_bookname_struct(array, length_array);
    else if (choose == 3)
        delete_publish_house_struct(array, length_array);
    else if (choose == 4)
        delete_pages_struct(array, length_array);
    else if (choose == 5)
    {
        printf("\nChoose index (First book is 1): ");
        choose = input_integer();
        while ((choose == -1) || (choose < 1) || (choose > 5))
        {
            printf("\n\nIncorrect input! Please, choose field for delete (1 - author, 2 - bookname, 3 - publishing house, 4 - number of pages, 5 - index): ");
            fflush(stdin);
            choose = input_integer();
        }
        if (choose < *length_array)
        {
            delete_struct(array, choose - 1, length_array);
            printf("\nDelete is complete!\n");
        }
        else
            printf("No element with this index!\n");
    }
    printf("\n");
    return result;
}

void save_in_file(char *file_name, struct book *array, int length_array)
{
    FILE *f;
    f = fopen(file_name, "w");
    if (f == NULL)
        return;
    for (int i = 0; i < length_array; i++)
    {
        fprintf(f, "%s\n%s\n%s\n%d\n%d", array[i].author, array[i].bookname, array[i].publishing_house, array[i].number_pages, array[i].book_type);
        switch (array[i].book_type)
        {
        case 0:
            fprintf(f, "\n%s\n%d\n%d\n", array[i].technic.branch, array[i].technic.language, array[i].technic.age);
            break;
        case 1:
            fprintf(f, "\n%d\n", array[i].fiction.genre);
            break;
        case 2:
            fprintf(f, "\n%d\n", array[i].children.genre);
            break;
        default:
            break;
        }
    }
    fclose(f);
}

void find_author(struct book *array, int length_array)
{
    char author[LEN_NAME];
    for (int i = 0; i < LEN_NAME; i++)
        author[i] = '\0';
    printf("\nInput author name for delete (length of it < 31): ");
    int res = input_string_of_book(author);
    while (res == -1)
    {
        for (int i = 0; i < LEN_NAME; i++)
            author[i] = '\0';
        printf("\n\nIncorrect input! Please, input author of book for delete (Length of it < 31): ");
        res = input_string_of_book(author);
    }
    if (res != -1)
    {
        int count = 0;
        change_last_symbol_after_input(author);
        for (int i = 0; i < length_array; i++)
        {
            if (strcmp(author, array[i].author) == 0)
            {
                count++;
                if (count == 1)
                {
                    printf("Founded structs:\n");
                    char *s1 = "Author", *s2 = "Bookname", *s3 = "Publish House", *s4 = "Number of pages", *s5 = "Type of literature", *s0 = "Index";
                    printf("%7s %35s %35s %35s %25s %20s\n\n", s0, s1, s2, s3, s4, s5);

                }
                printf("%8d", i + 1);
                print_struct(&array[i]);
            }
        }
    }
}

void find_bookname(struct book *array, int length_array)
{
    int res;
    char name[LEN_NAME];
    for (int i = 0; i < LEN_NAME; i++)
        name[i] = '\0';
    printf("\nInput bookname for delete (length of it < 31): ");
    res = input_string_of_book(name);
    while (res == -1)
    {
        for (int i = 0; i < LEN_NAME; i++)
            name[i] = '\0';
        printf("\n\nIncorrect input! Please, input bookname for delete (Length of it < 31): ");
        res = input_string_of_book(name);
    }
    if (res != -1)
    {
        int count = 0;
        change_last_symbol_after_input(name);
        for (int i = 0; i < length_array; i++)
        {
            if (strcmp(name, array[i].bookname) == 0)
            {
                count++;
                if (count == 1)
                {
                    printf("Founded structs:\n");
                    char *s1 = "Author", *s2 = "Bookname", *s3 = "Publish House", *s4 = "Number of pages", *s5 = "Type of literature", *s0 = "Index";
                    printf("%7s %35s %35s %35s %25s %20s\n\n", s0, s1, s2, s3, s4, s5);
                }
                printf("%8d", i + 1);
                print_struct(&array[i]);
            }
        }
    }
}

void find_publish_house(struct book *array, int length_array)
{
    int res;
    char pub_house[LEN_NAME];
    for (int i = 0; i < LEN_NAME; i++)
        pub_house[i] = '\0';
    printf("\nInput publish name to delete: ");
    res = input_string_of_book(pub_house);
    while (res == -1)
    {
        for (int i = 0; i < LEN_NAME; i++)
            pub_house[i] = '\0';
        printf("\n\nIncorrect input! Please, input author of book for delete (Length of it < 31): ");
        res = input_string_of_book(pub_house);
    }
    if (res != -1)
    {
        int count = 0;
        change_last_symbol_after_input(pub_house);
        for (int i = 0; i < length_array; i++)
        {
            if (strcmp(pub_house, array[i].publishing_house) == 0)
            {
                count++;
                if (count == 1)
                {
                    printf("Founded structs:\n");
                    char *s1 = "Author", *s2 = "Bookname", *s3 = "Publish House", *s4 = "Number of pages", *s5 = "Type of literature", *s0 = "Index";
                    printf("%7s %35s %35s %35s %25s %20s\n\n", s0, s1, s2, s3, s4, s5);
                }
                printf("%8d", i + 1);
                print_struct(&array[i]);
            }
        }
    }
}

void find_number_of_pages(struct book *array, int length_array)
{
     int res;
     printf("\nInput number of pages for delete (it is integer > 0): ");
     res = input_integer();
     while ((res == -1) || (res < 1))
     {
         printf("\n\nIncorrect input! Please, input number of pages (it is integer > 0): ");
         fflush(stdin);
         res = input_integer();
     }
     if (res != -1)
     {
         int count = 0;
         for (int i = 0; i < length_array; i++)
             if (array[i].number_pages == res)
             {
                 count++;
                 if (count == 1)
                 {
                     printf("Founded structs:\n");
                     char *s1 = "Author", *s2 = "Bookname", *s3 = "Publish House", *s4 = "Number of pages", *s5 = "Type of literature", *s0 = "Index";
                     printf("%7s %35s %35s %35s %25s %20s\n\n", s0, s1, s2, s3, s4, s5);
                 }
                 printf("%8d", i + 1);
                 print_struct(&array[i]);
             }
     }
}

void find_structs(struct book *array, int *length_array)
{
    int choose;
    if (*length_array == 0)
    {
        printf("\nYou can't find books in empty base!");
        return;
    }
    printf("Choose field for delete (1 - author, 2 - bookname, 3 - publishing house, 4 - number of pages): ");
    choose = input_integer();
    while ((choose == -1) || (choose < 1) || (choose > 4))
    {
        printf("\n\nIncorrect input! Please, choose field for delete (1 - author, 2 - bookname, 3 - publishing house, 4 - number of pages): ");
        fflush(stdin);
        choose = input_integer();
    }
    if (choose == 1)
        find_author(array, *length_array);
    else if (choose == 2)
        find_bookname(array, *length_array);
    else if (choose == 3)
        find_publish_house(array, *length_array);
    else if (choose == 4)
        find_number_of_pages(array, *length_array);
    printf("\n");
}
