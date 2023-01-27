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

void fill_pos(status_t *pos, char *filename)
{
    bool error;
    pos->his_map = malloc(sizeof(char *) * 5);
    int i = 0;
    FILE *file;
    char *buffer = NULL;
    size_t buffer_size = 0;
    ssize_t bytes_read;
    file = fopen(filename, "r");
    if (!file)
        error = false;
    if (!error) {
        while ((bytes_read = getline(&buffer, &buffer_size, file)) != -1) {
            pos->his_map[i] = my_strdup(buffer);
            i ++;
        }
        fclose(file);
    }
    pos->his_map[i] = NULL;
    pos->error = error;
}

void change_map(struct ship_s ship)
{
    int len = ship.len;
    int sum;
    if (len % 2 != 0)
        sum = 2;
    else
        sum = 1;
    ship.index = ship.index + 48  + 1;
    if (ship.start.line == ship.end.line) {
        for (int i = 0; len > i; i++) {
            map.my_map[SHIP_LINE][SHIP_COL + ((i * 2) + sum)] = ship.index;
        }
    } else {
        for (int j = 0; len > j; j++) {
            map.my_map[SHIP_LINE + j][(ship.start.col * 2)] = ship.index;
        }
    }
}

void change_enemy_map(struct ship_s ship)
{
    int len = ship.len;
    int sum;
    if (len % 2 != 0)
        sum = 2;
    else
        sum = 1;
    ship.index = ship.index + 48  + 1;
    if (ship.start.line == ship.end.line) {
        for (int i = 0; len > i; i++) {
            (map.his_map[SHIP_LINE][START_COL + ((i * 2) + sum)]) = ship.index;
        }
    } else {
        for (int j = 0; len > j; j++) {
            map.his_map[SHIP_LINE + j][ship.start.col * 2] = ship.index;
        }
    }
}

int check_change_map(status_t *map, char *file_name)
{
    bool error;
    char *attack = malloc(sizeof(char )* 3);
    int i = 0;
    FILE *file;
    char *buffer = NULL;
    size_t buffer_size = 0;
    ssize_t bytes_read;
    file = fopen(file_name, "r");
    if (!file)
        error = false;
    if (!error) {
        bytes_read = getline(&buffer, &buffer_size, file);
        attack = my_strdup(buffer);
        fclose(file);
    }
    map->error = error;
    manage_attack(map, attack);
    trigger_win();
    return (0);
}

int get_row(char c)
{
    if (c == 'A')
        return (1);
    if (c == 'B')
        return (2);
    if (c == 'C')
        return (3);
    if (c == 'D')
        return (4);
    if (c == 'E')
        return (5);
    if (c == 'F')
        return (6);
    if (c == 'G')
        return (7);
    if (c == 'H')
        return (8);
    return (0);
}
