#include "output.h"

void print_sparce_array(struct sparce_matrix *sp_matrix)
{
    printf("\n��������� ��������:       ");
    for (int i = 0; i < sp_matrix->nonzero_elems; i++)
        printf("%.2f ", sp_matrix->A[i]);
    printf("\n������� ��������:         ");
    for (int i = 0; i < sp_matrix->nonzero_elems; i++)
        printf("%d ", sp_matrix->JA[i]);
    printf("\n������ ��� �����:         ");
    for (int i = 0; i < sp_matrix->number_strings; i++)
        printf("%d ", sp_matrix->IA[i]);
}

void print_menu()
{
    printf("\n��������� ���������� ��������� ����������� ������� �� ������-�������\n\n");
    printf("�������� ���� �� ������� ����: \n");
    printf("1 - ������ (�������������) � ����������� ����������� ������� � ������-�������\n");
    printf("2 - ������ (�������������) ������� ������� � ����������� ���� � ������\n");
    printf("3 - �������� ����� ������ ���� ������� ������������ ������\n");
    printf("0 - �����\n");
    printf("�������� �����: ");
}

void print_matrix(struct matrix *matr)
{
    if (matr->number_columns > 20 || matr->number_strings > 20)
    {
        printf("\n\n������� � ������� ������� �������, ����� ����������� �� ��������!\n\n");
        return;
    }
    for (int i = 0; i < matr->number_strings; i++)
    {
        for (int j = 0; j < matr->number_columns; j++)
            printf("%f ", matr->array[i * matr->number_columns + j]);
        printf("\n");
    }
}
