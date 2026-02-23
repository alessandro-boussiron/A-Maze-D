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

room_type_t next_room_type(char *str)
{
    if (!str || str[0] != '#' || str[1] != '#')
        return ERROR;
    if (!my_strncmp(str, "##start", 7))
        return START;
    if (!my_strncmp(str, "##end", 5))
        return END;
    return CLASSIC;
}

int get_tunnel(char *line, amazed_t **amazed)
{
    char *name = line;

    if (!line || !amazed || !(*amazed))
        return 1;
    while (*line && *line != '-')
        line++;
    if (*line == '-') {
        *line = '\0';
        line++;
    }
    return link_two_rooms((*amazed)->room_list, name, line);
}

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
