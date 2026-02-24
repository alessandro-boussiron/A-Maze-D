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

static int move_robot(robot_t *robot)
{
    amazed_room_t *dest = NULL;

    if (!robot || !robot->room || !robot->room->linked_rooms)
        return ERROR_CODE;
    dest = robot->room->linked_rooms->biggest(robot->room->linked_rooms,
        bigger_weight);
    if (!dest)
        return ERROR_CODE;
    if (robot->room->weight <= dest->weight && (!dest->has_robot ||
            dest->type == END)) {
        robot->room->has_robot--;
        robot->room = dest;
        robot->room->has_robot++;
        if (my_putstr("go to ") || my_putstr(robot->room->name) ||
            my_putstr("\n"))
            return ERROR_CODE;
    }
    return SUCCESS_CODE;
}

int next_gen(amazed_t *amazed, linked_list_t *robots)
{
    robot_t *curr_robot = NULL;

    if (!amazed || !robots)
        return ERROR_CODE;
    for (node_t *cur_robot_node = robots->head; cur_robot_node;
        cur_robot_node = cur_robot_node->next) {
        curr_robot = (robot_t *)cur_robot_node->data;
        if (!curr_robot || !curr_robot->room || curr_robot->room->type == END)
            continue;
        if (move_robot(curr_robot))
            return ERROR_CODE;
    }
    return SUCCESS_CODE;
}
