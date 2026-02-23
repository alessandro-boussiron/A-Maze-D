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
    if (str[0] == '#' && str[1] != '#')
        return 1;
    return 0;
}

int is_valid_number(char *str)
{
    char *buffer = str;

    if (!str)
        return 0;
    while (*buffer) {
        if ((*buffer < '0' || *buffer > '9') && *buffer != '-')
            return 0;
        buffer++;
    }
    return 1;
}

int is_valid_name(char *str)
{
    char *buffer = str;

    if (!str)
        return 0;
    while (*buffer) {
        if ((*buffer >= '0' && *buffer <= '9') ||
            (*buffer >= 'a' && *buffer <= 'z') ||
            (*buffer >= 'A' && *buffer <= 'Z')) {
            buffer++;
            continue;
        }
        return 0;
    }
    return 1;
}

int is_tunnel(char *str)
{
    char *buffer = str;
    int has_delim = 0;

    if (!str)
        return 0;
    while (*buffer) {
        if (*buffer == '-')
            has_delim += 1;
        if ((*buffer >= '0' && *buffer <= '9') ||
            (*buffer >= 'a' && *buffer <= 'z') ||
            (*buffer >= 'A' && *buffer <= 'Z') || *buffer == '-') {
            buffer++;
            continue;
        }
    }
    return (has_delim != 1) ? 0 : 1;
}

int is_command(char *str)
{
    if (!str)
        return 0;
    if (str[0] == '#' && str[1] == '#')
        return 1;
    return 0;
}
