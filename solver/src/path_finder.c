/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** path_finder.c
*/

#include "my.h"

void choose_back_move(maze_t *maze, int *posx, int *posy, char *move)
{
    int (*find_move[])(maze_t *, int *, int *) = {back_three, back_four, \
    back_one, back_two};
    int pass = 0;
    int i = 0;

    while (pass == 0) {
        if (move[i] == 'o' && maze->maze[maze->size_x - 1] \
        [maze->size_y - 1] != 'o')
            pass = find_move[i](maze, posx, posy);
        i++;
    }
}

int win_condition(maze_t *maze, int *posx, int *posy, char *move)
{
    if (*posx == maze->size_x - 1 && *posy == maze->size_y - 1) {
        maze->maze[maze->size_x - 1][maze->size_y - 1] = 'o';
        free(move);
        return 1;
    }
    return 0;
}

int check_no_way(maze_t *maze, int *posx, int *posy)
{
    char *move = create_back(maze, *posx, *posy);

    if (win_condition(maze, posx, posy, move) == 1)
        return 1;
    if (move[0] != '*' && move[1] != '*' && move[2] != '*' && \
    move[3] != '*') {
        if (move[0] != 'o' && move[1] != 'o' && move[2] != 'o' && \
        move[3] != 'o') {
            free(move);
            return 84;
        }
        choose_back_move(maze, posx, posy, move);
        free(move);
        return 1;
    } else {
        maze->maze[*posx][*posy] = 'o';
        free(move);
        return 0;
    }
}

int find_move(maze_t *maze, int *posx, int *posy, char *move)
{
    int (*find_move[])(maze_t *, int *, int *) = {move_one, move_two, \
    move_three, move_four};
    int pass = 0;
    int i = 0;

    pass = check_no_way(maze, posx, posy);
    if (maze->maze[maze->size_x -1][maze->size_y - 1] == 'o' || pass == 84) {
        free(move);
        return 1;
    }
    while (pass == 0) {
        if (move[i] == '*')
            pass = find_move[i](maze, posx, posy);
        i++;
    }
    return 0;
}

maze_t path_finder(maze_t maze, int posx, int posy)
{
    char *move = create_moves(&maze, posx, posy);

    while ((posx != maze.size_x - 1 || posy != maze.size_y) && move != NULL) {
        if (find_move(&maze, &posx, &posy, move) == 1)
            return maze;
        free(move);
        move = create_moves(&maze, posx, posy);
    }
    return (maze);
}