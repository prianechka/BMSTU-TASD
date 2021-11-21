#ifndef TYPES_H
#define TYPES_H
#define LEN_NAME 30
#define MAX_STRUCTURES 999
#define EXPERIMENT 100000

enum key_error
{
    ok,
    error,
    end_reading
};

enum type_of_book
{

    technical,
    fictions,
    children
};

enum type_of_fiction
{
    novel,
    play,
    verse
};

enum type_of_child_literature
{
    fairytale,
    child_verse
};

enum type_of_original_language
{
    domestic,
    foreign
};

struct technical_literature
{
    char branch[LEN_NAME];
    enum type_of_original_language language;
    int age;
};

struct fiction_literature
{
    enum type_of_fiction genre;
};

struct children_literature
{
    enum type_of_child_literature genre;
};

struct book
{
    char author[LEN_NAME];
    char bookname[LEN_NAME];
    char publishing_house[LEN_NAME];
    int number_pages;
    enum type_of_book book_type;
    union
    {
        struct technical_literature technic;
        struct fiction_literature fiction;
        struct children_literature children;
    };
};

struct table
{
    int index_in_table;
    int number_of_pages;
};

#endif // TYPES_H
