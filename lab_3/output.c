#include "output.h"

void print_sparce_array(struct sparce_matrix *sp_matrix)
{
    printf("\nНенулевые значения:       ");
    for (int i = 0; i < sp_matrix->nonzero_elems; i++)
        printf("%.2f ", sp_matrix->A[i]);
    printf("\nИндексы столбцов:         ");
    for (int i = 0; i < sp_matrix->nonzero_elems; i++)
        printf("%d ", sp_matrix->JA[i]);
    printf("\nНомера для строк:         ");
    for (int i = 0; i < sp_matrix->number_strings; i++)
        printf("%d ", sp_matrix->IA[i]);
}

void print_menu()
{
    printf("\nПрограмма производит умножение разреженной матрицы на вектор-столбец\n\n");
    printf("Выберите один из пунктов меню: \n");
    printf("1 - ввести (сгенерировать) и перемножить разреженную матрицу и вектор-столбец\n");
    printf("2 - ввести (сгенерировать) обычные матрицы и перемножить друг с другом\n");
    printf("3 - сравнить время работы двух методов перемножения матриц\n");
    printf("0 - выход\n");
    printf("Выберите пункт: ");
}

void print_matrix(struct matrix *matr)
{
    if (matr->number_columns > 20 || matr->number_strings > 20)
    {
        printf("\n\nРазмеры у матрицы слишком большие, чтобы поместиться на мониторе!\n\n");
        return;
    }
    for (int i = 0; i < matr->number_strings; i++)
    {
        for (int j = 0; j < matr->number_columns; j++)
            printf("%f ", matr->array[i * matr->number_columns + j]);
        printf("\n");
    }
}
