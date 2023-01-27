/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** task06
*/

int my_strlen(char const *str);

int my_strcmp (char const *s1, char const *s2)
{
    int cnt_s1 = 0;
    int cnt_s2 = 0;
    int len_s2 = my_strlen(s2);

    while (s1[cnt_s1] == s2[cnt_s2]) {
        cnt_s1++;
        cnt_s2++;
    }
    if (cnt_s1 - 1 == len_s2)
        return (0);
    if (s1[cnt_s1] - s2[cnt_s2] < 0)
        return (-1);
    if (s1[cnt_s1] - s2[cnt_s2] > 0)
        return (1);
    return (84);
}
