/*
** EPITECH PROJECT, 2025
** node-cd.h
** File description:
** create and destroy a node
*/

#ifndef NODE_CD_H_
    #define NODE_CD_H_
    #include "./linked_list.h"

node_t *node_create(void *data);
void node_destroy(linked_list_t *ll, node_t *node);

#endif /* !NODE_CD_H_ */
