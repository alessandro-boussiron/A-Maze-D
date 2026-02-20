/*
** EPITECH PROJECT, 2025
** str_to_word_array
** File description:
** parse a string into array of words
*/
#include <stdlib.h>
#include "my.h"

static int is_alphanum(char a)
{
    if (a > 32 && a <= 126)
        return 1;
    return 0;
}

static char *string_to_array(int counter, int i, char const *str)
{
    char *dest = malloc(sizeof(char) * (counter + 1));
    int start = i - counter;

    if (!dest)
        return NULL;
    for (int j = 0; j < counter; j++)
        dest[j] = str[start + j];
    dest[counter] = '\0';
    return dest;
}

static char **string_allocation(char **array, char const *str)
{
    int delimiter_count = 0;

    for (int i = 1; str[i] != '\0'; i++)
        if (!(is_alphanum(str[i])) && is_alphanum(str[i - 1]))
            delimiter_count++;
    array = malloc(sizeof(char*) * (delimiter_count + 2));
    return array;
}

static char **size_allocation(char **array, char const *str)
{
    int buffer = 0;
    int tab = 0;
    int counter = 0;

    for (int i = 0; i <= my_strlen(str); i++) {
        if (is_alphanum(str[i]) && buffer == 1) {
            buffer = 0;
            tab++;
        }
        if (is_alphanum(str[i])) {
            counter++;
        }
        if (!(is_alphanum(str[i])) && i != 0 && is_alphanum(str[i - 1])) {
            buffer = 1;
            array[tab] = string_to_array(counter, i, str);
            counter = 0;
        }
    }
    array[tab + 1] = 0;
    return array;
}

char **my_str_to_word_array(char const *str)
{
    char **word_array = NULL;

    word_array = string_allocation(word_array, str);
    if (!word_array)
        return NULL;
    word_array = size_allocation(word_array, str);
    if (!word_array)
        return NULL;
    return word_array;
}
