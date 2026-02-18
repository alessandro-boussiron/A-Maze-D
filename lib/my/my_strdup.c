/*
** EPITECH PROJECT, 2025
** my_strdup.c
** File description:
** duplicate a string and return a duplicata
*/
#include "my.h"

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
