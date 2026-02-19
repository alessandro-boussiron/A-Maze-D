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

Test(is_comment, basic) {
    char feur[] = "#test";
    char feur2[] = "##feur";

    cr_assert(is_comment(feur) == 1);
    cr_assert(is_comment(feur2) == 0);
    cr_assert(is_comment(NULL) == 0);
}