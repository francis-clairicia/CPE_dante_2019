/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** check_no_way_ptr_func.c
*/

#include "my.h"

int back_one(maze_t *maze, int *posx, int *posy)
{
    node_t *tmp = NULL;

    *posx = maze->pos->first->x;
    *posy = maze->pos->first->y;
    tmp = maze->pos->first;
    maze->pos->first = maze->pos->first->next;
    free(tmp);
    maze->maze[*posx][*posy + 1] = 'N';
    return 1;
}

int back_two(maze_t *maze, int *posx, int *posy)
{
    node_t *tmp = NULL;

    *posx = maze->pos->first->x;
    *posy = maze->pos->first->y;
    tmp = maze->pos->first;
    maze->pos->first = maze->pos->first->next;
    free(tmp);
    maze->maze[*posx + 1][*posy] = 'N';
    return 1;
}

int back_three(maze_t *maze, int *posx, int *posy)
{
    node_t *tmp = NULL;

    *posx = maze->pos->first->x;
    *posy = maze->pos->first->y;
    tmp = maze->pos->first;
    maze->pos->first = maze->pos->first->next;
    free(tmp);
    maze->maze[*posx - 1][*posy] = 'N';
    return 1;
}

int back_four(maze_t *maze, int *posx, int *posy)
{
    node_t *tmp = NULL;

    *posx = maze->pos->first->x;
    *posy = maze->pos->first->y;
    tmp = maze->pos->first;
    maze->pos->first = maze->pos->first->next;
    free(tmp);
    maze->maze[*posx][*posy - 1] = 'N';
    return 1;
}