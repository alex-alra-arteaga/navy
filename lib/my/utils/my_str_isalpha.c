/*
** EPITECH PROJECT, 2022
** my string is alpha
** File description:
** check string
*/

int my_strlen(char const *str);

int my_str_isalpha(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if ((str[i] < 97 || str[i] > 122) &&
        (str[i] < 65 || str[i] > 90) && str[i] != ' '
        && str[my_strlen(str) - 1] != '.') {
            return (0);
        }
        i++;
    }
    return (1);
}
