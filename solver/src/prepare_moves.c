/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** prepare_moves.c
*/

#include "my.h"

char check_pos_exist(maze_t maze, int posx, int posy)
{
    if (posx >= maze.size_x || posx < 0 || posy >= maze.size_y || posy < 0) {
        return ('X');
    }
    return (maze.maze[posx][posy]);
}

char *create_back(maze_t *maze, int posx, int posy)
{
    char *move = malloc(sizeof(char) * 5);

    if (move != NULL) {
        move[0] = check_pos_exist(*maze, posx + 1, posy);
        move[1] = check_pos_exist(*maze, posx, posy + 1);
        move[2] = check_pos_exist(*maze, posx, posy - 1);
        move[3] = check_pos_exist(*maze, posx - 1, posy);
        move[4] = '\0';
    }
    return move;
}

char *create_moves(maze_t *maze, int posx, int posy)
{
    char *move = malloc(sizeof(char) * 5);

    if (move != NULL) {
        move[0] = check_pos_exist(*maze, posx, posy + 1);
        move[1] = check_pos_exist(*maze, posx + 1, posy);
        move[2] = check_pos_exist(*maze, posx - 1, posy);
        move[3] = check_pos_exist(*maze, posx, posy - 1);
        move[4] = '\0';
    }
    return move;
}