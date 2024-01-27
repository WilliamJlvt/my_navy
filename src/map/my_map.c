/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** my_map.c
*/

#include "../../include/my_navy.h"

int is_in_boat(vector2i_t pos, boat_data_t *boat)
{
    int x_inside = (pos.y >= boat->pos1.x && pos.y <= boat->pos2.x) ||
        (pos.y >= boat->pos2.x && pos.y <= boat->pos1.x);
    int y_inside = (pos.x >= boat->pos1.y && pos.x <= boat->pos2.y) ||
        (pos.x >= boat->pos2.y && pos.x <= boat->pos1.y);

    return x_inside && y_inside;
}

static void init_line(int i, int j, char *line, navy_t *navy)
{
    char result;

    if (navy->my_attacked_points[i][j] != '.') {
        line[j] = navy->my_attacked_points[i][j];
        return;
    }
    for (int k = 0; k < 4; k++) {
        if (is_in_boat((vector2i_t){i + 1, j + 1}, navy->boats[k])) {
            result = navy->boats[k]->size + '0';
            break;
        }
        result = '.';
    }
    line[j] = result;
}

char add_attacked_point(navy_t *navy, int x, int y)
{
    char result = 'o';

    if (navy->my_attacked_points[y][x] != '.')
        return result;
    for (int boat = 0; boat < 4; boat++) {
        if (is_in_boat((vector2i_t){y + 1, x + 1}, navy->boats[boat])) {
            result = 'x';
            break;
        }
    }
    return result;
}

void print_my_map(navy_t *navy)
{
    char printed_map[8][8];

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            init_line(i, j, printed_map[i], navy);
    my_putstr("\nmy navy:\n |A B C D E F G H\n-+---------------\n");
    for (int i = 1; i <= 8; i++) {
        my_put_nbr(i);
        my_putchar('|');
        for (int j = 0; j < 8; j++) {
            my_putchar(printed_map[i - 1][j]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
}
