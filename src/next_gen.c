/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** next_gen
*/
#include "../include/my.h"
#include "amazed.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

static int bigger_weight(void *data)
{
    amazed_room_t *casted_data = (amazed_room_t *)data;

    if (!data)
        return -1;
    if (casted_data->type == END)
        return INT_MAX;
    if (casted_data->has_robot)
        return 0;
    return casted_data->weight;
}

static int bigger_weight_anyway(void *data)
{
    amazed_room_t *casted_data = (amazed_room_t *)data;

    if (!data)
        return 0;
    return casted_data->weight;
}

static amazed_room_t *get_dest(amazed_room_t *room, int room_numbers)
{
    amazed_room_t *dest = NULL;

    if (!room || !room->linked_rooms)
        return NULL;
    dest = room->linked_rooms->biggest(room->linked_rooms, bigger_weight);
    if (!dest)
        return room;
    if (room->has_robot >= room_numbers - dest->weight
        || room->type != START)
        return dest;
    dest = room->linked_rooms->biggest(room->linked_rooms,
        bigger_weight_anyway);
    if (!dest || dest->has_robot)
        return room;
    return dest;
}

static int move_robot(robot_t *robot, int total_room, int i)
{
    amazed_room_t *dest = NULL;

    if (!robot || !robot->room || !robot->room->linked_rooms)
        return ERROR_CODE;
    dest = get_dest(robot->room, total_room);
    if (!dest)
        return ERROR_CODE;
    if (robot->room->weight <= dest->weight && (!dest->has_robot ||
            dest->type == END)) {
        robot->room->has_robot--;
        robot->room = dest;
        robot->room->has_robot++;
        if (print_robot_move(robot->serial_number, robot->room->name, i) < 0)
            return ERROR_CODE;
        return SUCCESS_CODE;
    }
    if (robot->room->type == START)
        return NO_MOVE_CODE;
    return SUCCESS_CODE;
}

int next_gen(amazed_t *amazed, robot_t **robots)
{
    int r = 0;
    int i = 0;

    if (!amazed || !robots)
        return ERROR_CODE;
    for (robot_t **curr_robot = robots; *curr_robot; curr_robot++) {
        if (!curr_robot || !(*curr_robot)->room ||
            (*curr_robot)->room->type == END)
            continue;
        r = move_robot((*curr_robot), amazed->room_list->size, i);
        i++;
        if (r == ERROR_CODE)
            return ERROR_CODE;
        if (r == NO_MOVE_CODE)
            break;
    }
    return SUCCESS_CODE;
}
