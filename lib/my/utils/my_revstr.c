/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** write a function that reverses a string
*/
#include "../../../includes/my.h"

char *my_revstr(char* str)
{
    int length = my_strlen(str);
    char temp;

    for (int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    return (str);
}
