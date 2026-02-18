/*
** EPITECH PROJECT, 2026
** linked_list
** File description:
** linked_list_apply.c
*/
#include "../linked_list.h"

void linked_list_apply(linked_list_t *ll, void(*applier)(void *data))
{
    if (!ll || !applier)
        return;
    for (node_t *curr = ll->head; curr; curr = curr->next) {
        applier(curr->data);
    }
}
