/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** Sink the float simulator by terminal
*/

#include "../includes/my.h"
#include <unistd.h>
#include <fcntl.h>

struct s_status map;

bool error_handling(int argc, char **argv)
{
    int fd;
    bool error = false;
    if (argc < 2 || argc > 3)
        error = true;
    if (argc == 2 && (fd = open(argv[1], O_RDWR)) == -1)
        error = true;
    if (argc == 3 && (fd = open(argv[2], O_RDWR)) == -1)
        error = true;
    return (error);
}

bool navy(int argc, char **argv)
{
    struct s_status pos;
    bool error;
    if (argc == 2) {
        map = read_local("map.txt");
        open_n_read_file(1, argv, &pos);
        if (!check_parse(pos.my_map)) {
            init_map(pos.my_map, 0);
            init_map(pos.his_map, 1);
        }
    }
    if (argc == 3) {
        map = read_local("map.txt");
        open_n_read_file(2, argv, &pos);
        if (!check_parse(pos.my_map)) {
            init_map(pos.my_map, 0);
            init_map(pos.his_map, 1);
        }
    }
    error = check_parse(pos.my_map);
    return (error);
}

bool init_navy(int argc, char **argv, bool error)
{
    init_signals();
    if (!error) {
        if (argc == 2)
            init_player1();
        if (argc == 3)
            init_player2(argv);
        error = navy(argc, argv);
    }
    return (error);
}

int main(int argc, char **argv)
{
    int isRunning = -1;
    bool error = error_handling(argc, argv);

    if (argc == 2 && IS_H_FLAG) {
        usage();
        return (0);
    }
    error = init_navy(argc, argv, error);
    while (!error && isRunning == -1) {
        isRunning = all_boats_hitted_p1();
        if (isRunning == -1)
            isRunning = all_boats_hitted_p2();
        usleep(2000000);
        if (isRunning != -1) {
            (isRunning == 0) ?
            (my_putstr("\nI won\n")) : (my_putstr("\nEnemy won\n"));
            return (isRunning);
        }
    }
    return (84);
}
