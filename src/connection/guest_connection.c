/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** guest_connection.c
*/

#include "../../include/my_navy.h"
#include "../../include/protocol.h"

static void on_enemy_connect(signal_type_e _, navy_t *navy, int sender)
{
    if (navy->guest_sig == -1 && navy->type == host) {
        my_putstr("enemy connected\n");
        navy->guest_sig = sender;
    }
}

int init_guest_connection(navy_t *navy)
{
    if (send_int(0, navy->host_sig) == 84)
        return 84;
    my_putstr("\nsuccessfully connected\n");
    return 0;
}
