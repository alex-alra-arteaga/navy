/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** Sink the float simulator by terminal
*/

#include <signal.h>
#include "../includes/my.h"
#include <sys/ucontext.h>
#include <unistd.h>
#include <fcntl.h>

int manage_status(status_t *map, char *attack, i_s_t input_st)
{
    if (!input_checker(input_st)) {
        return (0);
    }

    struct pos_s cordinates;
    set_coordinates(&cordinates, attack);

    attack[2] = '\0';
    if (map->his_map[cordinates.line][cordinates.col] >= '0'
        && map->his_map[cordinates.line][cordinates.col] <= '9') {
        my_putstr(attack);
        my_putstr(":");
        my_putstr("hit\n");
    } else {
        my_putstr(attack);
        my_putstr(":");
        my_putstr("missed\n");
    }
    return (0);
}

void manage_status_v2(status_t *map, char *attack)
{
    struct pos_s cordinates;
    set_coordinates(&cordinates, attack);

    attack[2] = '\0';
    if (map->my_map[cordinates.line][cordinates.col] >= '0'
        && map->my_map[cordinates.line][cordinates.col] <= '9') {
        my_putstr(attack);
        my_putstr(":");
        my_putstr("hit\n");

    } else {
        my_putstr(attack);
        my_putstr(":");
        my_putstr("missed\n");
    }
}

void manage_status_v3(status_t *map, char *attack)
{
    struct pos_s cordinates;
    set_coordinates(&cordinates, attack);

    attack[2] = '\0';
    if (map->his_map[cordinates.line][cordinates.col] >= '0'
    && map->his_map[cordinates.line][cordinates.col] <= '9') {
        my_putstr(attack);
        my_putstr(":");
        my_putstr("hit\n");

    } else {
        my_putstr(attack);
        my_putstr(":");
        my_putstr("missed\n");
    }
}

void manage_attack(status_t *map, char *attack)
{
    struct pos_s cordinates;
    set_coordinates(&cordinates, attack);
    if ((map->my_map[cordinates.line][cordinates.col] >= '0'
        && map->my_map[cordinates.line][cordinates.col] <= '9')
        || map->my_map[cordinates.line][cordinates.col] == 'x') {
        map->my_map[cordinates.line][cordinates.col] = 'x';
    } else
        map->my_map[cordinates.line][cordinates.col] = 'o';
}

void manage_empty(status_t *map, char *attack)
{
    static int binary = 1;
    struct pos_s cordinates;
    set_coordinates(&cordinates, attack);

    if (binary % 2 == 0) {
        if (map->my_map[cordinates.line][cordinates.col] >= '0'
            && map->my_map[cordinates.line][cordinates.col] <= '9') {
            map->his_empty_map[cordinates.line][cordinates.col] = 'x';
        } else {
            map->his_empty_map[cordinates.line][cordinates.col] = 'o';
        }
    }
    if (binary % 2 != 0) {
        if (map->his_map[cordinates.line][cordinates.col] >= '0'
            && map->his_map[cordinates.line][cordinates.col] <= '9') {
            map->his_empty_map[cordinates.line][cordinates.col] = 'x';
        } else {
            map->his_empty_map[cordinates.line][cordinates.col] = 'o';
        }
    }
}
