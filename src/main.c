/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** main
*/
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "amazed.h"
#include "my.h"

static int is_valid_number(char *str)
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

static int is_valid_buffer(char *buffer)
{
    while (*buffer) {
        if ((*buffer < 32 || *buffer > 126) &&
            *buffer != '\t' && *buffer != '\n' && *buffer != '\0')
            return 0;
        buffer++;
    }
    return 1;
}

static void filter_comments(char **buffer)
{
    char *str = NULL;
    int is_commented = 0;

    if (!buffer || !(*buffer))
        return;
    str = *buffer;
    while (*str && *str == ' ')
        str++;
    for (int i = 0; str[i]; i++) {
        if (i == 0 && str[i] == '#' && str[i + 1] == '#')
            return;
        if (i != 0 && str[i] == '#')
            is_commented += 1;
        if (is_commented)
            str[i] = '\0';
    }
}

static int args_count(char **args)
{
    int i = 0;

    for (; args[i]; i++);
    return i;
}

static char **get_next_command(int *error)
{
    char *buffer = NULL;
    char **line_args = NULL;
    size_t buff_size = 0;

    if (getline(&buffer, &buff_size, stdin) < 0 || !buffer)
        return error_return(NULL, buffer);
    buff_size = (size_t)my_strlen(buffer);
    buffer[buff_size - 1] = '\0';
    if (!(*buffer))
        return error_return(NULL, buffer);
    if (!is_valid_buffer(buffer))
        return error_return(error, NULL);
    filter_comments(&buffer);
    line_args = my_str_to_word_array(buffer);
    if (line_args == NULL)
        *error = 1;
    safe_free(buffer);
    return line_args;
}

int process_line(amazed_t **amazed, char **inputline)
{
    int arg_count = 0;

    if (!amazed || !inputline || !(*inputline))
        return 1;
    arg_count = args_count(inputline);
    if (is_comment(inputline[0]))
        return 0;
    if (arg_count == 1 && is_valid_number(inputline[0]) &&
        (*amazed)->robots_count == 0)
        return get_robots(inputline, amazed);
    if (arg_count == 3 && is_valid_number(inputline[1]) &&
        is_valid_number(inputline[2]))
        return get_rooms(inputline, amazed);
    if (arg_count == 1 && is_command(inputline[0]) &&
        (*amazed)->next_room_type == CLASSIC)
        return get_next_room_types(inputline, amazed);
    return 1;
}

int process_input(amazed_t **amazed)
{
    int error = 0;
    char **inputline = NULL;

    for (int i = 0; i == 0 || (inputline && !error); i++) {
        free_array(inputline);
        inputline = get_next_command(&error);
        if (!inputline || error)
            break;
        error = process_line(amazed, inputline);
    }
    return (error) ? 1 : 0;
}

int main(int ac, char **av)
{
    amazed_t *amazed = init_amazed();
    int err = EXIT_SUCCESS;

    if (ac > 2 || av[1] || !amazed)
        return 84;
    if (process_input(&amazed))
        err = 84;
    destroy_amazed(amazed);
    return err;
}
