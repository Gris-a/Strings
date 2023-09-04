#include <assert.h>
#include <stddef.h>

#include "../include/hash_functions.h"

void poly_hash(const char str[], size_t hashed_str_len, struct Hash *const hash)
{
    assert(str  != NULL);
    assert(hash != NULL);

    hash->hash_value = 0;
    hash->powered_P = 1;
    hash->str_len = 0;

    while(hash->str_len != hashed_str_len - 1)
    {
        hash->hash_value += (size_t)str[hash->str_len++] * hash->powered_P;
        hash->powered_P *= P;
    }

    hash->hash_value += (size_t)str[hash->str_len++] * hash->powered_P;
}

void poly_hash_next(const char *const substr_begin, struct Hash *const hash)
{
    assert(substr_begin != NULL);
    assert(hash != NULL);

    hash->hash_value = (hash->hash_value - (size_t)substr_begin[-1]) / P + hash->powered_P * (size_t)substr_begin[hash->str_len - 1];
}
