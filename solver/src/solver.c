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
#include <string.h>

int print_array(char **arr)
{
    int x = 0;

    while (arr[x] != NULL) {
        printf("%s\n", arr[x]);
        x++;
    }
    return 0;
}

int count_row(char **arr)
{
    int x = 0;

    while (arr[x] != NULL)
        x++;
    return (x);
}

maze_t remove_n(maze_t maze)
{
    int x = 0;
    int y = 0;

    while (maze.maze[x] != NULL) {
        while (maze.maze[x][y] != '\0') {
            if (maze.maze[x][y] == 'N')
                maze.maze[x][y] = '*';
            y++;
        }
        x++;
        y = 0;
    }
    return maze;
}

int solver(char *pathname)
{
    int fd = open(pathname, O_RDONLY);
    maze_t maze;

    if (fd == -1)
        return 84;
    maze.maze = fill_arr(fd);
    if (maze.maze == NULL)
        return 84;
    maze.size_x = count_row(maze.maze);
    maze.size_y = strlen(maze.maze[0]);
    maze = path_finder(maze, 0, 0);
    maze = remove_n(maze);
    if (print_array(maze.maze) == 84)
        return 84;
    return 0;
}