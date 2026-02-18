/*
** EPITECH PROJECT, 2025
** get_node.c
** File description:
** get a node data
*/
#include "../linked_list.h"

static void *get_node_data(linked_list_t *ll, size_t index)
{
    node_t *temp = ll->head;

    for (size_t i = 0; i < index; i++)
        temp = temp->next;
    return temp->data;
}

void *get_node(linked_list_t *ll, size_t index)
{
    if (!ll || ll->size <= index)
        return NULL;
    return get_node_data(ll, index);
}
