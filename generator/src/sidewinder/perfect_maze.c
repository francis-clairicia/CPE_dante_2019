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

    for (i = 0; i < 2; i += 1) {
        col += offset;
        if (col < 0 || col >= width)
            return;
        if (line[col] == WALL)
            return;
    }
    line[col - offset] = WALL;
}

void perfect_sidewinder_maze(char *line, int width)
{
    int col = 0;

    for (col = 0; col < width; col += 2) {
        check_side(line, col, width, -1);
        check_side(line, col, width, 1);
    }
}