/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** returns a number sent as a string
*/

#include "my.h"

static int my_is_number(char a)
{
    if (a >= '0' && a <= '9') {
        return 1;
    }
    return 0;
}

static long test_max_value(long i)
{
    if (i <= -2147483649) {
        return 0;
    }
    if (i > 2147483647) {
        return 0;
    }
    return i;
}

static int get_number(char const *str, int i, int sign)
{
    long power = 1;
    int nb_len = i;
    long result = 0;

    while (str[i] != '\0' && my_is_number(str[i])) {
        if (i - nb_len > 9) {
            return 0;
        }
        power = power * 10;
        i++;
    }
    power = power / 10;
    while (nb_len < i) {
        result = (str[nb_len] - '0') * power + result;
        power = power / 10;
        nb_len++;
    }
    result = result * sign;
    return test_max_value(result);
}

static int is_nbrneg(char a)
{
    if (a == '-'){
        return -1;
    } else {
        return 1;
    }
}

int my_getnbr(char const *str)
{
    int n = my_strlen(str);
    int sign = 1;

    for (int i = 0; i < n; i++) {
        sign = sign * is_nbrneg(str[i]);
        if (my_is_number(str[i])) {
            return get_number(str, i, sign);
        }
    }
    return 0;
}
