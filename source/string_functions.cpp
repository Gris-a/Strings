#include <assert.h>
#include <math.h>

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
    assert(src != NULL);

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
    assert(src != NULL);
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
    assert(str != NULL);
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
    assert(str != NULL);
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

char *my_strstr(char str[], const char substr[])
{
    assert(str != NULL);
    assert(substr != NULL);

    size_t substr_len = my_strlen(substr);
    if(substr_len == 0)
    {
        return str;
    }

    char substr_first = substr[0];
    while(*str != '\0')
    {
        if(*str == substr_first)
        {
            if(!my_strncmp(str, substr, substr_len))
            {
                return str;
            }
        }
        str++;
    }

    return NULL;
}
