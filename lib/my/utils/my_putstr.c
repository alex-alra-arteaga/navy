/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** task02
*/
#include "../../../includes/my.h"

int my_putstr(char const *str)
{
    int i;
    i = 0;
    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
