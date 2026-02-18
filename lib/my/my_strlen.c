/*
** EPITECH PROJECT, 2025
** my_strlen.c
** File description:
** task03 of day04
*/
#include "my.h"

int my_strlen(char const *str)
{
    int size = 0;

    if (!str)
        return size;
    while (*str){
        size++;
        str++;
    }
    return size;
}
