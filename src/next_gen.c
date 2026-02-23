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
    int indice = -1;
    amazed_room_t *cur_room = amazed->room_list->head;

    if (!cur_room)
        return 84;
    while (cur_room) {
        if (cur_room->weight = max_weight && cur_room->has_robot == 0) {
            my_putstr("tungtungtungsahur");
        }
    }
    return 0;
}