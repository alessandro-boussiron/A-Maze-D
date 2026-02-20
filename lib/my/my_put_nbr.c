/*
** EPITECH PROJECT, 2025
** my_print_alpha.c
** File description:
** task01 of Day03
*/
#include <unistd.h>
#include "my.h"

static int my_putchar(char c)
{
    return write(1, &c, 1);
}

int my_putstr(char *str)
{
    if (!str)
        return -1;
    if (write(1, str, my_strlen(str)) < my_strlen(str))
        return -1;
    return 0;
}

int my_put_nbr(int nb)
{
    long n = nb;

    if (n < 0) {
        if (my_putchar('-') != 1)
            return 1;
        n = -n;
    }
    if (n >= 10)
        if (my_put_nbr(n / 10))
            return 1;
    if (my_putchar((n % 10) + '0') != 1)
        return 1;
    return 0;
}
