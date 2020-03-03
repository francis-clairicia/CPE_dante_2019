/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** fill_arr.c
*/

#include "my.h"
#include <string.h>

char **fill_arr(int fd)
{
    char **maze = NULL;
    char *buff = NULL;
    int x = 0;

    if (fd == -1)
        return NULL;
    buff = get_next_line(fd);
    while (buff != NULL) {
        maze = realloc(maze, sizeof(char *) * (x + 2));
        maze[x] = malloc(sizeof(char) * (strlen(buff) + 1));
        if (maze[x] == NULL)
            return NULL;
        maze[x] = buff;
        maze[x][strlen(buff)] = '\0';
        buff = get_next_line(fd);
        x++;
    }
    maze[x] = NULL;
    return maze;
}