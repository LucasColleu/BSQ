/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-BSQ-lucas.colleu
** File description:
** check_error
*/

#include <my.h>
#include <bsq.h>

static int valid_first_ligne(char const *buffer)
{
    int size_ligne = my_find_char(buffer, '\n');
    int i = 0;

    if (size_ligne == -1)
        return (0);
    while (buffer[i] != '\n') {
        if (buffer[i] < '0' || buffer[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

static int only_valid_chars(char const *buffer)
{
    int i = 0;
    char valid_chars[] = ".o\n";

    while (buffer[i] != '\0') {
        if (my_find_char(valid_chars, buffer[i]) == -1)
            return (0);
        i++;
    }
    return (1);
}

static int check_map(char const *buffer, int total_lignes)
{
    int i = 0;
    int nb_lignes = 0;
    int nb_colonnes = 0;
    int total_colonnes = my_find_char(buffer, '\n');

    while (buffer[i] != '\0') {
        if (buffer[i] != '\n') {
            nb_colonnes++;
        } else if (nb_colonnes != total_colonnes) {
            return (1);
        } else {
            nb_lignes++;
            nb_colonnes = 0;
        }
        i++;
    }
    if (nb_lignes != total_lignes)
        return (1);
    return (0);
}

int check_error(char const *buffer)
{
    char const *map;

    if (valid_first_ligne(buffer) == 0)
        return (1);
    map = &buffer[my_find_char(buffer, '\n') + 1];
    if (only_valid_chars(map) == 0)
        return (1);
    return (check_map(map, my_getnbr(buffer)));
}
