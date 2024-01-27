/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** host_connection.c
*/

#include "../../include/my_navy.h"

static void on_enemy_connect(signal_type_e _, navy_t *navy, int sender)
{
    if (navy->guest_sig == -1 && navy->type == host) {
        my_putstr("\nenemy connected\n");
        navy->guest_sig = sender;
    }
}

void init_host_connection(navy_t *navy)
{
    my_putstr("\nwaiting for enemy connection...\n");
    register_listener(navy, connect_signal, &on_enemy_connect);
}
