/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** print_robot_move
*/
#include "../include/my.h"
#include <unistd.h>

int print_robot_move(int robot_number, int room_number)
{
    if (write(1, "P", 1) != 1)
        return ERROR_CODE;
    my_put_nbr(robot_number);
    if (write(1, "-", 1) != 1)
        return ERROR_CODE;
    my_put_nbr(room_number);
    if (write(1, "\n", 1) != 1)
        return ERROR_CODE;
    return SUCCESS_CODE;
}
