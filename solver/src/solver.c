/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** solver.c
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int print_array(char **arr)
{
    int x = 0;

    while (arr[x] != NULL) {
        printf("%s\n", arr[x]);
        x++;
    }
    return 0;
}

int solver(char *pathname)
{
    int fd = open(pathname, O_RDONLY);
    char **maze = NULL;

    if (fd == -1)
        return 84;
    maze = fill_arr(fd);
    if (maze == NULL)
        return 84;
    //maze = path_find(maze);
    if (print_array(maze) == 84)
        return 84;
    return 0;
}