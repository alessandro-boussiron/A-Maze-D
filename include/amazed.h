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
    #define NO_MOVE_CODE (int)(42)

amazed_t *init_amazed(void);
void destroy_amazed(amazed_t *self);
void safe_free(void *ptr);
void free_array(char **arr);
void *error_return(int *error, void *ptr);

int is_comment(char *str);
int is_command(char *str);
int is_valid_name(char *str);
int is_valid_number(char *str);
int is_tunnel(char *str);
room_type_t next_room_type(char *str);

int get_robots(char **line, amazed_t **amazed);
int get_rooms(char **line, amazed_t **amazed);
int get_tunnel(char *line, amazed_t **amazed);
int get_next_room_types(char **line, amazed_t **amazed);
int link_two_rooms(linked_list_t *ll, char *roomname1, char *roomname2);
int print_robot_move(int robot_number, char *room_number);

int dump_parsed_processes(amazed_t **amazed);
amazed_room_t *create_room(room_type_t type, char **params, int robots_count);

amazed_room_t *get_end_room(amazed_t *amazed);
amazed_room_t *get_start_room(amazed_t *amazed);

int set_weight(amazed_t *amazed);
int check_integrity(amazed_t *amazed);

int next_gen(amazed_t *amazed, robot_t **robots);

int solve_maze(amazed_t *amazed);

#endif /* !AMAZED_H_ */
