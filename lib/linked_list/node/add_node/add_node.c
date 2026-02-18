/*
** EPITECH PROJECT, 2025
** add_node.c
** File description:
** add a node by index
*/
#include "../../node_cd.h"
#include <stdio.h>

//printf("tail(\"%s\") was define at index %lu\n", ll->tail->data, index);

static void parse_ll_to_index(node_t **prev, node_t **temp, size_t index)
{
    for (size_t i = 0; i < index; i++) {
        *prev = *temp;
        *temp = (*temp)->next;
    }
}

static linked_list_t *append_node(linked_list_t *ll, node_t *n, size_t index)
{
    node_t *prev = NULL;
    node_t *temp = ll->head;

    parse_ll_to_index(&prev, &temp, index);
    if (prev)
        prev->next = n;
    else
        ll->head = n;
    n->prev = prev;
    n->next = temp;
    if (temp)
        temp->prev = n;
    else
        ll->tail = n;
    return ll;
}

void add_node(linked_list_t *ll, void *data, size_t index)
{
    node_t *node = node_create(data);

    if (!node)
        return;
    if (!ll || ll->size < index) {
        node_destroy(ll, node);
        return;
    }
    ll->size++;
    append_node(ll, node, index);
}
