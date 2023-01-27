/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** Sink the float simulator by terminal
*/

#include "../includes/my.h"
#include "../includes/ships.h"
#include <unistd.h>

bool is_won(void)
{
    if (all_boats_hitted_p2() == 1) {
        return (true);
    }
    if (all_boats_hitted_p1() == 0) {
        return (true);
    }
    return (false);
}

void set_coordinates(struct pos_s *pos, char *attck)
{
    pos->col = ((attck[0] - 16 - 48) * 2);
    pos->line = (attck[1] - 48 + 1);
}

void trigger_win(void)
{
    if (all_boats_hitted_p2() == 1) {
        if (map.pid > getpid())
            kill(map.pid, SIGUSR2);
        else
            kill(map.pid, SIGUSR1);
        map.pid = -1;
    }
    if (all_boats_hitted_p1() == 0) {
        if (map.pid > getpid())
            kill(map.pid, SIGUSR2);
        else
            kill(map.pid, SIGUSR1);
        map.pid = -1;
    }
}

ssize_t handle_input_attack(i_s_t input_st, size_t len, char *input)
{
    ssize_t nread;

    my_putstr(input_st.info);
    my_putstr("\nattack: ");
    if ((nread = getline(&input, &len, stdin)) == 1) {
        kill(getpid(), SIGKILL);
        kill(map.pid, SIGKILL);
    }
    return (nread);
}
