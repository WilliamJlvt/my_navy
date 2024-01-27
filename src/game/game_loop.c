/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** game_loop.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my_navy.h"
#include "../../include/protocol.h"

static vector2i_t ask_attack(navy_t *navy)
{
    char *argv = malloc(sizeof(char) * 3);
    size_t size = 2;
    int y;
    int x;
    int result;

    my_putstr("\nattack: ");
    result = getline(&argv, &size, stdin);
    y = char_to_int(argv[1]);
    if (result != 3 || argv[0] < 'A' || argv[0] > 'H' || y > 8 || y < 1) {
        my_putstr("\nwrong position\n");
        return ask_attack(navy);
    }
    x = argv[0] - 'A';
    y = char_to_int(argv[1]) - 1;
    send_int(100 + (x * 10) + y, get_enemy_pid(navy));
    navy->result = 0;
    free(argv);
    return (vector2i_t) {x, y};
}

void on_attack(navy_t *navy, int x, int y)
{
    my_putstr("\nresult: ");
    my_putchar(x + 'A');
    my_putchar(y + '1');
    if (add_attacked_point(navy, x, y) == 'o') {
        send_int(missed_attack, get_enemy_pid(navy));
        my_putstr(":missed\n");
        navy->my_attacked_points[y][x] = 'o';
    } else {
        send_int(hit_attack, get_enemy_pid(navy));
        my_putstr(":hit\n");
        navy->my_attacked_points[y][x] = 'x';
    }
    navy->turn_to_play = navy->type;
}

static void on_result(signal_type_e type, navy_t *navy, int sender)
{
    vector2i_t point = navy->last_attack;

    my_putstr("\nresult: ");
    my_putchar(point.x + 'A');
    my_putchar(point.y + '1');
    if (type == hit_attack) {
        navy->enemy_attacked_points[point.y][point.x] = 'x';
        my_putstr(":hit\n");
    } else if (type == missed_attack) {
        navy->enemy_attacked_points[point.y][point.x] = 'o';
        my_putstr(":missed\n");
    }
    navy->result = 1;
}

int game_loop(navy_t *navy)
{
    if (navy->turn_to_play == navy->type) {
        navy->last_attack = ask_attack(navy);
        while (!navy->result);
        navy->turn_to_play = get_enemy_type(navy);
    } else {
        my_putstr("\nwaiting for enemy's attack...\n");
        while (navy->turn_to_play != navy->type);
    }
    navy->played_rounds ++;
    if (navy->played_rounds % 2 == 0) {
        print_my_map(navy);
        print_enemy_map(navy);
    }
    return 1;
}

static int process_game(navy_t *navy)
{
    int win_status = -1;

    print_my_map(navy);
    print_enemy_map(navy);
    while (win_status == -1) {
        game_loop(navy);
        win_status = player_has_won(navy);
    }
    print_my_map(navy);
    print_enemy_map(navy);
    if (win_status == 1)
        my_putstr("\nI won\n");
    else if (win_status == 2)
        my_putstr("\nEnemy won\n");
    return win_status;
}

int start_game(navy_t *navy)
{
    register_listener(navy, hit_attack, &on_result);
    register_listener(navy, missed_attack, &on_result);
    navy->turn_to_play = host;
    navy->played_rounds = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; ++j) {
            navy->my_attacked_points[i][j] = '.';
            navy->enemy_attacked_points[i][j] = '.';
        }
    }
    return process_game(navy);
}
