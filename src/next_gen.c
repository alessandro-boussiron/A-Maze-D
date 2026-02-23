/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** next_gen
*/
#include "../include/my.h"
#include "amazed.h"
#include <unistd.h>

int next_gen(amazed_t *amazed, linked_list_t *robots)
{
    int max_weight = 0;
    int index = -1;
    node_t *cur_room = amazed->room_list->head->data;
    amazed_room_t *room = (amazed_room_t *)cur_room->data;

    if (!cur_room)
        return 84;
    while (cur_room) {
        if (room->weight == max_weight && room->has_robot == 0) {
            my_putstr("tungtungtungsahur");
        }
    }
    return 0;
}
