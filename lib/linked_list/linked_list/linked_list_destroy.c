/*
** EPITECH PROJECT, 2025
** linked_list_destroy.c
** File description:
** destroy a linked list
*/

#include "../linked_list.h"

void linked_list_destroy(linked_list_t **ll)
{
    if (!ll)
        return;
    (*ll)->clear(*ll);
    free(*ll);
    *ll = NULL;
}
