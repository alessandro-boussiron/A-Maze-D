/*
** EPITECH PROJECT, 2025
** remove_node.c
** File description:
** remove a node by index
*/
#include "../../node_cd.h"

static void parse_ll_to_index(node_t **prev, node_t **temp, size_t index)
{
    for (size_t i = 0; i < index; i++) {
        *prev = *temp;
        *temp = (*temp)->next;
    }
}

static linked_list_t *pop_node(linked_list_t *ll, size_t index)
{
    node_t *temp = ll->head;
    node_t *prev = NULL;
    node_t *next = NULL;

    parse_ll_to_index(&prev, &temp, index);
    next = temp->next;
    prev = temp->prev;
    if (prev)
        prev->next = next;
    else
        ll->head = next;
    if (next)
        next->prev = prev;
    else
        ll->tail = prev;
    node_destroy(ll, temp);
    return ll;
}

void remove_node(linked_list_t *ll, size_t index)
{
    if (!ll || ll->size - 1 < index || !ll->head) {
        return;
    }
    ll->size--;
    ll = pop_node(ll, index);
}
