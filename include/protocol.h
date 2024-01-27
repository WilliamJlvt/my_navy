/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** protocol.h
*/

#ifndef PROTOCOL_H
    #define PROTOCOL_H

    #include "my_navy.h"

typedef struct connection_s {
    int sig;
    int pid;
} connection_t;

typedef enum {
    PACKET_TYPE_PING,
    PACKET_TYPE_PONG
} packet_type_e;

typedef struct octet_s {
    int len;
    char *data;
} octet_t;

typedef struct packet_s {
    packet_type_e type;
    octet_t *data;
} packet_t;

typedef struct octet_queue_s {
    int channel;
    int pid;
    struct octet_queue_s *next;
} octet_queue_t;

typedef struct octet_manager_s {
    char *temp;
    char last_result;
    int last_sender;
    octet_queue_t *queue;
    navy_t *navy;
} octet_manager_t;

octet_manager_t *get_signal_manager(void);
int send_octet(char *octet, int pid);
int send_int(int num, int pid);
int int_from_binary(char *octet);
char *binary_from_int(int num);
int get_enemy_pid(navy_t *navy);

#endif /* PROTOCOL_H */
