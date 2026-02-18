/*
** EPITECH PROJECT, 2025
** node_destroy.c
** File description:
** destroy a node
*/
#include "../linked_list.h"
#include <stdio.h>

void node_destroy(linked_list_t *ll, node_t *node)
{
    if (!node || !ll)
        return;
    if (node->data) {
        if (ll->free_node)
            ll->free_node(node->data);
        free(node->data);
    }
    free(node);
}
