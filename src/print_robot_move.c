/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** print_robot_move
*/
#include "../include/my.h"
#include <unistd.h>

int print_robot_move(int robot_number, char *room_number)
{
    if (!room_number)
        return ERROR_CODE;
    if (write(1, "P", 1) != 1)
        return ERROR_CODE;
    if (my_put_nbr(robot_number) < 0)
        return ERROR_CODE;
    if (write(1, "-", 1) != 1)
        return ERROR_CODE;
    if (my_putstr(room_number) < 0)
        return ERROR_CODE;
    if (write(1, " ", 1) != 1)
        return ERROR_CODE;
    return SUCCESS_CODE;
}
