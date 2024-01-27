/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** map_parser.c
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../include/my_navy.h"

static void *invalid_file(void)
{
    write(2, "Invalid file\n", 13);
    return NULL;
}

char *get_file_contents(const char *path)
{
    int open_status;
    int read_status;
    char *buffer = malloc(sizeof(char) * 32);

    open_status = open(path, O_RDONLY);
    if (open_status < 0)
        return invalid_file();
    read_status = read(open_status, buffer, sizeof(char) * 31);
    if (read_status < 0)
        return invalid_file();
    buffer[read_status] = '\0';
    if (read_status < 31)
        return invalid_file();
    return buffer;
}

static int str_array_len(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return i;
}

static int init_vector(vector2i_t *vector, char x, char y)
{
    int ry = char_to_int(y);

    if (x < 'A' || x > 'H' || ry == -1 || ry == 0 || ry == 9)
        return 0;
    vector->x = x - 64;
    vector->y = ry;
    return 1;
}

int ar_size(vector2i_t pos1, vector2i_t pos2)
{
    int x = pos2.x - pos1.x;
    int y = pos2.y - pos1.y;

    if (x == 0)
        return y + 1;
    if (y == 0)
        return x + 1;
    return 0;
}

boat_data_t *boat_from_line(char *str, boat_data_t **boats)
{
    boat_data_t *boat = malloc(sizeof(boat_data_t));
    vector2i_t pos1 = {0, 0};
    vector2i_t pos2 = {0, 0};

    if (my_strlen(str) != 7)
        return NULL;
    if (char_to_int(str[0]) != -1 && init_vector(&pos1, str[2], str[3]) &&
        init_vector(&pos2, str[5], str[6])) {
        boat->size = char_to_int(str[0]);
        if (boats[boat->size - 2] != NULL || ar_size(pos1, pos2) != boat->size)
            return NULL;
        boat->pos1 = pos1;
        boat->pos2 = pos2;
        return boat;
    }
    return NULL;
}

static int valid_boat_size(int i)
{
    return i >= 2 && i <= 5;
}

boat_data_t **boats_from_string(char *str)
{
    boat_data_t **boat = malloc(sizeof(boat_data_t) * 5);
    boat_data_t *current = NULL;
    char **lines = my_str_to_word_array(str, '\n');

    for (int i = 0; i < 4; i++)
        boat[i] = NULL;
    if (str_array_len(lines) != 4)
        return NULL;
    for (int i = 0; lines[i] != NULL; i++) {
        current = boat_from_line(lines[i], boat);
        if (current == NULL || !valid_boat_size(current->size))
            return NULL;
        boat[current->size - 2] = current;
        free(lines[i]);
    }
    free(lines);
    boat[4] = NULL;
    return boat;
}
