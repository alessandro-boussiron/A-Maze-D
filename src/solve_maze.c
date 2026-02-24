/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** solve_maze
*/
#include "amazed.h"
#include "my.h"

static int launch_robots(amazed_t *amazed, linked_list_t *robots)
{
    amazed_room_t *end = get_end_room(amazed);
    size_t curr_gen = 0;
    int err = SUCCESS_CODE;

    if (!robots || !amazed || !end)
        return ERROR_CODE;
    while (end->has_robot == amazed->robots_count) {
        if (curr_gen > 100 || next_gen(amazed, robots)) {
            my_putstr("Error Occured.\n");
            err = ERROR_CODE;
            break;
        }
        curr_gen++;
    }
    return err;
}

static int init_robots(amazed_room_t *start, linked_list_t *robots,
    int nb_robots)
{
    if (!robots)
        return ERROR_CODE;
    for (int robot_added = 0; robot_added < nb_robots; robot_added++) {
        PUSH_END(robots, start);
        if (robots->size != robot_added)
            return ERROR_CODE;
    }
    return SUCCESS_CODE;
}

int solve_maze(amazed_t *amazed)
{
    linked_list_t *robots = NULL;
    amazed_room_t *start = get_start_room(amazed);
    int err = SUCCESS_CODE;

    if (!amazed)
        return ERROR_CODE;
    if (set_weight(amazed))
        return ERROR_CODE;
    robots = linked_list_create();
    if (!robots)
        return ERROR_CODE;
    if (init_robots(start, robots, amazed->robots_count) ||
        launch_robots(amazed, robots))
        err = ERROR_CODE;
    robots->destroy(&robots);
    return err;
}
