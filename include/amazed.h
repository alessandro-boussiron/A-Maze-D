/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** amazed
*/

#ifndef AMAZED_H_
    #define AMAZED_H_
    #include "linked_list.h"
    #include "amazed_structs.h"

amazed_t *init_amazed(void);
void destroy_amazed(amazed_t *self);
void safe_free(void *ptr);
void free_array(char **arr);
void *error_return(int *error, void *ptr);

int is_comment(char *str);
room_type_t get_next_room_type(char *str);

int get_robots(char **line, amazed_t **amazed);

#endif /* !AMAZED_H_ */
