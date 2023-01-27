/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** allocates memory and copies the string given as argument
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../../includes/my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    int len = my_strlen(src);
    if (src[0] == '\0') {
        return (NULL);
    }
    char *string = malloc((len +1) * sizeof(char));
    string[0] = '\0';
    while (src[i]) {
        string[i] = src[i];
        i++;
    }
    string[i] = '\0';
    return (string);
}
