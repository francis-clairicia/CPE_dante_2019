/*
** EPITECH PROJECT, 2019
** generator
** File description:
** maze_generator.h
*/

#ifndef HEADER_MAZE_GENERATOR
#define HEADER_MAZE_GENERATOR

#include <stdbool.h>

typedef struct vector
{
    int x;
    int y;
} vector_t;

typedef struct size
{
    vector_t maze;
    vector_t grid;
} vector_size_t;

enum DIRECTIONS
{
    N = 1 << 0,
    S = 1 << 1,
    E = 1 << 2,
    W = 1 << 3
};

#define FREE_SPACE '*'
#define WALL 'X'

int maze_generator(int width, int height, bool perfect_maze);

void sidewinder_algo(int width, int height, bool perfect_maze);
void generate_maze(char **maze, char **grid, vector_size_t size, bool perfect);
void perfect_sidewinder_maze(char *line, int width);
bool print_maze(char **maze, int width, int height, int actual_row);
void free_maze(char **maze, int height);

char **create_word_array(int width, int height);
void my_free_word_array(char **array);
int my_array_len(char * const *array);

#endif