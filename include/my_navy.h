/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** my_navy.h
*/

#ifndef MY_NAVY_H
    #define MY_NAVY_H

    #include "commons.h"

    #define SIGNAL_SIZE 5

typedef struct boat_data_s {
    int size;
    vector2i_t pos1;
    vector2i_t pos2;
} boat_data_t;

char *get_file_contents(const char *path);
boat_data_t **boats_from_string(char *str);

typedef enum {
    host,
    guest
} game_type_e;

typedef enum {
    connect_signal,
    hit_attack,
    missed_attack,
} signal_type_e;

typedef struct registered_listener_s listener_t;

typedef struct navy_s {
    boat_data_t **boats;
    game_type_e type;
    int host_sig;
    int guest_sig;
    listener_t **registered_listeners;
    char enemy_attacked_points[8][8];
    char my_attacked_points[8][8];
    game_type_e turn_to_play;
    vector2i_t last_attack;
    int result;
    int played_rounds;
} navy_t;

struct registered_listener_s {
    signal_type_e type;
    void (*handler)(signal_type_e, navy_t *, int);
};

int subscribe(navy_t *navy);
int connection(navy_t *navy, int host);
void init_host_connection(navy_t *navy);
int init_guest_connection(navy_t *navy);
game_type_e get_enemy_type(navy_t *navy);

// src/listener/signal_listener.c
void unregister_all(navy_t *navy);
void register_listener(navy_t *navy, signal_type_e type,
    void (*handler)(signal_type_e, navy_t *, int));
void handle_listeners(navy_t *navy, int signal, int sender);

// src/map/my_map.c
void print_my_map(navy_t *navy);
char add_attacked_point(navy_t *navy, int x, int y);

// src/map/enemy_map.c
void print_enemy_map(navy_t *navy);

// src/game/check_win.c
int player_has_won(navy_t *navy);

// src/game/game_loop.c
int start_game(navy_t *navy);
void on_attack(navy_t *navy, int x, int y);

#endif /* MY_NAVY_H */
