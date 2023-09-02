#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H

#include <stdbool.h>
#include <stddef.h>

size_t my_strlen(const char str[]);

size_t my_strnlen(const char str[], size_t max_len);

int my_strcmp(const char str1[], const char str2[]);

int my_strncmp(const char str1[], const char str2[], size_t n_chars);

char *my_strcpy(char dest[], const char src[]);

char *my_strncpy(char dest[], const char src[], size_t n_chars);

char *my_strcat(char str[], const char add_str[]);

char *my_strncat(char str[], const char add_str[], size_t n_chars);

char *my_strchr(char str[], const char ch);

char *my_strrchr(char str[], const char ch);

char *my_strdup(const char str[]);

char *my_strndup(const char str[], const size_t n_chars);

bool my_fputs(const char str[], FILE *file);

bool my_puts(const char str[]);

char *my_fgets(char str[], size_t n_chars, FILE *file);

ssize_t my_getline(char **lineptr, size_t *size, FILE *file);

char *my_strstr(char str[], const char substr[]);

#endif //STRING_FUNCTIONS_H
