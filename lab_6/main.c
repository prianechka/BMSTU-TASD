#include "process.h"
#include <windows.h>

int main()
{
    int result = -1;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setbuf(stdout, NULL);
    node_t *tree = NULL;
    avl_node_t *avl_tree = NULL;
    int *hash_key = malloc(sizeof (int));
    *hash_key = 31;
    int *hash_table = calloc(*hash_key, sizeof (int));
    int *collision = malloc(sizeof (int));
    *collision = 4;
    init_hash_table(&hash_table, *hash_key);
    FILE *f;
    f = fopen("in_1.txt", "r");
    process_input_file(f, &tree, &avl_tree, &hash_table, hash_key, *collision);
    fclose(f);
    while (result != 0)
        result = process_menu(&tree, &avl_tree, &hash_table, hash_key, collision);
    return 0;
}
