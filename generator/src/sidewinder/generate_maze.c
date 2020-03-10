/*
** EPITECH PROJECT, 2019
** generator
** File description:
** generate_maze.c
*/

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "maze_generator.h"

static void set_char_to_maze(char **maze, char c, int row, int col)
{
    static int maze_size = -1;
    char first = FREE_SPACE;
    char second = FREE_SPACE;

    if (maze_size < 0)
        maze_size = my_array_len(maze);
    if (c != ' ')
        second = WALL;
    if (c == '|')
        first = WALL;
    if (row < maze_size && col < (int)strlen(maze[row])) {
        maze[row][col] = first;
        if (maze[row + 1] != NULL)
            maze[row + 1][col] = second;
        if (row - 1 >= 0 && c == '|')
            maze[row - 1][col] = WALL;
    }
}

static void fill_maze(char **maze, int **grid, vector_t pos, vector_t size)
{
    int cell = grid[pos.y][pos.x];

    if ((cell == 0 && pos.y + 1 < size.y && grid[pos.y + 1][pos.x] == 0)
    || (cell & S) != 0)
        set_char_to_maze(maze, ' ', 2 * pos.y, 2 * pos.x);
    else
        set_char_to_maze(maze, '_', 2 * pos.y,  2 * pos.x);
    if ((cell == 0 && pos.x + 1 < size.x && grid[pos.y][pos.x + 1] == 0)) {
        if (pos.y + 1 < size.y
        && (grid[pos.y + 1][pos.x] == 0 || grid[pos.y + 1][pos.x + 1] == 0))
            set_char_to_maze(maze, ' ', 2 * pos.y, 2 * pos.x + 1);
        else
            set_char_to_maze(maze, '_', 2 * pos.y,  2 * pos.x + 1);
    } else if ((cell & E) != 0) {
        if (((cell | grid[pos.y][pos.x + 1]) & S) != 0)
            set_char_to_maze(maze, ' ', 2 * pos.y, 2 * pos.x + 1);
        else
            set_char_to_maze(maze, '_', 2 * pos.y, 2 * pos.x + 1);
    } else
        set_char_to_maze(maze, '|', 2 * pos.y, 2 * pos.x + 1);
}

void generate_maze(char **maze, int **grid, int grid_width, int grid_height)
{
    vector_t pos = {0, 0};
    vector_t size = {grid_width, grid_height};

    for (pos.y = 0; maze != 0 && grid != 0 && grid[pos.y] != 0; pos.y += 1) {
        for (pos.x = 0; pos.x < grid_width; pos.x += 1)
            fill_maze(maze, grid, pos, size);
    }
}