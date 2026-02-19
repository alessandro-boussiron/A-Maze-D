/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** parser
*/

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "amazed.h"
#include "my.h"

int get_robots(char **line, amazed_t **amazed)
{
    int robots = 0;

    if (!line || !(*line) || !amazed || !(*amazed))
        return 1;
    robots = my_getnbr(line[0]);
    if (robots <= 0)
        return 1;
    (*amazed)->robots_count = robots;
    return 0;
}

amazed_room_t *create_room(room_type_t type, char **params, int robots_count)
{
    amazed_room_t *room = malloc(sizeof(amazed_room_t));
    node_t **linked_rooms = malloc(sizeof(node_t *) * 1);
    coordinates_t coo = {0, 0};

    if (!room || !linked_rooms || !params)
        return NULL;
    linked_rooms[0] = NULL;
    coo.x = my_getnbr(params[1]);
    coo.y = my_getnbr(params[2]);
    room->name = my_strdup(params[0]);
    room->coo = coo;
    room->has_robot = (type == START) ? robots_count : 0;
    room->type = type;
    room->weight = 0;
    room->linked_count = 0;
    room->linked_rooms = linked_rooms;
    return room;
}

int get_rooms(char **line, amazed_t **amazed)
{
    amazed_room_t *room = NULL;

    if (!line || !amazed)
        return 1;
    room = create_room((*amazed)->next_room_type, line,
        (*amazed)->robots_count);
    (*amazed)->next_room_type = CLASSIC;
    PUSH_END((*amazed)->room_list, room);
    return 0;
}

int get_next_room_types(char **line, amazed_t **amazed)
{
    room_type_t room = CLASSIC;

    if (!line || !amazed)
        return 1;
    room = next_room_type(line[0]);
    switch (room) {
        case START:
            (*amazed)->room_status.has_start = 1;
            break;
        case END:
            (*amazed)->room_status.has_end = 1;
            break;
        default:
            break;
    }
    if (room == ERROR)
        return 1;
    (*amazed)->next_room_type = room;
    return 0;
}
