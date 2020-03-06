/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** free.c
*/

#include "my.h"

void free_arr(char **arr)
{
    int x = 0;

    while (arr[x] != NULL) {
        free(arr[x]);
        x += 1;
    }
    free(arr);
}

void free_linked_list(list_t *list)
{
    node_t *tmp = list->first;
    node_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(list);
}

void free_maze(maze_t maze)
{
    free_arr(maze.maze);
    free_linked_list(maze.pos);
}