/*
** EPITECH PROJECT, 2026
** linked_list
** File description:
** linked_list_search.c
*/
#include "../linked_list.h"

void *linked_list_search(linked_list_t *ll,
    int (*algo)(void *data, void *to_find), void *to_find)
{
    if (!ll || !algo)
        return NULL;
    for (node_t *curr = ll->head; curr; curr = curr->next)
        if (algo(curr->data, to_find))
            return curr->data;
    return NULL;
}
