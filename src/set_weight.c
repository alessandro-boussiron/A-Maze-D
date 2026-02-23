/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** set_weight
*/
#include "my.h"
#include "amazed.h"
#include <stdio.h>

static void add_to_queue(amazed_room_t **queue, int *end_queue,
    amazed_room_t *room_to_add)
{
    if (!end_queue || !room_to_add || !queue)
        return;
    queue[*end_queue] = room_to_add;
    (*end_queue)++;
}

static void process_curr_room(amazed_room_t **queue, amazed_room_t *curr_room,
    int *end_queue)
{
    amazed_room_t *neighbor_room = NULL;

    if (!queue || !curr_room || !curr_room->linked_rooms || !end_queue)
        return;
    for (node_t *neighboring = curr_room->linked_rooms->head; neighboring;
        neighboring = neighboring->next) {
        neighbor_room = (amazed_room_t *)neighboring->data;
        if (!neighbor_room)
            continue;
        if (neighbor_room->weight < curr_room->weight - 1) {
            neighbor_room->weight = curr_room->weight - 1;
            add_to_queue(queue, end_queue, neighbor_room);
        }
    }
}

static int start_queuing(amazed_room_t **queue, size_t nb_rooms,
    amazed_room_t *start_room)
{
    int start_queue = 0;
    int end_queue = 0;
    amazed_room_t *curr_room = NULL;

    if (!queue || !start_room)
        return ERROR_CODE;
    start_room->weight = nb_rooms;
    for (size_t i = 0; i < nb_rooms; i++)
        queue[i] = NULL;
    add_to_queue(queue, &end_queue, start_room);
    while (start_queue < end_queue) {
        curr_room = queue[start_queue];
        start_queue++;
        if (!curr_room)
            continue;
        process_curr_room(queue, curr_room, &end_queue);
    }
    return EXIT_SUCCESS;
}

int set_weight(amazed_t *amazed)
{
    amazed_room_t *end = get_end_room(amazed);
    amazed_room_t **queue = NULL;
    int err = EXIT_SUCCESS;

    if (!amazed || !amazed->room_list || !end)
        return ERROR_CODE;
    queue = malloc(sizeof(amazed_room_t *) * amazed->room_list->size);
    if (start_queuing(queue, amazed->room_list->size, end))
        err = ERROR_CODE;
    safe_free(queue);
    return err;
}
