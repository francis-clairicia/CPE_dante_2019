/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** use_list.c
*/

#include "my.h"

list_t *create_list(void)
{
    list_t *list = malloc(sizeof(list) * 1);

    if (list == NULL) {
        return (NULL);
    }
    list->first = NULL;
    return (list);
}

node_t *create_node(int x, int y)
{
    node_t *node = malloc(sizeof(node_t) * 1);

    if (node == NULL) {
        return (NULL);
    }
    node->x = x;
    node->y = y;
    node->next = NULL;
    return (node);
}

node_t *put_node_start(list_t *list, node_t *node)
{
    if (node == NULL || list == NULL) {
        return (NULL);
    }
    node->next = NULL;
    if (list->first == NULL) {
        list->first = node;
        return (node);
    }
    node->next = list->first;
    list->first = node;
    return (node);
}

node_t *put_node_end(list_t *list, node_t *node)
{
    node_t *tmp = NULL;

    if (node == NULL || list == NULL) {
        return (NULL);
    }
    node->next = NULL;
    if (list->first == NULL) {
        list->first = node;
        return (node);
    }
    tmp = list->first;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = node;
    return (node);
}