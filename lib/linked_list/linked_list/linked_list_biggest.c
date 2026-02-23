/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** linked_list_biggest
*/
#include "../linked_list.h"
#include <limits.h>

void *linked_list_biggest(linked_list_t *ll, int(*biggest)(void *data))
{
    int biggest_return = INT_MIN;
    int temp_return;
    void *biggest_data = NULL;

    if (!ll || !biggest)
        return NULL;
    for (node_t *curr = ll->head; curr; curr = curr->next) {
        temp_return = biggest(curr->data);
        if (temp_return > biggest_return) {
            biggest_return = temp_return;
            biggest_data = curr->data;
        }
    }
    return biggest_data;
}
