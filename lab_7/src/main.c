#include "../inc/process.h"

int main()
{
    int result = -1;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setbuf(stdout, NULL);
    FILE *f;
    f = fopen("in_1.txt", "r");
    graph_t *graph = create_graph(f);
    fclose(f);
    while (result != 0)
        result = process_menu(&graph);
    return 0;
}
