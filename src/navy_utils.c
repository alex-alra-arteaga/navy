/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** Sink the float simulator by terminal
*/

#include <stdio.h>
#include <stdlib.h>
#include "../includes/my.h"
#include <sys/ucontext.h>

i_s_t input_state(char *input)
{
    i_s_t i_st;
    char *allowed_char = my_strdup("ABCDEFGH");
    if (my_strlen(input) != 3)
        return (i_st = (i_s_t){.info = my_strdup("wrong_input"), .ok = false});
    for (int i = 0; allowed_char[i]; i++) {
        if (input[0] == allowed_char[i])
            break;
        if (i == 7)
            return (i_st = (i_s_t){
                .info = my_strdup("wrong_position"),
                .ok = false});
    }
    if (!is_num(input[1]))
        return (i_st = (i_s_t){.info = my_strdup("wrong_pos"), .ok = false});
    return (i_st = (i_s_t){.info = "ok", .ok = true});
}

int all_boats_hitted_p1(void)
{
    int cnt = 0;
    bool all_sinked = false;

    for (int i = 0; map.my_map[i] && !all_sinked; i++) {
        for (int j = 0; map.my_map[i][j] && !all_sinked; j++) {
            (map.his_empty_map[i][j] == 'x') ? (cnt++) : (j += 0);
            (cnt == 14) ? (all_sinked = true) : (j += 0);
        }
    }
    return (cnt == 14) ? (0) : (-1);
}

int all_boats_hitted_p2(void)
{
    int cnt = 0;
    bool all_sinked = false;

    for (int c = 0; map.my_map[c] && !all_sinked; c++) {
        for (int l = 0; map.my_map[c][l] && !all_sinked; l++) {
            (map.my_map[c][l] == 'x') ? (cnt++) : (l += 0);
            (cnt == 14) ? (all_sinked = true) : (l += 0);
        }
    }
    return (cnt == 14) ? (1) : (-1);
}

bool input_checker(i_s_t input_st)
{
    if (!input_st.ok) {
        my_putstr(input_st.info);
        return (false);
    }
    return (true);
}

char *get_input(char *file_name)
{
    bool error;
    char *attack = NULL;
    int i = 0;
    FILE *file;
    char *buffer = NULL;
    size_t buffer_size = 0;
    ssize_t bytes_read;
    file = fopen(file_name, "r");

    my_putstr("\n");
    if (!file)
        error = false;
    if (!error) {
        bytes_read = getline(&buffer, &buffer_size, file);
        attack = my_strdup(buffer);
        fclose(file);
    }
    return (attack);
}
