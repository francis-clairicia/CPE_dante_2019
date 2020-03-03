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

#endif
