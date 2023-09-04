#ifndef TESTS_H
#define TESTS_H

#include <string.h>

#define RUN_TEST1(function, my_function, counter, counter_true...) counter++\
                                                                  if(function(__VA_ARGS__) == my_function(__VA_ARGS__))\
                                                                    counter_true++;

#define RUN_TEST2(function, my_function, counter, counter_true...) counter++\
                                                                  if(!strcmp(function(__VA_ARGS__), my_function(__VA_ARGS__)))\
                                                                    counter_true++;

#define RUN_TEST3(function, my_function, counter, counter_true...) function(__VA_ARGS__);\
                                                                   my_function(__VA_ARGS__);

void my_strlen_test(void);

void my_strnlen_test(void);

void my_strcmp_test(void);

void my_strncmp_test(void);

void my_strcpy_test(void);

void my_strncpy_test(void);

void my_strcat_test(void);

void my_strncat_test(void);

void my_strchr_test(void);

void my_strrchr_test(void);

void my_strdup_test(void);

void my_strndup_test(void);

void my_fputs_test(void);

void my_puts_test(void);

void my_fgets_test(void);

void my_getline_test(void);

void my_strstr_test(void);

#endif //TESTS_H
