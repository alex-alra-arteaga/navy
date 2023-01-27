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

void init_player1(void)
{
    int fd = open("transmission/p2pid.txt", O_RDWR);

    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putstr("\nwaiting for enemy connection...\n");
    write(fd, my_int_to_str(getpid()), my_strlen(my_int_to_str(getpid())));
}

void init_player2(char **argv)
{
    int fd = open("transmission/pid.txt", O_RDWR);

    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    write(fd, my_int_to_str(getpid()), my_strlen(argv[1]));
    map.pid = my_getnbr(argv[1]);
    kill(map.pid, SIGUSR1);
}

void init_signals(void)
{
    struct sigaction player1_action;
    struct sigaction player2_action;

    player1_action.sa_handler = &player1_handler;
    sigemptyset(&player1_action.sa_mask);
    player1_action.sa_flags = 0;
    sigaction(SIGUSR1, &player1_action, NULL);
    player2_action.sa_handler = &player2_handler;
    sigemptyset(&player2_action.sa_mask);
    player2_action.sa_flags = 0;
    sigaction(SIGUSR2, &player2_action, NULL);
}

void init_map(char **postions, int control)
{
    int z = 0;
    int i = 0;

    while (postions[z]) {
        struct ship_s temp_ship;
        temp_ship.index = z;
        temp_ship.len = postions[z][0] - 48;
        temp_ship.start.col = get_row(postions[z][2]);
        temp_ship.start.line = postions[z][3] - 48;
        temp_ship.end.col = get_row(postions[z][5]);
        temp_ship.end.line = postions[z][6] - 48;
        (control == 0) ?
        (change_map(temp_ship)) : (change_enemy_map(temp_ship));
        z++;
    }
}
