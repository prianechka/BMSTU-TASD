#include <windows.h>
#include "process.h"

int main()
{
    int result = -1;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (result != 0)
        result = process_menu();
    return 0;
}
