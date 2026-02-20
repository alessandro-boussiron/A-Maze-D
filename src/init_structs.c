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

static void free_room(void *data)
{
    amazed_room_t **casted = (amazed_room_t **)data;

    free((*casted)->name);
    (*casted)->linked_rooms->destroy(&((*casted)->linked_rooms));
    free(*casted);
}

amazed_t *init_amazed(void)
{
    amazed_t *amazed = malloc(sizeof(amazed_t));
    linked_list_t *rooms = linked_list_create();
    room_status_t status = {0, 0};

    if (!amazed || !rooms)
        return NULL;
    amazed->robots_count = 0;
    amazed->room_list = rooms;
    amazed->room_list->set_dstr(amazed->room_list, free_room);
    amazed->next_room_type = CLASSIC;
    amazed->room_status = status;
    return amazed;
}
