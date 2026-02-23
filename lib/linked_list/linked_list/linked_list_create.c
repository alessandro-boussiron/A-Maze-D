/*
** EPITECH PROJECT, 2025
** linked_list_create.c
** File description:
** create a linked list
*/
#include "../node_ar.h"
#include "../node_g.h"
#include "../linked_list.h"

static void init_methods(linked_list_t *ll)
{
    ll->app_at = add_node;
    ll->rm_at = remove_node;
    ll->get = get_node;
    ll->set_dstr = linked_list_set_dstr;
    ll->apply = linked_list_apply;
    ll->search = linked_list_search;
    ll->dump = linked_list_dump;
    ll->clear = linked_list_clear;
    ll->destroy = linked_list_destroy;
    ll->biggest = linked_list_biggest;
    ll->lowest = linked_list_lowest;
    ll->search_nb = linked_list_search_nb;
}

linked_list_t *linked_list_create(void)
{
    linked_list_t *ll = malloc(sizeof(linked_list_t));

    if (!ll)
        return NULL;
    ll->head = NULL;
    ll->tail = NULL;
    ll->free_node = NULL;
    ll->size = 0;
    init_methods(ll);
    return ll;
}
