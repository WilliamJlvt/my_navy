/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** enemy_map.c
*/

#include "../../include/my_navy.h"

void print_enemy_map(navy_t *navy)
{
    my_putstr("\nenemy navy:\n |A B C D E F G H\n-+---------------\n");
    for (int i = 1; i <= 8; i++) {
        my_put_nbr(i);
        my_putchar('|');
        for (int j = 0; j < 8; j++) {
            my_putchar(navy->enemy_attacked_points[i - 1][j]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
}
