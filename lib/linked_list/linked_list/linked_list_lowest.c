/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** linked_list_lowest
*/
#include "../linked_list.h"
#include <limits.h>

void *linked_list_lowest(linked_list_t *ll, int(*lowest)(void *data))
{
    int lowest_return = INT_MAX;
    int temp_return;
    void *lowest_data = NULL;

    if (!ll || !lowest)
        return NULL;
    for (node_t *curr = ll->head; curr; curr = curr->next) {
        temp_return = lowest(curr->data);
        if (temp_return < lowest_return) {
            lowest_return = temp_return;
            lowest_data = curr->data;
        }
    }
    return lowest_data;
}
