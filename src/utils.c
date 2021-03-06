/*
** EPITECH PROJECT, 2020
** utils.c
** File description:
** utilitary fucntions source file
*/

#include "../include/navy.h"

int my_getnbr(char *str)
{
    int i = 0;
    int sign = 1;
    int	tmp = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    for (; str[i] != '\0'; ++i) {
        tmp = tmp * 10 + str[i] - '0';
    }
    return (tmp * sign);
}

char *my_strdup(char const *src)
{
    char *str;
    int copy = 0;
    int size = 0;
    size = my_strlen(src);
    str = malloc(size);
    while (src[copy] != '\0') {
        str[copy] = src[copy];
        copy++;
    }
    str[copy] = '\0';
    return (str);
}