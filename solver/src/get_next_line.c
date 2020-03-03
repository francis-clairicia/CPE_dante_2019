/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** read_and_display_read_line
*/

#include "get_next_line.h"
#include <string.h>

char *my_realloc(char *str)
{
    int count = 0;
    int size = strlen(str) + 3;
    char *tmp = malloc(sizeof(char) * size);

    if (tmp != NULL) {
        while (count != size - 2) {
            tmp[count] = str[count];
            count++;
        }
        tmp[count + 1] = '\0';
        free(str);
    }
    return (tmp);
}

char read_the_line(int fd)
{
    static int counter = 0;
    static char buff[READ_SIZE];
    static char *tmp = NULL;
    char c = '\0';

    if (counter == 0 && counter != -1) {
        counter = read(fd, buff, READ_SIZE);
        if (strlen(buff) == 0 || counter == 0)
            return ('\0');
        tmp = buff;
    }
    counter--;
    c = *tmp;
    tmp++;
    return (c);

}

char *ret(int i, char c, char *line)
{
    line[i] = '\0';
    if (!c) {
        if (line && strlen(line) > 1) {
            return (line);
        } else {
            free(line);
            return (NULL);
        }
    }
    return (line);
}

char *get_next_line(int fd)
{
    int i = 0;
    char c = '\0';
    char *line = malloc(sizeof(char *) * 3);

    if (line == NULL || fd == -1 || READ_SIZE <= 0)
        return (NULL);
    c = read_the_line(fd);
    while (c && c != '\n') {
        line[i] = c;
        line[i + 1] = '\0';
        line = my_realloc(line);
        c = read_the_line(fd);
        i++;
    }
    return (ret(i, c, line));
}