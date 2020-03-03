/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** path_finder.c
*/

#include "my.h"

char check_pos_exist(maze_t maze, int posx, int posy)
{
    if (posx >= maze.size_x || posx < 0 || posy >= maze.size_y || posy < 0) {
        return ('X');
    }
    return (maze.maze[posx][posy]);
}

char **check_no_way(maze_t maze, int posx, int posy)
{
    char move1 = check_pos_exist(maze, posx + 1, posy);
    char move2 = check_pos_exist(maze, posx, posy + 1);
    char move3 = check_pos_exist(maze, posx, posy - 1);
    char move4 = check_pos_exist(maze, posx - 1, posy);

    if (posx == maze.size_x - 1 && posy == maze.size_y - 1) {
        maze.maze[maze.size_x - 1][maze.size_y - 1] = 'o';
        return maze.maze;
    }
    if (move1 != '*' && move2 != '*' && move3 != '*' && move4 != '*') {
        if (move3 == 'o') {
            maze.maze[posx][posy] = 'N';
            path_finder(maze, posx, posy - 1);
        }
        if (move4 == 'o') {
            maze.maze[posx][posy] = 'N';
            path_finder(maze, posx - 1, posy);
        }
        if (move1 == 'o') {
            maze.maze[posx][posy] = 'N';
            path_finder(maze, posx + 1, posy);
        }
        if (move2 == 'o') {
            maze.maze[posx][posy] = 'N';
            path_finder(maze, posx, posy + 1);
        }
    } else {
        maze.maze[posx][posy] = 'o';
    }    
    return (maze.maze);
}

maze_t path_finder(maze_t maze, int posx, int posy)
{
    char move1 = check_pos_exist(maze, posx, posy + 1);
    char move2 = check_pos_exist(maze, posx + 1, posy);
    char move3 = check_pos_exist(maze, posx - 1, posy);
    char move4 = check_pos_exist(maze, posx, posy - 1);

    if (posx != maze.size_x - 1 || posy != maze.size_y) {
        maze.maze = check_no_way(maze, posx, posy);
        if (maze.maze[maze.size_x -1][maze.size_y - 1] == 'o')
            return maze;
        if (move1 == '*' && maze.maze[maze.size_x -1][maze.size_y - 1] != 'o') {
            path_finder(maze, posx, posy + 1);
        }
        if (move2 == '*' && maze.maze[maze.size_x -1][maze.size_y - 1] != 'o') {
            path_finder(maze, posx + 1, posy);
        }
        if (move3 == '*' && maze.maze[maze.size_x -1][maze.size_y - 1] != 'o') {
            path_finder(maze, posx - 1, posy);
        }
        if (move4 == '*' && maze.maze[maze.size_x -1][maze.size_y - 1] != 'o') {
            path_finder(maze, posx, posy - 1);
        }
    }
    return (maze);
}