/*
** EPITECH PROJECT, 2019
** generator
** File description:
** generate_maze.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "maze_generator.h"

static void set_char_to_maze(char **maze, char c, vector_t pos, vector_t size)
{
    char first = FREE_SPACE;
    char second = FREE_SPACE;

    if (c != ' ')
        second = WALL;
    if (c == '|')
        first = WALL;
    if (pos.y < size.y && pos.x < size.x) {
        maze[pos.y][pos.x] = first;
        if (maze[pos.y + 1] != NULL)
            maze[pos.y + 1][pos.x] = second;
        if (pos.y - 1 >= 0 && c == '|')
            maze[pos.y - 1][pos.x] = WALL;
    }
}

static void fill_first_col(char **maze, char **grid,
    vector_t pos, vector_size_t size)
{
    int cell = grid[pos.y][pos.x];
    vector_t maze_pos = {2 * pos.x, 2 * pos.y};

    if ((cell == 0 && pos.y + 1 < size.grid.y && grid[pos.y + 1][pos.x] == 0)
    || (cell & S) != 0)
        set_char_to_maze(maze, ' ', maze_pos, size.maze);
    else
        set_char_to_maze(maze, '_', maze_pos, size.maze);
}

static void fill_second_col(char **maze, char **grid, vector_t pos,
    vector_size_t size)
{
    int cell = grid[pos.y][pos.x];
    vector_t maze_pos = {2 * pos.x + 1, 2 * pos.y};

    if ((cell == 0 && pos.x + 1 < size.grid.x && grid[pos.y][pos.x + 1] == 0)) {
        if (pos.y + 1 < size.grid.y
        && (grid[pos.y + 1][pos.x] == 0 || grid[pos.y + 1][pos.x + 1] == 0))
            set_char_to_maze(maze, ' ', maze_pos, size.maze);
        else
            set_char_to_maze(maze, '_', maze_pos, size.maze);
    } else if ((cell & E) != 0) {
        if (((cell | grid[pos.y][pos.x + 1]) & S) != 0)
            set_char_to_maze(maze, ' ', maze_pos, size.maze);
        else
            set_char_to_maze(maze, '_', maze_pos, size.maze);
    } else
        set_char_to_maze(maze, '|', maze_pos, size.maze);
}

static bool create_new_lines(char **maze, int width, int height)
{
    int row = 0;

    for (row = 0; row < 4 && row < height; row += 1) {
        maze[row] = malloc(sizeof(char) * (width + 1));
        if (maze[row] == NULL) {
            my_free_word_array(maze);
            return (false);
        }
        maze[row][width] = '\0';
    }
    return (true);
}

void generate_maze(char **maze, char **grid, vector_size_t size, bool perfect)
{
    vector_t pos = {0, 0};
    int row = 0;

    if (maze == NULL || grid == NULL
    || !create_new_lines(maze, size.maze.x, size.maze.y))
        return;
    for (pos.y = 0; grid[pos.y] != NULL; pos.y += 1) {
        print_maze(maze, size.maze.x, size.maze.y, row);
        for (pos.x = 0; pos.x < size.grid.x; pos.x += 1) {
            fill_first_col(maze, grid, pos, size);
            fill_second_col(maze, grid, pos, size);
        }
        if (perfect && row + 1 < size.maze.y)
            perfect_sidewinder_maze(maze[row + 1], size.maze.x);
        row += 2;
    }
    while (print_maze(maze, size.maze.x, size.maze.y, row++));
}