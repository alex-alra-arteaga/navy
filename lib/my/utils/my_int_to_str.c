/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** library
*/

#include "stdlib.h"
#include "../../../includes/my.h"

char *conversion_n_redirection(int temp, int i, char *str, int num)
{
    while (temp > 0) {
        str[i++] = temp % 10 + '0';
        temp /= 10;
    }
    str[i] = '\0';
    if (num > 0) {
        str = my_revstr(str);
    }
    return (str);
}

char *my_int_to_str(int num)
{
    int i = 0;
    int j = 1;
    char* str;
    int temp = num;
    int temp2 = num;

    while (temp2 > 10) {
        temp2 /= 10;
        j++;
    }
    str = malloc(sizeof(char) * j + 2);
    if (temp < 0) {
        str[i++] = '-';
        temp = -temp;
    }
    str = conversion_n_redirection(temp, i, str, num);
    return str;
}
