/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** print
*/

#include "amazed.h"
#include "my.h"
#include <unistd.h>

static void dump_robots_count(int robot_count)
{
    my_putstr("#number_of_robots\n");
    my_put_nbr(robot_count);
    my_putstr("\n");
}

static void print_room_info(void *data)
{
    amazed_room_t *room = (amazed_room_t *)data;

    if (!data)
        return;
    switch (room->type) {
        case START:
            my_putstr("##start\n");
            break;
        case END:
            my_putstr("##end\n");
            break;
        default:
            break;
    }
    my_putstr(room->name);
    my_putstr(" ");
    my_put_nbr(room->coo.x);
    my_putstr(" ");
    my_put_nbr(room->coo.y);
    my_putstr("\n");
}
static void print_tunnels(void *data)
{
    char *tunnel = (char *)data;

    if (!data)
        return;
    my_putstr(tunnel);
    my_putstr("\n");
}

static void dump_rooms(linked_list_t *rooms)
{
    my_putstr("#rooms\n");
    rooms->apply(rooms, print_room_info);
}

static void dump_tunnels(linked_list_t *tunnels)
{
    my_putstr("#tunnels\n");
    tunnels->apply(tunnels, print_tunnels);
}

void dump_parsed_processes(amazed_t **amazed)
{
    dump_robots_count((*amazed)->robots_count);
    dump_rooms((*amazed)->room_list);
    dump_tunnels((*amazed)->parsed_tunnels);
}
