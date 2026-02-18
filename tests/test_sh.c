/*
** EPITECH PROJECT, 2026
** G-PSU-200-MPL-2-1-minishell1-6
** File description:
** test_sh
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(nothing, basic) {
    char *feur = NULL;
    cr_assert_null(feur);
}