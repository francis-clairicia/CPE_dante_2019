/*
** EPITECH PROJECT, 2019
** generator
** File description:
** print_maze.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "maze_generator.h"

static void move_line(char **maze, int row, int height)
{
    if (row + 4 >= height)
        return;
    maze[row + 4] = maze[row];
    maze[row] = NULL;
}

static void print_end_of_maze(char *line, int width, int height)
{
    int last_col = width - 1;

    if (line == NULL)
        return;
    line[last_col] = FREE_SPACE;
    if (width % 2 == 0 && height % 2 == 0) {
        last_col -= 1;
        if (last_col >= 0)
            line[last_col] = FREE_SPACE;
    }
    write(1, line, width);
}

bool print_maze(char **maze, int width, int height, int actual_row)
{
    static int row = 0;

    if (maze == NULL)
        return (false);
    while (row < actual_row - 1 && row < height) {
        if (row + 1 < height) {
            write(1, maze[row], width);
            write(1, "\n", 1);
            move_line(maze, row, height);
        } else {
            print_end_of_maze(maze[row], width, height);
        }
        row += 1;
    }
    return (row < height);
}