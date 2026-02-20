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

amazed_room_t *create_room(room_type_t type, char **params, int robots_count)
{
    amazed_room_t *room = malloc(sizeof(amazed_room_t));
    linked_list_t *linked_rooms = linked_list_create();
    coordinates_t coo = {0, 0};

    if (!room || !linked_rooms || !params)
        return NULL;
    coo.x = my_getnbr(params[1]);
    coo.y = my_getnbr(params[2]);
    room->name = my_strdup(params[0]);
    room->coo = coo;
    room->has_robot = (type == START) ? robots_count : 0;
    room->type = type;
    room->weight = 0;
    room->linked_rooms = linked_rooms;
    return room;
}
