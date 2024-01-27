/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** signal_manager.c
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include "../../../include/protocol.h"
#include "../../../include/commons.h"

octet_manager_t *manager;

octet_manager_t *get_signal_manager(void)
{
    return manager;
}

void update_reader(void)
{
    int i = 0;

    for (; manager->temp[i] != '\0'; i++);
    manager->temp[i] = manager->last_result;
    if (i == 7) {
        handle_listeners(get_signal_manager()->navy,
            int_from_binary(manager->temp), manager->last_sender);
        for (int j = 0; j < 8; j++)
            manager->temp[j] = '\0';
    }
}

static void my_handler(int sig, siginfo_t *siginfo, void *ctx)
{
    if (sig == SIGCONT)
        return;
    manager->last_result = sig == SIGUSR1 ? '0' : '1';
    manager->last_sender = siginfo->si_pid;
    kill(siginfo->si_pid, SIGCONT);
    update_reader();
}

int subscribe(navy_t *navy)
{
    struct sigaction act;
    char *str = malloc(sizeof(char) * 8);

    for (int i = 0; i < 8; i++)
        str[i] = '\0';
    manager = malloc(sizeof(octet_manager_t));
    manager->temp = str;
    manager->queue = NULL;
    manager->last_result = '\0';
    manager->navy = navy;
    act.sa_sigaction = my_handler;
    act.sa_flags = SA_SIGINFO;
    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putchar('\n');
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    sigaction(SIGCONT, &act, NULL);
}

int int_from_binary(char *octet)
{
    int nb = 0;

    for (int i = 0; octet[i] != '\0'; i++){
        nb <<= 1;
        if (octet[i] == '1')
            nb += 1;
    }
    return nb;
}
