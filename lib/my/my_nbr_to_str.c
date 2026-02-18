/*
** EPITECH PROJECT, 2025
** display a int
** File description:
** Display an int from one command
*/
#include "my.h"
#include <stdlib.h>
#include <stddef.h>

static void char_append(char *buffer, char c)
{
    int size = my_strlen(buffer);

    buffer[size] = c;
    buffer[size + 1] = '\0';
    return;
}

static void my_nbr_to_str(int nb, char *buffer)
{
    int nbs = nb / 10;

    nbs = nb - nbs * 10;
    if (nbs < 0) {
        nbs = -nbs;
    }
    nb = nb / 10;
    if (nb != 0) {
        my_nbr_to_str(nb, buffer);
    }
    char_append(buffer, nbs + '0');
    return;
}

char *nbr_str(int nb)
{
    char *buffer = malloc(sizeof(char) * 10);

    if (!buffer)
        return NULL;
    for (int i = 0; i < 10; i++)
        buffer[i] = '\0';
    my_nbr_to_str(nb, buffer);
    return buffer;
}
