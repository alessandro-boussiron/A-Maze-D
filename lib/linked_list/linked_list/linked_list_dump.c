/*
** EPITECH PROJECT, 2026
** linked_list
** File description:
** linked_list_dump
*/
#include "../linked_list.h"
#include <unistd.h>

static int my_putchar(char c)
{
    return write(1, &c, 1);
}

static int my_strlen(char *str)
{
    int i = 0;

    if (!str)
        return 0;
    for (; str[i]; i++);
    return i;
}

static int my_putstr(char *str)
{
    if (!str)
        return -1;
    if (write(1, str, my_strlen(str) ) < my_strlen(str))
        return -1;
    return 0;
}

static int my_put_nbr(int nb)
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

void linked_list_dump(linked_list_t *ll, void (*dump_node)(void *data))
{
    int index_temp = 0;

    if (!ll || !dump_node)
        return;
    for (node_t *curr = ll->head; curr; curr = curr->next) {
        if (my_putstr("[") || my_put_nbr(index_temp) || my_putstr("]: "))
            return;
        dump_node(curr->data);
        index_temp++;
        if (my_putstr("\n"))
            return;
    }
}
