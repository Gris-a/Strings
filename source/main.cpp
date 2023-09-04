#include <stdio.h>
#include<string.h>
#include "../include/hash_functions.h"
#include "../include/string_functions.h"

int main(void)
{
    char str[] = "b";
    char src[] = "b";
    printf("%d\n", strcmp(src, str));
    printf("%d\n", my_strcmp(src, str));

    return 0;
}
