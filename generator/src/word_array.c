/*
** EPITECH PROJECT, 2019
** generator
** File description:
** word_array.c
*/

#include <stdlib.h>
#include <string.h>

void my_free_word_array(char **array)
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

char **create_word_array(int width, int height)
{
    char **array = malloc(sizeof(char *) * (height + 1));
    int i = 0;

    if (array == NULL)
        return (NULL);
    for (i = 0; i < height; i += 1) {
        array[i] = malloc(sizeof(char) * (width + 1));
        if (array[i] == NULL) {
            my_free_word_array(array);
            return (NULL);
        }
        memset(array[i], 0, width + 1);
    }
    array[height] = NULL;
    return (array);
}

int my_array_len(char * const *array)
{
    int count = 0;

    if (array == NULL)
        return (0);
    while (array[count] != NULL)
        count += 1;
    return (count);
}