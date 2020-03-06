/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include "struct.h"
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

//get_next_line.c
char *get_next_line(int fd);

//solver.c
int solver(char *pathname);

//fill_arr.c
char **fill_arr(int fd);

//path_finder.c
maze_t path_finder(maze_t maze, int posx, int posy);
char check_pos_exist(maze_t maze, int posx, int posy);

//path_finder_ptr_func.c
int move_one(maze_t *maze, int *posx, int *posy);
int move_two(maze_t *maze, int *posx, int *posy);
int move_three(maze_t *maze, int *posx, int *posy);
int move_four(maze_t *maze, int *posx, int *posy);

//check_no_way_ptr_func.c
int back_one(maze_t *maze, int *posx, int *posy);
int back_two(maze_t *maze, int *posx, int *posy);
int back_three(maze_t *maze, int *posx, int *posy);
int back_four(maze_t *maze, int *posx, int *posy);

//prepare_moves.c
char *create_back(maze_t *maze, int posx, int posy);
char *create_moves(maze_t *maze, int posx, int posy);

//use_list.c
list_t *create_list(void);
node_t *create_node(int x, int y);
node_t *put_node_start(list_t *list, node_t *node);

//free.c
void free_maze(maze_t maze);
void free_arr(char **arr);

#endif
