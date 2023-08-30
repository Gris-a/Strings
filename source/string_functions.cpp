#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/string_functions.h"

/**
 * @file string_functions.cpp
 * @author Gris-a.
 * @brief My string functions.
*/

size_t my_strlen(const char str[])
{
    assert(str != NULL);

    size_t len = 0;
    while(str[len] != '\0')
    {
        len++;
    }

    return len;
}

size_t my_strnlen(const char str[], size_t max_len)
{
    assert(str != NULL);
    assert(!isnan(max_len));

    size_t len = 0;
    while(str[len] != '\0' && len < max_len)
    {
        len++;
    }

    return len;
}

int my_strcmp(const char str1[], const char str2[])
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    while(*str1 == *str2 && *str1 != '\0' && *str2 != '\0')
    {
        str1++;
        str2++;
    }

    return *str1 - *str2;
}

int my_strncmp(const char str1[], const char str2[], size_t n_chars)
{
    assert(str1 != NULL);
    assert(str2 != NULL);
    assert(!isnan(n_chars));

    while(*str1 == *str2 && *str1 != '\0' && *str2 != '\0' && --n_chars > 0)
    {
        str1++;
        str2++;
    }

    return *str1 - *str2;
}

char *my_strcpy(char dest[], const char src[])
{
    assert(dest != NULL);
    assert(src  != NULL);

    int i = 0;
    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return dest;

}

char *my_strncpy(char dest[], const char src[], size_t n_chars)
{
    assert(dest != NULL);
    assert(src  != NULL);
    assert(!isnan(n_chars));

    int i = 0;
    while(src[i] != '\0' && n_chars-- > 0)
    {
        dest[i] = src[i];
        i++;
    }

    if(n_chars > 0)
    {
        dest[i] = '\0';
    }

    return dest;

}

char *my_strcat(char str[], const char add_str[])
{
    assert(str     != NULL);
    assert(add_str != NULL);

    while(*(str) != '\0')
    {
        str++;
    }

    while(*(add_str) != '\0')
    {
        *(str++) = *(add_str++);
    }
    *str = '\0';

    return str;
}

char *my_strncat(char str[], const char add_str[], size_t n_chars)
{
    assert(str     != NULL);
    assert(add_str != NULL);
    assert(!isnan(n_chars));

    while(*(str) != '\0')
    {
        str++;
    }

    while(*(add_str) != '\0' && n_chars-- > 0)
    {
        *(str++) = *(add_str++);
    }
    *str = '\0';

    return str;
}

char *my_strchr(char str[], const char ch)
{
    assert(str != NULL);
    assert(!isnan(ch));

    while(*str != '\0')
    {
        if(*str == ch)
        {
            return str;
        }

        str++;
    }

    if(ch == '\0')
    {
        return str;
    }

    return NULL;
}

char *my_strrchr(char str[], const char ch)
{
    assert(str != NULL);
    assert(!isnan(ch));

    char *ans = NULL;

    while(*str != '\0')
    {
        if(*str == ch)
        {
            ans = str;
        }
        str++;
    }

    if(ch == '\0')
    {
        return str;
    }

    return ans;
}

char *my_strdup(const char str[])
{
    assert(str != NULL);

    size_t size    = my_strlen(str) + 1;
    char *str_copy = (char *)calloc(size, sizeof(char));

    if(str_copy == NULL)
    {
        my_fputs("Impossible to allocate memory.\n", stdout);
        return str_copy;
    }

    my_strcpy(str_copy, str);

    return str_copy;
}

char *my_strndup(const char str[], const size_t n_chars)
{
    assert(str != NULL);
    assert(!isnan(n_chars));

    size_t str_len = my_strlen(str);
    size_t size    = ((str_len < n_chars) ? str_len : n_chars) + 1;
    char *str_copy = (char *)calloc(size, sizeof(char));

    if(str_copy == NULL)
    {
        my_fputs("Impossible to allocate memory.\n", stdout);
        return str_copy;
    }

    my_strncpy(str_copy, str, size - 1);

    return str_copy;
}

void my_fputs(const char str[], FILE *file)
{
    assert(str  != NULL);
    assert(file != NULL);

    fwrite(str, sizeof(char), my_strlen(str), file);
}

void my_puts(const char str[])
{
    assert(str != NULL);

    fwrite(str, sizeof(char), my_strlen(str), stdout);
    fwrite(&"\n", sizeof(char), sizeof(char), stdout);
}

char *my_fgets(char str[], size_t n_chars, FILE *file)
{
    assert(str  != NULL);
    assert(file != NULL);
    assert(!isnan(n_chars));

    int ch = 0;
    int i  = 0;

    while(--n_chars > 0)
    {
        if(!fread(&ch, sizeof(char), sizeof(char), file))
        {
            if(i == 0)
            {
                return NULL;
            }

            str[i] = '\0';

            return str;
        }

        if(ch == '\n')
        {
            str[i++] = (char)ch;
            str[i] = '\0';

            return str;
        }

        str[i++] = (char)ch;
    }
    str[i] = '\0';

    return str;
}

ssize_t my_getline(char **lineptr, size_t *size, FILE *file)
{
    assert(lineptr  != NULL);
    assert(*lineptr != NULL);
    assert(size     != NULL);
    assert(file     != NULL);
    assert(!isnan(*size));

    int ch   = 0;
    size_t i = 0;

    while(!fread(&ch, sizeof(char), sizeof(char), file))
    {
        if(i + 2 > *size)
        {
            *lineptr = (char *)realloc(*lineptr, *size *= 2);
            if(!*lineptr)
            {
                my_fputs("Impossible to reallocate memory.\n", stdout);
                *size /= 2;
                return (ssize_t)-1;
            }
        }

        if(ch == '\n')
        {
            (*lineptr)[i++] = '\n';
            (*lineptr)[i]   = '\0';

            return (ssize_t)i;
        }

        (*lineptr)[i++] = (char)ch;
    }

    if(i == 0)
    {
        return (ssize_t)-1;
    }

    (*lineptr)[i] = '\0';

    return (ssize_t)i;
}
