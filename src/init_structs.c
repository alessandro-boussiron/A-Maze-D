/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** init_structs
*/

#include "amazed.h"
#include "my.h"

void safe_free(void *ptr)
{
    if (ptr)
        free(ptr);
    return;
}

void free_array(char **arr)
{
    if (!arr || !(*arr))
        return;
    for (int i = 0; arr[i]; i++)
        safe_free(arr[i]);
    safe_free(arr);
}

void destroy_amazed(amazed_t *self)
{
    if (!self)
        return;
    if (self->room_list)
        self->room_list->destroy(&self->room_list);
    safe_free(self);
}

amazed_t *init_amazed(void)
{
    amazed_t *amazed = malloc(sizeof(amazed));
    linked_list_t *rooms = linked_list_create();

    if (!amazed || !rooms)
        return NULL;
    amazed->robots_count = 0;
    amazed->room_list = rooms;
    return amazed;
}
