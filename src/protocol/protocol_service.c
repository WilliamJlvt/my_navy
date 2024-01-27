/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** protocol_service.c
*/

#include <unistd.h>
#include "../../include/my_navy.h"

int connection(navy_t *navy, int host)
{
    navy->host_sig = host;
    if (navy->type == guest) {
        navy->guest_sig = getpid();
        return init_guest_connection(navy);
    } else {
        init_host_connection(navy);
    }
    return 0;
}

int get_enemy_pid(navy_t *navy)
{
    return navy->type == host ? navy->guest_sig : navy->host_sig;
}
