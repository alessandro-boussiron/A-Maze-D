/*
** EPITECH PROJECT, 2026
** linked_list
** File description:
** linked_list_dump
*/
#include "../linked_list.h"
#include "my_lib.h"

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
