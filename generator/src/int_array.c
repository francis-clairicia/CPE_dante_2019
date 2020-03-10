/*
** EPITECH PROJECT, 2019
** generator
** File description:
** int_array.c
*/

#include <stdlib.h>
#include <string.h>
#include "maze_generator.h"

void my_free_int_array(int **array)
{
    int i = 0;

    if (array == NULL)
        return;
    while (array[i] != NULL) {
        free(array[i]);
        i += 1;
    }
    free(array);
}

int **create_int_array(int width, int height)
{
    int **array = malloc(sizeof(int *) * (height + 1));
    int i = 0;

    if (array == NULL)
        return (NULL);
    for (i = 0; i < height; i += 1) {
        array[i] = malloc(sizeof(int) * (width + 1));
        if (array[i] == NULL) {
            my_free_int_array(array);
            return (NULL);
        }
        memset(array[i], 0, sizeof(int) * (width + 1));
    }
    array[height] = NULL;
    return (array);
}