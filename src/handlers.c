/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** Sink the float simulator by terminal
*/
#include <signal.h>
#include "../includes/my.h"

void print_maps(status_t *map)
{
    my_putstr("\nmy positions:\n");
    for (int i = 0; i < 10; i++)
        my_putstr(map->my_map[i]);
    my_putstr("\nenemy's positions:\n");
    for (int j = 0; j < 10; j++)
        my_putstr(map->his_empty_map[j]);
}

void print_maps_n_transmit_input_n_getppid(void)
{
    print_maps(&map);
    get_ppid_n_transmit_input();
    kill(map.pid, SIGUSR2);
}

void print_maps_n_transmit_input_n_getp2pid(void)
{
    static int passes = 0;

    if (++passes % 2 != 0) {
        print_maps(&map);
        if (!is_won())
            my_putstr("\nwaiting for enemy's attack...");
    }
    if (passes % 2 == 0) {
        get_p2pid();
        getp2pid_n_transmit_input();
    }
}

void player1_handler(int sig)
{
    char *input;
    static int passes = 0;
    static int control = 0;

    if (!is_won() && control++ > 0) {
        input = get_input("transmission/transmission1.txt");
        manage_status_v2(&map, input);
    }
    if (!is_won() && !map.error) {
        if (passes++ == 0)
            my_putstr("\nenemy connected\n");
        if (passes > 1)
            check_change_map(&map, "transmission/transmission1.txt");
        if (passes > 0 && map.pid != -1 && !is_won()) {
            my_putchar('\n');
            print_maps_n_transmit_input_n_getppid();
        }
    }
    if (is_won())
        print_maps(&map);
}

void player2_handler(int sig)
{
    static int control = 0;
    static int binary = 1;
    static int passes = 0;
    if (!is_won() && control++ > 0 && binary % 2 == 0) {
        char *input = get_input("transmission/transmission1.txt");
        manage_status_v2(&map, input);
    }
    binary++;
    if (!is_won() && !map.error) {
        if (passes++ == 0)
            my_putstr("\nsuccessfully connected\n\n");
        if (passes > 1 && binary % 2 != 0)
            check_change_map(&map, "transmission/transmission1.txt");
        if (passes > 0 && map.pid != -1 && !is_won()) {
            my_putchar('\n');
            print_maps_n_transmit_input_n_getp2pid();
        }
        if (is_won())
            print_maps(&map);
    }
}
