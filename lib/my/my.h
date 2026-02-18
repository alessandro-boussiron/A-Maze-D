/*
** EPITECH PROJECT, 2025
** my;h
** File description:
** my lib
*/
#ifndef LIB_MY_H
    #define LIB_MY_H
    #include <stdlib.h>
    #define ERROR_CODE (int)(84)

char *my_strdup(const char *src);
int my_strlen(const char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_put_nbr(int nb);
char **my_str_to_word_array(char const *str);
char *nbr_str(int nb);

#endif //LIB_MY_H
