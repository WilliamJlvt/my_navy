/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>

int my_strlen_word(char const *str, char delimiter)
{
    int i;

    for (i = 0; str[i] != delimiter && str[i] != '\0'; i++);
    return i;
}

int my_strlen_size(char const *str, char delimiter)
{
    int i = 0;
    int x = 0;

    for (; str[i]; i++)
        if (str[i] == '\0' || str[i] == delimiter || str[i] == '\n' ||
            str[i] == '\t')
            x++;
    return x;
}

char **my_str_to_word_array(char const *str, char delimiter)
{
    int size = my_strlen_size(str, delimiter) + 2;
    char **r = malloc(sizeof(char *) * size);
    int i;
    int x;
    int y;

    for (i = 0; str[i] == delimiter; i++);
    for (x = 0; str[i] != '\0'; x++) {
        r[x] = malloc(sizeof(char) * (my_strlen_word(&str[i], delimiter) + 1));
        for (y = 0; str[i] != delimiter && str[i] != '\0' && str[i] != '\t';) {
            r[x][y] = str[i];
            y++;
            i++;
        }
        r[x][y] = '\0';
        for (; (str[i] == delimiter || str[i] == '\t') && str[i]; i++);
    }
    r[x] = NULL;
    return r;
}
