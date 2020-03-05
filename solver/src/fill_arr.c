/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** fill_arr.c
*/

#include "my.h"
#include <string.h>

int valid_line(char *buff)
{
    int i = 0;

    while (buff[i] != '\0') {
        if (buff[i] != 'X' && buff[i] != '*')
            return 84;
        i++;
    }
    return 0;
}

char **fill_arr(int fd)
{
    char **maze = NULL;
    char *buff = NULL;
    int x = 0;
    int size = 0;

    if (fd == -1)
        return NULL;
    buff = get_next_line(fd);
    size = strlen(buff);
    while (buff != NULL) {
        if ((int)strlen(buff) != size || valid_line(buff) != 0)
            return NULL;
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