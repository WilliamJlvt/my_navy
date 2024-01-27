/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** my_str_utils.c
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i] != '\0'; i++);
    return i;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    if (str == NULL)
        return;
    write(1, str, my_strlen(str));
}

int my_strcmp(char *s1, char *s2)
{
    for (int i = 0; s1 != 0; i++) {
        if (s1[i] > s2[i]) {
            return 1;
        }
        if (s1[i] < s2[i]) {
            return -1;
        }
        if (s1[i] == '\0') {
            return 0;
        }
    }
    return 0;
}
