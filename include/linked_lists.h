/*
** EPITECH PROJECT, 2025
** linked_list.h
** File description:
** linked list private lib
*/

#ifndef LINKED_LIST_H
    #define LINKED_LIST_H
    #include <stdlib.h>

typedef struct node
{
    int hash;
    char *value;

    struct node *prev;
    struct node *next;
} node_t;

typedef struct ll {
    size_t size;
    node_t *head;
    node_t *tail;
    void (*app_at)(struct ll **itself, char *data, int hash, size_t index);
    void (*rm_at)(struct ll **itself, size_t index);
    char *(*search_hash)(struct ll **itself, int hash);
    void (*clear)(struct ll **itself);
    void (*destroy)(struct ll **itself);
} linked_list_t;

linked_list_t *linked_list_create(void);
#endif // LINKED_LIST_H