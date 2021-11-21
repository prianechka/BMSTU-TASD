#include "../inc/graph.h"


graph_t *create_graph(FILE *f)
{
    graph_t *result_graph = malloc(sizeof (graph_t *));
    result_graph->size = malloc(sizeof (int));
    int result = read_int_number(f, result_graph->size);
    if ((result == error) || (result_graph->size <= 0))
        result_graph = NULL;
    else
    {
        result_graph->matrix = read_file(f, *result_graph->size, *result_graph->size);
        if (result_graph->matrix == NULL)
            result_graph = NULL;
    }
    return result_graph;
}


void floid(graph_t *graph, int flag)
{
    int **matrix = allocate_matrix(*graph->size, *graph->size);
    for (int i = 0; i < *graph->size; i++)
    {
        for (int j = 0; j < *graph->size; j++)
        {
            if (graph->matrix[i][j] != 0)
                matrix[i][j] = graph->matrix[i][j];
            else
                matrix[i][j] = MAX_GRAPH;
        }
    }
    for (int i = 0; i < *graph->size; i++)
        for (int j = 0; j < *graph->size; j++)
            for (int k = 0; k < *graph->size; k++)
                matrix[j][k] = (int)fmin(matrix[j][k], matrix[j][i] + matrix[i][k]);
    for (int i = 0; i < *graph->size; i++)
    {
        for (int j = 0; j < *graph->size; j++)
        {
            if (i == j)
                matrix[i][i] = 0;
            else if (matrix[i][j] == MAX_GRAPH)
                matrix[i][j] = -1;
        }
    }
    if (flag == 1)
    {
        print_array(matrix, *graph->size, *graph->size);
        print_graph(matrix, *graph->size, "floid");
    }
}

int min_distance(int *min_len, int *vertex, int size)
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

void dextra(graph_t *graph, int flag)
{
    int **result_matrix = allocate_matrix(*graph->size, *graph->size);
    for (int first_vertex = 0; first_vertex < *graph->size; first_vertex++)
    {
        int *min_len = malloc(*graph->size * sizeof (int));
        int *vertex = malloc(*graph->size * sizeof (int));
        int *matrix = malloc(*graph->size * sizeof (int));
        for (int i = 0; i < *graph->size; i++)
        {
            *(min_len + i) = MAX_GRAPH;
            *(vertex + i) = 0;
            *(matrix + i) = 0;
        }
        *(min_len + first_vertex) = 0;

        for (int i = 0; i < *graph->size - 1; i++)
        {
            int index_to_min = min_distance(min_len, vertex, *graph->size);
            *(vertex + index_to_min) = 1;
            for (int j = 0; j < *graph->size; j++)
            {
                if (!vertex[j] && graph->matrix[index_to_min][j] && min_len[index_to_min] != MAX_GRAPH
                    && min_len[index_to_min] + graph->matrix[index_to_min][j] < min_len[j])
                {
                    min_len[j] = min_len[index_to_min] + graph->matrix[index_to_min][j];
                    matrix[j] = index_to_min;
                }
            }
        }
        result_matrix[first_vertex] = min_len;
    }
    for (int i = 0; i < *graph->size; i++)
        for (int j = 0; j < *graph->size; j++)
            if (result_matrix[i][j] == MAX_GRAPH)
                result_matrix[i][j] = -1;
    if (flag == 1)
    {
        print_array(result_matrix, *graph->size, *graph->size);
        print_graph(result_matrix, *graph->size, "dextra");
    }
}

void belman(graph_t *graph, int flag)
{
    int **result_matrix = allocate_matrix(*graph->size, *graph->size);
    for (int vertex = 0; vertex < *graph->size; vertex++)
    {
        int *min_len = malloc(*graph->size * sizeof(int));

        for (int i = 0; i < *graph->size; i++)
            min_len[i] = MAX_GRAPH;
        min_len[vertex] = 0;
        for (int k = 0; k < *graph->size; k++)
            for (int i = 0; i < *graph->size; i++)
                for (int j = 0; j < *graph->size; j++)
                    if (graph->matrix[i][j] != 0) //если вершину не посещали
                        if (min_len[j] > min_len[i] + graph->matrix[i][j])
                            min_len[j] = min_len[i] + graph->matrix[i][j];
        result_matrix[vertex] = min_len;
    }
    for (int i = 0; i < *graph->size; i++)
        for (int j = 0; j < *graph->size; j++)
            if (result_matrix[i][j] == MAX_GRAPH)
                result_matrix[i][j] = -1;
    if (flag == 1)
    {
        print_array(result_matrix, *graph->size, *graph->size);
        print_graph(result_matrix, *graph->size, "belman");
    }
}
