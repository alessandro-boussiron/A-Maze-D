/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** check_integrity
*/
#include "amazed.h"
#include "my.h"

static int search_node_by_type(void *data, void *to_find)
{
    room_type_t *type_to_find = (room_type_t *)to_find;
    amazed_room_t *curr_room = (amazed_room_t *)data;

    if (!data || !to_find)
        return 0;
    if (curr_room->type == *type_to_find)
        return 1;
    return 0;
}

int check_integrity(amazed_t *amazed)
{
    room_type_t type_end = END;
    room_type_t type_start = START;
    room_type_t type_err = ERROR;
    int nb_end = 0;
    int nb_start = 0;
    int nb_error = 0;

    if (!amazed || !amazed->room_list)
        return ERROR_CODE;
    nb_end = amazed->room_list->search_nb(amazed->room_list,
        search_node_by_type, &type_end);
    nb_start = amazed->room_list->search_nb(amazed->room_list,
        search_node_by_type, &type_start);
    nb_error = amazed->room_list->search_nb(amazed->room_list,
        search_node_by_type, &type_err);;
    if (nb_end != 1 || nb_start != 1 || nb_error)
        return ERROR_CODE;
    return SUCCESS_CODE;
}
