/*
** EPITECH PROJECT, 2022
** is_float
** File description:
** handle the precision
*/

#include <stdbool.h>
#include <stdio.h>

bool is_float(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '.') {
            return (true);
        }
        i++;
    }
    return (false);
}
