/*
** EPITECH PROJECT, 2026
** linked_list
** File description:
** linked_list_set_dstr.c
*/
#include "../linked_list.h"

void linked_list_set_dstr(linked_list_t *ll, void (*free_node)(void *data))
{
    if (!ll || !free_node)
        return;
    ll->free_node = free_node;
}
