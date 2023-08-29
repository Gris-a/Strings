/**
 * @file string_functions.h
 * @author Gris-a.
 * @brief Declarations of my string functions.
*/

#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H
//TODO:strstr optimization, unit-tests, mainpage
#include <stddef.h>

/**
 * @brief My strlen, finds length of @b str.
 * @param str String.
 * @return length of @b str.
 * @note '\0' doesn`t count.
*/
size_t my_strlen(const char str[]);

/**
 * @brief My strnlen, finds length of @b str, but scan at most @b max_len characters.
 * @param str String.
 * @param max_len Maximum number of characters to scan.
 * @return length of @b str, if it is smaller than @b max_len, otherwise @b max_len.
 * @note '\0' doesn`t count.
*/
size_t my_strnlen(const char str[], size_t max_len);

/**
 * @brief My strcmp, compares @b str1 and @b str2 lexicographically.
 * @param str1 First string.
 * @param str2 Second string.
 * @return Difference of first non-matching characters.\n
 * The returned value is greater than zero if @b str1 is lexicographically greater than @b str2,
 * less than zero otherwise, and equals to zero if the strings are equal.
*/
int my_strcmp(const char str1[], const char str2[]);

/**
 * @brief My strncmp, compares @b str1 and @b str2 lexicographically, but scan at most @b n_chars characters.
 * @param str1 First string.
 * @param str2 Second string.
 * @param n_chars Maximum number of characters to scan.
 * @return Difference of first non-matching characters.\n
 * The returned value is greater than zero if @b str1 is lexicographically greater than @b str2,
 * less than zero otherwise, and equals to zero if the strings are equal.
*/
int my_strncmp(const char str1[], const char str2[], size_t n_chars);

/**
 * @brief My strcpy, copies @b src to @b dest.
 * @param dest String to be copy to.
 * @param src String to be copied.
 * @return Pointer to begining of copy.
 * @note @b dest is supposed to be big enough to contain @b src.
 *
*/
char *my_strcpy(char dest[], const char src[]);

/**
 * @brief My strncpy, copies at most @b n_chars characters of @b src to @b dest.
 * @param dest String to be copy to.
 * @param src String to be copied.
 * @return Pointer to begining of copy.
 * @note @b dest is supposed to be big enough to contain first @b n_chars characters of @b src.
*/
char *my_strncpy(char dest[], const char src[], size_t n_chars);

/**
 * @brief My strcat, append @b add_str to @b str.
 * @param str String to which @b add_str is added.
 * @param add_str String to be added to @b src.
 * @return Pointer to concatenated string.
 * @note @b str is supposed to be big enough for @b add_str to be added.
*/
char *my_strcat(char str[], const char add_str[]);

/**
 * @brief My strncat, append no more then @b n_chars of @b add_str to @b str.
 * @param str String to which @b add_str is added.
 * @param add_str String to be added to @b src.
 * @param n_chars Maximum number of characters to add.
 * @return Pointer to concatenated string.
 * @note @b str is supposed to be big enough for first @b n_chars of @b add_str to be added.
*/
char *my_strncat(char str[], const char add_str[], size_t n_chars);

/**
 * @brief My strrchr, finds first occurence of @b ch in @b str.
 * @param str String to be viewed.
 * @param ch Characther to search for.
 * @return Pointer to the first occurrence of @b ch in @b str, @b NULL if there is no @b ch in @b str.
*/
char *my_strchr(char str[], const char ch);

/**
 * @brief My strrchr, finds last occurence of @b ch in @b str.
 * @param str String to be viewed.
 * @param ch Characther to search for.
 * @return Pointer to the last occurrence of @b ch in @b str, @b NULL if there is no @b ch in @b str.
*/
char *my_strrchr(char str[], const char ch);

/**
 * @brief My strstr, finds first occurence of @b substr in @b str.
 * @param str String to be viewed.
 * @param substr Substring to search for.
 * @return Pointer to the first occurrence of @b substr in @b str, @b NULL if there is no @b substr in @b str.
*/
char *my_strstr(char str[], const char substr[]);

#endif //STRING_FUNCTIONS_H
