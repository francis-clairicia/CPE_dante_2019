/*
** EPITECH PROJECT, 2019
** generator
** File description:
** free_maze.c
*/

#include <stdlib.h>
#include "maze_generator.h"

void free_maze(char **maze, int height)
{
    int i = 0;

    if (maze == NULL)
        return;
    for (i = 0; i < height; i += 1) {
        if (maze[i] != NULL)
            free(maze[i]);
    }
    free(maze);
}