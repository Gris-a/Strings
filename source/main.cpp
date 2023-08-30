#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/string_functions.h"

/**
 * @file main.cpp
 * @author Gris-a.
 * @brief Main .cpp file.
*/

int main(void)
{
    FILE *file = fopen("file.txt", "a");
    fputs("aboba", file);
}
