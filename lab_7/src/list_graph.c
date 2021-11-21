#include "../inc/list_graph.h"

void init_list_graph(node_t **list, int n)
{
    for (int i = 0; i < n; i++)
    {
        list[i] = (node_t *)malloc(sizeof (node_t));
        list[i]->index = i;
        list[i]->weight = 0;
        list[i]->next = NULL;
    }
}


void create_list_graph(FILE *f, int n, node_t **list)
{
    int a;
    int *number = &a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            read_int_number(f, number);
            if (*number != 0)
            {
                node_t *tmp = list[i];
                while (tmp->next != NULL)
                    tmp = tmp->next;
                tmp->next = (node_t*)malloc(sizeof (node_t));
                tmp = tmp->next;
                tmp->index = j;
                tmp->weight = *number;
                tmp->next = NULL;
            }
        }
    }
}

int get_value(node_t **list, int i, int j)
{
    int result = 0;
    node_t *tmp = list[i]->next;
    while (tmp != NULL)
    {
        if (tmp->index == j)
        {
            result = tmp->weight;
            break;
        }
        else
            tmp = tmp->next;
    }
    return result;
}

void print_list_graph(node_t **list, int n)
{
    for (int i = 0; i < n; i++)
    {
        node_t *tmp = list[i]->next;
        while (tmp != NULL)
        {
            printf("%d -> %d: %d\n", i + 1, tmp->index + 1, tmp->weight);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

void floid_list(node_t **list, int n, int flag)
{
    int **matrix = allocate_matrix(n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (get_value(list, i, j) != 0)
                matrix[i][j] = get_value(list, i, j);
            else
                matrix[i][j] = MAX_GRAPH;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                matrix[j][k] = (int)fmin(matrix[j][k], matrix[j][i] + matrix[i][k]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                matrix[i][j] = 0;
            else if (matrix[i][j] == MAX_GRAPH)
                matrix[i][j] = -1;
        }
    }
    if (flag == 1)
    {
        print_array(matrix, n, n);
        print_graph(matrix, n, "floid_list");
    }
}

int list_min_distance(int *min_len, int *vertex, int size)
{
    int min = INT_MAX;
    int min_index;

    for (int i = 0; i < size; i++)
    {
        if (vertex[i] == 0 && min_len[i] <= min)
        {
            min = min_len[i];
            min_index = i;
        }
    }

    return min_index;
}

void dextra_list(node_t **list, int n, int flag)
{
    int **result_matrix = allocate_matrix(n, n);
    for (int first_vertex = 0; first_vertex < n; first_vertex++)
    {
        int *min_len = malloc(n * sizeof (int));
        int *vertex = malloc(n * sizeof (int));
        int *matrix = malloc(n * sizeof (int));
        for (int i = 0; i < n; i++)
        {
            *(min_len + i) = MAX_GRAPH;
            *(vertex + i) = 0;
            *(matrix + i) = 0;
        }
        *(min_len + first_vertex) = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int index_to_min = list_min_distance(min_len, vertex, n);
            *(vertex + index_to_min) = 1;
            for (int j = 0; j < n; j++)
            {
                if (!vertex[j] && get_value(list, index_to_min, j) && min_len[index_to_min] != MAX_GRAPH
                    && min_len[index_to_min] + get_value(list, index_to_min, j) < min_len[j])
                {
                    min_len[j] = min_len[index_to_min] + get_value(list, index_to_min, j);
                    matrix[j] = index_to_min;
                }
            }
        }
        result_matrix[first_vertex] = min_len;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (result_matrix[i][j] == MAX_GRAPH)
                result_matrix[i][j] = -1;
    if (flag == 1)
    {
        print_array(result_matrix, n, n);
        print_graph(result_matrix, n, "dextra_list");
    }
}

void belman_list(node_t **list, int n, int flag)
{
    int **result_matrix = allocate_matrix(n, n);
    for (int vertex = 0; vertex < n; vertex++)
    {
        int *min_len = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            min_len[i] = MAX_GRAPH;
        min_len[vertex] = 0;
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (get_value(list, i, j) != 0)
                        if (min_len[j] > min_len[i] + get_value(list, i, j))
                            min_len[j] = min_len[i] + get_value(list, i, j);
        result_matrix[vertex] = min_len;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (result_matrix[i][j] == MAX_GRAPH)
                result_matrix[i][j] = -1;
    if (flag == 1)
    {
        print_array(result_matrix, n, n);
        print_graph(result_matrix, n, "dextra");
    }
}
