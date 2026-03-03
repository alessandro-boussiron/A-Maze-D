/*
** EPITECH PROJECT, 2026
** G-PSU-200-MPL-2-1-minishell1-6
** File description:
** test_sh
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "amazed.h"
#include <unistd.h>
#include <fcntl.h>

Test(init_destroy_amazed, basic) {
    amazed_t *feur = init_amazed();

    cr_assert_not_null(feur);
    destroy_amazed(NULL);
    destroy_amazed(feur);
    feur = NULL;
    cr_assert_null(feur);
}

Test(safe_free, basic) {
    char *feur = malloc(sizeof(char) * 4);

    safe_free(NULL);
    safe_free(feur);
    feur = NULL;
    cr_assert_null(feur);
}

Test(error_returns_null, basic) {
    int error = 0;

    error_return(&error, NULL);
    cr_assert(error < 0);
}

Test(error_returns_null, set_error) {

    int *error = NULL;

    error_return(error, NULL);
    cr_assert_null(error);
}

Test(error_returns, basic) {
    int error = 0;
    char *feur = malloc(sizeof(char) * 4);

    error_return(&error, feur);
    cr_assert(error < 0);
}

Test(get_robots_basic, basic) {
    amazed_t *amazed = init_amazed();
    char *feur[] = {
        "45",
        NULL,
    };
    int result = get_robots(feur, &amazed);
    cr_assert(!result && amazed->robots_count == 45);
}

Test(get_robots_null_params, basic) {
    int result = get_robots(NULL, NULL);
    cr_assert(result == 1);
}

Test(get_robots_wrong_value, basic) {
    amazed_t *amazed = init_amazed();
    char *feur[] = {
        "0",
        NULL,
    };
    int result = get_robots(feur, &amazed);
    cr_assert(result == 1);
}

Test(free_array, basic) {
    char **feur = malloc(sizeof(char *) * 2);
    feur[1] = NULL;
    feur[0] = malloc(sizeof(char) * 4);

    free_array(feur);
    feur = NULL;
    cr_assert_null(feur);
}

Test(free_array_null, basic) {
    char **feur = NULL;

    free_array(feur);
    cr_assert_null(feur);
}

Test(goofy_amazed_destroy, basic) {
    amazed_t *amazed = init_amazed();

    amazed->room_list = NULL;
    amazed->parsed_tunnels = NULL;
    cr_assert_null(amazed->room_list);
    cr_assert_null(amazed->parsed_tunnels);
    destroy_amazed(amazed);
    cr_assert_not_null(amazed);
}

Test(is_comment, basic) {
    char feur[] = "#test";
    char feur2[] = "##feur";

    cr_assert(is_comment(feur) == 1);
    cr_assert(is_comment(feur2) == 0);
    cr_assert(is_comment(NULL) == 0);
}

Test(is_valid_number, basic) {
    char feur[] = "45687";
    char feur2[] = "-4deq89";

    cr_assert(is_valid_number(feur) == 1);
    cr_assert(is_valid_number(feur2) == 0);
    cr_assert(is_valid_number(NULL) == 0);
}

Test(is_command, basic) {
    char feur[] = "##45687";
    char feur2[] = "#4deq89";

    cr_assert(is_command(feur) == 1);
    cr_assert(is_command(feur2) == 0);
    cr_assert(is_command(NULL) == 0);
}

Test(is_valid_name, basic) {
    char feur[] = "45687";
    char feur2[] = "-4deq89";

    cr_assert(is_valid_name(feur) == 1);
    cr_assert(is_valid_name(feur2) == 0);
    cr_assert(is_valid_name(NULL) == 0);
}

Test(is_tunnel, basic) {
    char feur[] = "abcdef-abce";
    char feur2[] = "#4deq89";

    cr_assert(is_tunnel(feur) == 1);
    cr_assert(is_tunnel(feur2) == 0);
    cr_assert(is_tunnel(NULL) == 0);
}

Test(get_robots, basic) {
    amazed_t *amazed = init_amazed();
    char *feur[] = {
        "14",
        NULL,
    };
    cr_assert(get_robots(feur, &amazed) == 0);
    cr_assert(amazed->robots_count == 14);
    
    cr_assert(get_robots(NULL, &amazed) == 1);
    cr_assert(get_robots(feur, NULL) == 1);
}

Test(next_room_type, basic) {
    amazed_t *amazed = init_amazed();
    char *feur[] = {
        "##start",
        NULL,
    };
    char *feur2[] = {
        "##end",
        NULL,
    };
    cr_assert(get_next_room_types(feur, &amazed) == 0);
    cr_assert(amazed->room_status.has_start == 1);
    cr_assert(get_next_room_types(feur2, &amazed) == 0);
    cr_assert(amazed->room_status.has_end == 1);

    cr_assert(get_next_room_types(NULL, &amazed) == 1);
    cr_assert(get_next_room_types(feur, NULL) == 1);
}

Test(get_rooms, basic) {
    amazed_t *amazed = init_amazed();
    char *feur[] = {
        "quoicoufeur",
        "59",
        "48",
        NULL,
    };
    cr_assert(get_rooms(feur, &amazed) == 0);
    amazed_room_t *room = (amazed_room_t *)amazed->room_list->head->data;
    cr_assert(room->type == CLASSIC && room->coo.x == 59 && room->coo.y == 48);

    cr_assert(get_next_room_types(NULL, &amazed) == 1);
    cr_assert(get_next_room_types(feur, NULL) == 1);
}

Test(get_rooms, start) {
    amazed_t *amazed = init_amazed();
    char *feur[] = {
        "quoicoufeur",
        "59",
        "48",
        NULL,
    };
    amazed->next_room_type = START;
    cr_assert(get_rooms(feur, &amazed) == 0);
    amazed_room_t *room = (amazed_room_t *)amazed->room_list->head->data;
    cr_assert(room->type == START && room->coo.x == 59 && room->coo.y == 48);

    cr_assert(get_next_room_types(NULL, &amazed) == 1);
    cr_assert(get_next_room_types(feur, NULL) == 1);
    cr_assert(get_next_room_types(NULL, NULL) == 1);
}

Test(get_rooms, end) {
    amazed_t *amazed = init_amazed();
    char *feur[] = {
        "quoicoufeur",
        "59",
        "48",
        NULL,
    };
    amazed->next_room_type = END;
    cr_assert(get_rooms(feur, &amazed) == 0);
    amazed_room_t *room = (amazed_room_t *)amazed->room_list->head->data;
    cr_assert(room->type == END && room->coo.x == 59 && room->coo.y == 48);

    cr_assert(get_next_room_types(NULL, &amazed) == 1);
    cr_assert(get_next_room_types(feur, NULL) == 1);
}

Test(next_room_type, macro_return) {
    char feur[] = "##start";
    char end[] = "##end";
    char stonks[] = "iqodjzod";
    char bonk[] = "##bonk";

    cr_assert(next_room_type(NULL) == ERROR);
    cr_assert(next_room_type(stonks) == ERROR);
    cr_assert(next_room_type(feur) == START);
    cr_assert(next_room_type(end) == END);
    cr_assert(next_room_type(bonk) == CLASSIC);
}

Test(set_tunnels, basic) {
    amazed_t *amazed = init_amazed();
    char *feur[] = {
        "quoicoufeur",
        "59",
        "48",
        NULL,
    };
    char *feur2[] = {
        "feur",
        "70",
        "40",
        NULL,
    };
    char tunnel0[] = "quoicoufeur-feur";
    char tunnel2[] = "quoicoufeur-";
    char tunnel1[] = "-feur";
    get_rooms(feur, &amazed);
    get_rooms(feur2, &amazed);

    cr_assert_not_null(amazed->room_list->head->data);
    cr_assert(get_tunnel(tunnel0, &amazed) == 0);
    cr_assert(get_tunnel(tunnel1, &amazed));
    cr_assert(get_tunnel(tunnel2, &amazed));
    cr_assert(get_tunnel(NULL, &amazed) == 1);
    cr_assert(get_tunnel(tunnel0, NULL) == 1);
    cr_assert(get_tunnel(NULL, NULL) == 1);
}

Test(dump_processes, basic) {
    amazed_t *amazed = init_amazed();
    char *feur[] = {
        "0",
        "59",
        "48",
        NULL,
    };
    char *feur2[] = {
        "1",
        "70",
        "97",
        NULL,
    };
    char *feur3[] = {
        "2",
        "40",
        "10",
        NULL,
    };
    char *feur4[] = {
        "14",
        NULL,
    };
    char tunnel[] = "0-1";
    char tunnel2[] = "1-2";
    amazed->next_room_type = END;
    get_rooms(feur, &amazed);
    amazed->next_room_type = START;
    get_rooms(feur2, &amazed);
    get_rooms(feur3, &amazed);
    get_robots(feur4, &amazed);
    get_tunnel(tunnel, &amazed);
    get_tunnel(tunnel2, &amazed);
    cr_assert_not_null(amazed->room_list->head->data);
    cr_assert_not_null(amazed->parsed_tunnels->head->data);
    cr_assert(amazed->robots_count != 0);
    cr_assert(dump_parsed_processes(&amazed) == 0);
    cr_assert(dump_parsed_processes(NULL) == 1);
    close(1);
    cr_assert(dump_parsed_processes(&amazed) == 0);
    int fd = open("/dev/tty", O_WRONLY);
    dup2(fd, 1);
}

Test(solve_maze, basic) {
    amazed_t *amazed = init_amazed();
    char *feur[] = {
        "0",
        "59",
        "48",
        NULL,
    };
    char *feur2[] = {
        "1",
        "70",
        "97",
        NULL,
    };
    char *feur3[] = {
        "2",
        "40",
        "10",
        NULL,
    };
    char *feur4[] = {
        "14",
        NULL,
    };
    char tunnel[] = "0-1";
    char tunnel2[] = "1-2";
    amazed->next_room_type = END;
    get_rooms(feur, &amazed);
    amazed->next_room_type = START;
    get_rooms(feur2, &amazed);
    get_rooms(feur3, &amazed);
    get_robots(feur4, &amazed);
    get_tunnel(tunnel, &amazed);
    get_tunnel(tunnel2, &amazed);
    cr_assert_not_null(amazed->room_list->head->data);
    cr_assert_not_null(amazed->parsed_tunnels->head->data);
    cr_assert(amazed->robots_count != 0);
    cr_assert(solve_maze(amazed) == 0);
}

Test(check_integrity, basic) {
    amazed_t *amazed = init_amazed();
    char *feur[] = {
        "0",
        "59",
        "48",
        NULL,
    };
    char *feur2[] = {
        "1",
        "70",
        "97",
        NULL,
    };
    char *feur3[] = {
        "2",
        "40",
        "10",
        NULL,
    };
    char *feur4[] = {
        "14",
        NULL,
    };
    char tunnel[] = "0-1";
    char tunnel2[] = "1-2";
    cr_assert(check_integrity(amazed));
    amazed->next_room_type = END;
    get_rooms(feur, &amazed);
    get_rooms(feur2, &amazed);
    amazed->next_room_type = START;
    get_rooms(feur3, &amazed);
    cr_assert(check_integrity(amazed) == 0);
    get_robots(feur4, &amazed);
    get_tunnel(tunnel, &amazed);
    get_tunnel(tunnel2, &amazed);
    cr_assert_not_null(amazed->room_list->head->data);
    cr_assert_not_null(amazed->parsed_tunnels->head->data);
    cr_assert(amazed->robots_count != 0);
    cr_assert(check_integrity(amazed) == 0);
}

Test(dump_processes, null_arg) {
    cr_assert(dump_parsed_processes(NULL));
}

Test(check_integrity, null_arg) {
    cr_assert(check_integrity(NULL));
}

Test(solve_maze, null_arg) {
    cr_assert(solve_maze(NULL));
}

Test(check_integrity, no_ends) {
    amazed_t *amazed = init_amazed();
    char *feur[] = {
        "0",
        "59",
        "48",
        NULL,
    };
    char *feur2[] = {
        "1",
        "70",
        "97",
        NULL,
    };
    char *feur3[] = {
        "2",
        "40",
        "10",
        NULL,
    };
    char *feur4[] = {
        "14",
        NULL,
    };
    cr_assert(check_integrity(amazed));
    get_rooms(feur, &amazed);
    get_rooms(feur2, &amazed);
    amazed->next_room_type = START;
    get_rooms(feur3, &amazed);
    cr_assert(check_integrity(amazed));
    get_robots(feur4, &amazed);
    cr_assert(amazed->robots_count != 0);
    cr_assert(check_integrity(amazed));
}

Test(print_robot_move, null_arg) {
    cr_assert(print_robot_move(0, NULL, 0));
}

Test(print_robot_move, basic) {
    close(1);
    int i = 0;
    char feur[] = "fesuifs";
    cr_assert(print_robot_move(5, feur, i));
    int fd = open("/dev/tty", O_WRONLY);
    dup2(fd, 1);
}