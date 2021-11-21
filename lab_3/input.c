#include "input.h"
#include <locale.h>
#include <windows.h>


int input_integer(int *new_number)
{
    int c, res = ok, result = 0, length = 0, flag_minus = 0;
    while ((c = getchar()) != '\n')
    {
        if (c >= '0' && c <= '9' && res == ok)
        {
            result = (result * 10 + c - 48);
            length++;
        }
        else if (length == 0 && c == '-')
        {
            flag_minus = 1;
            length++;
        }
        else
            res = error;
    }
    if (res == ok)
    {
        *new_number = result;
        if (flag_minus == 1)
            *new_number *= (-1);
    }

    if (length == 0)
        res = error;
    return res;
}
int input_float(double *result)
{
    *result = 0;
    int res = ok;
    char c;
    int length = 0, minus = 0, fraction = 0, length_fraction = 1, fraction_count = 0;
    while ((c = getchar()) != '\n')
    {
        if (c >= '0' && c <= '9' && res == ok)
        {
            if (fraction == 0)
                *result = (*result * 10 + c - 48);
            else if (fraction == 1)
            {
                *result += ((c - 48) / pow(10, length_fraction));
                length_fraction++;
            }
            length++;
        }
        else if ((length == 0) && (c == '-'))
            minus = 1;
        else if (c == '.')
        {
            fraction = 1;
            if (++fraction_count > 1)
                res = error;
        }
        else
            res = error;
    }
    if (res == ok && minus == 1)
        *result *= (-1);
    return res;
}

void make_sparce_matrix(struct matrix *matr, struct sparce_matrix *sp_matrix, int count_nonzero)
{
    sp_matrix->number_columns = matr->number_columns;
    sp_matrix->number_strings = matr->number_strings;
    sp_matrix->nonzero_elems = count_nonzero;
    sp_matrix->A = calloc(count_nonzero, sizeof(double));
    sp_matrix->JA = calloc(count_nonzero, sizeof(int));
    sp_matrix->IA = calloc(matr->number_strings, sizeof(int));
    int count_string = 0, count_elem = 0;
    for (int i = 0; i < matr->number_strings; i++)
    {
        count_string = 0;
        for (int j = 0; j < matr->number_columns; j++)
        {
            if (matr->array[i * matr->number_columns + j] != 0)
            {
                sp_matrix->A[count_elem] = matr->array[i * matr->number_columns + j];
                sp_matrix->JA[count_elem] = j;
                if (count_string == 0)
                    sp_matrix->IA[i] = count_elem;
                count_string++;
                count_elem++;
            }
            else if ((j == matr->number_columns - 1) && (count_string == 0))
                sp_matrix->IA[i] = -1;
        }
    }
}

void input_auto_matrix(struct matrix *matr, int *count_of_nonzero)
{
    int result = ok;
    printf("Выберите примерный коэффициент заполнения матрицы (число от 0 до 1): ");
    double q;
    result = input_float(&q);
    while (result == error || (q <= 0) || (q > 1))
    {
        printf("\nНеправильный ввод! Пожалуйста, выберите примерный коэффицент заполнения матрицы (число от 0 до 1): ");
        result = input_float(&q);
    }
    q *= 100;
    matr->array = malloc(matr->number_strings * matr->number_columns * sizeof(double));
    for (int i = 0; i < matr->number_strings; i++)
    {
        for (int j = 0; j < matr->number_columns; j++)
        {
            double reg = rand()%100;
            if (reg < q)
            {
                double new_number = rand()%100;
                matr->array[i * matr->number_columns + j] = new_number;
                *count_of_nonzero += 1;
            }
            else
                matr->array[i * matr->number_columns + j] = 0;
        }
    }
}

void input_hand_matrix(struct matrix *matr, int *count_of_nonzero)
{
    int result = ok;
    matr->array = calloc(matr->number_strings * matr->number_columns, sizeof(double));
    for (int i = 0; i < matr->number_strings; i++)
    {
        for (int j = 0; j < matr->number_columns; j++)
        {
            printf("\nВведите число, индекс строки - %d, индекс столбца - %d: ", i, j);
            double new_number;
            result = input_float(&new_number);
            while (result == error)
            {
                printf("\nНеправильный ввод! Пожалуйста, введите число, индекс строки - %d, индекс столбца - %d: ", i, j);
                result = input_float(&new_number);
            }
            matr->array[i * matr->number_columns + j] = new_number;
            if (new_number != 0)
                *count_of_nonzero += 1;
        }
    }
}

void input_sparce_matrix(struct matrix *matr, int *count_nonzero)
{
    int new_number, res;
    printf("Введите количество строк матрицы (натуральное число): ");
    res = input_integer(&new_number);
    while ((res == error) || (new_number < 1))
    {
        printf("\nВы ввели неправильно! Пожалуйста, введите количество строк матрицы (натуральное число): ");
        new_number = 0;
        res = input_integer(&new_number);
    }
    matr->number_strings = new_number;

    printf("Введите количество столбцов матрицы (натуральное число): ");
    res = input_integer(&new_number);
    while ((res == error) || (new_number < 1))
    {
        new_number = 0;
        printf("\nВы ввели неправильно! Пожалуйста, введите количество столбцов матрицы (натуральное число): ");
        res = input_integer(&new_number);
    }
    matr->number_columns = new_number;

    printf("Выберите режим ввода: 1 - автоматический (программа сама создаст матрицу)");
    printf(", 2 - ручной: ");
    res = input_integer(&new_number);
    while (res == error || (new_number != 1 && new_number != 2))
    {
        new_number = 0;
        printf("\nВы ввели неправильно! Пожалуйста, выберите режим ввода: 1 - автоматический (программа сама создаст матрицу), 2 - ручной: ");
        res = input_integer(&new_number);
    }
    if (new_number == 1)
        input_auto_matrix(matr, count_nonzero);
    else
        input_hand_matrix(matr, count_nonzero);
}

void input_vector(struct matrix *matr, int *count_nonzero)
{
    int res, new_number;
    printf("Выберите режим ввода: 1 - автоматический (программа сама создаст матрицу)");
    printf(", 2 - ручной: ");
    res = input_integer(&new_number);
    while (res == error || (new_number != 1 && new_number != 2))
    {
        new_number = 0;
        printf("\nВы ввели неправильно! Пожалуйста, выберите режим ввода: 1 - автоматический (программа сама создаст матрицу), 2 - ручной: ");
        res = input_integer(&new_number);
    }
    if (new_number == 1)
        input_auto_matrix(matr, count_nonzero);
    else
        input_hand_matrix(matr, count_nonzero);
}
