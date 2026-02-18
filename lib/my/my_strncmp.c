/*
** EPITECH PROJECT, 2025
** strcmp
** File description:
** compare string value
*/
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int s1_value = 0;
    int s2_value = 0;

    for (int i = 0; s1[i] && i < n; i++)
        s1_value += s1[i];
    for (int i = 0; s2[i] && i < n; i++)
        s2_value += s2[i];
    return s1_value - s2_value;
}
