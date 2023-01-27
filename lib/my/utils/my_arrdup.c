/*
** EPITECH PROJECT, 2022
** my_arrdup.c
** File description:
** my_strdup but for arrays
*/

#include "../../../includes/my.h"

char **my_arrdup(char **src, int size)
{
    char **str_array;
    int lines = size;
    int l = 0;

    if (src != NULL || src[0][0] == '\0')
        return (NULL);
    str_array = malloc(sizeof(char*) * lines + sizeof(char *));
    while (l < lines) {
        str_array[l] = NULL;
        str_array[l] = my_strdup(src[l]);
        l++;
    }
    str_array[l] = NULL;
    return (str_array);
}
