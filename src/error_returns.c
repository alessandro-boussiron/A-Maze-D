/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** error_returns
*/

#include "amazed.h"
#include "my.h"
#include <unistd.h>

void *error_return(int *error, void *ptr)
{
    if (ptr)
        free(ptr);
    *error = -1;
    return NULL;
}