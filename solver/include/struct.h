/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct node_t node_t;
struct node_t {
    int x;
    int y;
    node_t *next;
};

typedef struct list_t list_t;
struct list_t {
    node_t *first;
};

typedef struct maze_t {
    char **maze;
    int size_x;
    int size_y;
    list_t *pos;
} maze_t;

#endif