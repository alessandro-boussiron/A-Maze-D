/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** linked_list_search_nb
*/
#include "../linked_list.h"

int linked_list_search_nb(linked_list_t *ll,
    int (*algo)(void *data, void *to_find), void *to_find)
{
    int count = 0;

    if (!ll || !algo)
        return count;
    for (node_t *curr = ll->head; curr; curr = curr->next)
        if (algo(curr->data, to_find))
            count++;
    return count;
}
