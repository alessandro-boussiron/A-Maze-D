/*
** EPITECH PROJECT, 2025
** linked_list_clear.c
** File description:
** clear a linked list
*/
#include "../node_cd.h"
#include "../linked_list.h"

void linked_list_clear(linked_list_t *ll)
{
    size_t temp = ll->size;

    for (size_t i = 0; i < temp; i++)
        POP_START(ll);
}
