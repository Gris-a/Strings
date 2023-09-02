#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

#include <stddef.h>

const size_t P = 257;

size_t poly_hash(const char str[], const size_t str_len, size_t *const hash);

size_t poly_hash_next(const char *const sub_str_begin, const size_t hash, const size_t substr_len, const size_t powered_P);


#endif //HASH_FUNCTIONS_H