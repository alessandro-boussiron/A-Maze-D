/*
** EPITECH PROJECT, 2025
** node_create.c
** File description:
** create a node
*/

#include "../linked_list.h"
#include "my.h"

node_t *node_create(void *data)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        return NULL;
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}
