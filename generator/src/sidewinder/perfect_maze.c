/*
** EPITECH PROJECT, 2019
** generator
** File description:
** perfect_maze.c
*/

#include "maze_generator.h"

static void check_side(char *line, int col, int width, int offset)
{
    int i = 0;

    for (i = 0; i < 2; i += 2) {
        col += offset;
        if (col < 0 || col >= width)
            return;
        if (line[col] == WALL)
            return;
    }
    line[col - offset] = WALL;
}

char **perfect_sidewinder_maze(char **maze, int width, int height)
{
    int row = 0;
    int col = 0;

    for (row = 1; row < height; row += 2) {
        for (col = 0; col < width; col += 2) {
            check_side(maze[row], col, width, -1);
            check_side(maze[row], col + 1, width, 1);
        }
    }
    return (maze);
}