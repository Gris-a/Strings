#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/string_functions.h"

/**
 * @file main.cpp
 * @author Gris-a.
 * @brief Main .cpp file.
*/

//TODO:unit-tests, mainpage, readme, documentation.

int main(void)
{
    char *ptr = NULL;
    size_t size = 500;
    printf("%zd\n", getline(&ptr, &size, stdin));
    printf("%zu\n", size);
    return 0;
}
