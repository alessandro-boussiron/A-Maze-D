/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** find_end_room
*/
#include "amazed.h"
#include <stdio.h>

static int search_node_by_type(void *data, void *to_find)
{
    room_type_t *type_to_find = (room_type_t *)to_find;
    amazed_room_t *curr_room = (amazed_room_t *)data;

    if (!data || !to_find)
        return 0;
    if (curr_room->type == *type_to_find)
        return 1;
    return 0;
}

amazed_room_t *get_end_room(amazed_t *amazed)
{
    room_type_t type_end = END;
    amazed_room_t *end = NULL;

    if (!amazed || !amazed->room_list)
        return NULL;
    end = amazed->room_list->search(amazed->room_list,
        search_node_by_type, &type_end);
    return end;
}
