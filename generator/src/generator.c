/*
** EPITECH PROJECT, 2019
** generator
** File description:
** generator.c
*/

#include <stddef.h>
#include <unistd.h>
#include "maze_generator.h"

int maze_generator(int width, int height, bool perfect_maze)
{
    if (width <= 0 || height <= 0)
        return (84);
    sidewinder_algo(width, height, perfect_maze);
    return (0);
}