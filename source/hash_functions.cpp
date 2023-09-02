#include <assert.h>
#include <stddef.h>

#include "../include/hash_functions.h"

size_t poly_hash(const char str[], const size_t str_len, size_t *const hash)
{
    assert(str != NULL);
    assert(hash != NULL);

    *hash = 0;
    size_t i = 0;
    size_t powered_P = 1;

    while(i != str_len - 1)
    {
        *hash += (size_t)str[i++] * powered_P;
        powered_P *= P;
    }

    *hash += (size_t)str[i] * powered_P;

    return powered_P;
}

size_t poly_hash_next(const char *const substr_begin, const size_t hash, const size_t substr_len, const size_t powered_P)
{
    assert(substr_begin != NULL);

    return (hash - (size_t)substr_begin[-1]) / P + powered_P * (size_t)substr_begin[substr_len - 1];
}
