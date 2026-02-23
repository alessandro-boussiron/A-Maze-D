/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** link_two_rooms
*/
#include "amazed.h"
#include "my.h"

static int search_node(void *data, void *to_find)
{
    amazed_room_t *casted_data = (amazed_room_t *)data;
    char *casted_to_find = (char *)to_find;

    if (!data || !to_find)
        return 0;
    if (my_strcmp(casted_data->name, casted_to_find) == 0)
        return 1;
    return 0;
}

static int link_rooms(amazed_room_t *room1, amazed_room_t *room2)
{
    size_t size1 = 0;
    size_t size2 = 0;

    if (!room1 || !room2 || !room1->linked_rooms || !room2->linked_rooms)
        return ERROR_CODE;
    size1 = room1->linked_rooms->size;
    size2 = room2->linked_rooms->size;
    PUSH_END(room1->linked_rooms, room2);
    PUSH_END(room2->linked_rooms, room1);
    if (room1->linked_rooms->size <= size1 ||
        room2->linked_rooms->size <= size2)
        return ERROR_CODE;
    return EXIT_SUCCESS;
}

static int check_links(amazed_room_t *room1, amazed_room_t *room2)
{
    amazed_room_t *found = NULL;

    if (!room1 || !room2 || !room1->linked_rooms || !room2->linked_rooms)
        return ERROR_CODE;
    found = room1->linked_rooms->search(room1->linked_rooms,
        search_node, room2->name);
    if (found)
        return ERROR_CODE;
    found = room2->linked_rooms->search(room1->linked_rooms,
        search_node, room1->name);
    if (found)
        return ERROR_CODE;
    return EXIT_SUCCESS;
}

int link_two_rooms(linked_list_t *ll, char *roomname1, char *roomname2)
{
    amazed_room_t *room1 = NULL;
    amazed_room_t *room2 = NULL;

    if (!ll || ll->size < 2 || my_strcmp(roomname1, roomname2) == 0)
        return ERROR_CODE;
    room1 = ll->search(ll, search_node, roomname1);
    room2 = ll->search(ll, search_node, roomname2);
    if (check_links(room1, room2) || link_rooms(room1, room2))
        return ERROR_CODE;
    return EXIT_SUCCESS;
}
