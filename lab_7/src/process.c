#include "../inc/process.h"

void process_print(graph_t *graph)
{
    printf("\nТекущий граф в текстовом варианте:\n");
    print_array(graph->matrix, *graph->size, *graph->size);
    print_graph(graph->matrix, *graph->size, "graphi");
    printf("Текущий граф в графическом варианте: graph.gv\n");
}

void process_floid(graph_t *graph)
{
    printf("\nКратчайшие расстояния в текстовом варианте:\n");
    floid(graph, 1);
    printf("Кратчайшие расстояния в графическом варианте: floid.gv\n");
}

void process_dextra(graph_t *graph)
{
    printf("\nКратчайшие расстояния в текстовом варианте:\n");
    dextra(graph, 1);
    printf("Кратчайшие расстояния в графическом варианте: dextra.gv\n");
}

void process_belman(graph_t *graph)
{
    printf("\nКратчайшие расстояния в текстовом варианте:\n");
    belman(graph, 1);
    printf("Кратчайшие расстояния в графическом варианте: belman.gv\n");
}


void check_graph(graph_t *graph, void (*first)(graph_t*, int), int N)
{
    clock_t start, stop;
    double all_time = 0;
    for (int i = 0; i < N; i++)
    {
        start = clock();
        first(graph, 0);
        stop = clock();
        all_time += (stop - start);
    }
    printf("%.7fсек         ", all_time / CLK_TCK / N);
}
void check_list_graph(node_t **list, void (*first)(node_t **, int, int), int N, int size)
{
    clock_t start, stop;
    double all_time = 0;
    for (int i = 0; i < N; i++)
    {
        start = clock();
        first(list, size, 0);
        stop = clock();
        all_time += (stop - start);
    }
    printf("%.7fсек     ", all_time / CLK_TCK / N);
}

void read_new_file(graph_t **graph, node_t ***list_graph, char *name)
{
    int n;
    FILE *f;
    f = fopen(name, "r");
    read_int_number(f, &n);
    *list_graph = calloc(n, sizeof (node_t *));
    init_list_graph(*list_graph, n);
    create_list_graph(f, n, *list_graph);
    fclose(f);
    f = fopen(name, "r");
    *graph = create_graph(f);
    fclose(f);
}

void check_efficiency()
{
    int n;
    FILE *f;
    f = fopen("in_1.txt", "r");
    read_int_number(f, &n);
    node_t **list_graph = calloc(n, sizeof (node_t *));
    init_list_graph(list_graph, n);
    create_list_graph(f, n, list_graph);
    fclose(f);
    f = fopen("in_1.txt", "r");
    graph_t *graph = create_graph(f);
    printf("\nСравнение эффективности реализаций графа:");
    printf("\n---------------------------------------\n");
    printf("Флойд");
    printf("\n---------------------------------------\n");
    printf("Количество вершин   |Количество рёбер    |Матрица(время)       |Матрица(память)     |Список(время)    |Список(память)  |\n");

    printf("%d                   |5                   |", *graph->size);
    check_graph(graph, floid, 1000);
    printf("|68                  |");
    check_list_graph(list_graph, floid_list, 1000, *graph->size);
    printf("|224             |\n");

    read_new_file(&graph, &list_graph, "in_2.txt");

    printf("%d                   |9                   |", *graph->size);
    check_graph(graph, floid, 1000);
    printf("|260                 |");
    check_list_graph(list_graph, floid_list, 1000, *graph->size);
    printf("|416             |\n");

    read_new_file(&graph, &list_graph, "in_3.txt");

    printf("%d                   |19                  |", *graph->size);
    check_graph(graph, floid, 1000);
    printf("|520                 |");
    check_list_graph(list_graph, floid_list, 1000, *graph->size);
    printf("|736             |\n");

    read_new_file(&graph, &list_graph, "in_4.txt");

    printf("%d                  |15                  |", *graph->size);
    check_graph(graph, floid, 1000);
    printf("|580                 |");
    check_list_graph(list_graph, floid_list, 1000, *graph->size);
    printf("|672             |\n");

    read_new_file(&graph, &list_graph, "in_5.txt");

    printf("%d                  |30                  |", *graph->size);
    check_graph(graph, floid, 1000);
    printf("|580                 |");
    check_list_graph(list_graph, floid_list, 1000, *graph->size);
    printf("|1088            |\n");

    read_new_file(&graph, &list_graph, "in_6.txt");

    printf("%d                  |36                  |", *graph->size);
    check_graph(graph, floid, 1000);
    printf("|1600                |");
    check_list_graph(list_graph, floid_list, 1000, *graph->size);
    printf("|1472            |\n");

    read_new_file(&graph, &list_graph, "in_7.txt");

    printf("%d                  |119                 |", *graph->size);
    check_graph(graph, floid, 1000);
    printf("|1600                |");
    check_list_graph(list_graph, floid_list, 1000, *graph->size);
    printf("|4128            |\n");

    read_new_file(&graph, &list_graph, "in_1.txt");

    printf("\n---------------------------------------\n");
    printf("Дейкстра");
    printf("\n---------------------------------------\n");
    printf("Количество вершин   |Количество рёбер    |Матрица(время)       |Матрица(память)     |Список(время)    |Список(память)  |\n");
    printf("%d                   |5                   |", *graph->size);
    check_graph(graph, dextra, 1000);
    printf("|68                  |");
    check_list_graph(list_graph, dextra_list, 1000, *graph->size);
    printf("|224             |\n");

    read_new_file(&graph, &list_graph, "in_2.txt");

    printf("%d                   |9                   |", *graph->size);
    check_graph(graph, dextra, 1000);
    printf("|260                 |");
    check_list_graph(list_graph, dextra_list, 1000, *graph->size);
    printf("|416             |\n");

    read_new_file(&graph, &list_graph, "in_3.txt");

    printf("%d                   |19                  |", *graph->size);
    check_graph(graph, dextra, 1000);
    printf("|520                 |");
    check_list_graph(list_graph, dextra_list, 1000, *graph->size);
    printf("|736             |\n");

    read_new_file(&graph, &list_graph, "in_4.txt");

    printf("%d                  |15                  |", *graph->size);
    check_graph(graph, dextra, 1000);
    printf("|580                 |");
    check_list_graph(list_graph, dextra_list, 1000, *graph->size);
    printf("|672             |\n");

    read_new_file(&graph, &list_graph, "in_5.txt");

    printf("%d                  |30                  |", *graph->size);
    check_graph(graph, dextra, 1000);
    printf("|580                 |");
    check_list_graph(list_graph, dextra_list, 1000, *graph->size);
    printf("|1088            |\n");

    read_new_file(&graph, &list_graph, "in_6.txt");

    printf("%d                  |36                  |", *graph->size);
    check_graph(graph, dextra, 1000);
    printf("|1600                |");
    check_list_graph(list_graph, dextra_list, 1000, *graph->size);
    printf("|1472            |\n");

    read_new_file(&graph, &list_graph, "in_7.txt");

    printf("%d                  |119                 |", *graph->size);
    check_graph(graph, dextra, 1000);
    printf("|1600                |");
    check_list_graph(list_graph, dextra_list, 1000, *graph->size);
    printf("|4128            |\n");

    read_new_file(&graph, &list_graph, "in_1.txt");

    printf("\n---------------------------------------\n");
    printf("Беллман");
    printf("\n---------------------------------------\n");
    printf("Количество вершин   |Количество рёбер    |Матрица(время)       |Матрица(память)     |Список(время)    |Список(память)  |\n");
    printf("%d                   |5                   |", *graph->size);
    check_graph(graph, belman, 1000);
    printf("|68                  |");
    check_list_graph(list_graph, belman_list, 1000, *graph->size);
    printf("|224             |\n");

    read_new_file(&graph, &list_graph, "in_2.txt");

    printf("%d                   |9                   |", *graph->size);
    check_graph(graph, belman, 1000);
    printf("|260                 |");
    check_list_graph(list_graph, belman_list, 1000, *graph->size);
    printf("|416             |\n");

    read_new_file(&graph, &list_graph, "in_3.txt");

    printf("%d                   |19                  |", *graph->size);
    check_graph(graph, belman, 1000);
    printf("|520                 |");
    check_list_graph(list_graph, belman_list, 1000, *graph->size);
    printf("|736             |\n");

    read_new_file(&graph, &list_graph, "in_4.txt");

    printf("%d                  |15                  |", *graph->size);
    check_graph(graph, belman, 1000);
    printf("|580                 |");
    check_list_graph(list_graph, belman_list, 1000, *graph->size);
    printf("|672             |\n");

    read_new_file(&graph, &list_graph, "in_5.txt");

    printf("%d                  |30                  |", *graph->size);
    check_graph(graph, belman, 100);
    printf("|580                 |");
    check_list_graph(list_graph, belman_list, 100, *graph->size);
    printf("|1088            |\n");

    read_new_file(&graph, &list_graph, "in_6.txt");

    printf("%d                  |36                  |", *graph->size);
    check_graph(graph, belman, 100);
    printf("|1600                |");
    check_list_graph(list_graph, belman_list, 100, *graph->size);
    printf("|1472            |\n");

    read_new_file(&graph, &list_graph, "in_7.txt");

    printf("%d                  |119                 |", *graph->size);
    check_graph(graph, belman, 100);
    printf("|1600                |");
    check_list_graph(list_graph, belman_list, 100, *graph->size);
    printf("|4128            |\n");
}

void change_graph(graph_t **graph)
{
    printf("\nВведите название файла: ");
    char new_file[40];
    for (int i = 0; i < 40; i++)
        new_file[i] = '\0';
    input_string(new_file);
    change_last_symbol_after_input(new_file);
    FILE *f1;
    f1 = fopen(new_file, "r");
    if (f1 == NULL)
        printf("Такого файла не существует!\n\n");
    else
        *graph = create_graph(f1);
    fclose(f1);
}

int process_menu(graph_t **graph)
{
    int choose = 0, res;
    print_menu();
    res = input_integer(&choose);
    while ((res == error) || (choose < 0) || (choose > 8))
    {
        printf("\n\nНеправильный ввод! Введите заново: ");
        fflush(stdin);
        res = input_integer(&choose);
    }
    switch (choose)
    {
    case 1:
        process_print(*graph);
        break;
    case 2:
        process_floid(*graph);
        break;
    case 3:
        process_dextra(*graph);
        break;
    case 4:
        process_belman(*graph);
        break;
    case 5:
        check_efficiency();
        break;
    case 6:
        change_graph(graph);
        break;
    }
    return choose;
}


