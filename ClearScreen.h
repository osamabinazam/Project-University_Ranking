

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Perform Terminal Clear Operations
#if defined(_WIN32) || defined(_WIN64)
void clearScreen()
{
    system("cls");
}
#else
void clearScreen()
{
    system("clear");
}
#endif



