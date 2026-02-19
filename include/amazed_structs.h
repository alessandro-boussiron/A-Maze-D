/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** amazed_structs
*/

#ifndef AMAZED_STRUCTS_H_
    #define AMAZED_STRUCTS_H_
    #include "linked_list.h"

typedef struct coordinates
{
    int x;
    int y;
} coordinates_t;

typedef enum room_type
{
    START,
    CLASSIC,
    END,
    ERROR,
} room_type_t;

typedef struct amazed_room
{
    coordinates_t coo;
    room_type_t type;
    char *name;
    node_t **linked_rooms;
    size_t linked_count;
    int weight;
    int has_robot;
} amazed_room_t;

typedef struct room_status
{
    int has_start;
    int has_end;
} room_status_t;

typedef struct amazed
{
    linked_list_t *room_list;
    int robots_count;
    room_type_t next_room_type;
    room_status_t room_status;
} amazed_t;

#endif /* !AMAZED_STRUCTS_H_ */
