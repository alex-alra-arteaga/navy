/*
** EPITECH PROJECT, 2022
** is_num.c
** File description:
** handle the width
*/

#include <stdbool.h>

bool is_num(char c)
{
    if (c > 47 && c < 58) {
        return (true);
    }
    return (false);
}
