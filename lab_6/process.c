#include "process.h"

void process_input_file(FILE *f, node_t **tree, avl_node_t **avl_tree, int **hash_table, int *hash_key, int collision)
{
    int result = ok, hash_result = ok;

    int number, old_hash;
    result = read_int_number(f, &number);
    while (result == ok)
    {
        int p = 0;
        int *q = &p;
        insert(tree, number, q);
        *avl_tree = avl_insert(*avl_tree, number, q, 0);
        hash_result = insert_in_table(number, hash_table, *hash_key, collision, 0);
        if (hash_result == error)
            old_hash = *hash_key;
        while (hash_result == error)
        {
            restruct_hash_table(hash_table, hash_key, collision, old_hash);
            hash_result = insert_in_table(number, hash_table, *hash_key, collision, 0);
        }
        result = read_int_number(f, &number);
    }
}

double count_time_tree(node_t **tree, int n, int inserted_number)
{
    int p = 0;
    int *q = &p;
    clock_t start, stop;
    double all_time = 0;
    for (int i = 0; i < n; i++)
    {
        start = clock();
        insert(tree, inserted_number, q);
        delete_value(*tree, inserted_number);
        stop = clock();
        all_time += 1.5 * (stop - start);
    }
    return all_time / CLK_TCK / n;
}

double count_time_avl_tree(avl_node_t *avl_tree, int n, int inserted_number)
{
    double all_time = 0;
    int p = 0;
    int *q = &p;
    clock_t start, stop;
    for (int i = 0; i < n; i++)
    {
        start = clock();
        avl_insert(avl_tree, inserted_number, q, 0);
        stop = clock();
        all_time += (stop - start);
        avl_remove(avl_tree, inserted_number);
    }
    return all_time / CLK_TCK / n;
}

double count_time_hash(int **hash_table, int hash_key, int n, int inserted_number, int collision)
{
    double all_time = 0;
    clock_t start, stop;
    //int res, old_hash;
    for (int i = 0; i < n; i++)
    {
        start = clock();
        insert_in_table(inserted_number, hash_table, hash_key, collision, 0);
        stop = clock();
        all_time += (stop - start);
    }
    return all_time / CLK_TCK / n;
}

void check_efficience(int collision)
{
    if (collision < 4)
        collision = 4;
    int n = 50;
    node_t *tree = NULL;
    avl_node_t *avl_tree = NULL;
    int *hash_key = malloc(sizeof (int));
    *hash_key = 31;
    int *hash_table = calloc(*hash_key, sizeof (int));
    init_hash_table(&hash_table, *hash_key);
    printf("Добавление элемента");
    printf("\n---------------------------------------\n");
    printf("Количество элементов   |Файл               |Обычное дерево     |AVL-дерево         |Хэш-таблица        |\n");
    printf("%d                     |", n);
    FILE *f;
    f = fopen("efficiency_1.txt", "r");
    process_input_file(f, &tree, &avl_tree, &hash_table, hash_key, collision);
    fclose(f);
    clock_t start, stop;
    double all_time = 0;
    for (int i = 0; i < 10; i++)
    {
        start = clock();
        f = fopen("efficiency_1_copy.txt", "a");
        fprintf(f, "%d", n + 1);
        fclose(f);
        stop = clock();
        all_time += stop - start;
    }
    printf("%.10f       |", all_time / CLK_TCK / 10);
    printf("%.10f       |", count_time_tree(&tree, 10000, 10*n + 1));
    printf("%.10f       |", count_time_avl_tree(avl_tree, 1000000, 10*n + 1));
    printf("%.10f       |\n", count_time_hash(&hash_table, *hash_key, 1000000, n + 1, collision));
    n = 100;
    avl_tree = NULL;
    tree = NULL;
    free(hash_table);
    free(hash_key);
    hash_key = malloc(sizeof (int));
    *hash_key = 101;
    hash_table = calloc(*hash_key, sizeof (int));
    init_hash_table(&hash_table, *hash_key);
    printf("%d                    |", n);
    FILE *f1;
    f1 = fopen("efficiency_2.txt", "r");
    process_input_file(f1, &tree, &avl_tree, &hash_table, hash_key, collision);
    fclose(f1);
    for (int i = 0; i < 10; i++)
    {
        start = clock();
        f = fopen("efficiency_2_copy.txt", "a");
        fprintf(f, "%d", n + 1);
        fclose(f);
        stop = clock();
        all_time += stop - start;
    }
    printf("%.10f       |", all_time / CLK_TCK / 10);
    printf("%.10f       |", count_time_tree(&tree, 1000, 10 * n + 1));
    printf("%.10f       |", count_time_avl_tree(avl_tree, 1000000, 10*n + 1));
    printf("%.10f       |\n", count_time_hash(&hash_table, *hash_key, 1000000, 10 * n + 1, collision));
    n = 500;
    printf("%d                    |", n);
    f = fopen("efficiency_3.txt", "r");
    avl_tree = NULL;
    tree = NULL;
    free(hash_table);
    free(hash_key);
    hash_key = malloc(sizeof (int));
    *hash_key = 10007;
    hash_table = calloc(*hash_key, sizeof (int));
    init_hash_table(&hash_table, *hash_key);
    process_input_file(f, &tree, &avl_tree, &hash_table, hash_key, collision);
    fclose(f);
    for (int i = 0; i < 10; i++)
    {
        start = clock();
        f = fopen("efficiency_3_copy.txt", "a");
        fprintf(f, "%d", n + 1);
        fclose(f);
        stop = clock();
        all_time += stop - start;
    }
    printf("%.10f       |", all_time / CLK_TCK/ 10);
    printf("%.10f       |", count_time_tree(&tree, 10000, 10 * n + 1));
    printf("%.10f       |", count_time_avl_tree(avl_tree, 1000000, 10 * n + 1));
    printf("%.10f       |\n", count_time_hash(&hash_table, *hash_key, 1000000, 10 * n + 1, collision));
    n = 1000;
    printf("%d                   |", n);
    f = fopen("efficiency_4.txt", "r");
    tree = NULL;
    avl_tree = NULL;
    free(hash_table);
    free(hash_key);
    hash_key = malloc(sizeof (int));
    *hash_key = 10007;
    hash_table = calloc(*hash_key, sizeof (int));
    init_hash_table(&hash_table, *hash_key);
    process_input_file(f, &tree, &avl_tree, &hash_table, hash_key, collision);
    fclose(f);
    for (int i = 0; i < 10; i++)
    {
        start = clock();
        f = fopen("efficiency_4_copy.txt", "a");
        fprintf(f, "%d", n + 1);
        fclose(f);
        stop = clock();
        all_time += stop - start;
    }
    printf("%.10f       |", all_time / CLK_TCK/ 10);
    printf("%.10f       |", count_time_tree(&tree, 10000, 10 * n + 1));
    printf("%.10f       |", count_time_avl_tree(avl_tree, 1000000, 10 * n + 1));
    printf("%.10f       |\n", count_time_hash(&hash_table, *hash_key, 1000000, 10 * n + 1, collision));
    n = 2000;
    printf("%d                   |", n);
    f = fopen("efficiency_5.txt", "r");
    avl_tree = NULL;
    tree = NULL;
    free(hash_table);
    free(hash_key);
    hash_key = malloc(sizeof (int));
    *hash_key = 19997;
    hash_table = calloc(*hash_key, sizeof (int));
    init_hash_table(&hash_table, *hash_key);
    process_input_file(f, &tree, &avl_tree, &hash_table, hash_key, collision);
    fclose(f);
    for (int i = 0; i < 10; i++)
    {
        start = clock();
        f = fopen("efficiency_5_copy.txt", "a");
        fprintf(f, "%d", n + 1);
        fclose(f);
        stop = clock();
        all_time += stop - start;
    }
    printf("%.10f       |", all_time / CLK_TCK/ 10);
    printf("%.10f       |", count_time_tree(&tree, 10000, 10 * n + 1));
    printf("%.10f       |", count_time_avl_tree(avl_tree, 1000000, 10 * n + 1));
    printf("%.10f       |\n", count_time_hash(&hash_table, *hash_key, 100000, 10 * n + 1, collision));
    printf("-----------------------------------------\n");
    free_tree(tree);
    free_avl_tree(avl_tree);
}

void process_add_new_elem(node_t **tree, avl_node_t *avl_tree, int **hash_table, int *hash_key, int collision)
{
    int res, add_elem, old_hash;
    printf("Введите целое число для добавления: ");
    res = input_integer(&add_elem);
    while (res == error)
    {
        printf("\n\nНеправильный ввод! Введите заново: ");
        fflush(stdin);
        res = input_integer(&add_elem);
    }
    int result = find_in_table(add_elem, *hash_table, *hash_key, collision);
    if (result == error)
    {
        int p = 0;
        int *q = &p;
        insert(tree, add_elem, q);
        printf("\nПри добавлении в обычное дерево произошло %d сравнений\n", *q);
        *q = 0;
        avl_tree = avl_insert(avl_tree, add_elem, q, 1);
        printf("При добавлении в АВЛ-дерево произошло %d сравнений", *q);
        res = insert_in_table(add_elem, hash_table, *hash_key, collision, 1);
        if (res == error)
        {
            printf("\n\nПотребовалась реструктуризация таблицы!\n\n");
            old_hash = *hash_key;
        }
        while (res == error)
        {
            restruct_hash_table(hash_table, hash_key, collision, old_hash);
            res = insert_in_table(add_elem, hash_table, *hash_key, collision, 1);
        }
        printf("\n\nЭлемент добавлен!\n\n");
    }
    else
        printf("\n\nЭлемент уже был добавлен!\n\n");
}

void process_del_elem(node_t **tree, avl_node_t *avl_tree, int *hash_table, int *hash_key, int collision)
{
    int res, del_elem;
    printf("Введите целое число для удаления: ");
    res = input_integer(&del_elem);
    while (res == error)
    {
        printf("\n\nНеправильный ввод! Введите заново: ");
        fflush(stdin);
        res = input_integer(&del_elem);
    }
    int result = find_in_table(del_elem, hash_table, *hash_key, collision);
    if (result == ok)
    {
        delete_value(*tree, del_elem);
        //avl_remove(avl_tree, del_elem);
        avl_node_t *tmp = NULL;
        avl_node_t *remove_elem = avl_tree_find_del_node(avl_tree, &tmp, del_elem);
        avl_tree_delete(remove_elem, &tmp);
        remove_in_table(del_elem, &hash_table, *hash_key, collision);
        printf("\n\nЭлемент удалён!\n\n");
    }
    else
        printf("\n\nЭлемент не найден!\n\n");
}

void change_collision(int *collision)
{
    int choose = 0, res;
    printf("Введите новое число коллизий (целое число): ");
    res = input_integer(&choose);
    while ((res == error) || (choose <= 0))
    {
        printf("\n\nНеправильный ввод! Введите заново: ");
        fflush(stdin);
        res = input_integer(&choose);
    }
    *collision = choose;
}

int process_menu(node_t **tree, avl_node_t **avl_tree, int **hash_table, int *hash_key, int *collision)
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
        printf("Текстовый вариант:\n\n");
        print_tree(*tree, "tree", 0);
        printf("Графический вариант:\n");
        FILE *f;
        f = fopen("usual.gv", "w");
        export_to_dot(f, *tree);
        fclose(f);
        printf("\nСохранено в файл: usual.gv\n\n");
        break;
    case 2:
        printf("Текстовый вариант:\n\n");
        print_avl_tree(*avl_tree, "tree", 0);
        printf("Графический вариант:\n");
        FILE *f1;
        f1 = fopen("avl.gv", "w");
        avl_export_to_dot(f1, *avl_tree);
        fclose(f1);
        printf("\nСохранено в файл: avl.gv\n\n");
        break;
    case 3:
        printf("Текущий ключ для хэш-функции: %d\n", *hash_key);
        printf("Текущее максимальное количество сравнений: %d\n", *collision);
        print_hash_table(*hash_table, *hash_key);
        break;
    case 4:
        process_add_new_elem(tree, *avl_tree, hash_table, hash_key, *collision);
        break;
    case 5:
        process_del_elem(tree, *avl_tree, *hash_table, hash_key, *collision);
        break;
    case 6:
        check_efficience(*collision);
        break;
    case 7:
        change_collision(collision);
        break;
    case 8:
        printf("In-order обход дерева: ");
        in_order_search(*tree);
        printf("\n");
        printf("Pre-order обход дерева: ");
        pre_order_search(*tree);
        printf("\n");
        printf("Post-order обход дерева: ");
        post_order_search(*tree);
        printf("\n");
    }
    return choose;
}
