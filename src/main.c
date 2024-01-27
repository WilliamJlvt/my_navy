/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** main.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/my_navy.h"

int pre_init(int argc, char *argv[])
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        my_putstr("USAGE\n");
        my_putstr("\t./navy [first_player_pid] navy_positions\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("\tfirst_player_pid: only for the 2nd player.");
        my_putstr("pid of the first player.\n");
        my_putstr("\tnavy_positions:");
        my_putstr("file representing the positions of the ships.\n");
        return 1;
    }
    return 0;
}

int init_navy(navy_t *navy, int argc, char *argv[])
{
    char *file_content = get_file_contents(argc == 2 ? argv[1] : argv[2]);

    if (file_content == NULL)
        return 84;
    navy->boats = boats_from_string(file_content);
    if (navy->boats == NULL)
        return 84;
    for (int i = 0; i < 4; i++)
        if (navy->boats[i] == NULL)
            return 84;
    navy->guest_sig = -1;
    navy->registered_listeners = malloc(sizeof(listener_t) * SIGNAL_SIZE);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            navy->my_attacked_points[i][j] = '.';
            navy->enemy_attacked_points[i][j] = '.';
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    navy_t *navy = malloc(sizeof(navy_t));
    game_type_e type = argc == 2 ? host : guest;

    if ((argc != 2 && argc != 3) || navy == NULL)
        return 84;
    if (pre_init(argc, argv))
        return 0;
    navy->type = type;
    if (init_navy(navy, argc, argv) == 84)
        return 84;
    if (type == guest && my_get_nbr(argv[1]) <= 0)
        return 84;
    subscribe(navy);
    if (connection(navy, type == host ? getpid() : my_get_nbr(argv[1])) == 84)
        return 84;
    while (navy->guest_sig == -1);
    start_game(navy);
}

game_type_e get_enemy_type(navy_t *navy)
{
    return (navy->type == host) ? guest : host;
}
