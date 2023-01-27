/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** library
*/

int my_getnbr(char const *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    for (; str[i] != '\0'; i++) {
        result = result * 10 + (str[i] - '0');
    }
    return sign * result;
}
