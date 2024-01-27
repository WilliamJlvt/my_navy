/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** signal_sender.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "../../../include/protocol.h"

void add_to_queue(int channel, int pid)
{
    octet_queue_t *new = malloc(sizeof(octet_queue_t));
    octet_queue_t *tmp = get_signal_manager()->queue;

    new->channel = channel;
    new->pid = pid;
    new->next = NULL;
    if (get_signal_manager()->queue == NULL) {
        get_signal_manager()->queue = new;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}

int update(void)
{
    octet_queue_t *tmp = get_signal_manager()->queue;

    if (tmp == NULL)
        return 0;
    while (tmp != NULL) {
        if (kill(tmp->pid, tmp->channel) == -1)
            return 84;
        tmp = tmp->next;
        get_signal_manager()->queue = get_signal_manager()->queue->next;
        usleep(1000);
    }
    return 0;
}

int send_octet(char *octet, int pid)
{
    if (my_strlen(octet) != 8) {
        write(2, "Invalid octet\n", 14);
        return 84;
    }
    for (int i = 0; i < 8; ++i) {
        if (octet[i] != '1' && octet[i] != '0') {
            write(2, "Invalid octet\n", 14);
            return 84;
        }
        add_to_queue(octet[i] == '0' ? SIGUSR1 : SIGUSR2, pid);
        if (update() == 84)
            return 84;
    }
    return 0;
}

char *binary_from_int(int num)
{
    char *binary = malloc(sizeof(char) * 9);

    if (num > 255 || num < 0 || binary == NULL) {
        free(binary);
        return NULL;
    }
    for (int i = 0; i < 8; i++)
        binary[i] = '0';
    binary[8] = '\0';
    for (int i = 7; i >= 0; i--) {
        binary[i] = (char) ((num % 2) + '0');
        num /= 2;
    }
    return binary;
}

int send_int(int num, int pid)
{
    char *octet = binary_from_int(num);
    int result;

    if (octet == NULL)
        return 84;
    result = send_octet(octet, pid);
    free(octet);
    return result;
}
