/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** next_gen
*/
#include "../include/my.h"
#include "amazed.h"
#include <unistd.h>

static int bigger_weight(void *data)
{
    amazed_room_t *casted_data = (amazed_room_t *)data;

    if (!data)
        return 1;
    return casted_data->weight;
}

static int move_robot(amazed_room_t *robot)
{
    amazed_room_t *dest = NULL;

    if (!robot)
        return ERROR_CODE;
    dest = robot->linked_rooms->biggest(robot->linked_rooms, bigger_weight);
    if (!dest)
        return ERROR_CODE;
    if (robot->weight < dest->weight && !dest->has_robot) {
        robot->has_robot--;
        robot = dest;
        robot->has_robot++;
        if (my_putstr("go to ") < 0 || my_putstr(robot->name) < 0 ||
            my_putstr("\n") < 0)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int next_gen(amazed_t *amazed, linked_list_t *robots)
{
    amazed_room_t *cur_robot_room = NULL;

    if (!amazed || !robots)
        return 84;
    for (node_t *cur_robot = robots->head; cur_robot;
        cur_robot = cur_robot->next) {
        cur_robot_room = (amazed_room_t *)cur_robot->data;
        if (!cur_robot_room || cur_robot_room->type == END)
            continue;
        if (move_robot(cur_robot_room) != 0)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
