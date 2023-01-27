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

void open_n_read_file(int index, char **argv, status_t *pos)
{
    bool error;
    int i = 0;
    char *buffer = NULL;
    size_t buffer_size = 0;
    ssize_t bytes_read;
    FILE *file = fopen(argv[index], "r");

    (index == 1) ? (fill_pos(pos, argv[1])) : (fill_pos(pos, argv[2]));
    pos->my_map = malloc(sizeof(char *) * 5);
    if (!file)
        error = false;
    while (!error
    && (bytes_read = getline(&buffer, &buffer_size, file)) != -1) {
        pos->my_map[i] = my_strdup(buffer);
        i++;
    }
    fclose(file);
    pos->my_map[i] = NULL;
    pos->error = error;
}

status_t read_local(char *file_name)
{
    status_t status = {.my_map = NULL, .his_map = NULL};
    status.my_map = malloc(sizeof(char *) * 10);
    status.his_map = malloc(sizeof(char *) * 10);
    status.his_empty_map = malloc(sizeof(char *) * 10);
    int i = 0;
    char *buffer = NULL;
    size_t buffer_size = 0;
    ssize_t bytes_read;
    FILE *file = fopen(file_name, "r");
    while ((bytes_read = getline(&buffer, &buffer_size, file)) != -1) {
        status.my_map[i] = my_strdup(buffer);
        status.his_map[i] = my_strdup(buffer);
        status.his_empty_map[i] = my_strdup(buffer);
        i++;
    }
    status.my_map[i] = NULL;
    status.his_map[i] = NULL;
    status.his_empty_map[i] = NULL;
    fclose(file);
    return (status);
}
