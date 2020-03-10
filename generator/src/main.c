/*
** EPITECH PROJECT, 2019
** generator
** File description:
** main.c
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "maze_generator.h"

static int my_str_isnum(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0') {
        if ((str[i] < '0') || (str[i] > '9'))
            return (0);
        i += 1;
    }
    return (1);
}

static int print_help(void)
{
    printf("%s\n", "USAGE");
    printf("\t%s\n\n", "./generator x y [perfect]");
    printf("%s\n", "DESCRIPTION");
    printf("\t%s\t\t%s\n", "x", "the width of the maze");
    printf("\t%s\t\t%s\n", "y", "the height of the maze");
    printf("\t%s\t\t%s\n", "perfect", "For anything as parameter, the maze will be considered");
    printf("\t\t\t%s\n", "as perfect. Imperfect othrewise");
    return (0);
}

int main(int ac, char *av[])
{
    srand(time(NULL));
    if (ac == 2 && strcmp(av[1], "-h") == 0)
        return (print_help());
    if (ac != 3 && ac != 4)
        return (84);
    if (!my_str_isnum(av[1]) || !my_str_isnum(av[2]))
        return (84);
    return (maze_generator(atoi(av[1]), atoi(av[2]), (ac == 4)));
}