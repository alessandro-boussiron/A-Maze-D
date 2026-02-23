/*
** EPITECH PROJECT, 2025
** my_strdup.c
** File description:
** duplicate a string and return a duplicata
*/
#include "my.h"

char *my_strndup(const char *src, int n)
{
    char *dest;
    int size = 0;

    if (!src)
        return NULL;
    size = my_strlen(src);
    if (size == 0)
        return NULL;
    n = (size < n) ? size : n;
    dest = malloc(n + 1);
    if (!dest)
        return NULL;
    dest[n] = '\0';
    for (int i = 0; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    return dest;
}

char *my_strdup(const char *src)
{
    char *dest;
    int i = 0;

    if (!src)
        return NULL;
    dest = malloc(my_strlen(src) + 1);
    if (!dest)
        return NULL;
    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
