/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** bytes_reader.c
*/

#include <stdlib.h>
#include "../../../include/commons.h"

char *int_to_binary(int value)
{
    char *result = malloc(sizeof(char) * 9);
    int i = 0;

    for (int j = 0; j < 8; j++) {
        result[j] = '0';
    }
    result[8] = '\0';
    while (value > 0) {
        result[i] = (value % 2) + '0';
        value /= 2;
        i++;
    }
    return my_rev_str(result);
}
