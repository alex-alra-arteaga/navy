/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** Contains the prototypes of all the functions in libmy.a
*/

#include <stdio.h>

#ifndef SHIPS_H_
    #define SHIPS_H_

    #define IS_H_FLAG \
    (argv[1][0] == '-' && argv[1][1] == 'h' && my_strlen(argv[1]) == 2)
    #define SHIP_LINE (ship.start.line + 1)
    #define SHIP_COL (ship.start.col + 2)
    #define START_COL ((ship.start.col + 2))

    struct pos_s {
        int line;
        int col;
    };

    struct ship_s {
        int index;
        int len;
        struct pos_s start;
        struct pos_s end;
    };

    typedef struct s_status {
        int pid;
        bool error;
        char **my_map;
        char **his_map;
        char **his_empty_map;
        char **argv;
    } status_t;

    typedef struct s_status_str {
        bool error;
        char *buff;
    }status_str_t;


    typedef struct s_input_state {
        bool ok;
        char *info;
    }i_s_t;

    typedef struct s_input {
        char *input;
        i_s_t input_st;
    }input_t;

    typedef struct s_input_a {
        i_s_t input_st;
        char *input;
    }input_a_t;

    extern struct s_status map;
    extern void player1_handler(int sig);
    extern void player2_handler(int sig);
    bool all_boats_hitted(void);
    void init_player1(void);
    void init_player2(char **argv);
    void init_signals(void);
    void init_map(char **postions, int control);
    void get_pid(void);
    void get_p2pid(void);
    void get_ppid_n_transmit_input(void);
    void print_maps_n_transmit_input_n_getppid(void);
    void getp2pid_n_transmit_input(void);
    void change_enemy_map(struct ship_s ship);
    void print_maps_n_transmit_input_n_getp2pid(void);
    void change_map(struct ship_s ship);
    bool all_boats_hitted(void);
    status_t read_local(char *file_name);
    int get_row(char c);
    void open_n_read_file(int index, char **argv, status_t *pos);
    int check_change_map(status_t *map, char *file_name);
    void fill_pos(status_t *pos, char *filename);
    int all_boats_hitted_p1(void);
    int all_boats_hitted_p2(void);
    i_s_t input_state(char *input);
    void manage_status_v2(status_t *map, char *attack);
    int manage_status(status_t *map, char *attack, i_s_t input_st);
    bool input_checker(i_s_t input_st);
    char *get_input(char *file_name);
    input_t handle_attack(int fd);
    void usage(void);
    void set_coordinates(struct pos_s *pos, char *attck);
    void manage_attack(status_t *map, char *attack);
    void manage_status_v3(status_t *map, char *attack);
    void read_n_manage_file(status_t *status, char *file_name);
    void manage_empty(status_t *map, char *attack);
    bool attack_pos_manager(char *input);
    bool is_won(void);
    void trigger_win(void);
    ssize_t handle_input_attack(i_s_t input_st, size_t len, char *input);
    bool check_parse(char **line);

#endif
