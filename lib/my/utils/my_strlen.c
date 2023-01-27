/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** task03
*/

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i]) {
        i++;
    }
    return (i);
}
