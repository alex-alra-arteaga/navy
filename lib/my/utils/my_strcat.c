/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** Concatenates two strings
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int cnt_1 = 0;
    int cnt_2 = 0;

    cnt_1 = my_strlen(dest);
    while (src[cnt_2]) {
        dest[cnt_1] = src[cnt_2];
        cnt_1++;
        cnt_2++;
    }
    dest[cnt_1] = '\0';
    return (dest);
}
