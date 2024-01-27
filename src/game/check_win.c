/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** check_win.c
*/

#include "../../include/my_navy.h"

static int count_str_char(char *str, char c, int len)
{
    int result = 0;

    for (int i = 0; i < len; i++)
        if (str[i] == c)
            result++;
    return result;
}

static int count_x(char points[8][8])
{
    int result = 0;

    for (int i = 0; i < 8; ++i)
        result += count_str_char(points[i], 'x', 8);
    return result;
}

int player_has_won(navy_t *navy)
{
    if (count_x(navy->enemy_attacked_points) >= 14)
        return 1;
    if (count_x(navy->my_attacked_points) >= 14)
        return 2;
    return -1;
}
