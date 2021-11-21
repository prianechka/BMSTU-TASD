#include "process.h"


void process_sparce_matrix()
{
    struct sparce_matrix sp_matrix;
    struct matrix matr;
    struct sparce_matrix vector;
    struct matrix vector_matrix;

    int count_nonzero = 0, res, choose;

    input_sparce_matrix(&matr, &count_nonzero);
    make_sparce_matrix(&matr, &sp_matrix, count_nonzero);
    printf("Вывести получившуюся матрицу? 1 - да, 0 - нет: ");
    res = input_integer(&choose);
    while ((res == error) || (choose < 0) || (choose > 1))
    {
        printf("\n\nНеправильный ввод! Вывести получившуюся матрицу? 1 - да, 0 - нет: ");
        fflush(stdin);
        res = input_integer(&choose);
    }
    if (choose == 1)
    {
        printf("Получившася матрица: \n");
        print_sparce_array(&sp_matrix);
    }

    count_nonzero = 0;
    vector_matrix.number_columns = 1;
    vector_matrix.number_strings = sp_matrix.number_columns;
    printf("\n\nВведите элементы вектора-столбца\n");
    input_vector(&vector_matrix, &count_nonzero);
    make_sparce_matrix(&vector_matrix, &vector, count_nonzero);

    printf("Вывести получившуюся матрицу? 1 - да, 0 - нет: ");
    res = input_integer(&choose);
    while ((res == error) || (choose < 0) || (choose > 1))
    {
        printf("\n\nНеправильный ввод! Вывести получившуюся матрицу? 1 - да, 0 - нет: ");
        fflush(stdin);
        res = input_integer(&choose);
    }
    if (choose == 1)
    {
        printf("Получившася матрица: \n");
        print_sparce_array(&vector);
    }

    struct sparce_matrix result;
    multiply_sparce_matrix(&sp_matrix, &vector, &result);
    printf("\n\nПолучившийся ответ при умножении: \n");
    print_sparce_array(&result);

    free(sp_matrix.IA);
    free(sp_matrix.JA);
    free(sp_matrix.A);
    free(vector.IA);
    free(vector.JA);
    free(vector.A);
    free(result.IA);
    free(result.JA);
    free(result.A);

    printf("\n\n\n");
}

void process_matrix()
{
    struct matrix matr_one;
    struct matrix vector;

    int count_nonzero, res, choose;
    input_sparce_matrix(&matr_one, &count_nonzero);
    printf("Вывести получившуюся матрицу? 1 - да, 0 - нет: ");
    res = input_integer(&choose);
    while ((res == error) || (choose < 0) || (choose > 1))
    {
        printf("\n\nНеправильный ввод! Вывести получившуюся матрицу? 1 - да, 0 - нет: ");
        fflush(stdin);
        res = input_integer(&choose);
    }
    if (choose == 1)
    {
        printf("Получившася матрица: \n");
        print_matrix(&matr_one);

    }
    vector.number_columns = 1;
    vector.number_strings = matr_one.number_columns;
    printf("Введите элементы вектора-столбца: \n");
    input_vector(&vector, &count_nonzero);
    printf("Вывести получившуюся матрицу? 1 - да, 0 - нет: ");
    res = input_integer(&choose);
    while ((res == error) || (choose < 0) || (choose > 1))
    {
        printf("\n\nНеправильный ввод! Вывести получившуюся матрицу? 1 - да, 0 - нет: ");
        fflush(stdin);
        res = input_integer(&choose);
    }
    if (choose == 1)
    {
        printf("Получившийся вектор: \n");
        print_matrix(&vector);
    }

    struct matrix result;
    result.number_columns = 1;
    result.number_strings = matr_one.number_strings;
    result.array = calloc (result.number_columns * result.number_strings, sizeof(double));
    multiply_matrix(&matr_one, &vector, &result);
    printf("\n\nПолучившийся ответ при умножении: \n");
    print_matrix(&result);

    free(matr_one.array);
    free(vector.array);
    free(result.array);
}

void process_compare()
{
    struct sparce_matrix sp_matrix;
    struct matrix matr;
    struct sparce_matrix vector;
    struct matrix vector_matrix;

    int count_nonzero = 0, res, choose;

    input_sparce_matrix(&matr, &count_nonzero);
    make_sparce_matrix(&matr, &sp_matrix, count_nonzero);
    printf("Вывести получившуюся матрицу? 1 - да, 0 - нет: ");
    res = input_integer(&choose);
    while ((res == error) || (choose < 0) || (choose > 1))
    {
        printf("\n\nНеправильный ввод! Вывести получившуюся матрицу? 1 - да, 0 - нет: ");
        fflush(stdin);
        res = input_integer(&choose);
    }
    if (res == 1)
    {
        printf("Получившася матрица: \n");
        print_sparce_array(&sp_matrix);
    }

    count_nonzero = 0;
    vector_matrix.number_columns = 1;
    vector_matrix.number_strings = sp_matrix.number_strings;
    printf("\n\nВведите элементы вектора-столбца\n");
    input_vector(&vector_matrix, &count_nonzero);
    make_sparce_matrix(&vector_matrix, &vector, count_nonzero);

    printf("Вывести получившуюся матрицу? 1 - да, 0 - нет: ");
    res = input_integer(&choose);
    while ((res == error) || (choose < 0) || (choose > 1))
    {
        printf("\n\nНеправильный ввод! Вывести получившуюся матрицу? 1 - да, 0 - нет: ");
        fflush(stdin);
        res = input_integer(&choose);
    }
    if (res == 1)
    {
        printf("\nПолучившийся вектор-столбец: \n");
        print_sparce_array(&vector);
    }
    printf("Seg_sparce = %d\n", (sp_matrix.nonzero_elems * 2 + sp_matrix.number_strings + 6 + vector.nonzero_elems * 2 +vector.number_strings) * 4);

    printf("\nХарактеристики основной матрицы: %d - количество строк, %d - количество столбцов\n\n", sp_matrix.number_strings, sp_matrix.number_columns);
    clock_t start, stop;
    start = clock();
    for (int i = 0; i < TIME; i++)
    {
        struct sparce_matrix result;
        multiply_sparce_matrix(&sp_matrix, &vector, &result);
        free(result.A);
        free(result.JA);
        free(result.IA);
    }
    stop = clock();
    printf("\n\nВремя умножения алгоритмами разреженных матриц: ");
    double time = ((double)stop - (double)start) / CLK_TCK;
    printf("%fs\n", time);

    printf("Seg usual= %d\n", (matr.number_strings * matr.number_strings + 4 + vector_matrix.number_columns * vector_matrix.number_strings) * 4);

    start = clock();
    for (int i = 0; i < TIME; i++)
    {
        struct matrix result;
        result.number_columns = 1;
        result.number_strings = matr.number_strings;
        result.array = calloc (result.number_columns * result.number_strings, sizeof(double));
        multiply_matrix(&matr, &vector_matrix, &result);
        free(result.array);
    }
    stop = clock();
    printf("\nВремя умножения алгоритмами обычных матриц: ");
    time = ((double)stop - (double)start) / CLK_TCK;
    printf("%fs\n", time);
}


int process_menu()
{
    int choose = 0, res;
    print_menu();
    res = input_integer(&choose);
    while ((res == error) || (choose < 0) || (choose > 3))
    {
        printf("\n\nНеправильный ввод! Выберите правильный пункт меню: ");
        fflush(stdin);
        res = input_integer(&choose);
    }
    switch (choose)
    {
    case 1:
        process_sparce_matrix();
        break;
    case 2:
        process_matrix();
        break;
    case 3:
        process_compare();
        break;
    }
    return choose;
}
