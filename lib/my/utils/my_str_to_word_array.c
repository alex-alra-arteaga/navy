/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** splits a string into words
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int is_char_alpha(char c)
{
    if ((c > '0') && ((c > '`' && c < '{')
    || (c > '@' && c < '[') || c == '_')) {
        return (0);
    }
    return (1);
}

int num_words(char const *str, int i, int cnt)
{
    while (str[i]) {
        if (is_char_alpha(str[i]) == 0)
            cnt++;
        i++;
        if (is_char_alpha(str[i]) == 1)
            break;
    }
    return (cnt);
}

int string(char const *str)
{
    int i = 1;
    int cnt_3 = 0;
    while (str[i]) {
        if (is_char_alpha(str[i]) == 0
        && is_char_alpha(str[i +1]) == 1)
            cnt_3++;
        i++;
    }
    return (cnt_3);
}

char **my_str_to_word_array(char const *str)
{
    int j = 0;
    int cnt = string(str);
    int cnt_2 = 0;
    int cnt_3;
    char **arr = malloc(((1 +cnt) * sizeof(char*)));

    for (int i = 0; i <= cnt; i++){
        arr[i] = NULL;
    }
    while (cnt_2 < cnt) {
        cnt_3 = 0;
        arr[cnt_2] = malloc(sizeof(char) * num_words(str, j, cnt) +1);
        arr[cnt_2][0] = '\0';
        while (str[j] && is_char_alpha(str[j]) == 0) {
            arr[cnt_2][cnt_3++] = str[j++];
        }
        arr[cnt_2++][cnt_3] = '\0';
        j++;
    }
    return (arr);
}
