/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** Sink the float simulator by terminal
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "../includes/my.h"
#include <fcntl.h>
#include <sys/ucontext.h>
#include <unistd.h>
#include <stdbool.h>

bool attack_pos_manager(char *input)
{
    char str[8] = "ABCDEFGH";
    char num[8] = "12345678";
    int control = 0;
    for (int i = 0; str[i]; i++) {
        if (input[0] == str[i])
            control++;
    }

    for (int j = 0; num[j]; j++) {
        if (input[1] == num[j] && control == 1)
            return true;
    }
    return false;
}
