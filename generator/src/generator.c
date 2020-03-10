/*
** EPITECH PROJECT, 2019
** generator
** File description:
** generator.c
*/

#include <stddef.h>
#include <unistd.h>
#include "maze_generator.h"

static void print_map(char * const *map, int width)
{
    int y = 0;

    for (y = 0; map != NULL && map[y] != NULL; y += 1) {
        write(1, map[y], width);
        if (map[y + 1] != NULL)
            write(1, "\n", 1);
    }
}

int maze_generator(int width, int height, bool perfect_maze)
{
    char **map = sidewinder_algo(width, height, perfect_maze);

    if (map == NULL)
        return (84);
    print_map(map, width);
    my_free_word_array(map);
    return (0);
}