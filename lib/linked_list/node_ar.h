/*
** EPITECH PROJECT, 2025
** node_ar.h
** File description:
** add and remove a node
*/

#ifndef NODE_AR_H
    #define NODE_AR_H
    #include <stdlib.h>
    #include "./linked_list.h"

void add_node(linked_list_t *ll, const void *data, size_t index);
void remove_node(linked_list_t *ll, size_t index);

#endif // NODE_AR_H
