/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** splits a string into words
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int is_char_splittable(char c, char split)
{
    if (c == split) {
        return (1);
    }
    return (0);
}

int num_words_split(char const *str, int i, int cnt, char split)
{
    while (str[i]) {
        if (is_char_splittable(str[i], split) == 0)
            cnt++;
        i++;
        if (is_char_splittable(str[i], split) == 1)
            break;
    }
    return (cnt == 0 ? 1 : cnt);
}

int string_split(char const *str, char split)
{
    int i = 0;
    int cnt_3 = 1;
    while (str[i] && str[i +1]) {
        if (is_char_splittable(str[i], split) == 0
            && is_char_splittable(str[i + 1], split) == 1)
            cnt_3++;
        i++;
    }
    return (cnt_3);
}

char **my_split(char const *str, char split)
{
    int j = 0;
    int cnt = string_split(str, split);
    int cnt_2 = 0;
    int cnt_3;
    char **arr = malloc(((1 +cnt) * sizeof(char*)));
    for (int i = 0; i <= cnt; i++){
        arr[i] = NULL;
    }
    while (cnt_2 < cnt) {
        cnt_3 = 0;
        arr[cnt_2] =
                malloc(sizeof(char) * num_words_split(str, j, cnt, split));
        arr[cnt_2][0] = '\0';
        while (str[j] && is_char_splittable(str[j], split) == 0) {
            arr[cnt_2][cnt_3++] = str[j++];
        }
        arr[cnt_2++][cnt_3] = '\0';
        j++;
    }
    return (arr);
}
