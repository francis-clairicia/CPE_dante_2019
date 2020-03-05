/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** path_finder_ptr_func.c
*/

#include "my.h"

int move_one(maze_t *maze, int *posx, int *posy)
{
    node_t *tmp = NULL;

    tmp = create_node(*posx, *posy);
    put_node_start(maze->pos, tmp);
    *posy = *posy + 1;
    return 1;
}

int move_two(maze_t *maze, int *posx, int *posy)
{
    node_t *tmp = NULL;

    tmp = create_node(*posx, *posy);
    put_node_start(maze->pos, tmp);
    *posx = *posx + 1;
    return 1;
}

int move_three(maze_t *maze, int *posx, int *posy)
{
    node_t *tmp = NULL;

    tmp = create_node(*posx, *posy);
    put_node_start(maze->pos, tmp);
    *posx = *posx - 1;
    return 1;
}

int move_four(maze_t *maze, int *posx, int *posy)
{
    node_t *tmp = NULL;

    tmp = create_node(*posx, *posy);
    put_node_start(maze->pos, tmp);
    *posy = *posy - 1;
    return 1;
}