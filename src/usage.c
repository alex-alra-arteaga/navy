/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** Sink the float simulator by terminal
*/

#include "../includes/my.h"

void usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid: only for the 2nd player. pid of the ");
    my_putstr("first player.\n\tnavy_positions: file representing the ");
    my_putstr("positions of the ships.\n");
}
