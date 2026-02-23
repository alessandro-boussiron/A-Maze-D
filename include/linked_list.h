/*
** EPITECH PROJECT, 2025
** linked_list.h
** File description:
** linked list private lib
*/

#ifndef LINKED_LIST_H
    #define LINKED_LIST_H
    #include <stdlib.h>
    #define PUSH_START(ll, data) (ll->app_at(ll, data, 0))
    #define PUSH_END(ll, data) (ll->app_at(ll, data, ll->size))
    #define POP_START(ll) (ll->rm_at(ll, 0))
    #define POP_END(ll) (ll->rm_at(ll, ll->size - 1))

typedef struct node
{
    void *data;
    struct node *prev;
    struct node *next;
} node_t;

typedef struct ll
{
    //Atributs
    size_t size;
    node_t *head;
    node_t *tail;
    //Private
    void (*free_node)(void *data);
    //Methods
    void (*app_at)(struct ll *self, const void *data, size_t index);
    void (*rm_at)(struct ll *self, size_t index);
    void *(*get)(struct ll *self, size_t index);
    void (*set_dstr)(struct ll *self, void (*free_node)(void *data));
    void (*apply)(struct ll *self, void (*applier)(void *data));
    void *(*biggest)(struct ll *self, int (*algo)(void *data));
    void *(*lowest)(struct ll *self, int (*algo)(void *data));
    void *(*search)(struct ll *self, int (*algo)(void *data, void *to_find),
        void *to_find);
    int (*search_nb)(struct ll *self, int (*algo)(void *data, void *to_find),
        void *to_find);
    void (*dump)(struct ll *self, void (*dump_node)(void *data));
    void (*clear)(struct ll *self);
    void (*destroy)(struct ll **self);
} linked_list_t;
linked_list_t *linked_list_create(void);
#endif // LINKED_LIST_H
