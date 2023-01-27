/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** Sink the float simulator by terminal
*/

#include <signal.h>
#include "../includes/my.h"
#include <fcntl.h>
#include <sys/ucontext.h>
#include <unistd.h>

void get_pid(void)
{
    int fd_pid = open("transmission/pid.txt", O_RDWR);
    int file_size = lseek(fd_pid, 0, SEEK_END);
    char *ppid_str = malloc(file_size);
    lseek(fd_pid, 0, SEEK_SET);
    if (read(fd_pid, ppid_str, file_size) == -1 || fd_pid == -1 || !ppid_str) {
        map.error = true;
        return;
    }
    ppid_str[file_size] = '\0';
    map.pid = my_getnbr(ppid_str);
    free(ppid_str);
    close(fd_pid);
}

void get_p2pid(void)
{
    int fd_pid = open("transmission/p2pid.txt", O_RDWR);
    int file_size = lseek(fd_pid, 0, SEEK_END);
    char *ppid_str = malloc(file_size);
    lseek(fd_pid, 0, SEEK_SET);
    if (read(fd_pid, ppid_str, file_size) == -1 || fd_pid == -1 || !ppid_str) {
        map.error = true;
        return;
    }
    ppid_str[file_size] = '\0';
    map.pid = my_getnbr(ppid_str);
    free(ppid_str);
    close(fd_pid);
}

void get_ppid_n_transmit_input(void)
{
    input_t input;
    char *my_input;
    static int passes = 0;
    int fd = open("transmission/transmission1.txt", O_RDWR);

    if (fd == -1) {
        map.error = true;
        return;
    }
    get_pid();
    if (passes++ == 0)
        kill(map.pid, SIGUSR2);
    input = handle_attack(fd);
    my_input = get_input("transmission/transmission1.txt");
    manage_empty(&map, my_input);
    manage_status(&map, input.input, input.input_st);
    if (!is_won())
        my_putstr("\nwaiting for enemy's attack...");
    close(fd);
}

input_t handle_attack(int fd)
{
    char *input = malloc(sizeof(char) * 100);
    input_t inputs_t;
    size_t len;
    ssize_t nread;
    my_putstr("\nattack: ");
    if ((nread = getline(&input, &len, stdin)) == -1)
        kill(map.pid, SIGKILL), kill(getpid(), SIGKILL);
    i_s_t input_st = input_state(input);
    if (input_st.ok)
        write(fd, input, nread - 1);
    while (!input_st.ok) {
        free(input);
        input = malloc(sizeof(char) * 100);
        handle_input_attack(input_st, len, input);
        input_st = input_state(input);
        if (input_st.ok) {
            write(fd, input, nread);
        }
    }
    return (inputs_t = (input_t){.input = input, .input_st = input_st});
}

void getp2pid_n_transmit_input(void)
{
    char *my_input;
    char *my_input2;
    int fd = open("transmission/transmission1.txt", O_RDWR);

    if (fd == -1) {
        map.error = true;
        return;
    }
    handle_attack(fd);
    my_input2 = get_input("transmission/transmission1.txt");
    manage_empty(&map, my_input2);
    my_input = get_input("transmission/transmission1.txt");
    manage_status_v3(&map, my_input);
    kill(getpid(), SIGUSR2);
    kill(map.pid, SIGUSR1);
    close(fd);
}
