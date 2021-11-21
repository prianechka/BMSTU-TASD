#include <stdlib.h>
#include <windows.h>
#include "process.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int result = -1;
    while (result != 0)
        result = process_menu();
    return result;
}
