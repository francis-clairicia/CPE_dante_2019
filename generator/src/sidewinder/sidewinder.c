/*
** EPITECH PROJECT, 2019
** generator
** File description:
** sidewinder.c
*/

#include <stdlib.h>
#include <string.h>
#include "maze_generator.h"

static void setup_grid(char **grid, int row, int width)
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

void sidewinder_algo(int width, int height, bool perfect_maze)
{
    vector_size_t size = {
        {width, height},
        {(width + 1) / 2, (height + 1) / 2}
    };
    char **maze = calloc(height + 1, sizeof(char *));
    char **grid = create_word_array(size.grid.x, size.grid.y);
    int row = 0;

    if (maze == NULL || grid == NULL) {
        free(maze);
        my_free_word_array(grid);
        return;
    }
    for (row = 0; grid[row] != NULL; row += 1)
        setup_grid(grid, row, size.grid.x);
    generate_maze(maze, grid, size, perfect_maze);
    free_maze(maze, height);
    my_free_word_array(grid);
}