#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/string_functions.h"

const size_t MAX_STR_LINE = 100;
const size_t MAX_N_STR = 100;

const size_t WIDTH = 3;
const size_t HEIGHT = 2;

void print_data(const int *arr_ptr, const size_t HEIGHT, const size_t WIDTH);

/**
 * @file main.cpp
 * @author Gris-a.
 * @brief Main .cpp file.
 * //TODO:unit-tests, mainpage, readme, documentation.
*/



int main(void)
{
    int arr[HEIGHT][WIDTH] = {{1, 2, 3},
                              {4, 5, 6}};

    print_data((int *)arr, HEIGHT, WIDTH);
    return 0;
}

void print_data(const int *arr_ptr, const size_t height, const size_t width)
{
    assert(arr_ptr != NULL);

    for(size_t i = 0; i < height; i++)
    {
        for(size_t j = 0; j < width; j++)
        {
            printf("%d ", *(arr_ptr + i * width + j));
        }
        printf("\n");
    }
}