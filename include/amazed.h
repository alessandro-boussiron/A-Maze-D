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
int is_command(char *str);
room_type_t next_room_type(char *str);

int get_robots(char **line, amazed_t **amazed);
int get_rooms(char **line, amazed_t **amazed);
int get_next_room_types(char **line, amazed_t **amazed);
int link_two_rooms(linked_list_t *ll, char *roomname1, char *roomname2);

amazed_room_t *create_room(room_type_t type, char **params, int robots_count);

#endif /* !AMAZED_H_ */
