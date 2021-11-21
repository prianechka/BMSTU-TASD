#include "../inc/output.h"

void print_graph(int **matrix, int n, char *name)
{
    FILE *f;
    char *gv = ".gv";
    int len = strlen(name);
    char new_string[len + 4];
    for (int i = 0; i < len; i++)
        new_string[i] = name[i];
    for (int i = len; i < len + 3; i++)
        new_string[i] = gv[i - len];
    new_string[len + 3] = '\0';
    f = fopen(new_string, "w");
    fprintf(f, "digraph %s {\nrankdir=LR\n", name);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((i != j) && (j > i) && (matrix[i][j] > 0) && (matrix[i][j] != MAX_GRAPH))
                fprintf(f, "%d -> %d[label = %d, arrowhead = none]\n", i + 1, j + 1, matrix[i][j]);
    fprintf(f, "}\n");
    fclose(f);
}

void print_array(int **array, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((j != i) && (j > i) && (array[i][j] > 0))
                printf("������� %d <-> %d = %d\n", i + 1, j + 1, array[i][j]);
            else if (((j != i) && (j > i) && (array[i][j] == -1)))
                printf("����� ��������� %d � %d ���� ���\n", i + 1, j + 1);
        }
    }
}

void print_menu()
{
    printf("------------------------------------\n");
    printf("1 - ������� ������� ����\n");
    printf("2 - ����� ���������� ���� ����� ��������� ������� ������\n");
    printf("3 - ����� ���������� ���� ����� ��������� ������� ��������\n");
    printf("4 - ����� ���������� ���� ����� ��������� ������� ��������\n");
    printf("5 - �������� ������������� �������� � ����������\n");
    printf("6 - ������� ����\n");
    printf("0 - �����\n");
    printf("�������� ����� ����: ");
}

