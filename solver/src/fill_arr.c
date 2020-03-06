/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** fill_arr.c
*/

#include "my.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

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

char **read_file(int fd, struct stat statbuf)
{
    char **maze = NULL;
    char *buff = get_next_line(fd);
    int size = strlen(buff);
    int x = 0;

    maze = malloc(sizeof(char *) * ((statbuf.st_size / size) + 1));
    while (buff != NULL) {
        if ((int)strlen(buff) != size || valid_line(buff) != 0) {
            free(buff);
            maze[x] = NULL;
            free_arr(maze);
            return NULL;
        }
        maze[x] = buff;
        buff = get_next_line(fd);
        x += 1;
    }
    maze[x] = NULL;
    return maze;
}

char **fill_arr(int fd)
{
    char **maze = NULL;
    struct stat statbuf;

    if (fd == -1)
        return NULL;
    fstat(fd, &statbuf);
    maze = read_file(fd, statbuf);
    if (maze[0][0] != '*') {
        free_arr(maze);
        return NULL;
    }
    return maze;
}