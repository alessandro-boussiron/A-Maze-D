/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** parser_checks
*/

#include "my.h"
#include "amazed.h"

int is_comment(char *str)
{
    if (!str)
        return 0;
    for (size_t i = 0; str[i]; i++)
        if (str[i] == '#' && str[i + 1] != '#')
            return 1;
    return 0;
}

room_type_t get_next_room_type(char *str)
{
    if (!str || str[0] != '#' || str[1] != '#')
        return ERROR;
    if (my_strncmp(str, "##start", 7))
        return START;
    if (my_strncmp(str, "##end", 5))
        return END;
    return CLASSIC;
}
