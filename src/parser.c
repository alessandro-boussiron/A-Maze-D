/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** parser
*/

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "amazed.h"
#include "my.h"


int get_robots(char **line, amazed_t **amazed)
{
    int robots = 0;

    if (!line || !(*line) || !amazed || !(*amazed))
        return 1;
    robots = my_getnbr(line[0]);
    if (robots == 0)
        return 1;
    (*amazed)->robots_count = robots;
    return 0;
}
