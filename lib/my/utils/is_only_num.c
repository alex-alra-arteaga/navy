/*
** EPITECH PROJECT, 2022
** is_only_num
** File description:
** handle the width
*/

#include <stdbool.h>


bool is_only_num(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if ((str[i] < 48 || str[i] > 57) &&
        (str[i] != '.')) {
        return (false);
    }
    i++;
    }
    return (true);
}
