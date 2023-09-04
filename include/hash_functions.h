#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

#include <stddef.h>

struct Hash
{
    size_t str_len;
    size_t hash_value;
    size_t powered_P;
};

const size_t P = 257;

void poly_hash(const char str[], size_t str_len, struct Hash *const hash);

void poly_hash_next(const char *const sub_str_begin, struct Hash *const hash);


#endif //HASH_FUNCTIONS_H
