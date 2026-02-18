/*
** EPITECH PROJECT, 2026
** G-CPE-200-MPL-2-1-amazed-2
** File description:
** amazed
*/

#ifndef AMAZED_H_
    #define AMAZED_H_
    #include "linked_lists.h"
    #include "amazed_structs.h"

amazed_t *init_amazed(void);
void destroy_amazed(amazed_t *self);
void safe_free(void *ptr);
void free_array(char **arr);
void *error_return(int *error, void *ptr);

#endif /* !AMAZED_H_ */
