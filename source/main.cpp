#include <math.h>
#include <stdio.h>
#include <string.h>

#include "../include/string_functions.h"

/**
 * @file main.cpp
 * @author Gris-a.
 * @brief Main .cpp file.
*/

int main(void)
{
    char str1[] = "kjngkjngkjgnkjgndndg";
    char str2[] = "aboba";
    my_strncpy(str1, str2, 5);
    printf("%s\n", str1);
    return 0;
}
