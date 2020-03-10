/*
** EPITECH PROJECT, 2019
** generator
** File description:
** sidewinder.c
*/

#include <stdlib.h>
#include <string.h>
#include "maze_generator.h"

static char **finalize_maze(char **maze, int width, int height, bool perfect)
{
    int last_row = height - 1;
    int last_col = width - 1;

    maze[last_row][last_col] = FREE_SPACE;
    if (width % 2 == 0 && height % 2 == 0) {
        last_col -= 1;
        if (last_col >= 0)
            maze[last_row][last_col] = FREE_SPACE;
    }
    if (perfect)
        return (perfect_sidewinder_maze(maze, width, height));
    return (maze);
}

static void setup_grid(int **grid, int row, int width)
{
    int col = 0;
    int start = 0;
    int weight = 2;
    int cell = 0;

    for (col = 0; col < width; col += 1) {
        if (row > 0 && ((col + 1) == width || (rand() % weight) == 0)) {
            cell = start + (rand() % (col - start + 1));
            grid[row][cell] |= N;
            grid[row - 1][cell] |= S;
            start = col + 1;
        } else if (col + 1 < width) {
            grid[row][col] |= E;
            grid[row][col + 1] |= W;
        }
    }
}

char **sidewinder_algo(int width, int height, bool perfect_maze)
{
    int grid_width = (width + 1) / 2;
    int grid_height = (height + 1) / 2;
    char **maze = create_word_array(width, height);
    int **grid = create_int_array(grid_width, grid_height);
    int row = 0;

    if (maze == NULL || grid == NULL) {
        my_free_word_array(maze);
        my_free_int_array(grid);
        return (NULL);
    }
    for (row = 0; maze[row] != NULL; row += 1)
        memset(maze[row], ' ', width);
    for (row = 0; grid[row] != NULL; row += 1)
        setup_grid(grid, row, grid_width);
    generate_maze(maze, grid, grid_width, grid_height);
    my_free_int_array(grid);
    return (finalize_maze(maze, width, height, perfect_maze));
}