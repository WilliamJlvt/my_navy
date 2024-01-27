/*
** EPITECH PROJECT, 2024
** navy
** File description:
** utils.h
*/

#ifndef UTILS_H
    #define UTILS_H

typedef struct vector2i_s {
    int x;
    int y;
} vector2i_t;

int my_strlen(char const *str);
void my_putchar(char c);
void my_putstr(char const *str);
void my_put_nbr(int nb);
char *my_strdup(char *str);
int my_strcmp(char const *s1, char const *s2);
char **my_str_to_word_array(char const *str, char delimiter);
int my_get_nbr(char const *str);
int char_to_int(char c);
char *my_rev_str(char *str);

#endif /* UTILS_H */
