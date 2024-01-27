/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** signal_listener.c
*/

#include <stdlib.h>
#include "../../include/my_navy.h"

void register_listener(navy_t *navy, signal_type_e type,
    void (*handler)(signal_type_e, navy_t *, int))
{
    listener_t *new_node = malloc(sizeof(listener_t));

    new_node->type = type;
    new_node->handler = handler;
    navy->registered_listeners[type] = new_node;
}

void unregister_all(navy_t *navy)
{
    for (int i = 0; i < SIGNAL_SIZE; i++)
        free(navy->registered_listeners[i]);
    free(navy->registered_listeners);
}

void handle_listeners(navy_t *navy, int signal, int sender)
{
    int coos = signal - 100;

    if (signal >= 100 && signal <= 188) {
        on_attack(navy, coos / 10, coos - ((coos / 10) * 10));
        return;
    }
    if (signal < 0 || signal > SIGNAL_SIZE)
        return;
    navy->registered_listeners[signal]->handler(signal, navy, sender);
}
