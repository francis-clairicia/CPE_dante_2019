/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** main.c
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac != 2 || av == NULL || av[1] == NULL)
        return 84;
    if (solver(av[1]) == 84)
        return 84;
    return 0;
}